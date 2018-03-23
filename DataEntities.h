#pragma once
#include <string>
#include "../cfg/cfg/Config.h"
#include <vector>
#include <map>
#include "../json11/json11.hpp"
#include "../log4z/log4z.h" 
#define BUF_SIZE 1024

using namespace zsummer::log4z;
using namespace json11;
using std::string;
using namespace std;

class DataEntities
{
public:
	DataEntities();
	~DataEntities();
	
};


#define WM_SVR_SOCKET WM_USER+1
#define WM_CALLIN_MSG WM_USER+21
using namespace std;

typedef enum
{
	OFFLINE = 0,
	ONLINE,
	PA_ON,
	PA_OFF,
	CALL_CLOSE,
	CALL_IN,
	CALL_ONGOING,
	CALL_MISS,
	CALL_OUT,
}T_DEV_STATE;


typedef struct
{
	T_DEV_STATE comm_state;
	T_DEV_STATE call_state;
}t_dh_state;
typedef struct
{
	T_DEV_STATE comm_state;
	T_DEV_STATE pa_state;
}t_gb_state;

class t_call_info
{
public:
	string call_number_from;
	string call_number_to;
	string callin_time;
	int call_duration_seconds;
	string record_path;
	string alarm_info;
	string alarm_type;
	string car_plate_number;
};

using namespace cfg;
using namespace std;
class t_config {
public:
	string str_title_img_path;
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

	string str_gb_online_pa_on_img_path;
	string str_gb_offline_pa_on_img_path;
	string str_gb_online_pa_off_img_path;
	string str_gb_offline_pa_off_img_path;
	

	string str_option_img_path;
	CRect  rcOptionButton;
	int dh_count;
	int gb_count;
	CRect rc_title;
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
	string rec_path;
};

class t_call_history
{
public:
	int call_count;
	vector<t_call_info> call_info;
};


typedef enum {
	MSG_REQ = 0,
	MSG_REPLY,
}T_MSG_TYPE;

typedef enum {
	CMD_CALL_INFO = 0,
	CMD_CALL_REQ,
	CMD_CALL_HUNGUP,
}T_CMD;
typedef enum {
	DOOR_CLOSE = 0,
	DOOR_OPEN,
}T_STATE;


class t_call_protocol {
public:
	int dev_id;
	T_MSG_TYPE type;
	T_CMD cmd;
	T_STATE door_state;
};

int rcvbuf_to_obj(char* buf, t_call_protocol& cp);


union T_PCM_HEADER{
	struct {
		uint8_t flag;
		uint8_t seq;
		uint8_t spk_sw[32];
	};
	uint8_t buf_header[34];
};

union T_PCM_FRAME {
	struct {
		T_PCM_HEADER header;
		uint8_t pcm_data;
	};
	uint8_t buf[2 + 32 + 1280];	
};

void set_pcm_header(T_PCM_HEADER* pheader, int id, T_DEV_STATE state);
