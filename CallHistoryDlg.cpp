// CalloutDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "vt.h"
#include "CallHistoryDlg.h"
#include "afxdialogex.h"


// CCallHistoryDlg �Ի���

IMPLEMENT_DYNAMIC(CCallHistoryDlg, CDialogEx)

CCallHistoryDlg::CCallHistoryDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_HISTORY, pParent)
{

}

CCallHistoryDlg::~CCallHistoryDlg()
{
}

void CCallHistoryDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCallHistoryDlg, CDialogEx)
END_MESSAGE_MAP()


// CCallHistoryDlg ��Ϣ�������


BOOL CCallHistoryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//MessageBox(_T("~~~"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}
