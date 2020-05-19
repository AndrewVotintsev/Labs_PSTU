#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
	//–уссификаци€ ввода в консоль
	SetConsoleCP(1251);

	//–уссификаци€ вывода на консоль
	SetConsoleOutputCP(1251);

	cout << "Ћабораторна€ работа є9: —троковый ввод-вывод." << endl;


	//¬ызов меню
	int N = 0, K = 0;
	printf("¬введите N:");
	scanf("%d", &N);
	printf("¬введите K:");
	scanf("%d", &K);

	//≈сли N или K, то меньше нул€ исправл€ем это
	if (N < 0) N = 0;
	if (K < 0)K = 0;

	//≈сли N > K, то мен€ем их местами
	if (K < N)
	{
		int temp = N;
		N = K;
		K = temp;
	}

	//
	FILE* f1, *f2;
	//максимальна€ длина строки
	const int MAXLINE = 255;

	//строка, с помощью которой выполн€етс€ копирование
	char buf[MAXLINE];

	// если при открытии файла возникает 
	if ((f1 = fopen("F1.txt", "r")) == NULL)
	{
		//ошибка, то выходим из функции
		fclose(f1);
		printf("ќшибка открыти€ файла F1.txt!\n");
		system("pause");
		return 1;
	}

	// если при открытии файла возникает 
	if ((f2 = fopen("F2.txt", "w")) == NULL)
	{
		//ошибка, то выходим из функции
		fclose(f1);
		fclose(f2);
		printf("ќшибка открыти€ файла F2.txt!\n");
		system("pause");
		return 1;
	}

	//—четчик строк
	int i = 0;
	// опирование из файла f1 в файл f2
	//строк от N до K
	while (fgets(buf, MAXLINE, f1) != NULL)
	{
		if (i >= N && i <= K)
			fputs(buf, f2);
		i++;
	}
	fclose(f1);
	fclose(f2);

	//ѕеречень согласных букв
	char consonant[] = "Ѕб¬в√гƒд∆ж«з…й кЋлћмЌнѕп–р—с“т‘ф’х÷ц„чЎшўщ";
	// если при открытии файла возникает 
	if ((f2 = fopen("F2.txt", "r")) == NULL)
	{
		//ошибка, то выходим из функции
		fclose(f2);
		printf("ќшибка открыти€ файла F1.txt!\n");
		system("pause");
		return 1;
	}

	//—четчик согласных букв
	i = 0;
	while (fgets(buf, MAXLINE, f2) != NULL)
	{
		for (int k = 0; k < strlen(buf); k++)
			for (int j = 0; j < strlen(consonant); j++)
				if (buf[k] == consonant[j])
					i++;
	}
	//«акрытие файла
	fclose(f2);

	printf("¬ файле F2.txt %d согласных букв.\n", i);

	cout << endl;
	system("pause");
	return 0;
}