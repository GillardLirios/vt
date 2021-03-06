// CSvrSocket.cpp: 实现文件
//

#include "stdafx.h"
#include "vt.h"
#include "CSvrSocket.h"


// CSvrSocket

CSvrSocket::CSvrSocket()
{
	m_pWnd = NULL;
	m_pCallinWnd = NULL;
}

CSvrSocket::~CSvrSocket()
{
}


// CSvrSocket 成员函数


void CSvrSocket::OnAccept(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
#if 1
	int param = ACCEPT;
	if (m_pWnd != NULL)
		m_pWnd->SendMessage(WM_SVR_SOCKET, (WPARAM)this, (LPARAM)&param);
#else
	CSvrSocket* pClntSock = new CSvrSocket();
	SOCKADDR_IN clntAddr;
	int clntAddrSz = sizeof(clntAddr);
	pClntSock->m_pWnd = this;
	Accept(*pClntSock, (SOCKADDR*)&clntAddr, &clntAddrSz);
	m_pClnts.push_back(pClntSock);
#endif
	CSocket::OnAccept(nErrorCode);
}


void CSvrSocket::OnClose(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	int param = CLOSE;
	if (m_pWnd != NULL)
		m_pWnd->SendMessage(WM_SVR_SOCKET, (WPARAM)this, (LPARAM)&param);
	CSocket::OnClose(nErrorCode);
}


void CSvrSocket::OnConnect(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	
	CSocket::OnConnect(nErrorCode);
}


void CSvrSocket::OnReceive(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类
	int param = RECIEVE;
	if (m_pCallinWnd != NULL)
		m_pCallinWnd->SendMessage(WM_CALLIN_MSG, (WPARAM)this, (LPARAM)&param);
	else if (m_pWnd != NULL)
		m_pWnd->SendMessage(WM_SVR_SOCKET, (WPARAM)this, (LPARAM)&param);
	CSocket::OnReceive(nErrorCode);
}


void CSvrSocket::OnSend(int nErrorCode)
{
	// TODO: 在此添加专用代码和/或调用基类

	CSocket::OnSend(nErrorCode);
}
