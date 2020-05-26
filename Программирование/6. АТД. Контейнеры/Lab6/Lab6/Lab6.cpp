#include <iostream>
#include "Multiplicity.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "ru");

	int powerA;
	int powerB;

	cout << "Введите мощьность множества A:" << endl;
	cin >> powerA;
	Multiplicity A(powerA);
	cout << "Введите числа принадлежащие множеству А:" << endl;
	cin >> A;

	cout << "Введите мощьность множества B:" << endl;
	cin >> powerB;
	Multiplicity B(powerB);
	cout << "Введите числа принадлежащие множеству B:" << endl;
	cin >> B;

	Multiplicity C;
	C = A + B;

	cout << "Элементы первого множества: " << A << endl;
	cout << "Его мощьность: " << A() << endl;
	cout << endl;
	cout << "Элементы второго множества: " << B << endl;
	cout << "Его мощьность: " << B() << endl;
	cout << endl;
	cout << "Результат объединения множеств: " << C << endl;
	cout << "Мощьность полученного множества: " << C() << endl;
	cout << endl;

	int index;
	cout << "Введите индекс элемента из последнего множества: ";
	cin >> index;
	cout << "Данные по индексу " << index << ": " << C[index] << endl;
	cout << endl;

	cout << "Выводим елементы множества с помощью класса итератора: " << endl;
	int k = 1;

	for (Iterator i = C.first(); i != C.last(); i++)
	{
		cout << k++ << ". " << *i << endl;
	}

	return 0;
}