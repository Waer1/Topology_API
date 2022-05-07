#pragma once
/**
 * @file Device.h
 * @author Yousef Alwaer (elwaeryousef@gmail.com)
 * @brief 
 * main class of the All componnet or all devices used in this program with 
 * virual print to print each type of device specificlly
 * holding the shared info among all types of devices
 * 
 * @version 0.1
 * @date 2022-05-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <string>
#include <map>
#include <iostream>
using namespace std;


/**
 * @brief main class of the All componnet or all devices used in this program with 
 * 
 */
class Device
{
protected:
/**
 * @brief id of the device
 * 
 */
	string id;
	/**
	 * @brief map contain devices connected to this device 3 terminals or 2 terminals
	 * 
	 */
	map<string, string> netList;

	/**
	 * @brief the defalt and min and max value that can be connected to component
	 * 
	 */
	float defaulval; float max;float min;
	/**
	 * @brief string hold the type of the Device
	 * 
	 */
	string type;
public:

/**
 * @brief Construct a new Device object
 * 
 * @param id the id of the device
 * @param netList the list of connected devices to the device 
 * @param def default valude from this device
 * @param max max valude from this device
 * @param min min valude from this device
 */
	Device(string id , map<string, string> netList ,  float def, float max, float min);
	
	/**
	 * @brief default Construct a new Device object
	 */
	Device();
	/**
	 * @brief set the ID of the Device
	 * 
	 * @param id new ID of device
	 */
	void setID(string id);
	/**
	 * @brief Set the Default object
	 * 
	 * @param def new default value of device
	 */
	void set_Default(float def);
	/**
	 * @brief Set the netList object
	 * 
	 * @param netList new netList of device
	 */
	void set_netList(map<string, string> netList);
	/**
	 * @brief Set the Max object
	 * 
	 * @param max new max value of device
	 */
	void set_Max(float max);
	/**
	 * @brief Set the Min object
	 * 
	 * @param min new min value of device
	 */
	void set_Min(float min);
	/**
	 * @brief Set the type object
	 * 
	 * @param name new type
	 */
	void set_type(string name);

	/**
	 * @brief Get the type object
	 * 
	 * @return string 
	 */
	string get_type();
	/**
	 * @brief Get the Default object
	 * 
	 * @return float 
	 */
	float get_Default();
	/**
	 * @brief Get the netList object
	 * 
	 * @return map<string, string> 
	 */
	map<string, string> get_netList();
	/**
	 * @brief Get the max object
	 * 
	 * @return float 
	 */
	float get_max();
	/**
	 * @brief Get the min object
	 * 
	 * @return float 
	 */
	float get_min();
	/**
	 * @brief Get the id object
	 * 
	 * @return string 
	 */
	string get_id();
	/**
	 * @brief print the general device info 
	 * 
	 */
	virtual void Print_Device();
	~Device();
};

