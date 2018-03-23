#pragma once
#include "DataEntities.h"
#include <thread>
#include <mutex>

class CPcmSender
{
public:
	CPcmSender();
	~CPcmSender();
	string m_ip;
	int m_port;
	
	int worker_thread_sender();
	int worker_thread_capture();

	int start();
	int stop();

	std::thread m_thd_worker_capture;

	T_PCM_FRAME m_pcm_frame;
	std::mutex	m_mutex_frame;

	int m_cv_exit;
	std::mutex m_mutex_cv_exit;

	int update_frame_header(T_PCM_HEADER* header);

};

