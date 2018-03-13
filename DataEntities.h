#pragma once
#include <string>
#include "../cfg/cfg/Config.h"
#include <vector>
#include "../json11/json11.hpp"

using namespace json11;
class DataEntities
{
public:
	DataEntities();
	~DataEntities();
};

#define WM_SVR_SOCKET WM_USER+1
#define WM_RCV_HUNGUP WM_USER+21
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
}DEV_STATE;


typedef struct
{
	DEV_STATE comm_state;
	DEV_STATE call_state;
}t_dh_state;
typedef struct
{
	DEV_STATE comm_state;
	DEV_STATE pa_state;
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
	int dev_id;
	T_MSG_TYPE type;
	T_CMD cmd;
	T_STATE door_state;
};