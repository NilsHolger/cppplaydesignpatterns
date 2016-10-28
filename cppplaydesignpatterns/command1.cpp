#include "headers.h"
using namespace std;
class Person;

class Command
{
	Person *object;
	void(Person:: *method)();
public:
	Command(Person *obj = 0, void(Person:: *meth)() = 0)
	{
		object = obj;
		method = meth;
	}
	void execute()
	{
		(object->*method)();
	}
};

class Person
{
	string name;
	Command cmd;
public:
	Person(string n, Command c) : cmd(c)
	{
		name = n;
	}
	void talk()
	{
		cout << name << " is talking" << '\n';
		cmd.execute();
	}
	void passOn()
	{
		cout << name << " is passing on" << '\n';
		cmd.execute();
	}
	void gossip()
	{
		cout << name << " is gossiping" << '\n';
		cmd.execute();
	}
	void listen()
	{
		cout << name << " is listening" << '\n';
	}
};

auto main() -> int
{
	Person carol("Carol", Command());
	Person mary("Mary", Command(&carol, &Person::listen));
	Person bettina("Bettina", Command(&mary, &Person::gossip));
	Person sophie("Sophie", Command(&bettina, &Person::passOn));
	sophie.talk();
}
