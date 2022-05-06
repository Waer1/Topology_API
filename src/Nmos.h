#pragma once
#include "ThreeTerminal.h"
class Nmos : public ThreeTerminal
{
public:
    Nmos(string typ, map<string, string> netList, float def, float max, float min);
    virtual void Print_Device();
    ~Nmos();

};

