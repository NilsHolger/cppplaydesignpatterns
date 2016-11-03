#include "headers.h"

using namespace std;

class MA
{
public:
	virtual MA* clone() = 0;
	virtual void collect_data() = 0;
};
class Factory
{
public:
	static MA* make_ma(int selection);
private:
	static MA* s_prototypes[4];
};

class CA0 : public MA
{
	MA* clone() { return new CA0; }
	void collect_data()
	{
		cout << "CA0: collect data memory 0\n";
	}
};
class CA1 : public MA
{
	MA* clone() { return new CA1; }
	void collect_data()
	{
		cout << "CA1: collect data memory 1\n";
	}
};
class CA2 : public MA
{
	MA* clone() { return new CA2; }
	void collect_data()
	{
		cout << "CA2: collect data memory2\n";
	}
};
MA* Factory::s_prototypes[] = { 0, new CA0, new CA1, new CA2 };
MA* Factory::make_ma(int selection){ return s_prototypes[selection]->clone(); }

//auto main() -> int
//{
//	vector roles;
//	int selection;
//
//	while (true)
//	{
//		cout << "CA0(1), CA1(2), CA2(3), Launch(0): ";
//		cin >> selection;
//		if (selection == 0)
//		{
//			break;
//		}
//		roles.push_back(Factory::make_ma(selection));
//
//		for (int i = 0; i < roles.size(); i++)
//		{
//				roles[i]->collect_data();
//		}
//		for (int i = 0; i < roles.size(); i++)
//		{
//				delete roles[i];
//		}
//	}
//	getchar();
//}
