#pragma once
#include "Device.h"
class TwoTerminal :
    public Device
{
public:
    TwoTerminal(string id, map<string, string> netList, float defalutval, float max, float min);
    string getT1();
    string getT2();
    void setT1(string t1);
    void setT2(string t2);
};

