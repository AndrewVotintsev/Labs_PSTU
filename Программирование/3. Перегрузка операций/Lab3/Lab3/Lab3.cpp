#include "Money.h"
#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "ru");
	cout << "Лабораторная работа №3. Перегрузка операций." << endl << endl;

	Money product_1;
	Money product_2;
	Money product_3;
	cout << endl;
	cout << "Введите стоимость первого товара (product_1): " << endl;
	cin >> product_1;
	cout << endl;
	cout << "Введите стоимость второго товара (product_2): " << endl;
	cin >> product_2;
	cout << endl;
	product_3 = product_1 + product_2;
	cout << "Сумма введеных значений (product_1 + product_2): " << product_3 << endl;
	cout << endl;
	product_3 = product_1 - product_2;
	cout << "Разность введеных значений (product_1 - product_2): " << product_3 << endl;
	cout << endl;
	product_3 = product_1;
	cout << "Присвоение значения (product_3 = product_1): " << product_3 << endl << endl;

	
	return 0;
}