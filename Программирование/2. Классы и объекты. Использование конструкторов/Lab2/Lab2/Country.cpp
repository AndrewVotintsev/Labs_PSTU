#include "Country.h"
#include <iostream>
#include <string>

using namespace std;

Country::Country()
{
	capital = "";
	quantity = 0;
	area = 0;
	cout << "Вызвался конструктор без параметров\t" << this << endl;
}

Country::Country(string C, int Q, double A)
{
	capital = C;
	quantity = Q;
	area = A;
	cout << "Вызвался конструктор с параметрами\t" << this << endl;
}

Country::Country(const Country &c)
{
	capital = c.capital;
	quantity = c.quantity;
	area = c.area;
	cout << "Вызвался конструктор копирования\t" << this << endl;
}

Country::~Country()
{
	cout << "Вызвался деструктор\t" << this << endl;
}

void Country::setName(string N)
{
	capital = N;
}

int Country::getQuantity()
{
	return quantity;
}

void Country::setQuantity(int Q)
{
	quantity = Q;
}

double Country::getArea()
{
	return area;
}

void Country::setArea(double A)
{
	area = A;
}

void Country::show()
{
	cout << "Столица\t" << capital << endl;
	cout << "Площадь\t" << area << endl;
	cout << "Количество\t" << quantity << endl;
}
