// CalloutDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "vt.h"
#include "CallHistoryDlg.h"
#include "afxdialogex.h"


// CCallHistoryDlg 对话框

IMPLEMENT_DYNAMIC(CCallHistoryDlg, CDialogEx)

CCallHistoryDlg::CCallHistoryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_HISTORY, pParent)
	, m_dateStart(COleDateTime::GetCurrentTime())
	, m_timeStart(COleDateTime::GetCurrentTime())
	, m_dateEnd(COleDateTime::GetCurrentTime())
	, m_timeEnd(COleDateTime::GetCurrentTime())
{

}

CCallHistoryDlg::~CCallHistoryDlg()
{
}

void CCallHistoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_START_DATE, m_dateStart);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_START_TIME, m_timeStart);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_END_DATE, m_dateEnd);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER_END_TIME, m_timeEnd);
	DDX_Control(pDX, IDC_LIST_HISTORY, m_listHistory);
}


BEGIN_MESSAGE_MAP(CCallHistoryDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SEARCH, &CCallHistoryDlg::OnBnClickedButtonSearch)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST_HISTORY, &CCallHistoryDlg::OnNMDblclkListHistory)
END_MESSAGE_MAP()


// CCallHistoryDlg 消息处理程序


BOOL CCallHistoryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//MessageBox(_T("~~~"));
	DWORD dwStyle = m_listHistory.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_listHistory.SetExtendedStyle(dwStyle);
	m_listHistory.InsertColumn(0, _T("序号"), LVCFMT_LEFT, 25);
	m_listHistory.InsertColumn(1, _T("主叫"), LVCFMT_LEFT, 60);
	m_listHistory.InsertColumn(2, _T("被叫"), LVCFMT_LEFT, 60);
	m_listHistory.InsertColumn(3, _T("时间"), LVCFMT_LEFT, 180);
	m_listHistory.InsertColumn(4, _T("时长"), LVCFMT_LEFT, 100);
	m_listHistory.InsertColumn(5, _T("类型"), LVCFMT_LEFT, 100);
	m_listHistory.InsertColumn(6, _T("信息"), LVCFMT_LEFT, 100);
	m_listHistory.InsertColumn(7, _T("号牌"), LVCFMT_LEFT, 100);
	m_listHistory.InsertColumn(8, _T("录音"), LVCFMT_LEFT, 100);

	m_Mytip.Create(this);
	m_Mytip.AddTool(GetDlgItem(IDC_LIST_HISTORY), _T("双击播放录音"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
 

void CCallHistoryDlg::OnBnClickedButtonSearch()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	COleDateTime start(m_dateStart.GetYear(), m_dateStart.GetMonth(), m_dateStart.GetDay(),
		m_timeStart.GetHour(), m_timeStart.GetMinute(), m_timeStart.GetSecond());
	m_timeStart = start;
	COleDateTime end(m_dateEnd.GetYear(), m_dateEnd.GetMonth(), m_dateEnd.GetDay(),
		m_timeEnd.GetHour(), m_timeEnd.GetMinute(), m_timeEnd.GetSecond());
	m_timeEnd = end;
	load_call_history();
}

int CCallHistoryDlg::load_call_history()
{
	m_cfg_call_history.load("./call_history.dat");
	m_call_history.call_count = m_cfg_call_history.get_value("HISTORY", "call_count", 0);
	char buf[1024];
	m_call_history.call_info.clear();
	vector<COleDateTime> time;
	map<COleDateTime, t_call_info> mapHistory;
	for (int i = 0; i < m_call_history.call_count; i++)
	{
		sprintf_s(buf, 1024, "CALL%d", i);
		t_call_info ci;
		ci.call_number_from = m_cfg_call_history.get_value(buf, "call_number_from", "null");
		ci.call_number_to = m_cfg_call_history.get_value(buf, "call_number_to", "null");
		ci.callin_time = m_cfg_call_history.get_value(buf, "callin_time", "null");
		ci.call_duration_seconds = m_cfg_call_history.get_value(buf, "call_duration_seconds", 0);
		ci.record_path = m_cfg_call_history.get_value(buf, "record_path", "null");
		ci.car_plate_number = m_cfg_call_history.get_value(buf, "car_plate_number", "null");
		ci.alarm_type = m_cfg_call_history.get_value(buf, "alarm_type", "null");
		ci.alarm_info = m_cfg_call_history.get_value(buf, "alarm_info", "null");
		int nYear, nMonth, nDate, nHour, nMin, nSec;
		sscanf_s(ci.callin_time.c_str(), "%d-%d-%d %d:%d:%d", &nYear, &nMonth, &nDate, &nHour, &nMin, &nSec);
		COleDateTime callTime(nYear, nMonth, nDate, nHour, nMin, nSec);
		if (callTime >= m_timeStart && callTime <= m_timeEnd)
		{
			m_call_history.call_info.push_back(ci);
			time.push_back(callTime);
			mapHistory[callTime] = ci;
		}
	}
	sort(time.begin(), time.end());
	m_cis.clear();
	USES_CONVERSION;
	for (int i = 0; i < time.size(); i++)
	{
		CString str;
		m_cis.push_back(mapHistory[time[i]]);
		str.Format(_T("%d"), i);
		m_listHistory.InsertItem(i, str);
		//m_listHistory.SetItemText(i, 0, CString(_T("%d"),i));
		m_listHistory.SetItemText(i, 1, A2W(m_cis[i].call_number_from.c_str()));
		m_listHistory.SetItemText(i, 2, A2W(m_cis[i].call_number_to.c_str()));
		m_listHistory.SetItemText(i, 3, A2W(m_cis[i].callin_time.c_str()));
		
		str.Format(_T("%02d:%02d:%02d"), m_cis[i].call_duration_seconds / 3600, 
			(m_cis[i].call_duration_seconds % 3600) / 60,	m_cis[i].call_duration_seconds % 60);
		m_listHistory.SetItemText(i, 4, str);
		m_listHistory.SetItemText(i, 5, A2W(m_cis[i].record_path.c_str()));
		m_listHistory.SetItemText(i, 6, A2W(m_cis[i].alarm_type.c_str()));
	}

	return 0;
}


void CCallHistoryDlg::OnNMDblclkListHistory(NMHDR *pNMHDR, LRESULT *pResult)
{
	USES_CONVERSION;
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	UpdateData(TRUE);
	POSITION pos = m_listHistory.GetFirstSelectedItemPosition();
	int index = m_listHistory.GetNextSelectedItem(pos);
	MessageBox(A2W(m_cis[index].record_path.c_str()));
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


BOOL CCallHistoryDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_MOUSEMOVE)
		m_Mytip.RelayEvent(pMsg);
	return CDialogEx::PreTranslateMessage(pMsg);
}
