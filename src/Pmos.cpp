#include "Pmos.h"

Pmos::Pmos(string typ, map<string, string> netList, float def, float max, float min) :ThreeTerminal(typ, netList, def, max, min)
{
    this->set_type("Pmos");
}

void Pmos::Print_Device()
{
	cout << "Pmos : " << this->get_id() << endl;
	Device::Print_Device();
	cout << endl;
}

Pmos::~Pmos()
{
}
