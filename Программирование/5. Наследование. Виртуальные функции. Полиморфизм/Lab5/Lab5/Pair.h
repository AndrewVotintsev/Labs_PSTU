#pragma once
#include <iostream>
#include "Object.h"

using namespace std;

class Pair :
	public Object
{
public:
	Pair();
	Pair(int, int);
	Pair(const Pair&);
	~Pair();
	friend istream& operator >> (istream& in, Pair& other);
	friend ostream& operator << (ostream& out, const Pair& other);
	Pair& operator = (const Pair& other);
	Pair operator + (const Pair& other);
	//Селекторы
	int getFirst() { return first; };
	int getSecond() { return second; };
	//Модификаторы
	void setFirst(int);
	void setSecond(int);
	//Переопределение виртуальной функции абстрактного класса
	void Show() override;
protected:
	int first, second;

};

