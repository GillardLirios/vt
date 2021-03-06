
// vtDlg.h: 头文件
//

#pragma once

#include "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\atlmfc\include\atlimage.h"
#include "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\atlmfc\include\afxwin.h"
//#include "E:\GitHub\cfg\cfg\Config.h"
#include "CSvrSocket.h"

#include "CallinDlg.h"
#include "DataEntities.h"
#include "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.12.25827\atlmfc\include\atltypes.h"
#include "PcmSender.h"

#define MAX_DH_COUNT	30
#define MAX_GB_COUNT	30

// CvtDlg 对话框

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

	t_gb_state m_gb_state[30];
	t_dh_state m_dh_state[30];

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
	CMenu m_menu;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	CPoint m_pt_lb_down;
	CPoint m_pt_rb_down;
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	CStatic m_stcTitle;
	afx_msg void OnCallHistory();
	int ToggleStnGbState(int dev_id);
	afx_msg LRESULT OnGbStateChange(WPARAM wParam, LPARAM lParam);
	CPcmSender m_gb_pcm_sender;
	afx_msg void OnBoradcastSw();
	bool m_b_boardcast_sw;
};

