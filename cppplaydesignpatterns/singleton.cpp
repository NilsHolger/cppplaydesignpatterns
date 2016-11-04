#include "headers.h"
using namespace std;

class GlobalClass
{
	int i_value;
	static GlobalClass *s_instance;
	GlobalClass(int d = 1)
	{
		i_value = d;
	}
public:
	int get_value()
	{
		return i_value;
	}
	void set_value(int d)
	{
		i_value = d;
	}
	static GlobalClass *instance()
	{
		if (!s_instance)
		{
			s_instance = new GlobalClass;
		}
		return s_instance;
	}
};

GlobalClass *GlobalClass::s_instance = 0;

void a(void)
{
	GlobalClass::instance()->set_value(10);
	cout << "a: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
}

void b(void)
{
	GlobalClass::instance()->set_value(100);
	cout << "b: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
}


//auto main() -> int
//{
//	cout << "m: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
//	a();
//	b();
//	getchar();
//}

