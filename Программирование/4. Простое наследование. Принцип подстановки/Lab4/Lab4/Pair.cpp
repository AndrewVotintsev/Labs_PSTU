#include "Pair.h"
#include <iostream>

Pair::Pair()
{
	first = 0;
	second = 0;
}

Pair::Pair(int F, int S)
{
	first = F;
	second = S;
}

Pair::Pair(const Pair &other)
{
	this->first = other.first;
	this->second = other.second;
}

Pair::~Pair()
{
}

Pair& Pair::operator=(const Pair& other)
{
	this->first = other.first;
	this->second = other.second;

	return *this;
}

Pair Pair::operator+(const Pair& other)
{
	Pair sum;
	sum.first = this->first + this->second;
	sum.second = other.first + other.second;
	return sum;
}

void Pair::setFirst(int F)
{
	first = F;
}

void Pair::setSecond(int S)
{
	second = S;
}

istream & operator>>(istream & in, Pair & other)
{
	cout << "¬ведите первое число: ";
	in >> other.first;
	cout << "¬ведите второе число: ";
	in >> other.second;

	return in;
}

ostream & operator<<(ostream & out, const Pair & other)
{
	out << "First: " << other.first << endl;
	out << "Second: " << other.second << endl;

	return out;
}
