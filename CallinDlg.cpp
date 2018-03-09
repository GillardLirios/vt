// CallinDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "vt.h"
#include "CallinDlg.h"
#include "afxdialogex.h"


// CCallinDlg 对话框

IMPLEMENT_DYNAMIC(CCallinDlg, CDialogEx)

CCallinDlg::CCallinDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_CALL_IN, pParent)
{

}

CCallinDlg::~CCallinDlg()
{
}

void CCallinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCallinDlg, CDialogEx)
END_MESSAGE_MAP()


// CCallinDlg 消息处理程序
