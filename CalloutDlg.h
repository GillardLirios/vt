#pragma once


// CCalloutDlg �Ի���

class CCalloutDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCalloutDlg)

public:
	CCalloutDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCalloutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_CALL_OUT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
