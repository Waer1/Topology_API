#pragma once
#include "Device.h"
class ThreeTerminal :
    public Device
{
public:
    ThreeTerminal(string id, map<string, string> netList, float defalutval, float max, float min);
    string getSrc();
    string getDrain();
    string getGate();
    void setSrc(string src);
    void setGate(string gate);
    void setDrain(string drain);
};

