#pragma once
#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include "Pair.h"
using namespace std;
template <class T>
class List
{
	priority_queue<T, vector<T>, less<T>> queue;
	int length;
public:
	List(void);
	List(int n);
	void Print();
	~List(void);

	T SredneeAr();
	void AddInList(T element, int pos);
	void Search();
	void Decrease(T sr);
};
template <class T>
List<T>::List()
{
	length = 0;
}
template <class T>
List<T>::List(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		queue.push(a);
	}
}
template <class T>
void List<T>::Print()
{
	vector<T> tmp;
	while (!queue.empty())
	{
		tmp.push_back(queue.top());
		queue.pop();
	}
	for (int i = 0; i < tmp.size(); i++)
	{
		cout << i << " элемент: " << tmp[i] << endl;
	}
	for (int i = 0; i < tmp.size(); i++)
	{
		queue.push(tmp[i]);
	}
	tmp.clear();
	cout << endl;
}
template <class T>
List<T>::~List()
{
}
//3
template <class T>
T List<T>::SredneeAr()
{
	vector<T> tmp;
	while (!queue.empty())
	{
		tmp.push_back(queue.top());
		queue.pop();
	}
	T s;
	for (int i = 0; i < tmp.size(); i++) {
		s = s + tmp[i];
	}
	for (int i = 0; i < tmp.size(); i++)
	{
		queue.push(tmp[i]);
	}

	T n(tmp.size(), tmp.size());
	return s / n;
}
template <class T>
void List<T>::AddInList(T element, int pos)
{
	vector<T> tmp;
	int n = queue.size();
	for (int i = 0; i < n; i++)
	{
		if (i == pos)
		{
			tmp.push_back(element);
		}
		tmp.push_back(queue.top());
		queue.pop();
	}
	for (int i = 0; i < tmp.size(); i++)
	{
		queue.push(tmp[i]);
	}
	tmp.clear();
}
//4
template <class T>
void List<T>::Search()
{
	vector<T> tmp;
	int n = queue.size();
	T k1, k2;
	cout << "¬ведите диапазон дл€ поиска в виде двух пар[k1, k2]: ";
	cin >> k1 >> k2;
	for (int i = 0; i < n; i++)
	{
		if (queue.top() < k1 || queue.top() > k2)
		{
			tmp.push_back(queue.top());
		}
		queue.pop();
	}
	for (int i = 0; i < tmp.size(); i++)
	{
		queue.push(tmp[i]);
	}
	tmp.clear();
}
// 5
template <class T>
void List<T>::Decrease(T sr)
{
	vector<T> tmp;
	while (!queue.empty())
	{
		tmp.push_back(queue.top() - sr);
		queue.pop();
	}
	for (int i = 0; i < tmp.size(); i++)
	{
		queue.push(tmp[i]);
	}
	tmp.clear();
}
