#include "stdafx.h"
#include "PcmSender.h"


CPcmSender::CPcmSender()
	: m_Port(0)
{
	LOGFMTT("");
}


CPcmSender::~CPcmSender()
{
	LOGFMTT("");
}


int CPcmSender::worker_thread_sender()
{
	LOGFMTT("");
	while (1)
	{
		Sleep(20);
	}
	LOGFMTT("");
	return 0;
}
int CPcmSender::worker_thread_capture()
{
	LOGFMTT("");
	while (1)
	{
		Sleep(20);
	}
	LOGFMTT("");
	return 0;
}


int CPcmSender::call_worker(void* ptr)
{
	LOGFMTT("");
	return 0;
}


int CPcmSender::start()
{
	LOGFMTT("");
	return 0;
}


int CPcmSender::stop()
{
	return 0;
}
