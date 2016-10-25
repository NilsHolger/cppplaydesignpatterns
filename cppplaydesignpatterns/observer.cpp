#include "headers.h"
#include <mutex>
using namespace std;
using namespace boost;

struct Technology;

struct TechnologyListener
{
	virtual ~TechnologyListener() = default;
	virtual void TechnologyChanged(Technology& t,
		const string& property_name, const any new_value) = 0;
};

static mutex mtx;

struct Technology
{
	explicit Technology(const int power) : power(power){}
	virtual int GetPower() const{
		return power;
	}
	virtual void SetPower(const int power){
		if (this->power == power){ return; }

		auto old_p_s = GetPassesStandards();
		this->power = power;
		Notify("power", this->power);
		auto new_p_s = GetPassesStandards();
		if (old_p_s != new_p_s){
			Notify("take", new_p_s);
		}
	}

	bool GetPassesStandards()const {
		return power >= 100;
	}

	void Subscribe(TechnologyListener* tl)
	{
		lock_guard<mutex> guard{ mtx };
		if (find(std::begin(listeners), std::end(listeners), tl) == std::end(listeners)) {
			listeners.push_back(tl);
		}
	}
	void Unsubscribe(TechnologyListener* tl){
		lock_guard<mutex> guard{ mtx };
		for (auto it = listeners.begin(); it != listeners.end(); ++it){
			if (*it == tl){
				*it = nullptr;
			}
		}
	}
	void Notify(const string& property_name, const any new_value){
		lock_guard<mutex> guard{ mtx };
		for (const auto listener : listeners){
			if (listener){
				listener->TechnologyChanged(*this, property_name, new_value);
				listeners.erase(remove(listeners.begin(), listeners.end(), nullptr),
					listeners.end());
			}
		}
	}
private:
	int power;
	vector<TechnologyListener*> listeners;
};

struct WickedListener : TechnologyListener
{
	void TechnologyChanged(Technology& t, const string& property_name, const any new_value)
	{
		t.Unsubscribe(this);
	}
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
		else if (property_name == "take"){
			cout << any_cast<bool>(new_value);
		}
		cout << '\n';
	}
};

//auto main() -> int
//{
//	Technology v8{ 98 };
//	ConsoleListener	cl;
//	//WickedListener cl;
//	v8.Subscribe(&cl);
//	v8.Subscribe(&cl);
//	v8.SetPower(99);
//	v8.SetPower(100);
//	v8.Unsubscribe(&cl);
//	v8.SetPower(101);
//}