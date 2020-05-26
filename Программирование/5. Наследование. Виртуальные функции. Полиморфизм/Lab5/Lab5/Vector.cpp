#include "Vector.h"

Vector::Vector()
{
	beg = 0;
	size = 0;
	cur = 0;
}

Vector::Vector(int n)
{
	beg = new Object * [n];
	size = n;
	cur = 0;
}

Vector::~Vector()
{
	if (beg != 0) delete[] beg;//Освобождение памяти
	beg = 0;
}

void Vector::Add(Object* p)
{
	//Добавление указаьелей на обекты в массив
	if (cur < size) {
		beg[cur] = p;
		cur++;
	}
}

ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0) out << "Empty!!!" << endl;
	Object** p = v.beg;
	//Вывод данных из объектов
	for (int i = 0; i < v.cur; i++) {
		out << "Результат №" << i + 1 << ":" << endl;
		(*p)->Show();
		out << endl;
		p++;
	}

	return out;
}
