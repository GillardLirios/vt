
// vtDlg.h: 头文件
//

#pragma once
#include "../cfg/cfg/Config.h"
#include "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\atlmfc\include\atlimage.h"
#include "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\atlmfc\include\afxwin.h"
//#include "E:\GitHub\cfg\cfg\Config.h"
#define MAX_DH_COUNT	30
// CvtDlg 对话框
using namespace cfg;
using namespace std;
class t_config{
public:
	string str_dh_online_img_path;
	string str_dh_offline_img_path;
	string str_dh_callin_img_path;
	string str_dh_active_img_path;
	string str_dh_callmiss_img_path;
	string str_dh_callout_img_path;
	string str_dh_close_img_path;
	string str_dh_busy_img_path;

	string str_gb_online_img_path;
	string str_gb_offline_img_path;
	string str_gb_active_img_path;
	string str_gb_busy_img_path;
	int dh_count;
	int gb_count;
	CRect DH[30];
	CRect GB[30];
};

class CvtDlg : public CDialog
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
	t_config m_cfg_data;
	CImage m_imgBK;
	CBrush m_brush;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	CStatic m_stc_dh[30];
	CStatic m_stc_gb[30];
	int load_cfg();
};
