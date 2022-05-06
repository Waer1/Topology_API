#include "Device.h"

Device::Device(string id, map<string, string> netList , float def, float max, float min)
{
	setID(id);
	set_Default(def);
	set_Max(max);
	set_netList(netList);
	set_Min(min);
}

Device::Device()
{
	set_Default(0);
	set_Max(0);
	set_Min(0);
	set_type("");
}

void Device::set_Default(float def)
{
	this->defaulval = def;
}

void Device::set_netList(map<string, string> netListval)
{
	this->netList = netListval;
}

void Device::setID(string id) { 
	this->id = id; 
}

void Device::set_Max(float max)
{
	this->max = max;
}

void Device::set_Min(float min)
{
	this->min = min;
}

void Device::set_type(string name)
{
	this->type = name;
}

string Device::get_type()
{
	return this->type;
}

float Device::get_Default()
{
	return this->defaulval;
}

float Device::get_max()
{
	return this->max;
}

map<string, string> Device::get_netList()
{
	return this->netList;
}

float Device::get_min()
{
	return this->min;
}

void Device::Print_Device()
{
	printf("Device Details : \n Default: %f , max:  %f  , min: %f \n" ,this->get_Default() , this->get_max() , this->get_min());
}

string Device::get_id()
{
	return this->id;
}

Device::~Device()
{
}
