#include "topology.h"

bool topology::ISconnectedNetList(string netListNodeID, map<string, string> netList) const
{
	for (auto node : netList)
		if (node.second == netListNodeID)
			return 1;
	return 0;

}

topology::topology(string id)
{
	this->id = id;
}

topology::topology(string id, const vector<Device*>& Devices)
{
	this->id = id;
	setDevices(Devices);
}

void topology::setDevices(const vector<Device*>& Devices)
{
	for (Device * dev : Devices) {
		if (dynamic_cast<Resistance*>(dev))
			this->Devices.push_back(new Resistance(dev->get_id(), dev->get_netList(), dev->get_Default(), dev->get_max(),dev->get_min()));
		else if (dynamic_cast<Pmos*>(dev))
			this->Devices.push_back(new Pmos(dev->get_id(), dev->get_netList(), dev->get_Default(), dev->get_max(), dev->get_min()));
		else
			this->Devices.push_back(new Nmos(dev->get_id(), dev->get_netList(), dev->get_Default(), dev->get_max(), dev->get_min()));
	}
}

void topology::setId(string id)
{
	this->id = id;
}

string topology::getID() const
{
	return this->id;
}

vector<Device*> topology::getDevices() const
{
	return this->Devices;
}

vector<Device*> topology::getConnectedDevices(string netListNodeID) const
{
	vector<Device*> result;
	for (auto component : Devices) {
		map<string, string> netList = component->get_netList();
		if (this->ISconnectedNetList(netListNodeID, netList))
			result.push_back(component);
	}
	return result;
}

topology::~topology()
{
	for (auto& device : this->Devices)
	{
		delete device;
		device = nullptr;
	}
	this->Devices.clear();
}
