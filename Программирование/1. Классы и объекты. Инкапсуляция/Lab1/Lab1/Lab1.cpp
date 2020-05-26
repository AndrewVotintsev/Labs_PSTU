#include <iostream>
#include <stdlib.h>
#include "fraction.h"

using namespace std;

//Внешняя функция, для получения структуры как результат
fraction make_fraction(double first, double second) {
	/*Завершение работы программы в случае не валидных данных*/
	if (first == 0) {
		printf("Переменная A не может ровняться нолю!!!");
		exit(0);
	}
	fraction t;
	t.Init(first, second);
	return t;
}

int main() {
	setlocale(LC_ALL, "ru");

	cout << "Лабораторная работа №1. Классы и объекты, инкапсуляция." << endl << endl;

	cout << "Линейное уравнение вида: y=Ax+B" << endl;
	fraction line;
	fraction twoLine;
	double A, B;
	
	line.Read();

	cout << endl;
	cout << "Вывод полей структуры: " << endl;

	line.Show();
	cout << endl;
	cout << "Ответ: " << endl;
	cout << "Корень x=" << line.Root() << endl;

	cout << endl;
	cout << "Внешний метод: " << endl;
	cout << "Переменная A: ";
	cin >> A;
	cout << "Переменная B: ";
	cin >> B;

	twoLine = make_fraction(A, B);
	cout << endl;
	cout << "Вывод полей структуры: " << endl;
	twoLine.Show();
	cout << endl;
	cout << "Ответ: " << endl;
	cout << "Корень x=" << twoLine.Root() << endl;
	return 0;
}