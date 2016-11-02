#include "headers.h"

using namespace std;

class Memento
{
	int balance;
public:
	Memento(const int balance) : balance(balance){}
	friend class BankAccount;
	friend class BankAccount2;
};

class BankAccount
{
	int balance = 0;
	vector<shared_ptr<Memento>> changes;
	int current;
public:
	explicit BankAccount(const int balance) : balance(balance)
	{
		changes.emplace_back(make_shared<Memento>(balance));
		current = 0;
	}
	void restore(shared_ptr<Memento>& m)
	{
		if (m)
		{
			balance = m->balance;
			changes.push_back(m);
			current = changes.size() - 1;
		}
	}
	shared_ptr<Memento> deposit(int amount)
	{
		balance += amount;
		auto m = make_shared<Memento>(balance);
		changes.push_back(m);
		++current;
		return m;
	}
	shared_ptr<Memento> undo()
	{
		if (current > 0)
		{
			--current;
			auto m = changes[current];
			balance = m->balance;
			return m;
		}
		return{};
	}
	shared_ptr<Memento> redo()
	{
		if (current + 1 < changes.size())
		{
			++current;
			auto m = changes[current];
			balance = m->balance;
			return m;
		}
		return{};
	}
	friend ostream& operator <<(ostream& os, const BankAccount& obj)
	{
		return os << "balance " << obj.balance;
	}
};


//auto main()	-> int
//{
//	BankAccount ba{ 1000 };
//	ba.deposit(500);
//	ba.deposit(250);
//	cout << ba << '\n'; //1750
//	ba.undo();
//	cout << ba << '\n';	 //1500
//	ba.undo();
//	cout << ba << '\n';	 //1000
//	ba.redo();
//	cout << ba << '\n'; //1500
//	ba.redo();
//	cout << ba << '\n'; //1750
//	getchar();
//}