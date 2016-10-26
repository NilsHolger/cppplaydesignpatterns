#include "headers.h"
using namespace std;
namespace msm = boost::msm;
namespace mpl = boost::mpl;
using namespace msm::front;

vector<string> state_names{"off hook","connecting","connected","onhold","killed"};
struct CallDialed {};
struct HungUp {};
struct CallConnected {};
struct PlacedOnHold {};
struct TakenOffHold {};
struct LeftMessage {};
struct PhoneThrownAway {};
struct PhoneStateMachine : state_machine_def<PhoneStateMachine>
{
	struct OffHook : state<> {};
	struct Connecting : state<> {};
	struct Connected : state<> {};
	struct OnHold : state<> {};
	struct PhoneKilled : state<> {};
	struct transition_table : mpl::vector<
		Row<OffHook, CallDialed, Connecting>,
		Row<Connecting, CallConnected, Connected>,
		Row<Connected, PlacedOnHold, OnHold>,
		Row<OnHold, PhoneThrownAway, PhoneKilled>> {};
	typedef OffHook initial_state;
};

auto main() -> int
{
	msm::back::state_machine<PhoneStateMachine> phone;
	auto info = [&]()
	{
		auto i = phone.current_state()[0];
		cout << "phone is currently " << state_names[i] << '\n';
	
	};
	info();
	phone.process_event(CallDialed{});
	info();
}

