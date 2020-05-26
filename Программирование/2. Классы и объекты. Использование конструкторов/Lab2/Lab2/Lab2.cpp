#include "Country.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

//�������� ������� � ������� � �������
Country write() {
	string c;
	int q;
	double a;

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	cout << "������� �������� �������: " << endl;
	cin >> c;
	cout << "������� ���������� �������: " << endl;
	cin >> q;
	cout << "������� �������: " << endl;
	cin >> a;

	Country none(c, q, a);

	return none;
}

//����� ������ �������
void print(Country c) {
	c.show();
}

int main() {

	setlocale(LC_ALL, "ru");

	cout << "������������ ������ �2. ������ � �������, ������������� �������������." << endl << endl;

	cout << "����������� ���: \"Country russia;\"" << endl;
	Country russia;
	russia.show();
	cout << endl;

	cout << "����������� ���: \"Country australia(\"������\", 2000000, 152.3);\"" << endl;
	Country australia("������", 2000000, 152.3);
	australia.show();
	cout << endl;

	cout << "����������� ���: \"Country england = australia;\"" << endl;
	Country england = australia;
	england.show();
	cout << endl;
	england.setName("������");
	england.setQuantity(1000500);
	england.setArea(1000.562);

	cout << "����������� ���: \"print(england);\"" << endl;
	print(england);
	cout << endl;

	cout << "����������� ���: \"russia = write();\"" << endl;
	russia = write();
	russia.show();
	cout << endl;

	return 0;
}