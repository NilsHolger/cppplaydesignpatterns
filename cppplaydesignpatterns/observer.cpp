#include "headers.h"
using namespace std;
using namespace boost;

struct Technology;

struct TechnologyListener
{
	virtual ~TechnologyListener() = default;
	virtual void TechnologyChanged(Technology& t,
		const string& property_name, const any new_value) = 0;
};

struct Technology
{
	explicit Technology(const int power) : power(power){}
	virtual int GetPower() const{
		return power;
	}
	virtual void SetPower(const int power){
		if (this->power == power){ return; }
		this->power = power;
		notify("power", this->power);
	}
	void subscribe(TechnologyListener* tl)
	{
		listeners.push_back(tl);
	}
	void notify(const string& property_name, const any new_value){
		for (const auto listener : listeners){
			listener->TechnologyChanged(*this, property_name, new_value);
		}
	}
private:
	int power;
	vector<TechnologyListener*> listeners;
};

struct ConsoleListener : TechnologyListener
{
	void TechnologyChanged(Technology& t, const string& property_name, const any new_value)
	{
		cout << "technologies " << property_name << " has changed to ";
		if (property_name == "power")
		{
			cout << any_cast<int>(new_value);
		}
		cout << '\n';
	}
};

auto main() -> int
{
	Technology v8{ 100 };
	ConsoleListener cl;
	v8.subscribe(&cl);
	v8.SetPower(10000);
	v8.SetPower(1000000);
}