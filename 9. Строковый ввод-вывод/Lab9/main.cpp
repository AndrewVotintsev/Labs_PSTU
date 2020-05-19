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

	cout << "������������ ������ �9: ��������� ����-�����." << endl;


	//����� ����
	int N = 0, K = 0;
	printf("�������� N:");
	scanf("%d", &N);
	printf("�������� K:");
	scanf("%d", &K);

	//���� N ��� K, �� ������ ���� ���������� ���
	if (N < 0) N = 0;
	if (K < 0)K = 0;

	//���� N > K, �� ������ �� �������
	if (K < N)
	{
		int temp = N;
		N = K;
		K = temp;
	}

	//
	FILE* f1, *f2;
	//������������ ����� ������
	const int MAXLINE = 255;

	//������, � ������� ������� ����������� �����������
	char buf[MAXLINE];

	// ���� ��� �������� ����� ��������� 
	if ((f1 = fopen("F1.txt", "r")) == NULL)
	{
		//������, �� ������� �� �������
		fclose(f1);
		printf("������ �������� ����� F1.txt!\n");
		system("pause");
		return 1;
	}

	// ���� ��� �������� ����� ��������� 
	if ((f2 = fopen("F2.txt", "w")) == NULL)
	{
		//������, �� ������� �� �������
		fclose(f1);
		fclose(f2);
		printf("������ �������� ����� F2.txt!\n");
		system("pause");
		return 1;
	}

	//������� �����
	int i = 0;
	//����������� �� ����� f1 � ���� f2
	//����� �� N �� K
	while (fgets(buf, MAXLINE, f1) != NULL)
	{
		if (i >= N && i <= K)
			fputs(buf, f2);
		i++;
	}
	fclose(f1);
	fclose(f2);

	//�������� ��������� ����
	char consonant[] = "������������������������������������������";
	// ���� ��� �������� ����� ��������� 
	if ((f2 = fopen("F2.txt", "r")) == NULL)
	{
		//������, �� ������� �� �������
		fclose(f2);
		printf("������ �������� ����� F1.txt!\n");
		system("pause");
		return 1;
	}

	//������� ��������� ����
	i = 0;
	while (fgets(buf, MAXLINE, f2) != NULL)
	{
		for (int k = 0; k < strlen(buf); k++)
			for (int j = 0; j < strlen(consonant); j++)
				if (buf[k] == consonant[j])
					i++;
	}
	//�������� �����
	fclose(f2);

	printf("� ����� F2.txt %d ��������� ����.\n", i);

	cout << endl;
	system("pause");
	return 0;
}