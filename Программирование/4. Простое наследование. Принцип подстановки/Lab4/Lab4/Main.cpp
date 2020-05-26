#include "Long.h"
#include "Pair.h"
#include <iostream>

using namespace std;

void f1(Pair& g) {
	int first;
	cout << "Введите первое число: ";
	cin >> first;
	g.setFirst(first);
	cout << g;
}

Pair f2() {
	int first, second;

	cout << "Введите первое число: ";
	cin >> first;
	cout << "Введите второе число: ";
	cin >> second;
	Long l(first, second);
	return l;
}

int main() {
	setlocale(LC_ALL, "ru");

	cout << "Лабораторная работа №4. Простое наследование, принцип подстановки." << endl << endl;

	int first, second;

	Pair d;
	cin >> d;
	cout << d << endl;

	cout << "Введите первое число: ";
	cin >> first;
	cout << "Введите второе число: ";
	cin >> second;
	Pair f(first, second);
	cout << f << endl;

	cout << "Операция сложения класса Pair:" << endl;
	Pair e;
	e = d + f;
	cout << e << endl;

	cout << "Присвоение полученных значений операции сложения в первый объект:" << endl;
	d = e;
	cout << d << endl;

	cout << "\nРабота с числами типа Long:\n" << endl;

	Long k;
	cin >> k;
	cout << k << endl;

	cout << "Введите первое число: ";
	cin >> first;
	cout << "Введите второе число: ";
	cin >> second;
	Long o(first, second);
	cout << o << endl;

	Long q;
	cout << "Переопределенная операция сложения для класса Long:" << endl;
	q = k + o;
	cout << q << endl;
	cout << "Операция умножения для класса Long:" << endl;
	q = k * o;
	cout << q << endl;
	cout << "Операция вычитания для класса Long:" << endl;
	q = k - o;
	cout << q << endl;

	cout << "Заменяем поле first:" << endl;
	f1(q);
	cout << endl;
	
	cout << "Принцип подстановки:" << endl;
	d = f2();
	cout << d << endl;

	return 0;
}