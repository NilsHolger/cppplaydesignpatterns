#include "headers.h"
using namespace std;
//using namespace boost::signals2;

struct Query
{
	string animal_name;
	enum Argument { attack, defense}argument;
	int result;
	Query(const string& animal_name, const Argument argument, const int result) : 
		animal_name(animal_name), argument(argument), result(result){}
};
struct Game
{
	boost::signals2::signal<void(Query&)> queries;
};

struct Animal
{
	Game& game;
	int attack, defense;
public:
	Animal(Game& game, const int attack, const int defense, const string& name) :
		game(game), attack(attack), defense(defense), name(name){}
	string name;
	int GetAttack()	const
	{
		Query q{ name, Query::Argument::attack, attack };
		game.queries(q);
		return q.result;
	}
	int GetDefense() const
	{
		Query q{ name, Query::Argument::defense, defense };
		game.queries(q);
		return q.result;
	}
	friend std::ostream& operator << (std::ostream& os, const Animal& obj)
	{
		return os
			<< "attack: " << obj.GetAttack()
			<< " defense: " << obj.GetDefense()
			<< " name: " << obj.name;
	}
};
class AnimalModifier
{
	Game& game;
	Animal& animal;
public:
	AnimalModifier(Game& game, Animal& animal) : game(game), animal(animal){}
	virtual ~AnimalModifier() = default;
};

class DoubleAttackModifier : public AnimalModifier
{
	boost::signals2::connection conn;
public:
	DoubleAttackModifier(Game& game, Animal& animal) : AnimalModifier(game, animal)
	{
		game.queries.connect([&](Query& q)
		{
			if (q.animal_name == animal.name &&
				q.argument == Query::Argument::attack)
			{
				q.result *= 10;
			}
			else if (q.animal_name == animal.name &&
				q.argument == Query::Argument::defense)
			{
				q.result *= 100;
			}
		});
	}
	virtual ~DoubleAttackModifier()
	{
		conn.disconnect();
	}
};

auto main() -> int
{
	Game game;
	Animal lion{ game, 10, 10, "Open Source" };
	cout << lion << '\n';
	DoubleAttackModifier d{ game, lion };
	cout << lion << '\n';
}