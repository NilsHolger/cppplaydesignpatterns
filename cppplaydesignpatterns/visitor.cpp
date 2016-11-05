#include "headers.h"

using namespace std;

class Element
{
public:
	virtual void accept(class Visitor &v) = 0;
};


class This : public Element
{
public:
	void accept(Visitor &v);
	string thiss()
	{
		return "This";
	}
};

class That : public Element
{
public:
	void accept(Visitor &v);
	string that()
	{
		return "That";
	}
};

class TheOther : public Element
{
public:
	void accept(Visitor &v);
	string theOther()
	{
		return "TheOther";
	}
};

class Visitor
{
public:
	virtual void visit(This *e) = 0;
	virtual void visit(That *e) = 0;
	virtual void visit(TheOther *e) = 0;
};

void This::accept(Visitor &v)
{
	v.visit(this);
}

void That::accept(Visitor &v)
{
	v.visit(this);
}

void TheOther::accept(Visitor &v)
{
	v.visit(this);
}


class UpVisitor : public Visitor
{
	void visit(This *e)
	{
		cout << "do up on " << e->thiss() << '\n';
	}

	void visit(That *e)
	{
		cout << "do up on " << e->that() << '\n';
	}

	void visit(TheOther *e)
	{
		cout << "do up on " << e->theOther() << '\n';
	}
};

class DownVisitor : public Visitor
{
	void visit(This *e)
	{
		cout << "do down on " << e->thiss() << '\n';
	
	}
	void visit(That *e)
	{
		cout << "do down on " << e->that() << '\n';
	}
	void visit(TheOther *e)
	{
		cout << "do down on " << e->theOther() << '\n';
	}


};


auto main() -> int
{
	Element *list[] = { new This(), new That(), new TheOther() };	  
	UpVisitor up; DownVisitor down;
	for (int i = 0; i < 3; i++) { list[i]->accept(up); }
	for (int i = 0; i < 3; i++) { list[i]->accept(down); }
	getchar();
}