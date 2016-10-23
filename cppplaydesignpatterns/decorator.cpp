#include "headers.h"
using namespace std;

struct Shape {
    virtual string str() const = 0;
};
struct Circle : Shape {
    float radius;
    explicit Circle(const float radius): radius{radius}{}
    string str() const override
    {
        ostringstream oss;
        oss << "circle with radius " << radius;
        return oss.str();
    }
};
struct Square : Shape {
    float side;
    explicit Square(const float side) : side(side){}
    string str() const override
    {
        ostringstream oss;
        oss << "square with side " << side;
    }
};
struct ColoredShape : Shape
{
    Shape& shape;
    string color;
    ColoredShape(Shape& shape, const string& color): shape{shape}, color{color}{}
    string str() const override
    {
        ostringstream oss;
        oss << shape.str() << " has color " << color;
        return oss.str();
    }
};
struct TransparentShape : Shape
{
    Shape& shape;
    uint8_t transparency;
    TransparentShape(Shape& shape, const uint8_t transparency): shape{shape}, transparency{transparency}{}
    string str() const override
    {
        ostringstream oss;
        oss << shape.str() << " has " << static_cast<float>(transparency) / 255.f * 100.f << " % transparency";
        return oss.str();
    }
};

int main(){
    Circle c{10};
    cout << c.str() << '\n';
    ColoredShape blue_c{c, "blue"};
    cout << blue_c.str() << '\n';
    TransparentShape qrtr_trpnt_c{c, 64};
    cout << qrtr_trpnt_c.str() << '\n';
    TransparentShape ten_trpnt_blue_c{blue_c, 25};
    cout << ten_trpnt_blue_c.str() << '\n';
}
