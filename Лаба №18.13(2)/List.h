#pragma once
#include <iostream>
#include <map>
#include <vector>
using namespace std;
template <class T>
class List
{
	multimap<int,T> m;
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
		m.insert(make_pair(i, a));
	}
}
template <class T>
void List<T>::Print()
{
	for ( int i =0;i<m.size(); i++)
	{
		auto it = m.find(i);
		cout << i << " элемент: " << it->second << endl;
	}
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
	T s;
	for (int i = 0; i < m.size(); i++) {
		auto it = m.find(i);
		s = s + it->second;
	}
	T n(m.size(), m.size());
	return s / n;
}
template <class T>
void List<T>::AddInList(T element, int pos)
{
	vector<T> tmp;
	for (int i = 0; i < m.size(); i++)
	{
		auto it = m.find(i);
		if (i == pos)
		{
			tmp.push_back(element);
		}
		tmp.push_back(it->second);
	}
	m.clear();
	for (int j = 0; j < tmp.size(); j++)
	{
		m.insert(make_pair(j, tmp[j]));
	}
}
//4
template <class T>
void List<T>::Search()
{
	vector <T> tmp;
	T k1, k2;
	cout << "¬ведите диапазон дл€ поиска в виде двух пар[k1, k2]: ";
	cin >> k1 >> k2;
	int j = 0;
	for (int i = 0; i < m.size(); i++)
	{
		auto it = m.find(i);
		if (it->second < k1 || it->second > k2)
		{
			tmp.push_back(it->second);
		}
	}
	m.clear();
	for (int i = 0; i < tmp.size(); i++)
	{
		m.insert(make_pair(i, tmp[i]));
	}
}
// 5
template <class T>
void List<T>::Decrease(T sr)
{
	for (int i = 0; i < m.size(); i++)
	{
		auto it = m.find(i);
		it->second = it->second - sr;
	}
}
