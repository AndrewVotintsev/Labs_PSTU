#include "Pair.h"
#include "Long.h"
#include "Vector.h"
#include <iostream>

using namespace std;

int main() {
	setlocale(LC_ALL, "ru");

	printf("������������ ������ �5. ������������, ����������� �������, �����������.\n\n");

	Vector v(2);
	printf("������� ���� ����� ���� Pair\n");
	Pair a;
	cin >> a;
	printf("\n������� ���� ����� ���� Long\n");
	Long b;
	cin >> b;
	Object* p = &a;
	v.Add(p);
	p = &b;
	v.Add(p);
	printf("\n����� �����������:\n");
	cout << v;

	return 0;
}