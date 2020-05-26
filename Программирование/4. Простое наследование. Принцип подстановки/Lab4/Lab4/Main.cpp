#include "Long.h"
#include "Pair.h"
#include <iostream>

using namespace std;

void f1(Pair& g) {
	int first;
	cout << "������� ������ �����: ";
	cin >> first;
	g.setFirst(first);
	cout << g;
}

Pair f2() {
	int first, second;

	cout << "������� ������ �����: ";
	cin >> first;
	cout << "������� ������ �����: ";
	cin >> second;
	Long l(first, second);
	return l;
}

int main() {
	setlocale(LC_ALL, "ru");

	cout << "������������ ������ �4. ������� ������������, ������� �����������." << endl << endl;

	int first, second;

	Pair d;
	cin >> d;
	cout << d << endl;

	cout << "������� ������ �����: ";
	cin >> first;
	cout << "������� ������ �����: ";
	cin >> second;
	Pair f(first, second);
	cout << f << endl;

	cout << "�������� �������� ������ Pair:" << endl;
	Pair e;
	e = d + f;
	cout << e << endl;

	cout << "���������� ���������� �������� �������� �������� � ������ ������:" << endl;
	d = e;
	cout << d << endl;

	cout << "\n������ � ������� ���� Long:\n" << endl;

	Long k;
	cin >> k;
	cout << k << endl;

	cout << "������� ������ �����: ";
	cin >> first;
	cout << "������� ������ �����: ";
	cin >> second;
	Long o(first, second);
	cout << o << endl;

	Long q;
	cout << "���������������� �������� �������� ��� ������ Long:" << endl;
	q = k + o;
	cout << q << endl;
	cout << "�������� ��������� ��� ������ Long:" << endl;
	q = k * o;
	cout << q << endl;
	cout << "�������� ��������� ��� ������ Long:" << endl;
	q = k - o;
	cout << q << endl;

	cout << "�������� ���� first:" << endl;
	f1(q);
	cout << endl;
	
	cout << "������� �����������:" << endl;
	d = f2();
	cout << d << endl;

	return 0;
}