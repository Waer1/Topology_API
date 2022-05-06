#pragma once
#include <cstdio>
#include <string>
#include <fstream>     
#include <iostream>
#include <vector>
#include "topology.h"
#include "API.h"

using namespace std;

class Controller
{
public:
	void startprogram();

private:
	API api;
	vector<topology *>TopologyList; // act as memory

	// get which service user want
	string getchoice();
	bool valid(string choice);

	// get Top ID from user and check if exist or not
	int getToplogyID();
	// get json file name from user and validate on it
	string getInputJsonFileName();
	// general purose function to get topology index in memory
	int findTopology(string topologyID) const;

	//Read a topology from a given JSON file and store it in the memory.
	void readJson();

	//Write a given topology from the memory to a JSON file.
	void WriteJson();
	pair<string, int> getOutputJsonFileName();

	//Query about which topologies are currently in the memory.
	void Querytopologies();
	//Delete a given topology from memory.
	void Deletetopology();
	bool deleteTopology(int index);

	//Query about which devices are in a given topology.
	void QueryWhichDevicesIn();
	//Query about which devices are connected to a given netlist node in a given topology.
	void whichConnected();

};

