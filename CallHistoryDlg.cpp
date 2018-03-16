// CalloutDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "vt.h"
#include "CallHistoryDlg.h"
#include "afxdialogex.h"


// CCallHistoryDlg 对话框

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


// CCallHistoryDlg 消息处理程序


BOOL CCallHistoryDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//MessageBox(_T("~~~"));
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
