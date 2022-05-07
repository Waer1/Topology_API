#pragma once
/**
 * @file Controller.h
 * @author Yousef Alwaer (elwaeryousef@gmail.com)
 * @brief this file is the controller of whole processes in the libratay 
 * -take the inputs from the user and check validation of this inputs
 * - do suitable action due to its input like redirect request to API file if will treat wiel json as in or out 
 * - preview any thing directly from memory
 * @version 0.3
 * @date 2022-05-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "API.h"

using namespace std;

/**
 * @brief controller class which have all flow control function of the program
 * 
 */
class Controller
{
public:

	/**
	 * @brief start the main program
	 * 			
	 */
	Controller();

	void startprogram();

private:

	/**
	 * @brief object from abi class to call it function when need treat with in/out json files
	 * 
	 */
	API api;
	


	/**
	 * @brief TopologyList act as memory of the device while hold the converted json files from reading 
	 * 
	 */
	vector<topology *>TopologyList; // act as memory

	// get which service user want

	/**
	 * @brief function to get the user choice and validate on input 
	 * - its make it stick in while loop till chose correct choice
	 * 
	 * @return string correct user choice
	 */
	string getchoice();

	/**
	 * @brief function to check the validation of user input 
	 * if inout between 0 and 7 its correct else output wrong msg and request rfom user other valid input
	 * 
	 * @param choice the input from user
	 * @return true if valid coice
	 * @return false if invalid choice
	 */
	bool valid(string choice);

	/**
	 * @brief Get the get Toplogy ID from user and check if exist or not
	 * by calling other function that iterate throw the tobology list
	 * 
	 * @return int if found will return i (index of the topology) if not found will return -1
	 */
	int getToplogyID();

	// 
	/**
	 * @brief get json file name from user and validate on it
	 * by chick its alreay created or not and user doent enter empty ot non json file
	 * 
	 * @return string the file name.json
	 */
	string getInputJsonFileName();


	// 
	/**
	 * @brief general purose function to get topology index in memory
	 * 
	 * @param topologyID the string is of searched topology
	 * @return int if found will return i (index of the topology) if not found will return -1
	 */
	int findTopology(string topologyID) const;

	/**
	 * @brief Read a topology from a given JSON file and store it in the memory.
	 * by calling api.readjson with the input name
	 */
	void readJson();

	/**
	 * @brief 
	 * Write a given topology from the memory to a JSON file by calling api.write with the input name and the topology
	 */
	void WriteJson();

	/**
	 * @brief Get the Output Json File Name object 
	 * simple functionget the file name and topolgy id by ohter function and return a pair of them
	 * 
	 * @return pair<string, int> <filename , topologyID>
	 */
	pair<string, int> getOutputJsonFileName();

	/**
	 * @brief Query about which topologies are currently in the memory
	 * 	printing all topologyes id from memory
	 * 
	 */
	void Querytopologies();

	/**
	 * @brief 
	 * Delete a given topology from memory after take the topology name from user and validate on it 
	 */
	void Deletetopology();
	/**
	 * @brief delete specific location in topologylist
	 * 
	 * @param index index of deleted topology
	 * @return true if deleted successfully
	 * @return false and not found or any exception
	 */
	bool deleteTopology(int index);

	//.
	/**
	 * @brief printout the devices connected in some topologies
	 * Query about which devices are in a given topology
	 */
	void QueryWhichDevicesIn();

	/**
	 * @brief Query about which devices are connected to a given netlist node in a given topology.
	 * 
	 */
	void whichConnected();

};

