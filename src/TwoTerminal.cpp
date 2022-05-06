#include "TwoTerminal.h"

TwoTerminal::TwoTerminal(string id, map<string, string> netList, float defalutval, float max, float min):Device(id,netList, defalutval,max , min )
{
}

string TwoTerminal::getT1()
{
	 return netList["t1"];;
}

string TwoTerminal::getT2()
{
	return netList["t2"];
}

void TwoTerminal::setT1(string t1)
{
	netList["t1"] = t1;
}

void TwoTerminal::setT2(string t2)
{
	netList["t2"] = t2;
}
