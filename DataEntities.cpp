#include "stdafx.h"
#include "DataEntities.h"


DataEntities::DataEntities()
{
}


DataEntities::~DataEntities()
{
}

 std::map<string, T_MSG_TYPE> MAP_OF_MSG_TYPE = {
	{"req",MSG_REQ },
	{"rpy",MSG_REPLY }
};

 std::map<string, T_CMD> MAP_OF_CMD = {
	{ "call_info",CMD_CALL_INFO },
	{ "call_req",CMD_CALL_REQ },
	{ "call_hungup",CMD_CALL_HUNGUP }
};

 std::map<string, T_STATE> MAP_OF_STATE = {
	{ "door_close",DOOR_CLOSE },
	{ "door_open",DOOR_OPEN }
};

int rcvbuf_to_obj(char* buf, t_call_protocol& cp)
{
	const string str = buf;
	string err;
	const auto json = Json::parse(str, err);
	if (!err.empty()) {
		LOGFMTE(err.c_str());
		return -1;
	}
	cp.dev_id		= json["dev_id"].int_value();
	cp.type			= MAP_OF_MSG_TYPE[json["msg_type"].string_value()];
	cp.cmd			= MAP_OF_CMD[json["cmd"].string_value()];
	cp.door_state	= MAP_OF_STATE[json["state"].string_value()];
	return 0;
}

unsigned char bitset(unsigned char num, unsigned char bit) /*设置某一位*/
{
	unsigned char bit_value[] = { 1,2,4,8,16,32,64,128 };
	return num | bit_value[bit];
}
unsigned char bitclr(unsigned char num, unsigned char bit) /*清除某一位*/
{
	unsigned char bit_value[] = { 1,2,4,8,16,32,64,128 };
	return num & ~bit_value[bit];
}

void set_pcm_header(T_PCM_HEADER* pheader, int id, T_DEV_STATE state)
{
	LOGFMTT("gb dev=%d, state=%s", id, state == PA_ON ? "PA on" : "PA off");
	if (id > 255)
		return;
	int addr = id / 8 + 2;
	int bit = id % 8;
	if (state==PA_ON)
		pheader->buf_header[addr] = bitset(pheader->buf_header[addr], bit);
	else
		pheader->buf_header[addr] = bitclr(pheader->buf_header[addr], bit);
}