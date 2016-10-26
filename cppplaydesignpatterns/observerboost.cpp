#include "headers.h"

using namespace std;
using namespace boost;

template<typename T>
struct INotifyPropertyChanged
{
	virtual ~INotifyPropertyChanged() = default;
	signals2::signal<void(T&, const string&)> PropertyChanged;
};

struct SexyLady : INotifyPropertyChanged<SexyLady>
{
	explicit SexyLady(const int shoesize) : shoesize(shoesize)
	{
	}
	virtual int GetShoeSize()
	{
		return shoesize;
	}

	virtual void SetShoeSize(const int shoesize)
	{
		if (this->shoesize == shoesize){ return; }
		this->shoesize = shoesize;
		PropertyChanged(*this, "shoesize");
	}
private:
	int shoesize;
};

//auto main() -> int
//{
//	SexyLady S{ 37 };
//	S.PropertyChanged.connect([](SexyLady&, const string& property_name)
//	{
//		cout << property_name << " has changed " << '\n';
//	});
//	S.SetShoeSize(38);
//}


