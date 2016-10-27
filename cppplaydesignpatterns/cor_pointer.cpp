#include "headers.h"
using namespace std;
struct Animal
{
	string name;
	int attack, defense;
	Animal(const string& name, const int attack, const int defense)
		: name(name),
		attack(attack),
		defense(defense)
	{
	}
	friend std::ostream& operator<<(std::ostream& os, const Animal& obj)
	{
		return os
			<< "name: " << obj.name
			<< " attack: " << obj.attack
			<< " defense: " << obj.defense;
	}
};
class AnimalModifier
{
	AnimalModifier* next = nullptr;
protected:
	Animal& animal;
public:

	explicit AnimalModifier(Animal& animal)
		: animal(animal)
	{
	}
	virtual ~AnimalModifier() = default;

	void add(AnimalModifier* cm)
	{
		if (next) next->add(cm);
		else next = cm;
	}
	virtual void handle()
	{
		if (next) next->handle();
	}
};
class NoBonusModifier : public AnimalModifier
{
public:
	explicit NoBonusModifier(Animal& animal)
		: AnimalModifier(animal)
	{
	}
	void handle() override
	{
	}
};

class DoubleAttackModifier : public AnimalModifier
{
public:
	explicit DoubleAttackModifier(Animal& creature)
		: AnimalModifier(creature)
	{
	}
	void handle() override
	{
		animal.attack *= 2;
		AnimalModifier::handle();
	}
};
class IncreaseDefenseModifier : public AnimalModifier
{
public:
	explicit IncreaseDefenseModifier(Animal& creature)
		: AnimalModifier(creature)
	{
	}
	void handle() override
	{
		if (animal.attack <= 2)
			animal.defense++;
		AnimalModifier::handle();
	}
};

//auto main() -> int
//{
//	Animal lion{ "Lion", 1, 1 };
//	AnimalModifier root{ lion };
//	DoubleAttackModifier r1{ lion };
//	DoubleAttackModifier r1_2{ lion };
//	IncreaseDefenseModifier r2{ lion };
//	//NoBonusModifier nob{ lion };
//	//root.add(&nob);
//	root.add(&r1);
//	root.add(&r1_2);
//	root.add(&r2);
//	root.handle();
//	cout << lion << '\n';
//}
