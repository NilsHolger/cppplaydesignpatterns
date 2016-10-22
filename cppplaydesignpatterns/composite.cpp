#include "headers.h"
using namespace std;
//interface lowest common denominator
class Component {
public:
	virtual void traverse() = 0;
};

class Leaf : public Component
{
	//scalar class/ is a relationship
	int value;
public:
	Leaf(int val){
		value = val;
	}
	void traverse(){
		cout << value << ' ';
	}
};
class Composite : public Component
{
	//vector class/is a relationship
	vector<Component *> children;
public:
	//container class coupled to interface
	void add(Component *ele){
		children.push_back(ele);
	}
	void traverse(){
		for (int i = 0; i < children.size(); i++){
			//polymorphism delegate to children
			children[i]->traverse();
		}
	}
};
//int main(){
//	const int cmb = 4;
//	const int lmb = 3;
//	Composite containers[cmb];
//	for (int i = 0; i < cmb; i++){
//		for (int j = 0; j < lmb; j++)	{
//			containers[i].add(new Leaf(i * lmb + j));
//		}
//	}
//	for (int i = 1; i < cmb; i++){
//		containers[0].add(&(containers[i]));
//	}
//		for (int i = 0; i < cmb; i++){
//			containers[i].traverse();
//			cout << '\n';
//		}
//}