#include "API.h"

API::API()
{
}

topology * API::ReadJson(string FileName)
{
	try
	{
		ifstream file(FileName);
		json jsonObject = json::parse(file);
		if (jsonObject.empty())return nullptr;
		return createTopology(jsonObject);
	}
	catch (string err)
	{
		cout << err;
        return nullptr;
	}
}


topology* API::createTopology(json jsonObject) {
	string id = jsonObject["id"];
	vector<Device*> components = createListOfDevices(jsonObject);
	return new topology(id, components);
}

vector<Device*> API::createListOfDevices(json jsonObject) {
	vector<Device*> Devices;
    size_t n = jsonObject["components"].size();
	for (size_t i = 0; i < n; i++)
		Devices.push_back(createDevice(jsonObject["components"][i]));
	return Devices;
}

Device* API::createDevice(const json& DeviceJson) {
    string type = DeviceJson["type"];
    if (type == "resistor") {
        return createResistor(DeviceJson);
    }
    else if (type == "nmos") {
        return createNmos(DeviceJson);
    }
    else {
        return createPmos(DeviceJson);
    }
}
Device* API::createResistor(const json& DeviceJson) {
    float min, max, def;
    string id = DeviceJson["id"];
    min = DeviceJson["resistance"]["min"];
    max = DeviceJson["resistance"]["max"];
    def = DeviceJson["resistance"]["default"];
    return new Resistance(id, DeviceJson["netlist"], def, max, min);
}

Device* API::createNmos(const json& DeviceJson) {
    float min, max, def;
    string id = DeviceJson["id"];
    min = DeviceJson["m(l)"]["min"];
    max = DeviceJson["m(l)"]["max"];
    def = DeviceJson["m(l)"]["default"];
    return new Nmos(id, DeviceJson["netlist"], def, max,  min );
}

Device* API::createPmos(const json& DeviceJson) {
    float min, max, def;
    string id = DeviceJson["id"];
    min = DeviceJson["m(l)"]["min"];
    max = DeviceJson["m(l)"]["max"];
    def = DeviceJson["m(l)"]["default"];
    return new Pmos(id, DeviceJson["netlist"], def, max, min);
}

/********************************************************************/


bool API::writeToJSON(string filename, const topology* Topology)
{
    try
    {
        ofstream file(filename);
        if (!file.is_open()) {
            printf("Error: opening the file failed\n");
            return 0;
        }

        json jsonFile = ConvertTopologyTojson(Topology);
        file << setw(4) << jsonFile << endl;
        return 1;
    }
    catch (const std::exception&)
    {
        return  0;
    }
}


json API::ConvertTopologyTojson(const topology* topo) {
    json jsonFile;
    jsonFile = { {"id", topo->getID()}, ConvertDevicesToJson(topo->getDevices()) };
    return jsonFile;
}


json API::ConvertDevicesToJson(const vector<Device*>& Devices) {
    json jsonFile;
    vector<json> jsonDevices;
    for (Device* comp : Devices)
        jsonDevices.push_back(ConvertDeviceToJson(comp));

    jsonFile = { "components", jsonDevices };
    return jsonFile;
}


json API::ConvertDeviceToJson(Device* Device) {
    json jsonFile;
    string devValue;
    string type = Device->get_type();

    if (type == "resistor") devValue = "resistance";
    else if (type == "nmos" || type == "pmos") devValue = "m(l)";

    json values = { {"default", Device->get_Default()}, {"min", Device->get_min()}, {"max", Device->get_max()} };
    jsonFile = { {"type", type}, {"id", Device->get_id()}, {devValue, values}, {"netlist", Device->get_netList()} };
    return jsonFile;
}

API::~API()
{
}
