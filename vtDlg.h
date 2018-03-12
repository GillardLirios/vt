
// vtDlg.h: 头文件
//

#pragma once
#include "../cfg/cfg/Config.h"
#include "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\atlmfc\include\atlimage.h"
#include "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\atlmfc\include\afxwin.h"
//#include "E:\GitHub\cfg\cfg\Config.h"
#include "CSvrSocket.h"
#include <vector>
#include "CallinDlg.h"
#define MAX_DH_COUNT	30
#define MAX_GB_COUNT	30
// CvtDlg 对话框
using namespace cfg;
using namespace std;
class t_config{
public:
	string str_dh_online_img_path;
	string str_dh_offline_img_path;
	string str_dh_callin_img_path;
	string str_dh_answer_img_path;
	string str_dh_active_img_path;
	string str_dh_callmiss_img_path;
	string str_dh_callout_img_path;
	string str_dh_close_img_path;
	string str_dh_hungup_img_path;
	string str_dh_busy_img_path;
	string str_callin_dialog_bk_img_path;

	string str_gb_online_img_path;
	string str_gb_offline_img_path;
	string str_gb_active_img_path;
	string str_gb_busy_img_path;

	string str_option_img_path;
	CRect  rcOptionButton;
	int dh_count;
	int gb_count;
	CRect DH[30];
	CRect GB[30];
	string str_dh_name[30];
	string str_dh_stake[30];
	string str_gb_name[30];
	string str_gb_stake[30];
	int gb_remote_port;
	int dh_local_svr_port;
	int dh_remote_wav_port;
	int dh_local_wav_port;
};

class t_call_history
{
public:
	int call_count;
	vector<t_call_info> call_info;
};
typedef enum
{
	GB_OFFLINE = 0,
	GB_ONLINE,
	GB_ACTIVE,
}GB_STATE;

typedef enum
{
	DH_OFFLINE = 0,
	DH_ONLINE,
	DH_CALL_IN,
	DH_ACTIVE,
	DH_CALL_MISS,
	DH_CALL_OUT,
}DH_STATE;

class CvtDlg : public CDialogEx
{
// 构造
public:
	CvtDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_VT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	Config m_cfg_file;
	Config m_cfg_call_history;
	t_call_history m_call_history;
	t_config m_cfg_data;
	CImage m_imgBK;
	CBrush m_brush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CStatic m_stc_dh[30];
	CStatic m_stc_dh_name[30];
	CStatic m_stc_dh_stake[30];
	CStatic m_stc_gb[30];
	CStatic m_stc_gb_name[30];
	CStatic m_stc_gb_stake[30];
	int load_cfg();
	CButton m_btnOption;

	GB_STATE m_gb_state[30];
	DH_STATE m_dh_state[30];

	afx_msg void OnStnClickedStaticGb1();
	afx_msg void OnStnClickedStaticGb2();
	afx_msg void OnStnClickedStaticGb3();
	afx_msg void OnStnClickedStaticGb4();
	afx_msg void OnStnClickedStaticGb5();
	afx_msg void OnStnClickedStaticGb6();
	afx_msg void OnStnClickedStaticGb7();
	afx_msg void OnStnClickedStaticGb8();
	afx_msg void OnStnClickedStaticGb9();
	afx_msg void OnStnClickedStaticGb10();
	afx_msg void OnStnClickedStaticGb11();
	afx_msg void OnStnClickedStaticGb12();
	afx_msg void OnStnClickedStaticGb13();
	afx_msg void OnStnClickedStaticGb14();
	afx_msg void OnStnClickedStaticGb15();
	afx_msg void OnStnClickedStaticGb16();
	afx_msg void OnStnClickedStaticGb17();
	afx_msg void OnStnClickedStaticGb18();
	afx_msg void OnStnClickedStaticGb19();
	afx_msg void OnStnClickedStaticGb20();
	afx_msg void OnStnClickedStaticGb21();
	afx_msg void OnStnClickedStaticGb22();
	afx_msg void OnStnClickedStaticGb23();
	afx_msg void OnStnClickedStaticGb24();
	afx_msg void OnStnClickedStaticGb25();
	afx_msg void OnStnClickedStaticGb26();
	afx_msg void OnStnClickedStaticGb27();
	afx_msg void OnStnClickedStaticGb28();
	afx_msg void OnStnClickedStaticGb29();
	afx_msg void OnStnClickedStaticGb30();
	int UpdatePic(CWnd* pWnd, string strPicPath);
	afx_msg LRESULT OnSvrSocket(WPARAM wParam, LPARAM lParam);
	std::vector<CSvrSocket*> m_pClnts;
	CSvrSocket m_SvrSock;
	afx_msg void OnBnClickedButtonRefesh();
	afx_msg void OnStnClickedStaticDh1();
	int load_call_history();
	int save_call_history();
};

