#include "Nmos.h"

Nmos::Nmos(string typ, map<string, string> netList, float def, float max, float min):ThreeTerminal(typ, netList, def, max, min)
{
	this->set_type("Nmos");
}

void Nmos::Print_Device()
{
	cout << "Nmos : " << this->get_id() << endl;
	Device::Print_Device();
	cout << endl;
}

Nmos::~Nmos()
{
}

