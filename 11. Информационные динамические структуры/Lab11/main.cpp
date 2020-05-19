#include <windows.h>
#include <iostream>

using namespace std;

//�������� ������, ����������� ����� ������������ ������
struct list {
	int info;//������
	list *next;//��������� �� ��������� �����
	list *prev;//��������� �� ���������� �����
};

/////////////////////////////////////////////////////////////////////////
//������� ������������ ������

//������� ������������� ������������ ������
list* Init()
{
	list* lst = new list();
	lst->next = NULL;
	lst->prev = NULL;
	return lst;
}

//���������� ����� � ������������ ������� ������������ ������
list* Insert(list* pred, int data)
{
	list* temp = new list; // ��������� ������ ��� �����
	temp->info = data; // ���� ������
	temp->next = pred->next; //���������� ����� �� ������ ����� �����
	temp->prev = pred; //���������� ����� �� ������ ����� �����
	pred->next = temp; //���������� ����� �� ����������� ����� � ������
	if (temp->next != NULL)
		temp->next->prev = temp; //���������� ����� �� ���������� ����� � ������

	cout << "� ������ �������� ������� " << data << endl;
	return temp;
}

//�������� ����� �� ������ ����� ������������ ������
void Delete(list* del)
{
	if (del) {
		if (del->prev != NULL)
			del->prev->next = del->next;//��������� ����� �����
		if (del->next != NULL)
			del->next->prev = del->prev;//��������� ����� �����
		delete del; //������������ ������
		del = NULL;
	}
}

//�������� �������� ��� ������� num
bool DeleteNum( list* lst, int num)
{
	//���� ������ �� ���������� ��� ����
	if(lst == NULL || lst->next == NULL)
		//�����
		return false;

	//������� ���������
	int i=0;
	list* p = lst->next;
	while(p!= NULL)
	{
		if(i == num)
		{
			Delete(p);
			return true;
		}
		p = p->next;
		i++;
	}
	return false;
}

//�������� ������������ ������
void Print(list* start)
{
	list* p = start->next;
	if (p == NULL)
	{
		cout << "������ ����." << endl;
		return;
	}

	cout << "������:" << endl;

	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->next;
	}
	cout << endl;
}

//������� ������������ ������
void Clear(list *start) {
	list* p = start->next;
	while (p != NULL) {
		list* t = p->next;
		Delete(p);
		p = t;
	}
}

//������� ���������� ������ � ���� filename
bool SaveToFile(const char* filename, list* lst)
{
	//���� ������ ���� ��� �� ����������
	if (lst == NULL || lst->next == NULL)
	{
		//�����
		return false;
	}

	FILE* f;
	// ���� ��� �������� ����� ��������� 
	if ((f = fopen(filename, "wb")) == NULL)
	{
		//������, �� ������� �� �������
		fclose(f);
		printf("������ �������� ����� !\n");
		system("pause");
		return false;
	}
	list* p = lst->next;
	while (p != NULL)
	{
		// ���������� ������ � ���� filename
		if (fwrite(&p->info, sizeof(int), 1, f) < 1)
		{
			//������, �� ������� �� �������
			fclose(f);
			printf("������ ������ � ����!\n");
			system("pause");
			return false;
		}
		p = p->next;
	}

	//�������� �����
	fclose(f);

	return true;
}

//������� �������� ������ �� ����� filename
bool LoadFromFile(const char* filename, list* lst)
{
	//���� ������ �� ����������
	if (lst == NULL)
	{
		//�������� ������
		lst = Init();
	}

	FILE* f;
	// ���� ��� �������� ����� ��������� 
	if ((f = fopen(filename, "rb")) == NULL)
	{
		//������, �� ������� �� �������
		fclose(f);
		printf("������ �������� ����� !\n");
		system("pause");
		return false;
	}

	list* p = lst;

	//���� �� ����� �����
	while (!feof(f))
	{
		int info = 0;
		// ������ ������ �� ����� filename
		if (fread(&info, sizeof(int), 1, f) > 0)
		{
			//���������� �������� ������
			p = Insert(p, info);
			Print(lst);
		}
		if (ferror(f) != 0)
		{
			//������, �� ������� �� �������
			fclose(f);
			printf("������ ������ �����!\n");
			system("pause");
			return false;
		}
	}

	//�������� �����
	fclose(f);

	return true;
}

// ������� ���������� ������ ����������
// �������, ��� n-���-�� ���������
void fillListRandom(list* lst, int n)
{
	for (int i = 0; i < n; ++i)
	{
		Insert(lst, rand() % 21 - 10);
		Print(lst);
	}
}

int main()
{
	//������������ ����� � �������
	SetConsoleCP(1251);

	//������������ ������ �� �������
	SetConsoleOutputCP(1251);

	//���-�� ��������� ������
	int N = 5;

	cout << "������������ ������ �11: �������������� ������������ ���������.\n" << endl;

	//������������ ������������ ������
	cout << "������������ ������������ ������" << endl;

	//������������� ������
	list *lst = Init();

	//����� ������
	Print(lst);

	//���������� ������
	fillListRandom(lst, N);

	//�������� �������� ��� ������� 2
	DeleteNum(lst, 2);

	cout<<"������ ������� ��� ������� 2."<<endl;

	//����� ������
	Print(lst);

	//���������� ������ � ����
	SaveToFile("list.dat", lst);

	//������� ������
	Clear(lst);

	cout << "������ �������� � ���� � ������!" << endl;

	//����� ������	
	Print(lst);

	//�������� ������ �� �����
	LoadFromFile("list.dat", lst);

	cout << "������ �������� �� ����!" << endl;

	//������� ������
	Clear(lst);

	//�������� ������
	delete lst;

	cout << endl;
	system("pause");
	return 0;
}