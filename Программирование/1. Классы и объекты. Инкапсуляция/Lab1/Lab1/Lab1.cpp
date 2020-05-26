#include <iostream>
#include <stdlib.h>
#include "fraction.h"

using namespace std;

//������� �������, ��� ��������� ��������� ��� ���������
fraction make_fraction(double first, double second) {
	/*���������� ������ ��������� � ������ �� �������� ������*/
	if (first == 0) {
		printf("���������� A �� ����� ��������� ����!!!");
		exit(0);
	}
	fraction t;
	t.Init(first, second);
	return t;
}

int main() {
	setlocale(LC_ALL, "ru");

	cout << "������������ ������ �1. ������ � �������, ������������." << endl << endl;

	cout << "�������� ��������� ����: y=Ax+B" << endl;
	fraction line;
	fraction twoLine;
	double A, B;
	
	line.Read();

	cout << endl;
	cout << "����� ����� ���������: " << endl;

	line.Show();
	cout << endl;
	cout << "�����: " << endl;
	cout << "������ x=" << line.Root() << endl;

	cout << endl;
	cout << "������� �����: " << endl;
	cout << "���������� A: ";
	cin >> A;
	cout << "���������� B: ";
	cin >> B;

	twoLine = make_fraction(A, B);
	cout << endl;
	cout << "����� ����� ���������: " << endl;
	twoLine.Show();
	cout << endl;
	cout << "�����: " << endl;
	cout << "������ x=" << twoLine.Root() << endl;
	return 0;
}