#include "Money.h"
#include <iostream>

using namespace std;

int main() {

	setlocale(LC_ALL, "ru");
	cout << "������������ ������ �3. ���������� ��������." << endl << endl;

	Money product_1;
	Money product_2;
	Money product_3;
	cout << endl;
	cout << "������� ��������� ������� ������ (product_1): " << endl;
	cin >> product_1;
	cout << endl;
	cout << "������� ��������� ������� ������ (product_2): " << endl;
	cin >> product_2;
	cout << endl;
	product_3 = product_1 + product_2;
	cout << "����� �������� �������� (product_1 + product_2): " << product_3 << endl;
	cout << endl;
	product_3 = product_1 - product_2;
	cout << "�������� �������� �������� (product_1 - product_2): " << product_3 << endl;
	cout << endl;
	product_3 = product_1;
	cout << "���������� �������� (product_3 = product_1): " << product_3 << endl << endl;

	
	return 0;
}