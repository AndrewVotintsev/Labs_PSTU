#include "fraction.h"

//Нахождение решения линейного уравнения
double fraction::Root()
{
	/*Проверка на валидность данных*/
	if (first == 0) {
		cout << "\nПеременная A не может ровняться нолю!!!" << endl << endl;
		exit(0);
	}
	else {
		return -second/first;
	}
}

//Инициализация переменных
void fraction::Init(double F, double S)
{
	first = F;
	second = S;
}

//Ввод переменных из консоли
void fraction::Read() {
	cout << "Переменная A: ";
	cin >> first;
	cout << "Переменная B: ";
	cin >> second;
}

//Вывод переменных в консоль
void fraction::Show()
{
	cout << "first: " << first << endl;
	cout << "second: " << second << endl;
}
