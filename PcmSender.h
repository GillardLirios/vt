#pragma once
#include "DataEntities.h"
#include <thread>
#include <mutex>

class CPcmSender
{
public:
	CPcmSender();
	~CPcmSender();
	int m_Port;
	uint8_t m_u8pcm_buf[2 + 32 + 1280];
	int worker_thread_sender();
	int worker_thread_capture();
	int call_worker(void* ptr);
	int start();
	int stop();
	std::mutex	m_mutex_q_send;
};

