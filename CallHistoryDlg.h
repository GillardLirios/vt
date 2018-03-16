#pragma once


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
};
