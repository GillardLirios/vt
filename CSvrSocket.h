#pragma once

#define WM_SVR_SOCKET WM_USER+1
#define ACCEPT 0
#define RECIEVE 1
#define CLOSE 2

#define BUF_SIZE 1024
// CSvrSocket 命令目标

class CSvrSocket : public CSocket
{
public:
	CSvrSocket();
	virtual ~CSvrSocket();

	CWnd* m_pWnd;

	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
};


