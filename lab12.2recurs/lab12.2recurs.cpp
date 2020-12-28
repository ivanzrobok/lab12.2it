#include <iostream>
#include<Windows.h>
using namespace std;

typedef int Info;

struct Elem
{
	Elem* link;
	Info info;
};
void enqueue(Elem*& first, Elem*& last, Info value);
Info dequeue(Elem*& first, Elem*& last);
void delete_el(Info x, Elem* L)
{
	if (L->link->info == x)
	{
		Elem* tmp = L->link->link;
		delete L->link;
		L->link = tmp;

	}
}
void Print(Elem* L)
{
	if (L != NULL)
	{
		cout << L->info<<" ";
		return Print(L->link);
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Elem* first = NULL,
		* last = NULL;
	Info N;
	cout << "Введіть кількість елементів "; cin >> N;
	cout << endl;
	for (int i = 1; i <= N; i++)
	{
		enqueue(first, last, i);
	}

	Print(first);
	cout << endl;
	int x;
	cout << "введіть елемент який хочете видалити ";
	cin >> x;
	cout << "модефікований список" << endl;
	delete_el(x, first);
	Print(first);

	while (first != NULL)
	{
		dequeue(first, last);
	}

	return 0;
}
void enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->link = NULL;
	if (last != NULL)
	{
		last->link = tmp;
	}
	last = tmp;
	if (first == NULL)
	{
		first = tmp;
	}
}
Info dequeue(Elem*& first, Elem*& last)
{
	Elem* tmp = first->link;
	Info value = first->info;
	delete first;
	first = tmp;
	if (first != NULL)
	{
		last = NULL;
	}
	return value;
}