
#include "headers.h"
using namespace std;
enum class State {
	OffHook,
	Connecting,
	Connected,
	OnHold
};
inline ostream& operator<<(ostream& os, const State& s)
{
	switch (s)
	{
	case::State::OffHook:
		os << "off the hook";
		break;
	case::State::Connecting:
		os << "connecting";
		break;
	case::State::Connected:
		os << "connected";
		break;
	case::State::OnHold:
		os << "on hold";
		break;
	}
	return os;
}

enum class Trigger {
	CallDialed,
	HungUp,
	CallConnected,
	PlacedOnHold,
	TakenOffHold,
	LeftMessage
};

inline ostream& operator<<(ostream& os, const Trigger& t)
{
	switch (t)
	{
	case::Trigger::CallDialed:
		os << "call dialed";
		break;
	case::Trigger::HungUp:
		os << "hung up";
		break;
	case::Trigger::CallConnected:
		os << "call connected";
		break;
	case::Trigger::TakenOffHold:
		os << "taken off hold";
		break;
	case::Trigger::LeftMessage:
		os << "get it done";
		break;
	default: break;
	}
	return os;
}

//auto main()	-> int
//{
//	map<State, vector<pair<Trigger, State>>> rules;
//	rules[State::OffHook] = {
//		{
//			Trigger::CallDialed, State::Connecting
//		}
//	};
//	rules[State::Connecting] = {
//		{
//			Trigger::HungUp, State::OffHook
//		},
//		{
//			Trigger::CallConnected, State::Connected
//		}
//	};
//	rules[State::Connected] = {
//		{
//			Trigger::LeftMessage, State::OffHook
//		},
//		{
//			Trigger::HungUp, State::OffHook
//		},
//		{
//			Trigger::PlacedOnHold, State::OnHold
//		}
//	};
//	rules[State::OnHold] = {
//		{
//			Trigger::TakenOffHold, State::Connected
//		},
//		{
//			Trigger::HungUp, State::OffHook
//		}
//	};
//
//	State currentState{ State::OffHook };
//	while (true)
//	{
//		cout << "phone is currently " << currentState << '\n';
//		select_trigger:
//		cout << "select a trigger: " << '\n';
//
//		int i = 0;
//		for (auto item : rules[currentState])
//		{
//			cout << i++ << ". " << item.first << '\n';
//		}
//		int input;
//		cin >> input;
//		if (input < 1 || (input + 1) > rules[currentState].size())
//		{
//			cout << "incorrect option. give it another shot.\n";
//			goto select_trigger;
//		}
//		currentState = rules[currentState][input].second;
//	}
//	cout << "done using the phone" << '\n';
//}
