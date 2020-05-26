#pragma once
#include <iostream>
#include <stdlib.h>

using namespace std;

struct fraction {
	double Root();
	void Read();
	void Show();
	void Init(double, double);
private:
	double first, second;
};