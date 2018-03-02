
// vtDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "vt.h"
#include "vtDlg.h"
#include "afxdialogex.h"
#include <fstream>
#include <string>
#include "../log4z/log4z.h" 
#include "../json11/json11.hpp"
using namespace json11;
using std::string;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
  
using namespace zsummer::log4z;
using namespace json11;
using std::string;
using namespace std;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
//7777
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CvtDlg 对话框



CvtDlg::CvtDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_VT_DIALOG, pParent)
{
	

	m_cfg.load("./user.cfg");
	
	ILog4zManager::getRef().setLoggerPath(LOG4Z_MAIN_LOGGER_ID, "./log");
	ILog4zManager::getRef().start();
	ILog4zManager::getRef().setLoggerLevel(LOG4Z_MAIN_LOGGER_ID, LOG_LEVEL_TRACE);
	LOGT("stream input *** " << "LOGT LOGT LOGT LOGT" << " *** ");
	LOGD("stream input *** " << "LOGD LOGD LOGD LOGD" << " *** ");
	LOGI("stream input *** " << "LOGI LOGI LOGI LOGI" << " *** ");
	LOGW("stream input *** " << "LOGW LOGW LOGW LOGW" << " *** ");
	LOGE("stream input *** " << "LOGE LOGE LOGE LOGE" << " *** ");
	LOGA("stream input *** " << "LOGA LOGA LOGA LOGA" << " *** ");
	LOGF("stream input *** " << "LOGF LOGF LOGF LOGF" << " *** ");
	LOGFMTT("format input *** %s *** %d ***", "LOGFMTT", 123456);
	LOGFMTD("format input *** %s *** %d ***", "LOGFMTD", 123456);
	LOGFMTI("format input *** %s *** %d ***", "LOGFMTI", 123456);
	LOGFMTW("format input *** %s *** %d ***", "LOGFMTW", 123456);
	LOGFMTE("format input *** %s *** %d ***", "LOGFMTE", 123456);
	LOGFMTA("format input *** %s *** %d ***", "LOGFMTA", 123456);
	LOGFMTF("format input *** %s *** %d ***", "LOGFMTF", 123456);
	//wchar_t buf[1024];
	//GetCurrentDirectory(1024, buf);
	//CString strpath = buf;
	//USES_CONVERSION;
	//LOGFMTI("current path:%s", W2A(buf));
	//if (m_imgBK.Load(_T("./image/background/img105.jpg")) == S_OK)
	//{
	//	LOGFMTI("load background image:%s ok","./image/background/img105.jpg");
	//}
	//else
	//{
	//	LOGFMTI("load background image:%s err, %d", "./image/background/img105.jpg", GetLastError());
	//}
	std::ifstream ifcfg("cfg.json");
	string err;
	//ifcfg >> strcfg;
	std::istreambuf_iterator<char> eos;
	std::string strcfg(std::istreambuf_iterator<char>(ifcfg), eos);

	auto jcfg = Json::parse(strcfg, err);
	if (!err.empty())
	{
		LOGFMTT(err.c_str());
	}
	
	std::string json_str = jcfg.dump();
	LOGFMTT(json_str.c_str());
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CvtDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CvtDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CvtDlg 消息处理程序

BOOL CvtDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MAXIMIZE);

	// TODO: 在此添加额外的初始化代码
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP1);   //IDB_BITMAP1是图片资源ID  
	m_brush.CreatePatternBrush(&bmp);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CvtDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CvtDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
	
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CvtDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



HBRUSH CvtDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	//HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	return (HBRUSH)m_brush;
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	//return hbr;
}
