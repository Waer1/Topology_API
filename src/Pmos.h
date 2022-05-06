#pragma once
#include "ThreeTerminal.h"
class Pmos :
    public ThreeTerminal
{
public:
    Pmos(string typ, map<string, string> netList, float def, float max, float min);
    virtual void Print_Device();
    ~Pmos();

};