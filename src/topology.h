#pragma once
#include "Resistance.h"
#include "Pmos.h"
#include "Nmos.h"
#include <vector>


class topology
{
private:
    string id;
    vector<Device*> Devices;
    bool ISconnectedNetList(string netListNodeID, map<string, string> netList) const;
public:
    topology(string id);
    topology(string id, const vector<Device*>& Devices);
    void setDevices(const vector<Device*>& Devices);
    void setId(string id);
    string getID() const;
    vector<Device*> getDevices() const;
    vector<Device*> getConnectedDevices(string netListNodeID) const;
    ~topology();


};

