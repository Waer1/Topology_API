#pragma once
#include "TwoTerminal.h"
class Resistance :
    public TwoTerminal
{
public:
    Resistance(string id, map<string, string> netList, float def, float max, float min);
    virtual void Print_Device();
    ~Resistance();

};

