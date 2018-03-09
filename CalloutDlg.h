#pragma once


// CCalloutDlg 对话框

class CCalloutDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCalloutDlg)

public:
	CCalloutDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCalloutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CALL_OUT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
