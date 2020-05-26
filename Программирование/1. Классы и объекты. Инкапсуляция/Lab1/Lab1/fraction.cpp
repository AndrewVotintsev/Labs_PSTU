#include "fraction.h"

//���������� ������� ��������� ���������
double fraction::Root()
{
	/*�������� �� ���������� ������*/
	if (first == 0) {
		cout << "\n���������� A �� ����� ��������� ����!!!" << endl << endl;
		exit(0);
	}
	else {
		return -second/first;
	}
}

//������������� ����������
void fraction::Init(double F, double S)
{
	first = F;
	second = S;
}

//���� ���������� �� �������
void fraction::Read() {
	cout << "���������� A: ";
	cin >> first;
	cout << "���������� B: ";
	cin >> second;
}

//����� ���������� � �������
void fraction::Show()
{
	cout << "first: " << first << endl;
	cout << "second: " << second << endl;
}
