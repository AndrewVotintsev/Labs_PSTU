#include "Money.h"
#include <fstream>
#include <iostream>
#include <cmath>



Money::Money()
{
	rub = cop = 0;
	cout << "Вызвался конструктор без параметров\t" << this << endl;

}

Money::Money(long R, int C)
{
	rub = R;
	cop = C;
	cout << "Вызвался конструктор с параметрами\t" << this << endl;

}

Money::Money(const Money & other)
{
	cout << "Вызвался конструктор копирования\t" << this << endl;

	this->cop = other.cop;
	this->rub = other.rub;
}

Money &Money::operator=(const Money & other)
{
	cout << "Вызвался оператор =" << endl;
	this->rub = other.rub;
	this->cop = other.cop;
	return *this;
}

Money Money::operator+(const Money & other)
{
	cout << "Вызвался оператор +" << endl;
	
	Money sum;
	sum.rub = this->rub + other.rub;
	sum.cop = this->cop + other.cop;
	
	return sum;
}

Money Money::operator-(const Money & other)
{
	cout << "Вызвался оператор -" << endl;
	Money diff;
	double minuend = this->rub + ((double)this->cop / 100);
	double subtrahend = other.rub + ((double)other.cop / 100);
	double different = minuend - subtrahend;
	double i;
	double f = modf(different, &i);
	diff.rub = (long)i;
	diff.cop = (int)(f * ((f < 0) ? -100 : 100));
	return diff;
}

Money::~Money()
{
	cout << "Вызвался деструктор\t" << this << endl;

}

void Money::setVlues(long R, int C)
{
	rub = R;
	cop = C;
}

void Money::showVlues()
{
	cout << rub << "," << cop << endl;
}

ostream & operator<<(ostream & out, const Money & other)
{
	cout << "(Вызвался оператор <<) ";

	out << other.rub << "," << other.cop;
	return out;
}

istream & operator>>(istream & in, Money & other)
{
	cout << "Вызвался оператор >>" << endl;
	cout << "Рубли: ";
	in >> other.rub;
	cout << "Копейки: ";
	in >> other.cop;
	return in;
}
