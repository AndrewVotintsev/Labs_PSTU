#include <iostream>
#include <string>
using namespace std;

int Diff(int a, int b)
{
	return a - b;
}

int Diff(double a, double b)
{
	 return a - b;
}

void Diff(char str1[],char str2[],string &str3, int a, int a1, int b, int b1)
{
	int p, c, d;
	char x, y;
	

	c = a - a1;
	p = b - b1;
	
	str3 = 'i' + str3;
	
	if (c < 0)
	{
		c += c * (-2);

		while (c != 0)
		{
			d = c % 10;
			c = c / 10;
			y = (char)(d + 48);
			str3 = y + str3;
		}

		str3 = '-' + str3;
	}

	if (c > 0)
	{
		while (c != 0)
		{
			d = c % 10;
			c = c / 10;
			y = (char)(d + 48);
			str3 = y + str3;
		}

		str3 = '+' + str3;
	}

	

	if (p < 0)
	{
		p += p * (-2);

		while (p != 0)
		{
			d = p % 10;
			p = p / 10;
			x = (char)(d + 48);
			str3 = x + str3;
		}

		str3 = '-' + str3;
	}

	if (p > 0)
	{
		while (p != 0)
		{
			d = p % 10;
			p = p / 10;
			x = (char)(d + 48);
			str3 = x + str3;
		}
	}
	
}

void Val(char str[], double &q, double &w)
{
	double y = 1, d = 10;

	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		if (48 <= (int)str[i] && (int)str[i] <= 57)
		{
			w = w + ((int)str[i] - 48)*y;
			y *= d;

			if (str[i-1]=='-')
			{
				w = w - 2 * w;
			}
		}

		if (str[i] == '+' || str[i] == '-')
		{
			y = 1;
			for (int j = i - 1; j >= 0; j--)
			{
				if (48 <= (int)str[j] && (int)str[j] <= 57)
				{
					q = q + ((int)str[j] - 48)*y;
					y *= d;

					if (str[j - 1] == '-')
					{
						q = q - 2 * q;
					}
				}
			}
			break;
		}
		
	}
	
	
	y = 1;

	for (int k = strlen(str)-1; k >= 0; k--)
	{
		if (str[k] == '.' || str[k] == ',')
		{
			w = w / y;
		}

		if (48 <= (int)str[k] && (int)str[k] <= 57)
		{
			y *= d;
		}
	}
	
	
	q;
	w;	
}

void main()
{
	setlocale(LC_ALL, "rus");

	double q = 0, w = 0, b, b1, a, a1;

	char str1[255] = {}, str2[255] = {};
	string str3;
	 
	for (int i = 1; i <= 2; i++)
	{
		if (i == 1)
		{
			cout << "¬ведите два вещественных числа:" << endl;
		}

		else
		{
			cout << "¬ведите два комплексных числа:" << endl;
			q = 0; w = 0;
		}

		gets_s(str1);
		gets_s(str2);

		if (str1[strlen(str1) - 1] != 'i' && str2[strlen(str2) - 1] != 'i')
		{
			Val(str1, q, w);
			a = round(w);
			q = 0;
			w = 0;
			Val(str2, q, w);
			b = round(w);
			cout << str1 << " - " << str2 << " = " << Diff(a, b) << endl;
		}

		else
		{
			Val(str1, q, w);
			a = w;
			b = q;
			w = 0;
			q = 0;
			Val(str2, q, w);
			a1 = w;
			b1 = q;
			Diff(str1, str2, str3, a, a1, b, b1);

			cout << "(" << str1 << ")-(" << str2 << ") = " << str3 << endl;




		}
	}

	system("pause");
}