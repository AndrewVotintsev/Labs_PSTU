#include "Country.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

//Создание объекта с данными о столице
Country write() {
	string c;
	int q;
	double a;

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	cout << "Введите название столицы: " << endl;
	cin >> c;
	cout << "Введите количество жителей: " << endl;
	cin >> q;
	cout << "Введите площадь: " << endl;
	cin >> a;

	Country none(c, q, a);

	return none;
}

//Вывод данных объекта
void print(Country c) {
	c.show();
}

int main() {

	setlocale(LC_ALL, "ru");

	cout << "Лабораторная работа №2. Классы и объекты, использование конструкторов." << endl << endl;

	cout << "Программный код: \"Country russia;\"" << endl;
	Country russia;
	russia.show();
	cout << endl;

	cout << "Программный код: \"Country australia(\"Сидней\", 2000000, 152.3);\"" << endl;
	Country australia("Сидней", 2000000, 152.3);
	australia.show();
	cout << endl;

	cout << "Программный код: \"Country england = australia;\"" << endl;
	Country england = australia;
	england.show();
	cout << endl;
	england.setName("Лондон");
	england.setQuantity(1000500);
	england.setArea(1000.562);

	cout << "Программный код: \"print(england);\"" << endl;
	print(england);
	cout << endl;

	cout << "Программный код: \"russia = write();\"" << endl;
	russia = write();
	russia.show();
	cout << endl;

	return 0;
}