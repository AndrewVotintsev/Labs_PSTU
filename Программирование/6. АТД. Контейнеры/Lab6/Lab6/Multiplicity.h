#pragma once
#include <iostream>

using namespace std;

class Iterator
{
	friend class Multiplicity;
	int* elem;

public:
	Iterator() { elem = 0; }
	Iterator(const Iterator& it) { elem = it.elem; }

	bool operator == (const Iterator& it) { return elem == it.elem; }
	bool operator != (const Iterator& it) { return elem != it.elem; }

	void operator ++ (int) { ++elem; }
	void operator -- (int) { --elem; }
	int& operator * () const { return *elem; }
};


class Multiplicity
{
public:
	Multiplicity();
	Multiplicity(int s, int k = 0);
	Multiplicity(const Multiplicity&object);
	~Multiplicity();
	friend ostream& operator << (ostream& out, const Multiplicity& object);
	friend istream& operator >> (istream& in, Multiplicity& object);
	Multiplicity& operator = (const Multiplicity& object);
	Multiplicity operator + (const Multiplicity& object);
	int& operator [] (int index);
	int operator () ();
	Iterator first();
	Iterator last();
private:
	int size;
	int* arr;
	Iterator beg;
	Iterator end;
};

