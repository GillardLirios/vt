#pragma once
#include <string>
#include "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\atlmfc\include\afxwin.h"
using namespace std;
class t_call_info
{
public:
	string call_number_from;
	string call_number_to;
	string callin_time;
	int call_duration_seconds;
	string record_path;
	string alarm_info;
	string alarm_type;
	string car_plate_number;
};
// CCallinDlg 对话框

class CCallinDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCallinDlg)

public:
	CCallinDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCallinDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CALL_IN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnStnClickedStaticAnswer();
	afx_msg void OnStnClickedStaticReject();
	CString m_strCarPlateNum;
	CString m_strAlarmType;
	CString m_strAlarmInfo;
	t_call_info m_ci;
	virtual BOOL OnInitDialog();
	string m_str_bk_pic;
	string m_str_answer_pic;
	string m_str_hungup_pic;
	string m_str_active_pic;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CBrush m_brush;
	CStatic m_stc_answer;
	CStatic m_stc_active;
	CStatic m_stc_reject;
};
