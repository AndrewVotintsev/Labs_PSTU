#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

//Структура Школьник
struct Schoolkid
{
	//фамилия, имя, отчество
	char FIO[40];

	//Класс
	char _class[3];

	//номер телефона
	char phone[11];

	//оценки по предметам 
	//0 - математика, 
	//1 - физика, 
	//2 - русский язык, 
	//3 - литература
	int grades[4];
};

//Функция ввода данных структуры Schoolkid
Schoolkid *InputData()
{
	Schoolkid *sk = new Schoolkid();

	//Буфер чтения
	char str[255];

	//формируем запись sk
	printf("ФИО=");
	cin.getline(str, 255);
	strncpy(sk->FIO, str, 40);

	printf("Класс=");
	cin.getline(str, 255);
	strncpy(sk->_class, str, 3);

	printf("Телефон=");
	cin.getline(str, 255);
	strncpy(sk->phone, str, 11);

	printf("Оценка по математике=");
	cin >> sk->grades[0];
	printf("Оценка по физике=");
	cin >> sk->grades[1];
	printf("Оценка по русскому языку=");
	cin >> sk->grades[2];
	printf("Оценка по литературе=");
	cin >> sk->grades[3];

	//Очистка буфера ввода
	cin.ignore();

	//Если хотя бы одна из оценок меньше 1,
	//то возвращаем пустое значение
	//это признак окончания ввода
	if (sk->grades[0] < 1 || sk->grades[1] < 1 || sk->grades[2] < 1 ||
		sk->grades[3] < 1)
	{
		delete sk;
		return nullptr;
	}
	return sk;
}

//Функция чтения данных из файла в массив mas
//максимум записей - max
int ReadFile(char* filename, Schoolkid* &mas)
{
	// указатель связанный с файлом
	FILE *f;

	// если при открытии файла возникает 
	if ((f = fopen(filename, "rb")) == NULL)
		//ошибка, то выходим из функции
		return -1;

	// установить указатель файла на конец файла 
	fseek(f, 0, SEEK_END);

	// получаем размер файла 
	//размер файла в байтах
	int Size = ftell(f);

	//Кол-во записей
	int numOfData = Size / sizeof(Schoolkid);

	// возвращаем указатель файла на начало файла
	rewind(f);

	mas = new Schoolkid[numOfData];

	//Счетчик записей
	int i = 0;

	//Цикл пока не конец файла или не превысим размер массива
	while (feof(f) != EOF && i < numOfData)
	{
		//Если считывание записи прошло не успешно
		if (fread(&mas[i], sizeof(Schoolkid), 1, f) < 1)

			//выход из цикла
			break;

		//Если ошибка чтения данных
		if (ferror(f) != 0)
		{
			//Закрытие файла
			fclose(f);
			printf("Ошибка чтения файла (%d).\n", ferror(f));
			system("pause");
			return false;
		}
		i++;
	}
	//Закрытие файла
	fclose(f);

	//возвращаем кол-во считанных записей
	return i;
}

//Функция добавления записи в начало файла
bool Add(char* filename, const Schoolkid data)
{
	// указатель связанный с файлом
	FILE *fOriginal;

	// если при открытии файла возникает 
	if ((fOriginal = fopen(filename, "rb+")) == NULL)
	{
		//ошибка, значит файл еще не создан
		//Создаем файл
		if ((fOriginal = fopen(filename, "wb")) == NULL)
		{
			//Ошибка создания файла
			printf("Ошибка создания файла!\n");
			system("pause");
			return false;
		}
		//Закрываем файл
		fclose(fOriginal);

		//И пытаемся открыть опять
		if ((fOriginal = fopen(filename, "rb+")) == NULL)
			//ошибка
			return false;
	}
	Schoolkid skTemp, skNext;

	// установить указатель файла на конец файла 
	fseek(fOriginal, 0, SEEK_END);

	// получаем размер файла 
	//размер файла в байтах
	int Size = ftell(fOriginal);

	//Кол-во записей
	int numOfData = Size / sizeof(Schoolkid);

	// возвращаем указатель файла на начало файла
	rewind(fOriginal);

	// Чтение первой записи из файла
	if (fread(&skTemp, sizeof(Schoolkid), 1, fOriginal) < 1)
	{
		//Записей нет
	}
	else
		//Перевод указателя на начало файла
		rewind(fOriginal);

	// записываем запись data в начало файла filename
	fwrite(&data, sizeof(Schoolkid), 1, fOriginal);
	//Проверка на наличие файловых ошибок
	if (ferror(fOriginal) != 0)
	{
		//Закрытие файлов
		fclose(fOriginal);
		printf("Ошибка записи в файл (%d).\n", ferror(fOriginal));
		system("pause");
		return false;
	}

	//Счетчик записей
	int i = 1;

	//Записываем записи по очереди в начало файла
	while (feof(fOriginal) != EOF && i <= numOfData)
	{
		// Чтение очередной записи из файла
		fread(&skNext, sizeof(Schoolkid), 1, fOriginal);

		//Перемещаем курсор на одну запись назад
		fseek(fOriginal, i * sizeof(Schoolkid), SEEK_SET);

		// записываем запись skTemp в файл filename
		fwrite(&skTemp, sizeof(Schoolkid), 1, fOriginal);
		//Проверка на наличие файловых ошибок
		if (ferror(fOriginal) != 0)
		{
			//Закрытие файлов
			fclose(fOriginal);
			printf("Ошибка записи в файл (%d).\n", ferror(fOriginal));
			system("pause");
			return false;
		}
		skTemp = skNext;
		i++;

		//Перемещаем курсор на одну запись вперед
		fseek(fOriginal, i * sizeof(Schoolkid), SEEK_SET);
	}
	//Закрытие файлов
	fclose(fOriginal);

	return true;
}

//Удаление записи по номеру
bool DelData(char* filename, const int num)
{
	//Если номер записи некорректный,то выход
	if (num < 0)return false;

	// указатель связанный с файлом
	FILE *fOriginal, *fTemp;

	// если при открытии файла возникает 
	if ((fOriginal = fopen(filename, "rb")) == NULL)
		//ошибка, то выходим из функции
		return false;

	Schoolkid skTemp;

	// установить указатель файла на конец файла 
	fseek(fOriginal, 0, SEEK_END);

	// получаем размер файла 
	//размер файла в байтах
	int Size = ftell(fOriginal);

	//Кол-во записей
	int numOfData = Size / sizeof(Schoolkid);

	//Если номер записи некорректный,то выход
	if (num >= numOfData)
	{
		//Закрытие файла
		fclose(fOriginal);
		return false;
	}

	// возвращаем указатель на начало файла
	rewind(fOriginal);

	// если при открытии файла возникает 
	if ((fTemp = fopen("temp.dat", "wb")) == NULL)
		//ошибка, то выходим из функции
		return false;

	//Копирование файла filename в файл temp.dat
	while (feof(fOriginal) != EOF)
	{
		if (fread(&skTemp, sizeof(Schoolkid), 1, fOriginal) < 1)
			break;
		if (fwrite(&skTemp, sizeof(Schoolkid), 1, fTemp) < 1)
			break;
	}
	//Закрытие файлов
	fclose(fOriginal);
	fclose(fTemp);

	// если при открытии файла возникает 
	if ((fOriginal = fopen(filename, "wb")) == NULL)
		//ошибка, то выходим из функции
		return false;

	// если при открытии файла возникает 
	if ((fTemp = fopen("temp.dat", "rb")) == NULL)
		//ошибка, то выходим из функции
		return false;

	//Копирование в файл filename всех записей
	//из файла temp.dat кроме записи под номером num
	int i = 0;
	while (feof(fTemp) != EOF && i < numOfData)
	{
		//Считывание очередной записи
		if (fread(&skTemp, sizeof(Schoolkid), 1, fTemp) < 1)
			break;

		//Если номер считанной записи не совпадает с номером удаляемой
		if (i != num)
		{
			//Пишем в файл filename считанную запись
			if (fwrite(&skTemp, sizeof(Schoolkid), 1, fOriginal) < 1)
				break;
		}
		i++;
	}
	//Закрытие файлов
	fclose(fOriginal);
	fclose(fTemp);

	//Удаление временного файла
	remove("temp.dat");

	return true;
}

//Удалить все элементы, у которых есть 2 хотя бы по одному предмету
bool DelSomeData(char* filename)
{
	// указатель связанный с файлом
	FILE *fOriginal, *fTemp;

	// если при открытии файла возникает 
	if ((fOriginal = fopen(filename, "rb")) == NULL)
		//ошибка, то выходим из функции
		return false;

	Schoolkid skTemp;

	// установить указатель файла на конец файла 
	fseek(fOriginal, 0, SEEK_END);

	// получаем размер файла 
	//размер файла в байтах
	int Size = ftell(fOriginal);

	//Кол-во записей
	int numOfData = Size / sizeof(Schoolkid);

	// возвращаем указатель на начало файла
	rewind(fOriginal);

	// если при открытии файла возникает 
	if ((fTemp = fopen("temp.dat", "wb")) == NULL)
		//ошибка, то выходим из функции
		return false;

	//Копирование файла filename в файл temp.dat
	while (feof(fOriginal) != EOF)
	{
		if (fread(&skTemp, sizeof(Schoolkid), 1, fOriginal) < 1)
			break;
		if (fwrite(&skTemp, sizeof(Schoolkid), 1, fTemp) < 1)
			break;
	}
	//Закрытие файлов
	fclose(fOriginal);
	fclose(fTemp);

	// если при открытии файла возникает 
	if ((fOriginal = fopen(filename, "wb")) == NULL)
		//ошибка, то выходим из функции
		return false;

	// если при открытии файла возникает 
	if ((fTemp = fopen("temp.dat", "rb")) == NULL)
		//ошибка, то выходим из функции
		return false;

	//Копирование в файл filename всех записей
	//из файла temp.dat кроме записи под номером num
	int i = 0;
	while (feof(fTemp) != EOF && i < numOfData)
	{
		//Считывание очередной записи
		if (fread(&skTemp, sizeof(Schoolkid), 1, fTemp) < 1)
			break;

		//Если Ученик имеет хотя бы одну двойку, то пропускаем запись
		if (skTemp.grades[0] != 2 && skTemp.grades[1] != 2 &&
			skTemp.grades[2] != 2 && skTemp.grades[3] != 2)
		{
			//Пишем в файл filename считанную запись
			if (fwrite(&skTemp, sizeof(Schoolkid), 1, fOriginal) < 1)
				break;
		}
		i++;
	}
	//Закрытие файлов
	fclose(fOriginal);
	fclose(fTemp);

	//Удаление временного файла
	remove("temp.dat");

	return true;

}

//Функция вывода массива на консоль
void PrintMas(Schoolkid* mas, int num)
{
	// Если файл пуст
	if (num <= 0 || mas == NULL)
	{
		//Выводим в консоль
		printf("Записей нет:!\n");
		return;
	}

	printf("Все записи:!\n");
	//Вывод всех записей из файла
	for (int i = 0; i < num; ++i)
	{
		printf("#%d: ", i);
		printf("ФИО=%s; ", mas[i].FIO);
		printf("Класс=%s; ", mas[i]._class);
		printf("Тел=%s; ", mas[i].phone);
		printf("Оценки: матем=%d, ", mas[i].grades[0]);
		printf("физ=%d, ", mas[i].grades[1]);
		printf("рус=%d, ", mas[i].grades[2]);
		printf("лит=%d\n", mas[i].grades[3]);
	}
}

//Функция Главное меню
void MainMenu()
{
	char str[255];
	str[0] = 'q';
	int n = 0;
	Schoolkid* sk = NULL;
	//Выводит меню выбора действий пока не будет выбран 0 или другое число не равное номеру пункта меню
	do
	{
		printf("\nМеню\n");
		printf("1-Добавить запись\n2-Удалить запись\n3-Просмотр записей\n");
		printf("4-Удалить все элементы, у которых есть 2 хотя бы по одному предмету\n0-Выход\n");
		printf("Ваш выбор:");
		cin.getline(str, 255);
		switch (str[0])
		{
		case '1'://Добавление записи
			sk = InputData();
			if(sk == NULL) break;
			//Если запись добавлена
			if (Add("school.dat", *sk))
				//Выводим в консоль
				printf("Запись добавлена!\n");
			delete sk;

			break;
		case '2'://Удаление записи
			printf("Введите номер записи для удаления:");
			cin >> n;
			if (DelData("school.dat", n))
				printf("Запись №%d удалена!\n", n);
			else
				printf("Запись №%d не удалена!\n", n);

			//Очистка буфера ввода
			cin.ignore();
			break;
		case '3'://Просмотр записей
			Schoolkid* mas;
			n = ReadFile("school.dat", mas);
			PrintMas(mas, n);
			if (mas != NULL)
				delete[] mas;
			break;
		case '4'://Удалить все элементы, у которых есть 2 хотя бы по одному предмету
			if (DelSomeData("school.dat"))
				printf("Записи удалены!\n");
			else
				printf("Запись не удалены!\n");
			break;
		default:
			break;
		}

	} while (str[0] != '0');
}

int main()
{
	//Руссификация ввода в консоль
	SetConsoleCP(1251);

	//Руссификация вывода на консоль
	SetConsoleOutputCP(1251);

	cout << "Лабораторная работа №8: Блоковый ввод-вывод." << endl;

	//Вызов меню
	MainMenu();

	cout << endl;
	return 0;
}