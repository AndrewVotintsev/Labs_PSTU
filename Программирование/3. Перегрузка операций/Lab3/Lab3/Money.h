#pragma once
#include <fstream>

using namespace std;

class Money
{

	long rub;
	int cop;
public:

	Money();
	Money(long, int);
	Money(const Money &other);
	Money &operator = (const Money &other);
	Money operator + (const Money &other);
	Money operator - (const Money &other);
	friend ostream& operator << (ostream &out, const Money &other);
	friend istream& operator >> (istream & in, Money & other);
	~Money();

	void setVlues(long R, int C);
	void showVlues();
};
