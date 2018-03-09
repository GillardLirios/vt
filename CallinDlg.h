#pragma once


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
};
