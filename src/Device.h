#pragma once
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Device
{
protected:
	string id;
	float defaulval;
	map<string, string> netList;
	float max;
	float min;
	string type;
public:
	Device(string id , map<string, string> netList ,  float def, float max, float min);
	Device();
	void setID(string id);
	void set_Default(float def);
	void set_netList(map<string, string> netList);
	void set_Max(float max);
	void set_Min(float min);
	void set_type(string name);

	string get_type();
	float get_Default();
	map<string, string> get_netList();
	float get_max();
	float get_min();
	string get_id();
	virtual void Print_Device();
	~Device();
};

