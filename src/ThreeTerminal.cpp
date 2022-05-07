#include "ThreeTerminal.h"

ThreeTerminal::ThreeTerminal(string id, map<string, string> netList, float defalutval, float max, float min):Device(id, netList, defalutval, max, min){}

string ThreeTerminal::getSrc() { return netList["source"]; }

string ThreeTerminal::getGate() { return netList["gate"]; }

string ThreeTerminal::getDrain() { return netList["drain"]; }

void ThreeTerminal::setSrc(string src) { netList["source"] = src; }

void ThreeTerminal::setDrain(string drain) { netList["drain"] = drain; }

void ThreeTerminal::setGate(string gate) { netList["gate"] = gate; }

ThreeTerminal::~ThreeTerminal(){}