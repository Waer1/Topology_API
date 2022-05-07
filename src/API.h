/**
 * @file API.h
 * @author Yousef Alwaer (elwaeryousef@gmail.com)
 * @brief API is the class use to treat with json in write json file or read from json files
 * -reading the json files and convert it to onject from Device type and store it on memory
 * - output topologies stored in memory to json files to files user detect that file
 * 
 * @version 0.1
 * @date 2022-05-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once
#include <fstream>
#include <iomanip>

#include "topology.h"
#include "json.hpp"


using json = nlohmann::json;

/**
 * @brief API is the class use to treat with json in write json file or read from json files
 * 
 */
class API
{
private:
public:
	API();
	
	/**
	 * @brief function used to create object from json file and check its empty or not and return pointer no null if object empty
	 * 
	 * @param FileName filename of json file prechecked on his validation 
	 * @return topology * the topology object formed from json file (filename)
	 */
	topology* ReadJson(string FileName);

	/**
	 * @brief Create a Topology object from json object passed to it by devide it to smaller task , each task create one list 
	 * 
	 * @param jsonObject json object from file name passed to readjson
	 * @return topology *  the topology object formed from json file (filename) and adding its id
	 */
	topology* createTopology(json jsonObject);

	/**
	 * @brief Create a List Of Devices object, by looping throught the lists exist in file and give each device to procude it
	 * 
	 * @param jsonObject json object from file name passed to readjson
	 * @return vector<Device*> vector of pointers of devices in list 
	 */
	vector<Device*> createListOfDevices(json jsonObject);

	/**
	 * @brief Create a Device object given from createListOfDevices by detect Device type and all suitanle function for it's creation
	 * 
	 * @param DeviceJson the device passed as json object
	 * @return Device* pointer to Device object
	 */
	Device* createDevice(const json& DeviceJson);

	/**
	 * @brief Create a Nmos object , called if the device type is Nmos
	 * 
	 * @param DeviceJson the Nmos passed as json object, with its specifications
	 * @return Device* pointer to Device object
	 */
	Device* createNmos(const json& DeviceJson);

	/**
	 * @brief Create a Nmos object , called if the device type is Pmos
	 * 
	 * @param DeviceJson the Pmos passed as json object, with its specifications
	 * @return Device* pointer to Device object
	 */
	Device* createPmos(const json& DeviceJson);

	/**
	 * @brief Create a Resistor object , called if the device type is Resistor
	 * 
	 * @param DeviceJson the Resistor passed as json object, with its specifications
	 * @return Device* pointer to Device object
	 */
	Device* createResistor(const json& DeviceJson);

	/**
	 * @brief function used to convert topology in memory to json file in a given json file name
	 * 
	 * @param filename name of the file  program will write on it
	 * @param Topology the topology which will be printed in as json object
	 * @return true is every thing done correctly
	 * @return false if throw any exepection from reading file or write on it
	 */
	bool writeToJSON(string filename, const topology* Topology);

	/**
	 * @brief convert the topology object to json object by divide it into smaller tasks. 
	 * each task is convert Device to separte json object
	 * 
	 * @param topo json file to the topology program will convert
	 * @return json 
	 */
	json ConvertTopologyTojson(const topology* topo);
	/**
	 * @brief function usedto separte all devices in given topology into json files per device
	 * 
	 * @param Deviceslist of devices want to convert  
	 * @return json json file to the list of deviecs converted
	 */
	json ConvertDevicesToJson(const vector<Device*>& Devices);

	/**
	 * @brief function convert device object into json onject
	 * 
	 * @param comp the object of device want to convert it
	 * @return json json file of that device
	 */
	json ConvertDeviceToJson(Device* comp);

	/**
	 * @brief Destroy the API object when end
	 * 
	 */
	~API();
};
