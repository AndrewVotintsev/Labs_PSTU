#include<iostream>

using namespace std;

void min(int num, ...)
{
	int *vall = &num;
	int min = *(++vall);
	
	for (int i = num; i > 0 ; i--)
	{
		if (*(vall) < min)
		{
			min = *(vall);
			++vall;
		}

		else
		{
			++vall;
		}
	}
	cout << min << endl;
}

void main ()
{
	setlocale(LC_ALL, "ru");
	cout << "ћинимальное число типа int из 5 параметров: ";
	min(5, 22, 203, 9, 56, 23);
	cout << "\n\n";
	cout << "ћинимальное число типа int из 12 параметрв: ";
	min(12, 2, 3, 12, 36, 5, 98, 4, 1, 25, 3, 72, 9);
	cout << "\n\n";
	cout << "ћинимальное число типа int из 10 параметров: ";
	min(10, 32, 125, 66, 502, 39, 217, 29, 53, 96, 210);
	cout << "\n\n";
	system("pause");

}