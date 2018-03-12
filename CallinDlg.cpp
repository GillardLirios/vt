// CallinDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "vt.h"
#include "CallinDlg.h"
#include "afxdialogex.h"


// CCallinDlg �Ի���

IMPLEMENT_DYNAMIC(CCallinDlg, CDialogEx)

CCallinDlg::CCallinDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CALL_IN, pParent)
	, m_strCarPlateNum(_T(""))
	, m_strAlarmType(_T(""))
	, m_strAlarmInfo(_T(""))
{
	m_call_state = DH_CALL_IN;
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
	DDX_Control(pDX, IDC_STATIC_ACTIVE, m_stc_active);
	DDX_Control(pDX, IDC_STATIC_REJECT, m_stc_reject);
	DDX_Control(pDX, IDC_STATIC_CLOSE, m_stc_close);
	DDX_Control(pDX, IDC_STATIC_CALL_DURATION, m_stc_call_duration);
}


BEGIN_MESSAGE_MAP(CCallinDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCallinDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CCallinDlg::OnBnClickedCancel)
	ON_STN_CLICKED(IDC_STATIC_ANSWER, &CCallinDlg::OnStnClickedStaticAnswer)
	ON_STN_CLICKED(IDC_STATIC_REJECT, &CCallinDlg::OnStnClickedStaticReject)
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CCallinDlg ��Ϣ�������


void CCallinDlg::OnBnClickedOk()
{
	UpdateData();
	USES_CONVERSION;
	m_ci.alarm_info = W2A(m_strAlarmInfo.GetBuffer());
	m_ci.alarm_type = W2A(m_strAlarmType.GetBuffer());
	m_ci.car_plate_number = W2A(m_strCarPlateNum.GetBuffer());
	if (m_ci.alarm_info.length() < 16)
	{
		MessageBox(_T("������Ϣ����̫��"));
		return;
	}
	if (m_ci.alarm_type.length() < 2)
	{
		MessageBox(_T("����д��������"));
		return;
	}
	if (m_ci.car_plate_number.length() < 8)
	{
		MessageBox(_T("����д���ƺ���"));
		return;
	}
	CDialogEx::OnOK();
}


void CCallinDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	return;
	CDialogEx::OnCancel();
}


void CCallinDlg::OnStnClickedStaticAnswer()
{
	switch (m_call_state)
	{
	case DH_CALL_IN:
		m_stc_answer.ShowWindow(SW_HIDE);
	//	m_stc_reject.ShowWindow(SW_HIDE);
		m_stc_active.ShowWindow(SW_SHOW);
		m_call_state = DH_ACTIVE;
		SetTimer(1, 1000,NULL);
		break;
	default:
		break;
	}

}


void CCallinDlg::OnStnClickedStaticReject()
{

	m_stc_answer.ShowWindow(SW_HIDE);
	m_stc_reject.ShowWindow(SW_HIDE);
	m_stc_active.ShowWindow(SW_HIDE);
	m_stc_close.ShowWindow(SW_SHOW);
	m_call_state = DH_ACTIVE;

}



BOOL CCallinDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	USES_CONVERSION;
	CImage img1,img2,img3,img4;
	img1.Load(A2W(m_str_answer_pic.c_str()));
	HBITMAP hbmp = img1.Detach();
	m_stc_answer.SetBitmap(hbmp);

	img2.Load(A2W(m_str_active_pic.c_str()));
	HBITMAP hbmp2 = img2.Detach();
	m_stc_active.SetBitmap(hbmp2);
	m_stc_active.ShowWindow(SW_HIDE);

	img4.Load(A2W(m_str_close_pic.c_str()));
	HBITMAP hbmp4 = img4.Detach();
	m_stc_close.SetBitmap(hbmp4);
	m_stc_close.ShowWindow(SW_HIDE);

	img3.Load(A2W(m_str_hungup_pic.c_str()));
	HBITMAP hbmp3 = img3.Detach();
	m_stc_reject.SetBitmap(hbmp3);

	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1);   //IDB_BITMAP1��ͼƬ��ԴID  
	m_brush.Detach();
	m_brush.CreatePatternBrush(&bmp);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


HBRUSH CCallinDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����
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
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}


void CCallinDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if (1 == nIDEvent)
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
