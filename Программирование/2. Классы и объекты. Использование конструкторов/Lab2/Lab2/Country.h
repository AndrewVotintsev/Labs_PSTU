#pragma once
#include <iostream>

using namespace std;

class Country
{
	string capital;
	int	quantity;
	double area;

	public:
		Country();
		Country(string, int, double);
		Country(const Country&);
		~Country();
		void setName(string N);
		int getQuantity();
		void setQuantity(int);
		double getArea();
		void setArea(double);
		void show();
};

