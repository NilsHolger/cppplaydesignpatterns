#include "headers.h"

using namespace std;
using namespace boost;

typedef uint32_t key;

struct User
{
	User(const string& first_name, const string& last_name) : 
		first_name(add(first_name)), last_name(add(last_name))
	{
	}
	const string& get_first_name()
	{
		return names.left.find(first_name)->second;
	}
	const string& get_last_name()
	{
		return names.left.find(last_name)->second;
	}

	friend ostream& operator<<(ostream& os, User& obj)
	{
		return os
			<< "first name: " << obj.first_name << " " << obj.get_first_name()
			<< " last name: " << obj.last_name << " " << obj.get_last_name();
	}

protected:
	static bimap<key, string> names;
	static int seed;
	key add(string s)
	{
		auto it = names.right.find(s);
		if (it == names.right.end())
		{
			key id = ++seed;
			names.insert(bimap<key, string>::value_type(seed, s));
			return id;
		}
		return it->second;
	}
	key first_name, last_name;
};

int User::seed = 0;
bimap<key, string> User::names{};

//auto main() -> int
//{
//	User hanna_fox{ "Hanna", "Fox" };
//	User maria_fox{ "Maria", "Fox" };
//	User sophia_fox{ "Sophia", "Fox" };
//
//	cout << "Hanna " << hanna_fox << '\n';
//	cout << "Maria " << maria_fox << '\n';
//	cout << "Sophia " << sophia_fox << '\n';
//	getchar();
//}
