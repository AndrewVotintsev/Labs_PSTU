#include <windows.h>
#include <iostream>

using namespace std;

//Стуктура данных, описывающая звено двухсвязного списка
struct list {
	int info;//данные
	list *next;//указатель на следующее звено
	list *prev;//указатель на предыдущее звено
};

/////////////////////////////////////////////////////////////////////////
//Функции двухсвязного списка

//Функция инициализации двухсвязного списка
list* Init()
{
	list* lst = new list();
	lst->next = NULL;
	lst->prev = NULL;
	return lst;
}

//Добавление звена в произвольную позицию двухсвязного списка
list* Insert(list* pred, int data)
{
	list* temp = new list; // Выделение памяти под звено
	temp->info = data; // Ввод данных
	temp->next = pred->next; //Проведение связи от нового звена вперёд
	temp->prev = pred; //Проведение связи от нового звена назад
	pred->next = temp; //Проведение связи от предыдущего звена к новому
	if (temp->next != NULL)
		temp->next->prev = temp; //Проведение связи от следующего звена к новому

	cout << "В список добавлен элемент " << data << endl;
	return temp;
}

//Удаление звена из любого места двухсвязного списка
void Delete(list* del)
{
	if (del) {
		if (del->prev != NULL)
			del->prev->next = del->next;//Обработка связи вперёд
		if (del->next != NULL)
			del->next->prev = del->prev;//Обработка связи назад
		delete del; //Освобождение памяти
		del = NULL;
	}
}

//Удаление элемента под номером num
bool DeleteNum( list* lst, int num)
{
	//Если список не существует или пуст
	if(lst == NULL || lst->next == NULL)
		//выход
		return false;

	//Счетчик элементов
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

//Просмотр двухсвязного списка
void Print(list* start)
{
	list* p = start->next;
	if (p == NULL)
	{
		cout << "Список пуст." << endl;
		return;
	}

	cout << "Список:" << endl;

	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->next;
	}
	cout << endl;
}

//Очистка двухсвязного списка
void Clear(list *start) {
	list* p = start->next;
	while (p != NULL) {
		list* t = p->next;
		Delete(p);
		p = t;
	}
}

//Функция сохранения списка в файл filename
bool SaveToFile(const char* filename, list* lst)
{
	//Если список пуст или не существует
	if (lst == NULL || lst->next == NULL)
	{
		//Выход
		return false;
	}

	FILE* f;
	// если при открытии файла возникает 
	if ((f = fopen(filename, "wb")) == NULL)
	{
		//ошибка, то выходим из функции
		fclose(f);
		printf("Ошибка открытия файла !\n");
		system("pause");
		return false;
	}
	list* p = lst->next;
	while (p != NULL)
	{
		// записываем данные в файл filename
		if (fwrite(&p->info, sizeof(int), 1, f) < 1)
		{
			//ошибка, то выходим из функции
			fclose(f);
			printf("Ошибка записи в файл!\n");
			system("pause");
			return false;
		}
		p = p->next;
	}

	//Закрытие файла
	fclose(f);

	return true;
}

//Функция загрузки списка из файла filename
bool LoadFromFile(const char* filename, list* lst)
{
	//Если список не существует
	if (lst == NULL)
	{
		//Создание списка
		lst = Init();
	}

	FILE* f;
	// если при открытии файла возникает 
	if ((f = fopen(filename, "rb")) == NULL)
	{
		//ошибка, то выходим из функции
		fclose(f);
		printf("Ошибка открытия файла !\n");
		system("pause");
		return false;
	}

	list* p = lst;

	//Цикл до конца файла
	while (!feof(f))
	{
		int info = 0;
		// чтение записи из файла filename
		if (fread(&info, sizeof(int), 1, f) > 0)
		{
			//Добавление элемента списка
			p = Insert(p, info);
			Print(lst);
		}
		if (ferror(f) != 0)
		{
			//ошибка, то выходим из функции
			fclose(f);
			printf("Ошибка чтения файла!\n");
			system("pause");
			return false;
		}
	}

	//Закрытие файла
	fclose(f);

	return true;
}

// Функция заполнения списка случайными
// числами, где n-кол-во элементов
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
	//Руссификация ввода в консоль
	SetConsoleCP(1251);

	//Руссификация вывода на консоль
	SetConsoleOutputCP(1251);

	//Кол-во элементов списка
	int N = 5;

	cout << "Лабораторная работа №11: Информационные динамические структуры.\n" << endl;

	//Тестирование двухсвязного списка
	cout << "Тестирование двухсвязного списка" << endl;

	//Инициализация списка
	list *lst = Init();

	//Вывод списка
	Print(lst);

	//Наполнение списка
	fillListRandom(lst, N);

	//Удаление элемента под номером 2
	DeleteNum(lst, 2);

	cout<<"Удален элемент под номером 2."<<endl;

	//Вывод списка
	Print(lst);

	//Сохранение списка в файл
	SaveToFile("list.dat", lst);

	//Очистка списка
	Clear(lst);

	cout << "Список сохранен в файл и очищен!" << endl;

	//Вывод списка	
	Print(lst);

	//Загрузка списка из файла
	LoadFromFile("list.dat", lst);

	cout << "Список загружен из файа!" << endl;

	//Очистка списка
	Clear(lst);

	//Удаление списка
	delete lst;

	cout << endl;
	system("pause");
	return 0;
}