#pragma once


// CCallinDlg �Ի���

class CCallinDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCallinDlg)

public:
	CCallinDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCallinDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CALL_IN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
