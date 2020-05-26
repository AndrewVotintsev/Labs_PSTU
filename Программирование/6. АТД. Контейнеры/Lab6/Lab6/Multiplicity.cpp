#include "Multiplicity.h"

Multiplicity::Multiplicity()
{
	size = 0;
	arr = 0;
}

Multiplicity::Multiplicity(int s, int k)
{
	size = s;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = k;
	}
	beg.elem = &arr[0];
	end.elem = &arr[size];
}

Multiplicity::Multiplicity(const Multiplicity& object)
{
	size = object.size;
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		arr[i] = object.arr[i];
	}
	beg = object.beg;
	end = object.end;
}

Multiplicity::~Multiplicity()
{
	delete[] arr;
	arr = 0;
}

Multiplicity& Multiplicity::operator=(const Multiplicity& object)
{
	if (this == &object) return *this;
	size = object.size;

	if (arr != 0) delete[] arr;
	arr = new int[size];

	for (int i = 0; i < size; i++) {
		arr[i] = object.arr[i];
	}

	beg.elem = &arr[0];
	end.elem = &arr[size];

	return *this;
}

Multiplicity Multiplicity::operator+(const Multiplicity& object)
{
	Multiplicity newObject;

	/*��������� ������ ������ �������*/
	newObject.size = this->size + object.size;

	for (int i = 0; i < this->size; i++) {
		for (int j = 0; j < object.size; j++) {
			/*��������� ������� ������������� ��������*/
			if (this->arr[i] == object.arr[j]) {
				newObject.size--;
			}
		}
	}
	/*��������� ������ ������ �������. �����!*/

	/*������� ���� ������*/
	newObject.arr = new int[newObject.size];
	int k = object.size;

	for (int i = 0; i < newObject.size; i++) {
		newObject.arr[i] = (i < object.size) ? object.arr[i] : 0;
	}
	
	for (int i = 0; i < this->size; i++) {
		bool isArray = false;
		for (int j = 0; j < newObject.size; j++) {
			/*��������� ������� ������������� ��������*/
			if (this->arr[i] == newObject.arr[j]) {
				isArray = true;
			}
		}
		/*���������� � ������ ���� �� �����������*/
		if (!isArray) {
			newObject.arr[k] = this->arr[i];
			k++;
		}
	}
	/*������� ���� ������. �����!*/

	return newObject;
}

int& Multiplicity::operator[](int index)
{
	if (index < size) return arr[index];
	else cout << "��� ������ �������" << endl;
}

int Multiplicity::operator()()
{
	return size;
}

Iterator Multiplicity::first()
{
	return beg;
}

Iterator Multiplicity::last()
{
	return end;
}

ostream& operator<<(ostream& out, const Multiplicity& object)
{
	out << "{";
	for (int i = 0; i < object.size; i++) {
		out << object.arr[i];
		if (i + 1 != object.size) out << ",";
	}
	out << "}";

	return out;
}

istream& operator>>(istream& in, Multiplicity& object)
{
	for (int i = 0; i < object.size; i++) {
		in >> object.arr[i];
	}

	return in;
}
