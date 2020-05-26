#pragma once
#include <iostream>
#include <Windows.h>
#include "Pair.h"

class Long : public Pair
{
public:
	Long() : Pair() {};
	Long(int F, int S) : Pair(F, S) {};
	Long(const Long&);
	Long operator + (const Long &other);
	Long operator - (const Long &other);
	Long operator * (const Long &other);
	friend ostream& operator << (ostream& out, const Long& other);
	friend istream& operator >> (istream& in, Long& other);
};

