#pragma once
#include "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\atlmfc\include\atltime.h"
#include "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\atlmfc\include\ATLComTime.h"
#include "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\atlmfc\include\afxdtctl.h"
#include "DataEntities.h"
#include "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\atlmfc\include\afxcmn.h"

// CCalloutDlg 对话框

class CCallHistoryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCallHistoryDlg)

public:
	CCallHistoryDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCallHistoryDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_HISTORY};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	COleDateTime m_dateStart;
	COleDateTime m_timeStart;
	COleDateTime m_dateEnd;
	COleDateTime m_timeEnd;
	afx_msg void OnBnClickedButtonSearch();
	Config m_cfg_call_history;
	t_call_history m_call_history;
	int load_call_history();
	vector<t_call_info> m_cis;
	CListCtrl m_listHistory;
	afx_msg void OnNMDblclkListHistory(NMHDR *pNMHDR, LRESULT *pResult);
	CToolTipCtrl m_Mytip;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
