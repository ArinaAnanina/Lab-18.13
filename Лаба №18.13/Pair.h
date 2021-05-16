#pragma once
#include <iostream>
using namespace std;

class Pair
{
	int First;
	double Second;
public:
	Pair();
	Pair(int First, double Second);
	Pair(const Pair& p);
	~Pair();
	void Show();
	void SetFirst(int N);
	void SetSecond(double D);
	int GetFirst()
	{
		return First;
	}
	double GetSecond()
	{
		return Second;
	}
	Pair& operator=(const Pair& p);
	Pair operator+(const Pair& p);
	Pair operator-(const Pair& p);
	Pair operator/(const Pair& p);
	friend ostream& operator<< (ostream& out, const Pair& p);
	friend istream& operator>> (istream& in, Pair& p);

	friend Pair operator-(const Pair& l, const Pair& r) {
		Pair p1(l.First - r.First, l.Second - r.Second);
		return p1;
	}

	friend bool operator<(const Pair& l, const Pair& r) {
		return (l.First < r.First) && (l.Second < r.Second);
	}

	friend bool operator>(const Pair& l, const Pair& r) {
		return (l.First > r.First) && (l.Second > r.Second);
	}
	// bool operator< (const Pair& r);
	bool operator> (const Pair& r);

	Pair operator++ (int);
};

