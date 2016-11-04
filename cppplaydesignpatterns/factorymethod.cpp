#include "headers.h"

using namespace std;

const double PI4 = 3.14159265359 / 4;

class Point
{
	Point(const float x, const float y) : x{ x }, y{ y } {}
public:
	float x, y;
	friend std::ostream& operator<<(std::ostream& os, const Point& obj)
	{
		return os << "x: " << obj.x << " y: " << obj.y << '\n';
	}
	friend class PointFactory;
};

class PointFactory
{
public:
	static Point NewCartesian(const float x, const float y)
	{
		return{ x, y };
	}

	static Point NewPolar(const float r, const float theta)
	{
		return{ r * cos(theta), r * sin(theta) };
	}
};


auto main() -> int
{
	auto c = PointFactory::NewCartesian(0, 1);
	auto p = PointFactory::NewPolar(1, PI4);
	cout << c << '\n';
	cout << p << '\n';
	getchar();
}