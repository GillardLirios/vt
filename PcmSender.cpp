#include "stdafx.h"
#include "PcmSender.h"

int call_worker(void* ptr);
CPcmSender::CPcmSender()
	: m_port(0)
{
	m_ip = "255.255.255.255";
	m_cv_exit = 0;
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
	LOGFMTT("start");
	while (1)
	{
		unique_lock <mutex> lk_frame(m_mutex_frame);
		

		

		unique_lock <mutex> lk_exit(m_mutex_cv_exit);
		if(m_cv_exit)
		{
			LOGFMTT("thread will exit");
			break;
		}

		this_thread::sleep_for(std::chrono::milliseconds(20));
	}
	LOGFMTT("exit");
	return 0;
}


int call_worker(void* ptr)
{
	LOGFMTT("");
	CPcmSender* pobj = (CPcmSender*)ptr;
	pobj->worker_thread_capture();
	return 0;
}


int CPcmSender::start()
{
	LOGFMTT("");
	m_thd_worker_capture = std::thread(call_worker,this);
	m_thd_worker_capture.detach();
	return 0;
}


int CPcmSender::stop()
{
	LOGFMTT("");
	return 0;
}


int CPcmSender::update_frame_header(T_PCM_HEADER* header)
{
	LOGFMTT("");
	m_mutex_frame.lock();
	memcpy(m_pcm_frame.buf, header->buf_header, sizeof(header));
	m_mutex_frame.unlock();
	return 0;
}
