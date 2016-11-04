#include "headers.h"
#include "hottechnology.h"

using namespace std;
unique_ptr<HT> make_t(string t)
{
	unique_ptr<HT> ht;
	if (t == "a")
	{
		ht = make_unique<A>();
		ht->b(100);
	}
	else
	{
		ht = make_unique<X>();
		ht->b(10);
	}
	return ht;
}
//auto main() -> int
//{
//	auto a = make_t("a");
//	getchar();
//}