#pragma once
#include "DataEntities.h"

#define ACCEPT 0
#define RECIEVE 1
#define CLOSE 2


// CSvrSocket 命令目标

class CSvrSocket : public CSocket
{
public:
	CSvrSocket();
	virtual ~CSvrSocket();

	CWnd* m_pWnd;
	CWnd* m_pCallinWnd;
	//std::vector<CSvrSocket*> m_pClnts;
	virtual void OnAccept(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
};


