#include "headers.h"
using namespace std;

class String {
	string s;
public:
	String(const string &s) : s(s){}
	String to_lower_copy()const {
		return boost::to_lower_copy(s);
	}
	vector<String> split(const string& delimeter = "  ")const {
		vector<string> parts;
		boost::split(parts, s, boost::is_any_of(delimeter), boost::token_compress_on);
		return vector<String>(parts.begin(), parts.end());
	}
	size_t get_length() const { return s.length(); };
};

//int main(){
//	
//	String s{ "You      Sexy      String" };
//	for (auto& t : s.to_lower_copy().split()){ cout << t.get_length() << '\n'; };
//
//}