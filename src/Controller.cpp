#include "Controller.h"

/*
input file name : topology.json
Out.json
*/


bool Controller::deleteTopology(int index) {
	try
	{
	auto it = TopologyList.begin();
	advance(it, index);
	TopologyList.erase(it);
	return 1;
	}
	catch (const std::exception&)
	{
		return 0;
	}
}

int Controller::findTopology(string topologyID) const {
	for (int i = 0, n = TopologyList.size(); i < n; i++)
		if (TopologyList[i]->getID() == topologyID)
			return i;
	return -1;
}

std::string Controller::getInputJsonFileName() {
	string fileName;
	bool flag;
	while (1) {
		flag = 1;
		printf("Enter input file (.json extension): ");
		cin >>fileName;
		if (fileName.find(".json") == string::npos) flag = 0;
		ifstream file;
		file.open(fileName, fstream::in);
		if (!file.is_open())flag = 0;
		file.close();
		if (flag) return fileName;
		system("CLS");
		printf("wrong Filename please write valide one \n");
	}
}

int Controller::getToplogyID() {
	string TopID;
	bool flag;
	int id;
	while (1) {
		flag = 1;
		printf("\nEnter Topology ID: ");
		cin >> TopID;
		id = findTopology(TopID);
		if (id == -1 ) flag = 0;
		if (flag) return id;
		system("CLS");
		printf("or No such topology in memory \n");
	}
}

pair<string,int> Controller::getOutputJsonFileName() {
	return { getInputJsonFileName() , getToplogyID() };
}

void Controller::readJson()
{
	string fileName = getInputJsonFileName();
	topology * in = api.ReadJson(fileName);
	if (in != nullptr) {
		printf("Successfully read from JSON\n");
		TopologyList.push_back(in);
	}
	else
	{
		printf("Fail To REad from JSON\n");
	}
}

void Controller::WriteJson()
{
	pair <string, int> filename_TopID;
	filename_TopID = getOutputJsonFileName();
	if (api.writeToJSON(filename_TopID.first, TopologyList[filename_TopID.second])) 
		printf("Successfully converted to JSON\n");
	else
		printf("Fail To Write To JSON\n");
}

void Controller::Querytopologies()
{
	for (int i = 0, count = TopologyList.size(); i < count; i++)
		cout << "Topology ID: " << TopologyList[i]->getID() << "\n";
}

void Controller::Deletetopology()
{
	int index = getToplogyID();
	cout << (deleteTopology(index) ? "Succesfully Deleted\n" : "Failde Deletion\n");
}

void Controller::QueryWhichDevicesIn()
{
	int index = getToplogyID();
	vector<Device*> components = TopologyList[index]->getDevices();
	if (components.size() > 0) {
		int count = components.size();
		printf("Devices in given topology: %d \n", count);
		for (auto com : components)
			com->Print_Device();
	}
}


void Controller::whichConnected()
{
	int index = getToplogyID();
	string nodeID;
	cout << "Enter Node ID: ";
	cin >> nodeID;	
	vector<Device*> Devices = TopologyList[index]->getConnectedDevices(nodeID);
	if (Devices.size() > 0) {
		int count = Devices.size();
		printf("Connected devices : %d \n" ,count );
		for (auto com : Devices)
			com->Print_Device();
	}
}

void Controller::startprogram()
{
	while (1)
	{
		int choice = stoi(getchoice());
		if (choice == 7) break;
		switch (choice)
		{
		case 1:readJson(); break;
		case 2:WriteJson(); break;
		case 3:Querytopologies(); break;
		case 4:Deletetopology(); break;
		case 5:QueryWhichDevicesIn(); break;
		case 6:whichConnected(); break;
		default:break;
		}
	}
	printf("program has finsih noramllly");
}

string Controller::getchoice()
{
	while(1) {
		string choice;
		printf("\nplease choice one of the following \n");
		printf("1) Read From Json file\n");
		printf("2) Write TO Json file\n");
		printf("3) Print All Topologies\n");
		printf("4) Delete Topology\n");
		printf("5) Get Devices To Topology\n");
		printf("6) Get Devices connected in a net list\n");
		printf("7) Exit\n");
		
		cin >> choice;
		system("CLS");
		if (valid(choice)) return choice;
		printf("wrong choice plese choice valide one \n");
	};

}

bool Controller::valid(string choice)
{
	if (choice == "1" || choice == "2" || choice == "3" || choice == "4" || choice == "5" || choice == "6" || choice == "7")
		return 1;
	return 0;
}
