#include <iostream>
#include "List.h"
#include "Pair.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	system("color F0");
	int n;
	cout << "Введите размер списка: ";
	cin >> n;
	List<Pair> list(n);
	list.Print();

	Pair sr = list.SredneeAr();
	cout << sr << endl;
	cout << "На какую позицию поставить среднее арифметическое ?" << endl;
	int p;
	cin >> p;
	list.AddInList(sr, p);
	list.Print();

	list.Search();
	list.Print();

	List<Pair> list3(4);
	sr = list3.SredneeAr();
	list3.Decrease(sr);
	list3.Print();
}