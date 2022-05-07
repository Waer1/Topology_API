#pragma once
/**
 * @file topology.h
 * @author your name (you@domain.com)
 * @brief this class hold the topologies which is vector of Devices and its unique id 
 * its the main purpose of program is to store and deal with topologies
 * @version 0.1
 * @date 2022-05-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "Resistance.h"
#include "Pmos.h"
#include "Nmos.h"
#include <vector>

/**
 * @brief this class hold the topologies which is vector of Devices and its unique id 
 * 
 */
class topology
{
private:
/**
 * @brief id of the topology
 * 
 */
    string id;
    /**
     * @brief 
     * vector of Devices in this topology
     */
    vector<Device*> Devices;
public:
/**
 * @brief Construct a new empty topology object
 * 
 * @param id the id of this object
 */
    topology(string id);
/**
 * @brief Construct a new topology object given its id and its set of Devices
 * 
 * @param id the id of this object
 * @param Devices set of Devices
 */
    topology(string id, const vector<Device*>& Devices);
    /**
     * @brief Set the vector of Devices
     * 
     * @param Devices 
     */
    void setDevices(const vector<Device*>& Devices);
    /**
     * @brief Set the Id object
     * 
     * @param id 
     */
    void setId(string id);
    /**
     * @brief getID object
     * 
     * @return string 
     */
    string getID() const;
    /**
     * @brief Get the Devices object
     * 
     * @return vector<Device*> 
     */
    vector<Device*> getDevices() const;
    /**
     * @brief Get the Connected Devices object
     * 
     * @param netListNodeID the net list of searched devices
     * @return vector<Device*> the connected devices
     */
    vector<Device*> getConnectedDevices(string netListNodeID) const;
    /**
     * @brief 
     * 
     * @param netListNodeID Device id you want to search for
     * @param netList the vector of devices that search on it
     * @return true 
     * @return false 
     */
    bool ISconnectedNetList(string netListNodeID, map<string, string> netList) const;
    /**
     * @brief Destroy the topology object
     * 
     */
    ~topology();


};

