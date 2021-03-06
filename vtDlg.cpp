
// vtDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "vt.h"
#include "vtDlg.h"
#include "afxdialogex.h"
#include <fstream>
#include <string>

#include "CalloutDlg.h"
#include "CallinDlg.h"
#include "CallHistoryDlg.h"
using namespace json11;
using std::string;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
  

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
	: CDialogEx(IDD_VT_DIALOG, pParent)
	, m_pt_lb_down(-1,0)
	, m_pt_rb_down(-1, 0)
	, m_b_boardcast_sw(false)
{
	

	load_cfg();
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
#if 0
	for (int i = 0; i < 30; i++)
	{
		m_gb_state[i].comm_state = OFFLINE;
		m_gb_state[i].pa_state = PA_OFF;
		m_dh_state[i].comm_state = ONLINE;
		m_dh_state[i].call_state = CALL_CLOSE;
	}
#else
	for (int i = 0; i < 30; i++)
	{
		m_gb_state[i].comm_state = ONLINE;
		m_gb_state[i].pa_state = PA_OFF;
		m_dh_state[i].comm_state = ONLINE;
		m_dh_state[i].call_state = CALL_CLOSE;
	}
#endif
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
	DDX_Control(pDX, IDC_STATIC_DH1, m_stc_dh[0]);
	DDX_Control(pDX, IDC_STATIC_DH2, m_stc_dh[1]);
	DDX_Control(pDX, IDC_STATIC_DH3, m_stc_dh[2]);
	DDX_Control(pDX, IDC_STATIC_DH4, m_stc_dh[3]);
	DDX_Control(pDX, IDC_STATIC_DH5, m_stc_dh[4]);
	DDX_Control(pDX, IDC_STATIC_DH6, m_stc_dh[5]);
	DDX_Control(pDX, IDC_STATIC_DH7, m_stc_dh[6]);
	DDX_Control(pDX, IDC_STATIC_DH8, m_stc_dh[7]);
	DDX_Control(pDX, IDC_STATIC_DH9, m_stc_dh[8]);
	DDX_Control(pDX, IDC_STATIC_DH10, m_stc_dh[9]);
	DDX_Control(pDX, IDC_STATIC_DH11, m_stc_dh[10]);
	DDX_Control(pDX, IDC_STATIC_DH12, m_stc_dh[11]);
	DDX_Control(pDX, IDC_STATIC_DH13, m_stc_dh[12]);
	DDX_Control(pDX, IDC_STATIC_DH14, m_stc_dh[13]);
	DDX_Control(pDX, IDC_STATIC_DH15, m_stc_dh[14]);
	DDX_Control(pDX, IDC_STATIC_DH16, m_stc_dh[15]);
	DDX_Control(pDX, IDC_STATIC_DH17, m_stc_dh[16]);
	DDX_Control(pDX, IDC_STATIC_DH18, m_stc_dh[17]);
	DDX_Control(pDX, IDC_STATIC_DH19, m_stc_dh[18]);
	DDX_Control(pDX, IDC_STATIC_DH20, m_stc_dh[19]);
	DDX_Control(pDX, IDC_STATIC_DH21, m_stc_dh[20]);
	DDX_Control(pDX, IDC_STATIC_DH22, m_stc_dh[21]);
	DDX_Control(pDX, IDC_STATIC_DH23, m_stc_dh[22]);
	DDX_Control(pDX, IDC_STATIC_DH24, m_stc_dh[23]);
	DDX_Control(pDX, IDC_STATIC_DH25, m_stc_dh[24]);
	DDX_Control(pDX, IDC_STATIC_DH26, m_stc_dh[25]);
	DDX_Control(pDX, IDC_STATIC_DH27, m_stc_dh[26]);
	DDX_Control(pDX, IDC_STATIC_DH28, m_stc_dh[27]);
	DDX_Control(pDX, IDC_STATIC_DH29, m_stc_dh[28]);
	DDX_Control(pDX, IDC_STATIC_DH30, m_stc_dh[29]);

	DDX_Control(pDX, IDC_STATIC_DH_NAME1, m_stc_dh_name[0]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME2, m_stc_dh_name[1]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME3, m_stc_dh_name[2]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME4, m_stc_dh_name[3]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME5, m_stc_dh_name[4]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME6, m_stc_dh_name[5]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME7, m_stc_dh_name[6]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME8, m_stc_dh_name[7]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME9, m_stc_dh_name[8]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME10, m_stc_dh_name[9]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME11, m_stc_dh_name[10]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME12, m_stc_dh_name[11]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME13, m_stc_dh_name[12]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME14, m_stc_dh_name[13]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME15, m_stc_dh_name[14]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME16, m_stc_dh_name[15]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME17, m_stc_dh_name[16]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME18, m_stc_dh_name[17]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME19, m_stc_dh_name[18]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME20, m_stc_dh_name[19]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME21, m_stc_dh_name[20]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME22, m_stc_dh_name[21]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME23, m_stc_dh_name[22]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME24, m_stc_dh_name[23]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME25, m_stc_dh_name[24]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME26, m_stc_dh_name[25]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME27, m_stc_dh_name[26]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME28, m_stc_dh_name[27]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME29, m_stc_dh_name[28]);
	DDX_Control(pDX, IDC_STATIC_DH_NAME30, m_stc_dh_name[29]);

	DDX_Control(pDX, IDC_STATIC_DH_STAKE1, m_stc_dh_stake[0]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE2, m_stc_dh_stake[1]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE3, m_stc_dh_stake[2]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE4, m_stc_dh_stake[3]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE5, m_stc_dh_stake[4]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE6, m_stc_dh_stake[5]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE7, m_stc_dh_stake[6]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE8, m_stc_dh_stake[7]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE9, m_stc_dh_stake[8]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE10, m_stc_dh_stake[9]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE11, m_stc_dh_stake[10]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE12, m_stc_dh_stake[11]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE13, m_stc_dh_stake[12]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE14, m_stc_dh_stake[13]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE15, m_stc_dh_stake[14]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE16, m_stc_dh_stake[15]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE17, m_stc_dh_stake[16]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE18, m_stc_dh_stake[17]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE19, m_stc_dh_stake[18]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE20, m_stc_dh_stake[19]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE21, m_stc_dh_stake[20]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE22, m_stc_dh_stake[21]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE23, m_stc_dh_stake[22]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE24, m_stc_dh_stake[23]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE25, m_stc_dh_stake[24]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE26, m_stc_dh_stake[25]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE27, m_stc_dh_stake[26]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE28, m_stc_dh_stake[27]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE29, m_stc_dh_stake[28]);
	DDX_Control(pDX, IDC_STATIC_DH_STAKE30, m_stc_dh_stake[29]);

	DDX_Control(pDX, IDC_STATIC_GB1, m_stc_gb[0]);
	DDX_Control(pDX, IDC_STATIC_GB2, m_stc_gb[1]);
	DDX_Control(pDX, IDC_STATIC_GB3, m_stc_gb[2]);
	DDX_Control(pDX, IDC_STATIC_GB4, m_stc_gb[3]);
	DDX_Control(pDX, IDC_STATIC_GB5, m_stc_gb[4]);
	DDX_Control(pDX, IDC_STATIC_GB6, m_stc_gb[5]);
	DDX_Control(pDX, IDC_STATIC_GB7, m_stc_gb[6]);
	DDX_Control(pDX, IDC_STATIC_GB8, m_stc_gb[7]);
	DDX_Control(pDX, IDC_STATIC_GB9, m_stc_gb[8]);
	DDX_Control(pDX, IDC_STATIC_GB10, m_stc_gb[9]);
	DDX_Control(pDX, IDC_STATIC_GB11, m_stc_gb[10]);
	DDX_Control(pDX, IDC_STATIC_GB12, m_stc_gb[11]);
	DDX_Control(pDX, IDC_STATIC_GB13, m_stc_gb[12]);
	DDX_Control(pDX, IDC_STATIC_GB14, m_stc_gb[13]);
	DDX_Control(pDX, IDC_STATIC_GB15, m_stc_gb[14]);
	DDX_Control(pDX, IDC_STATIC_GB16, m_stc_gb[15]);
	DDX_Control(pDX, IDC_STATIC_GB17, m_stc_gb[16]);
	DDX_Control(pDX, IDC_STATIC_GB18, m_stc_gb[17]);
	DDX_Control(pDX, IDC_STATIC_GB19, m_stc_gb[18]);
	DDX_Control(pDX, IDC_STATIC_GB20, m_stc_gb[19]);
	DDX_Control(pDX, IDC_STATIC_GB21, m_stc_gb[20]);
	DDX_Control(pDX, IDC_STATIC_GB22, m_stc_gb[21]);
	DDX_Control(pDX, IDC_STATIC_GB23, m_stc_gb[22]);
	DDX_Control(pDX, IDC_STATIC_GB24, m_stc_gb[23]);
	DDX_Control(pDX, IDC_STATIC_GB25, m_stc_gb[24]);
	DDX_Control(pDX, IDC_STATIC_GB26, m_stc_gb[25]);
	DDX_Control(pDX, IDC_STATIC_GB27, m_stc_gb[26]);
	DDX_Control(pDX, IDC_STATIC_GB28, m_stc_gb[27]);
	DDX_Control(pDX, IDC_STATIC_GB29, m_stc_gb[28]);
	DDX_Control(pDX, IDC_STATIC_GB30, m_stc_gb[29]);


	DDX_Control(pDX, IDC_STATIC_GB_NAME1, m_stc_gb_name[0]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME2, m_stc_gb_name[1]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME3, m_stc_gb_name[2]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME4, m_stc_gb_name[3]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME5, m_stc_gb_name[4]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME6, m_stc_gb_name[5]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME7, m_stc_gb_name[6]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME8, m_stc_gb_name[7]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME9, m_stc_gb_name[8]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME10, m_stc_gb_name[9]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME11, m_stc_gb_name[10]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME12, m_stc_gb_name[11]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME13, m_stc_gb_name[12]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME14, m_stc_gb_name[13]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME15, m_stc_gb_name[14]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME16, m_stc_gb_name[15]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME17, m_stc_gb_name[16]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME18, m_stc_gb_name[17]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME19, m_stc_gb_name[18]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME20, m_stc_gb_name[19]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME21, m_stc_gb_name[20]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME22, m_stc_gb_name[21]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME23, m_stc_gb_name[22]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME24, m_stc_gb_name[23]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME25, m_stc_gb_name[24]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME26, m_stc_gb_name[25]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME27, m_stc_gb_name[26]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME28, m_stc_gb_name[27]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME29, m_stc_gb_name[28]);
	DDX_Control(pDX, IDC_STATIC_GB_NAME30, m_stc_gb_name[29]);

	DDX_Control(pDX, IDC_STATIC_GB_STAKE1, m_stc_gb_stake[0]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE2, m_stc_gb_stake[1]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE3, m_stc_gb_stake[2]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE4, m_stc_gb_stake[3]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE5, m_stc_gb_stake[4]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE6, m_stc_gb_stake[5]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE7, m_stc_gb_stake[6]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE8, m_stc_gb_stake[7]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE9, m_stc_gb_stake[8]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE10, m_stc_gb_stake[9]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE11, m_stc_gb_stake[10]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE12, m_stc_gb_stake[11]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE13, m_stc_gb_stake[12]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE14, m_stc_gb_stake[13]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE15, m_stc_gb_stake[14]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE16, m_stc_gb_stake[15]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE17, m_stc_gb_stake[16]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE18, m_stc_gb_stake[17]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE19, m_stc_gb_stake[18]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE20, m_stc_gb_stake[19]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE21, m_stc_gb_stake[20]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE22, m_stc_gb_stake[21]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE23, m_stc_gb_stake[22]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE24, m_stc_gb_stake[23]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE25, m_stc_gb_stake[24]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE26, m_stc_gb_stake[25]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE27, m_stc_gb_stake[26]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE28, m_stc_gb_stake[27]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE29, m_stc_gb_stake[28]);
	DDX_Control(pDX, IDC_STATIC_GB_STAKE30, m_stc_gb_stake[29]);

	DDX_Control(pDX, IDC_BUTTON_OPTION, m_btnOption);
	DDX_Control(pDX, IDC_STATIC_TITLE, m_stcTitle);
}

BEGIN_MESSAGE_MAP(CvtDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_STN_CLICKED(IDC_STATIC_GB1, &CvtDlg::OnStnClickedStaticGb1)
	ON_STN_CLICKED(IDC_STATIC_GB2, &CvtDlg::OnStnClickedStaticGb2)
	ON_STN_CLICKED(IDC_STATIC_GB3, &CvtDlg::OnStnClickedStaticGb3)
	ON_STN_CLICKED(IDC_STATIC_GB4, &CvtDlg::OnStnClickedStaticGb4)
	ON_STN_CLICKED(IDC_STATIC_GB5, &CvtDlg::OnStnClickedStaticGb5)
	ON_STN_CLICKED(IDC_STATIC_GB6, &CvtDlg::OnStnClickedStaticGb6)
	ON_STN_CLICKED(IDC_STATIC_GB7, &CvtDlg::OnStnClickedStaticGb7)
	ON_STN_CLICKED(IDC_STATIC_GB8, &CvtDlg::OnStnClickedStaticGb8)
	ON_STN_CLICKED(IDC_STATIC_GB9, &CvtDlg::OnStnClickedStaticGb9)
	ON_STN_CLICKED(IDC_STATIC_GB10, &CvtDlg::OnStnClickedStaticGb10)
	ON_STN_CLICKED(IDC_STATIC_GB11, &CvtDlg::OnStnClickedStaticGb11)
	ON_STN_CLICKED(IDC_STATIC_GB12, &CvtDlg::OnStnClickedStaticGb12)
	ON_STN_CLICKED(IDC_STATIC_GB13, &CvtDlg::OnStnClickedStaticGb13)
	ON_STN_CLICKED(IDC_STATIC_GB14, &CvtDlg::OnStnClickedStaticGb14)
	ON_STN_CLICKED(IDC_STATIC_GB15, &CvtDlg::OnStnClickedStaticGb15)
	ON_STN_CLICKED(IDC_STATIC_GB16, &CvtDlg::OnStnClickedStaticGb16)
	ON_STN_CLICKED(IDC_STATIC_GB17, &CvtDlg::OnStnClickedStaticGb17)
	ON_STN_CLICKED(IDC_STATIC_GB18, &CvtDlg::OnStnClickedStaticGb18)
	ON_STN_CLICKED(IDC_STATIC_GB19, &CvtDlg::OnStnClickedStaticGb19)
	ON_STN_CLICKED(IDC_STATIC_GB20, &CvtDlg::OnStnClickedStaticGb20)	
	ON_STN_CLICKED(IDC_STATIC_GB21, &CvtDlg::OnStnClickedStaticGb21)
	ON_STN_CLICKED(IDC_STATIC_GB22, &CvtDlg::OnStnClickedStaticGb22)
	ON_STN_CLICKED(IDC_STATIC_GB23, &CvtDlg::OnStnClickedStaticGb23)
	ON_STN_CLICKED(IDC_STATIC_GB24, &CvtDlg::OnStnClickedStaticGb24)
	ON_STN_CLICKED(IDC_STATIC_GB25, &CvtDlg::OnStnClickedStaticGb25)
	ON_STN_CLICKED(IDC_STATIC_GB26, &CvtDlg::OnStnClickedStaticGb26)
	ON_STN_CLICKED(IDC_STATIC_GB27, &CvtDlg::OnStnClickedStaticGb27)
	ON_STN_CLICKED(IDC_STATIC_GB28, &CvtDlg::OnStnClickedStaticGb28)
	ON_STN_CLICKED(IDC_STATIC_GB29, &CvtDlg::OnStnClickedStaticGb29)
	ON_STN_CLICKED(IDC_STATIC_GB30, &CvtDlg::OnStnClickedStaticGb30)
	ON_MESSAGE(WM_SVR_SOCKET, &CvtDlg::OnSvrSocket)
//	ON_MESSAGE(WM_CALLIN_HUNGUP, &CvtDlg::OnCallinHungup)
	ON_BN_CLICKED(IDC_BUTTON_REFESH, &CvtDlg::OnBnClickedButtonRefesh)
	ON_STN_CLICKED(IDC_STATIC_DH1, &CvtDlg::OnStnClickedStaticDh1)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_CALL_HISTORY, &CvtDlg::OnCallHistory)

	ON_MESSAGE(WM_SVR_SOCKET, &CvtDlg::OnGbStateChange)
	
	ON_COMMAND(ID_BORADCAST_SW, &CvtDlg::OnBoradcastSw)
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

	/*m_menu.LoadMenu(IDR_MENU1);
	SetMenu(&m_menu);*/
	//ShowWindow(SW_HIDE);
	OnBnClickedButtonRefesh();
	ShowWindow(SW_MAXIMIZE);

	// TODO: 在此添加额外的初始化代码

	WSAData wsaData;
	AfxSocketInit(&wsaData);
	m_SvrSock.Create(m_cfg_data.dh_local_svr_port, SOCK_STREAM);
	m_SvrSock.m_pWnd = this;
	m_SvrSock.Listen();
	
	
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
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	CString strClassName;
	GetClassName(pWnd->GetSafeHwnd(), strClassName.GetBuffer(256), 256);
	if(strClassName.Find(_T("Static"))>=0)
	{
	
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(255, 255, 255));
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);	
	}
	else 
	{
		return (HBRUSH)m_brush;
	}
	
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	//return hbr;
}


int CvtDlg::load_cfg()
{
	m_cfg_file.load("./user.cfg");
	m_cfg_data.str_title_img_path = m_cfg_file.get_value("UI", "title_img", "./image/title.png");
	m_cfg_data.str_dh_online_img_path		= m_cfg_file.get_value("UI",   "dh_online_img", "./image/dh_online.png");
	m_cfg_data.str_dh_offline_img_path		= m_cfg_file.get_value("UI", "dh_offline_img", "./image/dh_offline.png");
	m_cfg_data.str_dh_callin_img_path		= m_cfg_file.get_value("UI", "dh_in_img", "./image/callin.png");
	m_cfg_data.str_dh_answer_img_path		= m_cfg_file.get_value("UI", "dh_answer_img", "./image/ic_incall_answer.png");
	m_cfg_data.str_dh_active_img_path		= m_cfg_file.get_value("UI", "dh_active_img", "./image/ic_incall_ongoing.png");
	m_cfg_data.str_dh_callmiss_img_path		= m_cfg_file.get_value("UI", "dh_miss_img", "./image/callmiss.png");
	m_cfg_data.str_dh_callout_img_path		= m_cfg_file.get_value("UI", "dh_out_img", "./image/callout.png");
	m_cfg_data.str_dh_hungup_img_path		= m_cfg_file.get_value("UI", "dh_hungup_img", "./image/ic_incall_hangup.png");
	m_cfg_data.str_dh_close_img_path		= m_cfg_file.get_value("UI", "dh_close_img", "./image/ic_incall_hangup.png");
	m_cfg_data.str_dh_busy_img_path			= m_cfg_file.get_value("UI", "dh_busy_img", "./image/busy.png");
	
	m_cfg_data.str_gb_online_pa_on_img_path = m_cfg_file.get_value("UI", "gb_online_pa_on_img", "./image/gb_online_pa_on.png");
	m_cfg_data.str_gb_offline_pa_on_img_path = m_cfg_file.get_value("UI", "gb_offline_pa_on_img", "./image/gb_offline_pa_on.png");
	m_cfg_data.str_gb_online_pa_off_img_path = m_cfg_file.get_value("UI", "gb_online_pa_off_img", "./image/gb_online_pa_off.png");
	m_cfg_data.str_gb_offline_pa_off_img_path = m_cfg_file.get_value("UI", "gb_offline_pa_off_img", "./image/gb_offline_pa_off.png");

	m_cfg_data.str_option_img_path = m_cfg_file.get_value("UI", "option_img", "./image/options_48.png");

	m_cfg_data.dh_count					= m_cfg_file.get_value("UI", "dh_count", 30);
	m_cfg_data.gb_count					= m_cfg_file.get_value("UI", "gb_count", 30);
	m_cfg_data.rcOptionButton.left = m_cfg_file.get_value("UI", "option_button_x", 1880);
	m_cfg_data.rcOptionButton.top = m_cfg_file.get_value("UI", "option_button_y", 50);
	m_cfg_data.rcOptionButton.right = m_cfg_data.rcOptionButton.left + m_cfg_file.get_value("UI", "option_button_w", 48);
	m_cfg_data.rcOptionButton.bottom = m_cfg_data.rcOptionButton.top + m_cfg_file.get_value("UI", "option_button_h", 48);

	m_cfg_data.rc_title.left = m_cfg_file.get_value("UI", "title_x", 1880);
	m_cfg_data.rc_title.top = m_cfg_file.get_value("UI", "title_y", 50);
	m_cfg_data.rc_title.right = m_cfg_data.rc_title.left + m_cfg_file.get_value("UI", "title_w", 48);
	m_cfg_data.rc_title.bottom = m_cfg_data.rc_title.top + m_cfg_file.get_value("UI", "title_h", 48);

	char buf[4096];

	for (int i = 0; i < m_cfg_data.dh_count; i++)
	{
		sprintf_s( buf, 4096, "dh%d_x", i+1);
		m_cfg_data.DH[i].left = m_cfg_file.get_value("UI", buf,200);
		//m_cfg_data.DH[i].left	= m_cfg_file.get_value("UI", buf, 200*i+200);
		sprintf_s(buf, 4096, "dh%d_y", i+1);
		m_cfg_data.DH[i].top	= m_cfg_file.get_value("UI", buf, 200);
		m_cfg_data.DH[i].right	= m_cfg_data.DH[i].left + m_cfg_file.get_value("UI", "dh_w", 40);
		m_cfg_data.DH[i].bottom = m_cfg_data.DH[i].top + m_cfg_file.get_value("UI", "dh_h", 40);
		sprintf_s(buf, 4096, "dh%d_name", i + 1);
		m_cfg_data.str_dh_name[i] = m_cfg_file.get_value("UI", buf, "DHn");
		sprintf_s(buf, 4096, "dh%d_stake", i + 1);
		m_cfg_data.str_dh_stake[i] = m_cfg_file.get_value("UI", buf, "DH_STAKEn");

	}
	for (int i = 0; i < m_cfg_data.gb_count; i++)
	{
		sprintf_s(buf, 4096, "gb%d_x", i + 1);
		m_cfg_data.GB[i].left = m_cfg_file.get_value("UI", buf, 200);
		//m_cfg_data.DH[i].left	= m_cfg_file.get_value("UI", buf, 200*i+200);
		sprintf_s(buf, 4096, "gb%d_y", i + 1);
		m_cfg_data.GB[i].top = m_cfg_file.get_value("UI", buf, 200);
		m_cfg_data.GB[i].right = m_cfg_data.GB[i].left + m_cfg_file.get_value("UI", "gb_w", 40);
		m_cfg_data.GB[i].bottom = m_cfg_data.GB[i].top + m_cfg_file.get_value("UI", "gb_h", 40);

		sprintf_s(buf, 4096, "gb%d_name", i + 1);
		m_cfg_data.str_gb_name[i] = m_cfg_file.get_value("UI", buf, "GBn");
		sprintf_s(buf, 4096, "gb%d_stake", i + 1);
		m_cfg_data.str_gb_stake[i] = m_cfg_file.get_value("UI", buf, "GB_STAKEn");

	}
	m_cfg_data.gb_remote_port = m_cfg_file.get_value("DEV_INFO", "gb_remote_port", 1200);
	m_cfg_data.dh_local_svr_port = m_cfg_file.get_value("DEV_INFO", "dh_local_svr_port", 1300);
	m_cfg_data.dh_remote_wav_port = m_cfg_file.get_value("DEV_INFO", "dh_remote_wav_port", 1301);
	m_cfg_data.dh_local_wav_port = m_cfg_file.get_value("DEV_INFO", "dh_local_wav_port", 1302);

	m_cfg_data.rec_path = m_cfg_file.get_value("RECORD", "rec_path", "./rec");
	
	return 0;
}



void CvtDlg::OnStnClickedStaticGb1()
{
	ToggleStnGbState(0);
}
void CvtDlg::OnStnClickedStaticGb2()
{
	ToggleStnGbState(1);
}
void CvtDlg::OnStnClickedStaticGb3()
{
	ToggleStnGbState(2);
}
void CvtDlg::OnStnClickedStaticGb4()
{
	ToggleStnGbState(3);
}
void CvtDlg::OnStnClickedStaticGb5()
{
	ToggleStnGbState(4);
}
void CvtDlg::OnStnClickedStaticGb6()
{
	ToggleStnGbState(5);
}
void CvtDlg::OnStnClickedStaticGb7()
{
	ToggleStnGbState(6);
}
void CvtDlg::OnStnClickedStaticGb8()
{
	ToggleStnGbState(7);
}
void CvtDlg::OnStnClickedStaticGb9()
{
	ToggleStnGbState(8);
}
void CvtDlg::OnStnClickedStaticGb10()
{
	ToggleStnGbState(9);
}

void CvtDlg::OnStnClickedStaticGb11()
{
	ToggleStnGbState(10);
}
void CvtDlg::OnStnClickedStaticGb12()
{
	ToggleStnGbState(11);
}
void CvtDlg::OnStnClickedStaticGb13()
{
	ToggleStnGbState(12);
}
void CvtDlg::OnStnClickedStaticGb14()
{
	ToggleStnGbState(13);
}
void CvtDlg::OnStnClickedStaticGb15()
{
	ToggleStnGbState(14);
}
void CvtDlg::OnStnClickedStaticGb16()
{
	ToggleStnGbState(15);
}
void CvtDlg::OnStnClickedStaticGb17()
{
	ToggleStnGbState(16);
}
void CvtDlg::OnStnClickedStaticGb18()
{
	ToggleStnGbState(17);
}
void CvtDlg::OnStnClickedStaticGb19()
{
	ToggleStnGbState(18);
}
void CvtDlg::OnStnClickedStaticGb20()
{
	ToggleStnGbState(19);
}

void CvtDlg::OnStnClickedStaticGb21()
{
	ToggleStnGbState(20);
}
void CvtDlg::OnStnClickedStaticGb22()
{
	ToggleStnGbState(21);
}
void CvtDlg::OnStnClickedStaticGb23()
{
	ToggleStnGbState(22);
}
void CvtDlg::OnStnClickedStaticGb24()
{
	ToggleStnGbState(23);
}
void CvtDlg::OnStnClickedStaticGb25()
{
	ToggleStnGbState(24);
}
void CvtDlg::OnStnClickedStaticGb26()
{
	ToggleStnGbState(25);
}
void CvtDlg::OnStnClickedStaticGb27()
{
	ToggleStnGbState(26);
}
void CvtDlg::OnStnClickedStaticGb28()
{
	ToggleStnGbState(27);
}
void CvtDlg::OnStnClickedStaticGb29()
{
	ToggleStnGbState(28);
}
void CvtDlg::OnStnClickedStaticGb30()
{
	ToggleStnGbState(29);
}

int CvtDlg::UpdatePic(CWnd* pWnd, string strPicPath)
{
	USES_CONVERSION;
	CImage img;
	img.Load(A2W(strPicPath.c_str()));

	HBITMAP hbmp2 = img.Detach();
	((CStatic*)pWnd)->SetBitmap(hbmp2);

	CRect rc;
	pWnd->GetWindowRect(&rc);
	pWnd->GetParent()->ScreenToClient(&rc);
	pWnd->GetParent()->InvalidateRect(&rc);
	return 0;
}

//afx_msg LRESULT CvtDlg::OnCallinHung(WPARAM wParam, LPARAM lParam)
//{
//}
afx_msg LRESULT CvtDlg::OnGbStateChange(WPARAM wParam, LPARAM lParam)
{
	int dev_id = wParam;
	T_DEV_STATE state = (T_DEV_STATE)lParam;
	LOGFMTI("Gb %d, %s", dev_id, state == PA_ON ? "PA on" : "PA off");
	T_PCM_HEADER header;
	for (int i = 1; i<255; i++)
	{
		set_pcm_header(&header, i, m_gb_state[i].pa_state);
	}
	m_gb_pcm_sender.update_frame_header(&header);
	return 1;
}

afx_msg LRESULT CvtDlg::OnSvrSocket(WPARAM wParam, LPARAM lParam)
{
	USES_CONVERSION;
	CSvrSocket* pservSock = (CSvrSocket*)wParam;
	CSvrSocket* pClntSock = new CSvrSocket();
	SOCKADDR_IN clntAddr;
	int clntAddrSz = sizeof(clntAddr);
	int param = *((int*)(lParam));
//	int recvLen;
	char buf[BUF_SIZE];
	switch (param)
	{
	case ACCEPT:
	{
		pservSock->Accept(*pClntSock, (SOCKADDR*)&clntAddr, &clntAddrSz);
		pClntSock->m_pWnd = this;
		//m_pClnts.AddTail(pClntSock);
		m_pClnts.push_back(pClntSock);
	}
	break;
	case RECIEVE:
	{
		memset(buf, 0, BUF_SIZE);
		int strLen = pservSock->Receive(buf, BUF_SIZE, 0);
		t_call_protocol cp;
		if (rcvbuf_to_obj(buf, cp))
		{
			return -1;
		}

		pservSock->Send(buf, strLen, 0);
		int dh_id = cp.dev_id;
		if (CMD_CALL_REQ == cp.cmd && m_dh_state[dh_id].call_state == CALL_CLOSE)
		{
			m_dh_state[dh_id].call_state = CALL_IN;
			CCallinDlg dlgCallin;
			dlgCallin.m_str_bk_pic = m_cfg_data.str_callin_dialog_bk_img_path;
			dlgCallin.m_str_answer_pic = m_cfg_data.str_dh_answer_img_path;
			dlgCallin.m_str_hungup_pic = m_cfg_data.str_dh_hungup_img_path;
			dlgCallin.m_str_active_pic = m_cfg_data.str_dh_active_img_path;
			dlgCallin.m_str_close_pic = m_cfg_data.str_dh_close_img_path;
			dlgCallin.m_ci.call_number_from = m_cfg_data.str_dh_name[cp.dev_id];
			COleDateTime t = COleDateTime::GetCurrentTime();
			CString strRecordTime = t.Format(_T("%Y-%m-%d %H:%M:%S"));
		/*	int64_t tm = t.GetTime();
			CString str;
			str.Format(_T("%I64d"), tm);*/
			dlgCallin.m_ci.callin_time = W2A(strRecordTime.GetBuffer());
			//CTime ts(atoi(dlgCallin.m_ci.callin_time.c_str()));
			/*str = t.Format("%Y-%m-%d %H:%M:%S");*/
			CString strRec = t.Format(_T("%Y%m%d_%H%M%S"));
			char buf[1024];
			sprintf_s(buf, 1024, "%s_%s.wav", W2A(strRec.GetBuffer()), dlgCallin.m_ci.call_number_from.c_str());
			dlgCallin.m_ci.record_path = buf;
			pservSock->m_pCallinWnd = &dlgCallin;
			INT_PTR nRes = dlgCallin.DoModal();

 			if (IDCANCEL == nRes)
			{

			}
			else
			{
				load_call_history();
				t_call_info ci;
				ci.call_number_from = dlgCallin.m_ci.call_number_from;
				ci.call_number_to = dlgCallin.m_ci.call_number_to;
				ci.callin_time = dlgCallin.m_ci.callin_time;
				ci.call_duration_seconds = dlgCallin.m_ci.call_duration_seconds;
				ci.record_path = dlgCallin.m_ci.record_path;
				ci.car_plate_number = dlgCallin.m_ci.car_plate_number;
				ci.alarm_type = dlgCallin.m_ci.alarm_type;
				ci.alarm_info = dlgCallin.m_ci.alarm_info;
				m_call_history.call_info.push_back(ci);
				m_call_history.call_count++;
				save_call_history();
			}
			pservSock->m_pCallinWnd = NULL;
			m_dh_state[dh_id].call_state = CALL_CLOSE;
		}
	}
	break;
	default:
		break;
	}
	return 0;
}


void CvtDlg::OnBnClickedButtonRefesh()
{
	USES_CONVERSION;
	load_cfg();
	//ShowWindow(SW_HIDE);
	HBITMAP hBmp = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP2));

	m_btnOption.SetBitmap(hBmp);
	/*m_btnOption.SetWindowPos(&wndTopMost, m_cfg_data.rcOptionButton.left, m_cfg_data.rcOptionButton.top,
		m_cfg_data.rcOptionButton.Width(), m_cfg_data.rcOptionButton.Height(), SWP_SHOWWINDOW)*/;
	m_btnOption.MoveWindow(&m_cfg_data.rcOptionButton);
	m_stcTitle.ShowWindow(SW_HIDE);
	CImage imgtitle;
	imgtitle.Load(A2W(m_cfg_data.str_title_img_path.c_str()));
	HBITMAP hbmpTitle = imgtitle.Detach();
	m_stcTitle.SetBitmap(hbmpTitle);
	m_stcTitle.MoveWindow(m_cfg_data.rc_title);
	m_stcTitle.ShowWindow(SW_SHOW);
	for (int i = 0; i < MAX_DH_COUNT; i++)
	{
		if (i < m_cfg_data.dh_count)
		{
			// DH pic
			CImage img;
			img.Load(A2W(m_cfg_data.str_dh_online_img_path.c_str()));
			HBITMAP hbmp = img.Detach();
			m_stc_dh[i].SetBitmap(hbmp);
			/*m_stc_dh[i].SetWindowPos(&wndTopMost, m_cfg_data.DH[i].left, m_cfg_data.DH[i].top,
				m_cfg_data.DH[i].Width(), m_cfg_data.DH[i].Height(), SWP_SHOWWINDOW);*/
			m_stc_dh[i].MoveWindow(m_cfg_data.DH[i]);
			m_stc_dh[i].ShowWindow(SW_SHOW);
			// DH name
			m_stc_dh_name[i].SetWindowTextW(A2W(m_cfg_data.str_dh_name[i].c_str()));
			m_stc_dh_name[i].MoveWindow(m_cfg_data.DH[i].left, m_cfg_data.DH[i].top + m_cfg_data.DH[i].Height() + 15,
				m_cfg_data.DH[i].Width(), m_cfg_data.DH[i].Height());
			m_stc_dh[i].ShowWindow(SW_SHOW);
			// DH stake
			m_stc_dh_stake[i].SetWindowTextW(A2W(m_cfg_data.str_dh_stake[i].c_str()));
			m_stc_dh_stake[i].MoveWindow(m_cfg_data.DH[i].left, m_cfg_data.DH[i].top + m_cfg_data.DH[i].Height() + 30,
				m_cfg_data.DH[i].Width(), m_cfg_data.DH[i].Height());
		}
		else
		{
			/*m_stc_dh[i].SetWindowPos(&wndTopMost, m_cfg_data.DH[i].left, m_cfg_data.DH[i].top,
				m_cfg_data.DH[i].Width(), m_cfg_data.DH[i].Height(), SWP_HIDEWINDOW);*/
			m_stc_dh[i].ShowWindow(SW_HIDE);
			//m_stc_dh_name[i].SetWindowPos(&wndTopMost, m_cfg_data.DH[i].left, m_cfg_data.DH[i].top + m_cfg_data.DH[i].Height() + 15,
			//	m_cfg_data.DH[i].Width(), m_cfg_data.DH[i].Height(), SWP_HIDEWINDOW);
		/*	m_stc_dh_stake[i].SetWindowPos(&wndTopMost, m_cfg_data.DH[i].left, m_cfg_data.DH[i].top + m_cfg_data.DH[i].Height() + 30,
				m_cfg_data.DH[i].Width(), m_cfg_data.DH[i].Height(), SWP_HIDEWINDOW);*/
			m_stc_dh_name[i].ShowWindow(SW_HIDE);
			m_stc_dh_stake[i].ShowWindow(SW_HIDE);
			
		}

	}
	for (int i = 0; i < MAX_GB_COUNT; i++)
	{
		if (i < m_cfg_data.gb_count)
		{
			CImage img;
			// GB pic
			img.Load(A2W(m_cfg_data.str_gb_online_pa_off_img_path.c_str()));
			HBITMAP hbmp2 = img.Detach();
			m_stc_gb[i].SetBitmap(hbmp2);
			/*m_stc_gb[i].SetWindowPos(&wndTopMost, m_cfg_data.GB[i].left, m_cfg_data.GB[i].top,
				m_cfg_data.GB[i].Width(), m_cfg_data.GB[i].Height(), SWP_SHOWWINDOW);*/
			m_stc_gb[i].MoveWindow(m_cfg_data.GB[i]);
			m_stc_gb[i].ShowWindow(SW_SHOW);
			// GB name
			m_stc_gb_name[i].SetWindowTextW(A2W(m_cfg_data.str_gb_name[i].c_str()));
			m_stc_gb_name[i].MoveWindow(m_cfg_data.GB[i].left, m_cfg_data.GB[i].top + m_cfg_data.GB[i].Height() + 15,
				m_cfg_data.GB[i].Width(), m_cfg_data.GB[i].Height());
			m_stc_gb_name[i].ShowWindow(SW_SHOW);
			// GB stake
			m_stc_gb_stake[i].SetWindowTextW(A2W(m_cfg_data.str_gb_stake[i].c_str()));
			m_stc_gb_stake[i].MoveWindow(m_cfg_data.GB[i].left, m_cfg_data.GB[i].top + m_cfg_data.GB[i].Height() + 30,
				m_cfg_data.GB[i].Width(), m_cfg_data.GB[i].Height());
			m_stc_gb_stake[i].ShowWindow(SW_SHOW);
		}
		else
		{
			/*m_stc_gb[i].SetWindowPos(&wndTopMost, m_cfg_data.GB[i].left, m_cfg_data.GB[i].top,
				m_cfg_data.GB[i].Width(), m_cfg_data.GB[i].Height(), SWP_HIDEWINDOW);
			m_stc_gb_name[i].SetWindowPos(&wndTopMost,m_cfg_data.GB[i].left, m_cfg_data.GB[i].top + m_cfg_data.GB[i].Height() + 15,
				m_cfg_data.GB[i].Width(), m_cfg_data.GB[i].Height(), SWP_HIDEWINDOW);
			m_stc_gb_stake[i].SetWindowPos(&wndTopMost, m_cfg_data.GB[i].left, m_cfg_data.GB[i].top + m_cfg_data.GB[i].Height() + 30,
				m_cfg_data.GB[i].Width(), m_cfg_data.GB[i].Height(), SWP_HIDEWINDOW);*/
			m_stc_gb[i].ShowWindow(SW_HIDE);
			m_stc_gb_name[i].ShowWindow(SW_HIDE);
			m_stc_gb_stake[i].ShowWindow(SW_HIDE);
		}

	}
	Invalidate();
	CBitmap bmp;
	bmp.LoadBitmap(IDB_BITMAP3);   //IDB_BITMAP1是图片资源ID  

	m_brush.Detach();
	m_brush.CreatePatternBrush(&bmp);
	//ShowWindow(SW_SHOW);
}


void CvtDlg::OnStnClickedStaticDh1()
{
	CCalloutDlg dlgCallout;
	INT_PTR nRes = dlgCallout.DoModal();
	if (IDCANCEL == nRes)
	{
		return;
	}
	else
	{

	}

}


int CvtDlg::load_call_history()
{
	m_cfg_call_history.load("./call_history.dat");
	m_call_history.call_count = m_cfg_call_history.get_value("HISTORY", "call_count", 0);
	char buf[1024];
	m_call_history.call_info.clear();
	for (int i = 0; i < m_call_history.call_count; i++)
	{
		sprintf_s(buf, 1024, "CALL%d", i);
		t_call_info ci;
		ci.call_number_from = m_cfg_call_history.get_value(buf, "call_number_from", "null");
		ci.call_number_to = m_cfg_call_history.get_value(buf, "call_number_to", "null");
		ci.callin_time = m_cfg_call_history.get_value(buf, "callin_time", "null");
		ci.call_duration_seconds = m_cfg_call_history.get_value(buf, "call_duration_seconds", 0);
		ci.record_path = m_cfg_call_history.get_value(buf, "record_path", "null");
		ci.car_plate_number = m_cfg_call_history.get_value(buf, "car_plate_number", "null");
		ci.alarm_type = m_cfg_call_history.get_value(buf, "alarm_type", "null");
		ci.alarm_info = m_cfg_call_history.get_value(buf, "alarm_info", "null");
		m_call_history.call_info.push_back(ci);
	}
	return 0;
}


int CvtDlg::save_call_history()
{
	CString str;
	SYSTEMTIME  st;
	GetLocalTime(&st);
	str.Format(_T("call_history_bak_%4d_%2d_%2d %2d_%2d_%2d.dat"), st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
	//DeleteFile(_T("./call_history_bak.dat"));
	MoveFile(_T("./call_history.dat"), str.GetBuffer());
	//m_cfg_call_history.load("./call_history.dat");
	Config cfg_call_history;
	cfg_call_history.set_value("HISTORY", "call_count", m_call_history.call_count);
	char buf[1024];
	for (int i = 0; i < m_call_history.call_count; i++)
	{
		sprintf_s(buf, 1024, "CALL%d", i);
		t_call_info ci = m_call_history.call_info[i];
		cfg_call_history.set_value(buf, "call_number_from", ci.call_number_from);
		cfg_call_history.set_value(buf, "call_number_to", ci.call_number_to);
		cfg_call_history.set_value(buf, "callin_time", ci.callin_time);
		cfg_call_history.set_value(buf, "call_duration_seconds", ci.call_duration_seconds);
		cfg_call_history.set_value(buf, "record_path", ci.record_path);
		cfg_call_history.set_value(buf, "car_plate_number", ci.car_plate_number);
		cfg_call_history.set_value(buf, "alarm_type", ci.alarm_type);
		cfg_call_history.set_value(buf, "alarm_info", ci.alarm_info);
		m_call_history.call_info.push_back(ci);
	}
	cfg_call_history.save("./call_history.dat");
	return 0;
}


void CvtDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (m_pt_lb_down.x != -1)
	{
		CRect rc;
		if (m_pt_lb_down.x < point.x) {
			rc.left = m_pt_lb_down.x;
			rc.right = point.x;
		}
		else {
			rc.left = point.x;
			rc.right = m_pt_lb_down.x;
		}
		if (m_pt_lb_down.y < point.y) {
			rc.top = m_pt_lb_down.y;
			rc.bottom = point.y;
		}
		else {
			rc.top = point.y;
			rc.bottom = m_pt_lb_down.y;
		}
		//ClientToScreen(&rc);
		CRect rctmp;
		for (int i = 0; i < m_cfg_data.gb_count; i++)
		{
			if (rctmp.IntersectRect(&rc, &m_cfg_data.GB[i]))
			{
				if (m_gb_state[i].pa_state != PA_ON)
				{
					m_gb_state[i].pa_state = PA_ON;
					if (m_gb_state[i].comm_state == ONLINE)
						UpdatePic(&m_stc_gb[i], m_cfg_data.str_gb_online_pa_on_img_path);
					else
						UpdatePic(&m_stc_gb[i], m_cfg_data.str_gb_offline_pa_on_img_path);
				}
			}
		}
	}
	else if (m_pt_rb_down.x != -1)
	{
		CRect rc;
		if (m_pt_rb_down.x < point.x) {
			rc.left = m_pt_rb_down.x;
			rc.right = point.x;
		}
		else {
			rc.left = point.x;
			rc.right = m_pt_rb_down.x;
		}
		if (m_pt_rb_down.y < point.y) {
			rc.top = m_pt_rb_down.y;
			rc.bottom = point.y;
		}
		else {
			rc.top = point.y;
			rc.bottom = m_pt_rb_down.y;
		}
		//ClientToScreen(&rc);
		CRect rctmp;
		for (int i = 0; i < m_cfg_data.gb_count; i++)
		{
			if (rctmp.IntersectRect(&rc, &m_cfg_data.GB[i]))
			{
				if (m_gb_state[i].pa_state != PA_OFF) {
					m_gb_state[i].pa_state = PA_OFF;
					if (m_gb_state[i].comm_state == ONLINE)
						UpdatePic(&m_stc_gb[i], m_cfg_data.str_gb_online_pa_off_img_path);
					else
						UpdatePic(&m_stc_gb[i], m_cfg_data.str_gb_offline_pa_off_img_path);
				}
			}
		}
	}
	
	CDialogEx::OnMouseMove(nFlags, point);
}


void CvtDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_pt_lb_down = point;
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CvtDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rc;
	if (m_pt_lb_down.x < point.x){
		rc.left = m_pt_lb_down.x;
		rc.right = point.x;
	}
	else {
		rc.left = point.x;
		rc.right = m_pt_lb_down.x;
	}
	if (m_pt_lb_down.y < point.y) {
		rc.top = m_pt_lb_down.y;
		rc.bottom = point.y;
	}
	else {
		rc.top = point.y;
		rc.bottom = m_pt_lb_down.y;
	}
	//ClientToScreen(&rc);
	CRect rctmp;
	for (int i = 0; i < m_cfg_data.gb_count; i++)
	{
		if(rctmp.IntersectRect(&rc,&m_cfg_data.GB[i]))
		{ 
			if (m_gb_state[i].pa_state != PA_ON)
			{
				m_gb_state[i].pa_state = PA_ON;
				if (m_gb_state[i].comm_state == ONLINE)
					UpdatePic(&m_stc_gb[i], m_cfg_data.str_gb_online_pa_on_img_path);
				else
					UpdatePic(&m_stc_gb[i], m_cfg_data.str_gb_offline_pa_on_img_path);
			}
		}
	}
	m_pt_lb_down.x = -1;
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CvtDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	m_pt_rb_down = point;
	CDialogEx::OnRButtonDown(nFlags, point);
}


void CvtDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CRect rc;
	if (m_pt_rb_down.x < point.x) {
		rc.left = m_pt_rb_down.x;
		rc.right = point.x;
	}
	else {
		rc.left = point.x;
		rc.right = m_pt_rb_down.x;
	}
	if (m_pt_rb_down.y < point.y) {
		rc.top = m_pt_rb_down.y;
		rc.bottom = point.y;
	}
	else {
		rc.top = point.y;
		rc.bottom = m_pt_rb_down.y;
	}
	//ClientToScreen(&rc);
	CRect rctmp;
	for (int i = 0; i < m_cfg_data.gb_count; i++)
	{
		if (rctmp.IntersectRect(&rc, &m_cfg_data.GB[i]))
		{
			if (m_gb_state[i].pa_state != PA_OFF)
			{
				m_gb_state[i].pa_state = PA_OFF;
				if (m_gb_state[i].comm_state == ONLINE)
					UpdatePic(&m_stc_gb[i], m_cfg_data.str_gb_online_pa_off_img_path);
				else
					UpdatePic(&m_stc_gb[i], m_cfg_data.str_gb_offline_pa_off_img_path);
			}
		}
	}
	m_pt_rb_down.x = -1;
	CDialogEx::OnRButtonUp(nFlags, point);
}


void CvtDlg::OnCallHistory()
{
	// TODO: 在此添加命令处理程序代码
	CCallHistoryDlg dlgCallhistory;	
	INT_PTR nRes = dlgCallhistory.DoModal();
	if (IDCANCEL == nRes)
	{

	}
	else
	{

	}
}


int CvtDlg::ToggleStnGbState(int dev_id)
{
	switch (m_gb_state[dev_id].pa_state)
	{
	case PA_OFF:
		if (m_gb_state[dev_id].comm_state == ONLINE)
			UpdatePic(&m_stc_gb[dev_id], m_cfg_data.str_gb_online_pa_on_img_path);
		else
			UpdatePic(&m_stc_gb[dev_id], m_cfg_data.str_gb_offline_pa_on_img_path);
		m_gb_state[dev_id].pa_state = PA_ON;
		break;
	case PA_ON:
		if (m_gb_state[dev_id].comm_state == ONLINE)
			UpdatePic(&m_stc_gb[dev_id], m_cfg_data.str_gb_online_pa_off_img_path);
		else
			UpdatePic(&m_stc_gb[dev_id], m_cfg_data.str_gb_offline_pa_off_img_path);
		m_gb_state[dev_id].pa_state = PA_OFF;
		break;
	default:
		break;
	}
	return 0;
}


void CvtDlg::OnBoradcastSw()
{
	// TODO: 在此添加命令处理程序代码
	if (m_b_boardcast_sw)
	{
		m_b_boardcast_sw = false;
		m_gb_pcm_sender.stop();
		m_menu.ModifyMenuW(1, MF_BYPOSITION, ID_BORADCAST_SW, _T("打开广播"));
	}
	else
	{
		m_b_boardcast_sw = true;
		m_gb_pcm_sender.start();
		m_menu.ModifyMenuW(1, MF_BYPOSITION, ID_BORADCAST_SW, _T("关闭广播"));
	}
}
