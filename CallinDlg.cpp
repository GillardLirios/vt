// CallinDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "vt.h"
#include "CallinDlg.h"
#include "afxdialogex.h"
#include "CSvrSocket.h"

// CCallinDlg 对话框

IMPLEMENT_DYNAMIC(CCallinDlg, CDialogEx)

CCallinDlg::CCallinDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CALL_IN, pParent)
	, m_strCarPlateNum(_T(""))
	, m_strAlarmType(_T(""))
	, m_strAlarmInfo(_T(""))
{
	m_call_state.call_state = CALL_IN;
}

CCallinDlg::~CCallinDlg()
{
}

void CCallinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CAR_PLATE_NUM, m_strCarPlateNum);
	DDX_Text(pDX, IDC_EDIT_ALARM_TYPE, m_strAlarmType);
	DDX_Text(pDX, IDC_EDIT_ALARM_INFO, m_strAlarmInfo);
	DDX_Control(pDX, IDC_STATIC_ANSWER, m_stc_answer);
	//	DDX_Control(pDX, IDC_STATIC_ACTIVE, m_stc_active);
	DDX_Control(pDX, IDC_STATIC_REJECT, m_stc_reject);
	DDX_Control(pDX, IDC_STATIC_CLOSE, m_stc_close);
	DDX_Control(pDX, IDC_STATIC_CALL_DURATION, m_stc_call_duration);
	DDX_Control(pDX, IDC_STATIC_CALL_FROM, m_stcCallFrom);
}


BEGIN_MESSAGE_MAP(CCallinDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCallinDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CCallinDlg::OnBnClickedCancel)
	ON_STN_CLICKED(IDC_STATIC_ANSWER, &CCallinDlg::OnStnClickedStaticAnswer)
	ON_STN_CLICKED(IDC_STATIC_REJECT, &CCallinDlg::OnStnClickedStaticReject)
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
	ON_MESSAGE(WM_CALLIN_MSG, &CCallinDlg::OnRcvHungup)
	ON_STN_CLICKED(IDC_STATIC_CLOSE, &CCallinDlg::OnStnClickedStaticClose)
END_MESSAGE_MAP()


// CCallinDlg 消息处理程序


void CCallinDlg::OnBnClickedOk()
{
	UpdateData();
	USES_CONVERSION;
	m_ci.alarm_info = W2A(m_strAlarmInfo.GetBuffer());
	m_ci.alarm_type = W2A(m_strAlarmType.GetBuffer());
	m_ci.car_plate_number = W2A(m_strCarPlateNum.GetBuffer());
	if (m_ci.alarm_info.length() < 16)
	{
		MessageBox(_T("报警信息字数太少"));
		return;
	}
	if (m_ci.alarm_type.length() < 2)
	{
		MessageBox(_T("请填写报警类型"));
		return;
	}
	if (m_ci.car_plate_number.length() < 8)
	{
		MessageBox(_T("请填写车牌号码"));
		return;
	}
	CDialogEx::OnOK();
}


void CCallinDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	//return;
                  	CDialogEx::OnCancel();
}


void CCallinDlg::OnStnClickedStaticAnswer()
{
	switch (m_call_state.call_state)
	{
	case CALL_IN:
		m_stc_answer.ShowWindow(SW_HIDE);
		m_stc_reject.ShowWindow(SW_HIDE);
		m_stc_close.ShowWindow(SW_SHOW);
		m_call_state.call_state = CALL_ONGOING;
		SetTimer(TIMER_CALL_DURATION_CNT, 1000,NULL);
		break;
	default:
		break;
	}

}


void CCallinDlg::OnStnClickedStaticReject()
{

	m_stc_answer.ShowWindow(SW_HIDE);
	m_stc_reject.ShowWindow(SW_HIDE);
//	m_stc_active.ShowWindow(SW_HIDE);
	m_stc_close.ShowWindow(SW_HIDE);
	m_call_state.call_state = CALL_CLOSE;

}



BOOL CCallinDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	USES_CONVERSION;
	CImage img1,img2,img3,img4;
	img1.Load(A2W(m_str_answer_pic.c_str()));
	HBITMAP hbmp = img1.Detach();
	m_stc_answer.SetBitmap(hbmp);
	
	img4.Load(A2W(m_str_close_pic.c_str()));
	HBITMAP hbmp4 = img4.Detach();
	m_stc_close.SetBitmap(hbmp4);
	m_stc_close.ShowWindow(SW_HIDE);

	img3.Load(A2W(m_str_hungup_pic.c_str()));
	HBITMAP hbmp3 = img3.Detach();
	m_stc_reject.SetBitmap(hbmp3);

	m_stcCallFrom.SetWindowText(A2W(m_ci.call_number_from.c_str()));

	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1);   //IDB_BITMAP1是图片资源ID  
	m_brush.Detach();
	m_brush.CreatePatternBrush(&bmp);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


HBRUSH CCallinDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	CString strClassName;
	GetClassName(pWnd->GetSafeHwnd(), strClassName.GetBuffer(256), 256);
	if (strClassName.Find(_T("Static")) >= 0)// || strClassName.Find(_T("Edit")) >= 0)
	{

		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255, 255, 255));
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	}
	else
	{
		return (HBRUSH)m_brush;
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}


void CCallinDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (TIMER_CALL_DURATION_CNT == nIDEvent)
	{
		m_ci.call_duration_seconds++;
		CString str;
		str.Format(_T("%02d:%02d:%02d"), m_ci.call_duration_seconds / 3600,
			(m_ci.call_duration_seconds % 3600) / 60, m_ci.call_duration_seconds % 60);
		m_stc_call_duration.SetWindowText(str.GetBuffer());
		CRect rc;
		m_stc_call_duration.GetWindowRect(&rc);
		m_stc_call_duration.GetParent()->ScreenToClient(&rc);
		m_stc_call_duration.GetParent()->InvalidateRect(&rc);
	}
	CDialogEx::OnTimer(nIDEvent);
}


afx_msg LRESULT CCallinDlg::OnRcvHungup(WPARAM wParam, LPARAM lParam)
{
	CSvrSocket* pservSock = (CSvrSocket*)wParam;
	int recvLen;
	char buf[BUF_SIZE];
	memset(buf, 0, BUF_SIZE);
	int strLen = pservSock->Receive(buf, BUF_SIZE, 0);
	t_call_protocol cp;
	if (rcvbuf_to_obj(buf, cp))
	{
		return -1;
	}
	if (CMD_CALL_HUNGUP == cp.cmd)
	{
		OnStnClickedStaticClose();
	}
	pservSock->Send(buf, strLen, 0);
	int dh_id = buf[0] - '0';
	return 0;
}


void CCallinDlg::OnStnClickedStaticClose()
{
	// TODO: 在此添加控件通知处理程序代码
	KillTimer(TIMER_CALL_DURATION_CNT);
	m_call_state.call_state = CALL_CLOSE;
	m_stc_close.ShowWindow(SW_HIDE);
}
