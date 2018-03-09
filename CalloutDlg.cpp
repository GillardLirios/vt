// CalloutDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "vt.h"
#include "CalloutDlg.h"
#include "afxdialogex.h"


// CCalloutDlg 对话框

IMPLEMENT_DYNAMIC(CCalloutDlg, CDialogEx)

CCalloutDlg::CCalloutDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CALL_OUT, pParent)
{

}

CCalloutDlg::~CCalloutDlg()
{
}

void CCalloutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCalloutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCalloutDlg 消息处理程序
