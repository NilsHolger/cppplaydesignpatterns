//#include "headers.h"
//using namespace std;
//
//struct Logger {
//	function<void()> func;
//	string name;
//	Logger(const function<void()>& func, const string& name) : 
//		func{ func }, name{ name }{}
//	void operator()() const {
//		cout << "entering " << name << '\n';
//		func();
//		cout << "exiting " << name << '\n';
//	}
//};
//template<typename Func>
//struct Logger1 {
//	Func func;
//	string name;
//	Logger1(Func func, const string& name) :
//		func{ func }, name{ name }{}
//	void operator()() const {
//		cout << "entering " << name << '\n';
//		func();
//		cout << "exiting " << name << '\n';
//	}
//};
//template<typename Func> auto make_logger1(Func func, const string& name){
//	return Logger1<Func>{func, name};
//}
//template<typename R, typename ... Args>
//struct Logger2{
//	function<R(Args ...)> func;
//	string name;
//	Logger2(const function<R(Args ...)> )
//};


//int main(){
//	auto logger = make_logger1([](){ cout << "Hello" << '\n'; }, "HelloFunc");
//	logger();
//}