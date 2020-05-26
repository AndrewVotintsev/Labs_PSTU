#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
	//Руссификация ввода в консоль
	SetConsoleCP(1251);

	//Руссификация вывода на консоль
	SetConsoleOutputCP(1251);

	cout << "Лабораторная работа №10: Динамические массивы." << endl;
	//Кол-во строк
	int n = 1;

	//Кол-во столбцов
	int m = 1;
	printf("Введите кол-во строк массива:");
	scanf("%d", &n);
	printf("Введите кол-во столбцов массива:");
	scanf("%d", &m);

	//Если N или K меньше нуля, то исправляем это
	if (n < 2) n = 2;
	if (m < 2) m = 2;

	//Инициализация массива mass[n][m]
	int **mass = new int*[n];
	// В каждой ячейке mass создаем массив на m элементов
	for (int i = 0; i < n; i++)
		mass[i] = new int[m];

	//Заполнение массива случайными данными (-10;10)
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mass[i][j] = rand() % 21 - 10;

	//Вывод массива mass на экран
	printf("Исходный массив:\n");
	for (int i = 0, k = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%3d ", mass[i][j]);

		printf("\n");
	}

	//Номер удаляемой строки
	int delN = 0;

	printf("Введите номер строки для удаления (0,%d):", n-1);
	scanf("%d", &delN);
	//Если delN не корректно, то исправляем это
	if (delN < 0 || delN >= n) delN = 0;

	//Инициализация массива massNew[n-1][m]
	int **massNew = new int*[n - 1];
	// В каждой ячейке massNew создаем массив на m элементов
	for (int i = 0; i < n - 1; i++)
		massNew[i] = new int[m];

	//Копирования массива mass в массив massNew
	for (int i = 0, k = 0; i < n; i++)
		//кроме удаленной строки
		if (i != delN)
		{
			for (int j = 0; j < m; j++)
				massNew[k][j] = mass[i][j];
			k++;
		}

	//Вывод массива mass на экран
	printf("Новый массив:\n");
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%3d ", massNew[i][j]);

		printf("\n");
	}

	//Очистка памяти массива mass[]
	for (int i = 0; i < n; ++i)
		delete[] mass[i];
	delete[] mass;

	//Очистка памяти массива massNew[]
	for (int i = 0; i < n-1; ++i)
		delete[] massNew[i];
	delete[] massNew;

	cout << endl;
	system("pause");
	return 0;
}