#include "headers.h"
using namespace std;
typedef int Coordinate;
typedef int Dimension;

//desired interface
class Rectangle {
public:
	virtual void draw() = 0;
};

//legacy component
class LegacyRectangle {
public:
	LegacyRectangle(Coordinate x1, Coordinate y1, Coordinate x2, Coordinate y2){
		x1_ = x1;
		y1_ = y1;
		x2_ = x2;
		y2_ = y2;
		cout << "LegacyRectangle: create. (" << x1_ << "," << y1_ << ") => ("
			<< x2_ << "," << y2_ << ")" << "\n";
	}
	void oldDraw(){
		cout << "LegacyRectangle: oldDraw. (" << x1_ << "," << y1_ <<
			") => (" << x2_ << "," << y2_ << ")" << '\n';
	}
private:
	Coordinate x1_;
	Coordinate y1_;
	Coordinate x2_;
	Coordinate y2_;
};
class RectangleAdapter : public Rectangle, private LegacyRectangle {
public:
	RectangleAdapter(Coordinate x, Coordinate y, Dimension w, Dimension h)
	: LegacyRectangle(x, y, x + w, y + h)
	{
		cout << "RectangleAdapter: create. (" << x << "," << y << "), width ="
			<< w << ", height = " << h << '\n';
	}
	virtual void draw()
	{
		cout << "RectangleAdapter: draw " << '\n';
		oldDraw();
	}
};

int main() {
	Rectangle *r = new RectangleAdapter(40, 100, 20, 10);
	r->draw();
}