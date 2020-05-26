#pragma once
#include <iostream>

using namespace std;

class Pair
{
public:
	Pair();
	Pair(int, int);
	Pair(const Pair&);
	~Pair();
	friend istream& operator >> (istream &in, Pair &other);
	friend ostream& operator << (ostream &out,const Pair &other);
	Pair& operator = (const Pair &other);
	Pair operator + (const Pair &other);
	//Селекторы
	int getFirst() { return first; };
	int getSecond() { return second; };
	//Модификаторы
	void setFirst(int);
	void setSecond(int);
protected:
	int first, second;

};

