#pragma once

#include "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\atlmfc\include\afxwin.h"
#include "DataEntities.h"

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
	string m_str_close_pic;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CBrush m_brush;
	CStatic m_stc_answer;
	CStatic m_stc_active;
	CStatic m_stc_reject;
	t_dh_state m_call_state;
	
	CStatic m_stc_close;
	CStatic m_stc_call_duration;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
protected:
	afx_msg LRESULT OnRcvHungup(WPARAM wParam, LPARAM lParam);
};

