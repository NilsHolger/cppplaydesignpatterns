#include "headers.h"
using namespace std;
class Base {
	//next pointer in base class
	Base *next;
public:
	Base()
	{
		next = 0;
	}
	void setNext(Base *n)
	{
		next = n;
	}
	void add(Base *n)
	{
		if (next){ next->add(n); }
		else { next = n; }
	}
	//chain method always delegates to next obj
	virtual void handle(int i)
	{
		next->handle(i);
	}
};
class Handler1 : public Base
{
public:
	void handle(int i)
	{
		if (rand() % 4)
		{
			cout << "H1 passed " << i << " ";
			Base::handle(i);
		}
		else
		{
			cout << "H1 handled " << i << " ";
		}
	}
};

class Handler2 : public Base
{
public:
	void handle(int i)
	{
		if (rand() % 4)
		{
			cout << "H2 passed " << i << " ";
			Base::handle(i);
		}
		else
		{
			cout << "H2 handled " << i << " ";
		}
	}
};

class Handler3 : public Base
{
public:
	void handle(int i)
	{
		if (rand() % 4)
		{
			cout << "H3 passed " << i << " ";
			Base::handle(i);
		}
		else
		{
			cout << "H3 handled " << i << " ";
		}
	}
};
class Handler4 : public Base
{
public:
	void handle(int i)
	{
		if (rand() % 4)
		{
			cout << "H4 passed " << i << " ";
			Base::handle(i);
		}
		else
		{
			cout << "H4 handled " << i << " ";
		}
	}
};

auto main() -> int
{
	srand(time(0));
	Handler1 root;Handler2 two;Handler3 three;Handler4 four;
	root.add(&two);root.add(&three);root.add(&four);four.setNext(&root);
	for (int i = 1; i < 10; i++)
	{
		root.handle(i);
		cout << '\n';
	}
}