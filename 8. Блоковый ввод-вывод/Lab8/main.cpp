#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

//��������� ��������
struct Schoolkid
{
	//�������, ���, ��������
	char FIO[40];

	//�����
	char _class[3];

	//����� ��������
	char phone[11];

	//������ �� ��������� 
	//0 - ����������, 
	//1 - ������, 
	//2 - ������� ����, 
	//3 - ����������
	int grades[4];
};

//������� ����� ������ ��������� Schoolkid
Schoolkid *InputData()
{
	Schoolkid *sk = new Schoolkid();

	//����� ������
	char str[255];

	//��������� ������ sk
	printf("���=");
	cin.getline(str, 255);
	strncpy(sk->FIO, str, 40);

	printf("�����=");
	cin.getline(str, 255);
	strncpy(sk->_class, str, 3);

	printf("�������=");
	cin.getline(str, 255);
	strncpy(sk->phone, str, 11);

	printf("������ �� ����������=");
	cin >> sk->grades[0];
	printf("������ �� ������=");
	cin >> sk->grades[1];
	printf("������ �� �������� �����=");
	cin >> sk->grades[2];
	printf("������ �� ����������=");
	cin >> sk->grades[3];

	//������� ������ �����
	cin.ignore();

	//���� ���� �� ���� �� ������ ������ 1,
	//�� ���������� ������ ��������
	//��� ������� ��������� �����
	if (sk->grades[0] < 1 || sk->grades[1] < 1 || sk->grades[2] < 1 ||
		sk->grades[3] < 1)
	{
		delete sk;
		return nullptr;
	}
	return sk;
}

//������� ������ ������ �� ����� � ������ mas
//�������� ������� - max
int ReadFile(char* filename, Schoolkid* &mas)
{
	// ��������� ��������� � ������
	FILE *f;

	// ���� ��� �������� ����� ��������� 
	if ((f = fopen(filename, "rb")) == NULL)
		//������, �� ������� �� �������
		return -1;

	// ���������� ��������� ����� �� ����� ����� 
	fseek(f, 0, SEEK_END);

	// �������� ������ ����� 
	//������ ����� � ������
	int Size = ftell(f);

	//���-�� �������
	int numOfData = Size / sizeof(Schoolkid);

	// ���������� ��������� ����� �� ������ �����
	rewind(f);

	mas = new Schoolkid[numOfData];

	//������� �������
	int i = 0;

	//���� ���� �� ����� ����� ��� �� �������� ������ �������
	while (feof(f) != EOF && i < numOfData)
	{
		//���� ���������� ������ ������ �� �������
		if (fread(&mas[i], sizeof(Schoolkid), 1, f) < 1)

			//����� �� �����
			break;

		//���� ������ ������ ������
		if (ferror(f) != 0)
		{
			//�������� �����
			fclose(f);
			printf("������ ������ ����� (%d).\n", ferror(f));
			system("pause");
			return false;
		}
		i++;
	}
	//�������� �����
	fclose(f);

	//���������� ���-�� ��������� �������
	return i;
}

//������� ���������� ������ � ������ �����
bool Add(char* filename, const Schoolkid data)
{
	// ��������� ��������� � ������
	FILE *fOriginal;

	// ���� ��� �������� ����� ��������� 
	if ((fOriginal = fopen(filename, "rb+")) == NULL)
	{
		//������, ������ ���� ��� �� ������
		//������� ����
		if ((fOriginal = fopen(filename, "wb")) == NULL)
		{
			//������ �������� �����
			printf("������ �������� �����!\n");
			system("pause");
			return false;
		}
		//��������� ����
		fclose(fOriginal);

		//� �������� ������� �����
		if ((fOriginal = fopen(filename, "rb+")) == NULL)
			//������
			return false;
	}
	Schoolkid skTemp, skNext;

	// ���������� ��������� ����� �� ����� ����� 
	fseek(fOriginal, 0, SEEK_END);

	// �������� ������ ����� 
	//������ ����� � ������
	int Size = ftell(fOriginal);

	//���-�� �������
	int numOfData = Size / sizeof(Schoolkid);

	// ���������� ��������� ����� �� ������ �����
	rewind(fOriginal);

	// ������ ������ ������ �� �����
	if (fread(&skTemp, sizeof(Schoolkid), 1, fOriginal) < 1)
	{
		//������� ���
	}
	else
		//������� ��������� �� ������ �����
		rewind(fOriginal);

	// ���������� ������ data � ������ ����� filename
	fwrite(&data, sizeof(Schoolkid), 1, fOriginal);
	//�������� �� ������� �������� ������
	if (ferror(fOriginal) != 0)
	{
		//�������� ������
		fclose(fOriginal);
		printf("������ ������ � ���� (%d).\n", ferror(fOriginal));
		system("pause");
		return false;
	}

	//������� �������
	int i = 1;

	//���������� ������ �� ������� � ������ �����
	while (feof(fOriginal) != EOF && i <= numOfData)
	{
		// ������ ��������� ������ �� �����
		fread(&skNext, sizeof(Schoolkid), 1, fOriginal);

		//���������� ������ �� ���� ������ �����
		fseek(fOriginal, i * sizeof(Schoolkid), SEEK_SET);

		// ���������� ������ skTemp � ���� filename
		fwrite(&skTemp, sizeof(Schoolkid), 1, fOriginal);
		//�������� �� ������� �������� ������
		if (ferror(fOriginal) != 0)
		{
			//�������� ������
			fclose(fOriginal);
			printf("������ ������ � ���� (%d).\n", ferror(fOriginal));
			system("pause");
			return false;
		}
		skTemp = skNext;
		i++;

		//���������� ������ �� ���� ������ ������
		fseek(fOriginal, i * sizeof(Schoolkid), SEEK_SET);
	}
	//�������� ������
	fclose(fOriginal);

	return true;
}

//�������� ������ �� ������
bool DelData(char* filename, const int num)
{
	//���� ����� ������ ������������,�� �����
	if (num < 0)return false;

	// ��������� ��������� � ������
	FILE *fOriginal, *fTemp;

	// ���� ��� �������� ����� ��������� 
	if ((fOriginal = fopen(filename, "rb")) == NULL)
		//������, �� ������� �� �������
		return false;

	Schoolkid skTemp;

	// ���������� ��������� ����� �� ����� ����� 
	fseek(fOriginal, 0, SEEK_END);

	// �������� ������ ����� 
	//������ ����� � ������
	int Size = ftell(fOriginal);

	//���-�� �������
	int numOfData = Size / sizeof(Schoolkid);

	//���� ����� ������ ������������,�� �����
	if (num >= numOfData)
	{
		//�������� �����
		fclose(fOriginal);
		return false;
	}

	// ���������� ��������� �� ������ �����
	rewind(fOriginal);

	// ���� ��� �������� ����� ��������� 
	if ((fTemp = fopen("temp.dat", "wb")) == NULL)
		//������, �� ������� �� �������
		return false;

	//����������� ����� filename � ���� temp.dat
	while (feof(fOriginal) != EOF)
	{
		if (fread(&skTemp, sizeof(Schoolkid), 1, fOriginal) < 1)
			break;
		if (fwrite(&skTemp, sizeof(Schoolkid), 1, fTemp) < 1)
			break;
	}
	//�������� ������
	fclose(fOriginal);
	fclose(fTemp);

	// ���� ��� �������� ����� ��������� 
	if ((fOriginal = fopen(filename, "wb")) == NULL)
		//������, �� ������� �� �������
		return false;

	// ���� ��� �������� ����� ��������� 
	if ((fTemp = fopen("temp.dat", "rb")) == NULL)
		//������, �� ������� �� �������
		return false;

	//����������� � ���� filename ���� �������
	//�� ����� temp.dat ����� ������ ��� ������� num
	int i = 0;
	while (feof(fTemp) != EOF && i < numOfData)
	{
		//���������� ��������� ������
		if (fread(&skTemp, sizeof(Schoolkid), 1, fTemp) < 1)
			break;

		//���� ����� ��������� ������ �� ��������� � ������� ���������
		if (i != num)
		{
			//����� � ���� filename ��������� ������
			if (fwrite(&skTemp, sizeof(Schoolkid), 1, fOriginal) < 1)
				break;
		}
		i++;
	}
	//�������� ������
	fclose(fOriginal);
	fclose(fTemp);

	//�������� ���������� �����
	remove("temp.dat");

	return true;
}

//������� ��� ��������, � ������� ���� 2 ���� �� �� ������ ��������
bool DelSomeData(char* filename)
{
	// ��������� ��������� � ������
	FILE *fOriginal, *fTemp;

	// ���� ��� �������� ����� ��������� 
	if ((fOriginal = fopen(filename, "rb")) == NULL)
		//������, �� ������� �� �������
		return false;

	Schoolkid skTemp;

	// ���������� ��������� ����� �� ����� ����� 
	fseek(fOriginal, 0, SEEK_END);

	// �������� ������ ����� 
	//������ ����� � ������
	int Size = ftell(fOriginal);

	//���-�� �������
	int numOfData = Size / sizeof(Schoolkid);

	// ���������� ��������� �� ������ �����
	rewind(fOriginal);

	// ���� ��� �������� ����� ��������� 
	if ((fTemp = fopen("temp.dat", "wb")) == NULL)
		//������, �� ������� �� �������
		return false;

	//����������� ����� filename � ���� temp.dat
	while (feof(fOriginal) != EOF)
	{
		if (fread(&skTemp, sizeof(Schoolkid), 1, fOriginal) < 1)
			break;
		if (fwrite(&skTemp, sizeof(Schoolkid), 1, fTemp) < 1)
			break;
	}
	//�������� ������
	fclose(fOriginal);
	fclose(fTemp);

	// ���� ��� �������� ����� ��������� 
	if ((fOriginal = fopen(filename, "wb")) == NULL)
		//������, �� ������� �� �������
		return false;

	// ���� ��� �������� ����� ��������� 
	if ((fTemp = fopen("temp.dat", "rb")) == NULL)
		//������, �� ������� �� �������
		return false;

	//����������� � ���� filename ���� �������
	//�� ����� temp.dat ����� ������ ��� ������� num
	int i = 0;
	while (feof(fTemp) != EOF && i < numOfData)
	{
		//���������� ��������� ������
		if (fread(&skTemp, sizeof(Schoolkid), 1, fTemp) < 1)
			break;

		//���� ������ ����� ���� �� ���� ������, �� ���������� ������
		if (skTemp.grades[0] != 2 && skTemp.grades[1] != 2 &&
			skTemp.grades[2] != 2 && skTemp.grades[3] != 2)
		{
			//����� � ���� filename ��������� ������
			if (fwrite(&skTemp, sizeof(Schoolkid), 1, fOriginal) < 1)
				break;
		}
		i++;
	}
	//�������� ������
	fclose(fOriginal);
	fclose(fTemp);

	//�������� ���������� �����
	remove("temp.dat");

	return true;

}

//������� ������ ������� �� �������
void PrintMas(Schoolkid* mas, int num)
{
	// ���� ���� ����
	if (num <= 0 || mas == NULL)
	{
		//������� � �������
		printf("������� ���:!\n");
		return;
	}

	printf("��� ������:!\n");
	//����� ���� ������� �� �����
	for (int i = 0; i < num; ++i)
	{
		printf("#%d: ", i);
		printf("���=%s; ", mas[i].FIO);
		printf("�����=%s; ", mas[i]._class);
		printf("���=%s; ", mas[i].phone);
		printf("������: �����=%d, ", mas[i].grades[0]);
		printf("���=%d, ", mas[i].grades[1]);
		printf("���=%d, ", mas[i].grades[2]);
		printf("���=%d\n", mas[i].grades[3]);
	}
}

//������� ������� ����
void MainMenu()
{
	char str[255];
	str[0] = 'q';
	int n = 0;
	Schoolkid* sk = NULL;
	//������� ���� ������ �������� ���� �� ����� ������ 0 ��� ������ ����� �� ������ ������ ������ ����
	do
	{
		printf("\n����\n");
		printf("1-�������� ������\n2-������� ������\n3-�������� �������\n");
		printf("4-������� ��� ��������, � ������� ���� 2 ���� �� �� ������ ��������\n0-�����\n");
		printf("��� �����:");
		cin.getline(str, 255);
		switch (str[0])
		{
		case '1'://���������� ������
			sk = InputData();
			if(sk == NULL) break;
			//���� ������ ���������
			if (Add("school.dat", *sk))
				//������� � �������
				printf("������ ���������!\n");
			delete sk;

			break;
		case '2'://�������� ������
			printf("������� ����� ������ ��� ��������:");
			cin >> n;
			if (DelData("school.dat", n))
				printf("������ �%d �������!\n", n);
			else
				printf("������ �%d �� �������!\n", n);

			//������� ������ �����
			cin.ignore();
			break;
		case '3'://�������� �������
			Schoolkid* mas;
			n = ReadFile("school.dat", mas);
			PrintMas(mas, n);
			if (mas != NULL)
				delete[] mas;
			break;
		case '4'://������� ��� ��������, � ������� ���� 2 ���� �� �� ������ ��������
			if (DelSomeData("school.dat"))
				printf("������ �������!\n");
			else
				printf("������ �� �������!\n");
			break;
		default:
			break;
		}

	} while (str[0] != '0');
}

int main()
{
	//������������ ����� � �������
	SetConsoleCP(1251);

	//������������ ������ �� �������
	SetConsoleOutputCP(1251);

	cout << "������������ ������ �8: �������� ����-�����." << endl;

	//����� ����
	MainMenu();

	cout << endl;
	return 0;
}