#pragma once
#include "headers.h"
using namespace std;

struct HT
{
	virtual void b(int e) = 0;
};

struct A : HT
{
	void b(int e)
	{
		cout << "a -> d -> i " << e << '\n';
	}
};

struct X : HT
{
	void b(int e)
	{
		cout << "c -> mc -> a " << e << '\n';
	}
};


