#pragma once
#include "Main.h"

class Test
{
private:
	string name2;
	string test_nm;
public:
	Test() : name2(""), test_nm("") {}
	Test(string name2, string test_nm) : name2(name2), test_nm(test_nm) {}

	void Setname2(string nm) { this->name2 = nm; }
	void TestChoice();
};