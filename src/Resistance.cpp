#include "Resistance.h"

Resistance::Resistance(string id, map<string, string> netList, float def, float max, float min) :TwoTerminal(id, netList, def, max, min)
{
    this->set_type("Resistance");
}

void Resistance::Print_Device()
{
	cout << "Resistance : " << get_type() << endl;
	Device::Print_Device();
	cout << endl;

}

Resistance::~Resistance()
{
}
