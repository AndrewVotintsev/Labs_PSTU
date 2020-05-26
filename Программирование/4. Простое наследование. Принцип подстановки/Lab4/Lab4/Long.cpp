#include "Long.h"

Long::Long(const Long& other)
{
	this->first = other.first;
	this->second = other.second;
}

Long Long::operator+(const Long& other)
{
	Long sum;
	sum.first = this->first + other.first;
	sum.second = this->second + other.second;
	return sum;
}

Long Long::operator-(const Long& other)
{
	Long diff;
	diff.first = this->first - other.first;
	diff.second = this->second - other.second;
	return diff;
}

Long Long::operator*(const Long& other)
{
	Long mult;
	mult.first = this->first * other.first;
	mult.second = this->second * other.second;
	return mult;
}

ostream& operator<<(ostream& out, const Long& other)
{
	out << "Older part: " << other.first << endl;
	out << "Younger part: " << other.second << endl;

	return out;
}

istream& operator>>(istream& in, Long& other)
{
	cout << "¬ведите первое число: ";
	in >> other.first;
	cout << "¬ведите второе число: ";
	in >> other.second;

	return in;
}
