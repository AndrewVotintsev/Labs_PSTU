#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
	//������������ ����� � �������
	SetConsoleCP(1251);

	//������������ ������ �� �������
	SetConsoleOutputCP(1251);

	cout << "������������ ������ �10: ������������ �������." << endl;
	//���-�� �����
	int n = 1;

	//���-�� ��������
	int m = 1;
	printf("������� ���-�� ����� �������:");
	scanf("%d", &n);
	printf("������� ���-�� �������� �������:");
	scanf("%d", &m);

	//���� N ��� K ������ ����, �� ���������� ���
	if (n < 2) n = 2;
	if (m < 2) m = 2;

	//������������� ������� mass[n][m]
	int **mass = new int*[n];
	// � ������ ������ mass ������� ������ �� m ���������
	for (int i = 0; i < n; i++)
		mass[i] = new int[m];

	//���������� ������� ���������� ������� (-10;10)
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			mass[i][j] = rand() % 21 - 10;

	//����� ������� mass �� �����
	printf("�������� ������:\n");
	for (int i = 0, k = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%3d ", mass[i][j]);

		printf("\n");
	}

	//����� ��������� ������
	int delN = 0;

	printf("������� ����� ������ ��� �������� (0,%d):", n-1);
	scanf("%d", &delN);
	//���� delN �� ���������, �� ���������� ���
	if (delN < 0 || delN >= n) delN = 0;

	//������������� ������� massNew[n-1][m]
	int **massNew = new int*[n - 1];
	// � ������ ������ massNew ������� ������ �� m ���������
	for (int i = 0; i < n - 1; i++)
		massNew[i] = new int[m];

	//����������� ������� mass � ������ massNew
	for (int i = 0, k = 0; i < n; i++)
		//����� ��������� ������
		if (i != delN)
		{
			for (int j = 0; j < m; j++)
				massNew[k][j] = mass[i][j];
			k++;
		}

	//����� ������� mass �� �����
	printf("����� ������:\n");
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < m; j++)
			printf("%3d ", massNew[i][j]);

		printf("\n");
	}

	//������� ������ ������� mass[]
	for (int i = 0; i < n; ++i)
		delete[] mass[i];
	delete[] mass;

	//������� ������ ������� massNew[]
	for (int i = 0; i < n-1; ++i)
		delete[] massNew[i];
	delete[] massNew;

	cout << endl;
	system("pause");
	return 0;
}