#pragma once


// CCalloutDlg �Ի���

class CCallHistoryDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCallHistoryDlg)

public:
	CCallHistoryDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCallHistoryDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_HISTORY};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
