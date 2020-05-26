#include <iostream>
#include "Multiplicity.h"

using namespace std;

int main() {

	setlocale(LC_ALL, "ru");

	int powerA;
	int powerB;

	cout << "������� ��������� ��������� A:" << endl;
	cin >> powerA;
	Multiplicity A(powerA);
	cout << "������� ����� ������������� ��������� �:" << endl;
	cin >> A;

	cout << "������� ��������� ��������� B:" << endl;
	cin >> powerB;
	Multiplicity B(powerB);
	cout << "������� ����� ������������� ��������� B:" << endl;
	cin >> B;

	Multiplicity C;
	C = A + B;

	cout << "�������� ������� ���������: " << A << endl;
	cout << "��� ���������: " << A() << endl;
	cout << endl;
	cout << "�������� ������� ���������: " << B << endl;
	cout << "��� ���������: " << B() << endl;
	cout << endl;
	cout << "��������� ����������� ��������: " << C << endl;
	cout << "��������� ����������� ���������: " << C() << endl;
	cout << endl;

	int index;
	cout << "������� ������ �������� �� ���������� ���������: ";
	cin >> index;
	cout << "������ �� ������� " << index << ": " << C[index] << endl;
	cout << endl;

	cout << "������� �������� ��������� � ������� ������ ���������: " << endl;
	int k = 1;

	for (Iterator i = C.first(); i != C.last(); i++)
	{
		cout << k++ << ". " << *i << endl;
	}

	return 0;
}