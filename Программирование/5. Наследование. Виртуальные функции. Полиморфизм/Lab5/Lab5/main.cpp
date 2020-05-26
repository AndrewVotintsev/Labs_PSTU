#include "Pair.h"
#include "Long.h"
#include "Vector.h"
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	printf("Лабораторная работа №5. Наследование, виртуальные функции, полиморфизм.\n\n");

	Vector v(2);
	printf("Введите пару чисел типа Pair\n");
	Pair a;
	cin >> a;
	printf("\nВведите пару чисел типа Long\n");
	Long b;
	cin >> b;
	Object* p = &a;
	v.Add(p);
	p = &b;
	v.Add(p);
	printf("\nВывод результатов:\n");
	cout << v;

	return 0;
}