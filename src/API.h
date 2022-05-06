#pragma once
#include <vector>
#include "topology.h"
#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include "json.hpp"
#include <iomanip>


using json = nlohmann::json;

class API
{
private:
public:
	API();
	// convert the jsoun file to tobology object;
	topology* ReadJson(string FileName);
	topology* createTopology(json jsonObject);
	vector<Device*> createListOfDevices(json jsonObject);
	Device* createDevice(const json& DeviceJson);
	Device* createNmos(const json& DeviceJson);
	Device* createPmos(const json& DeviceJson);
	Device* createResistor(const json& DeviceJson);

	//write Topology object to json file
	bool writeToJSON(string filename, const topology* Topology);
	json ConvertTopologyTojson(const topology* topo);
	json ConvertDevicesToJson(const vector<Device*>& components);
	json ConvertDeviceToJson(Device* comp);

	~API();
};
