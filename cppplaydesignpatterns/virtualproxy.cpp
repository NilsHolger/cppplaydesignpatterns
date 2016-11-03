#include "headers.h"

using namespace std;

struct Technology
{
	virtual ~Technology() = default;
	virtual void increase(int power) = 0;
	virtual void decrease(int power) = 0;
};

struct NewTechnology : Technology
{
	explicit NewTechnology(const int status) : status(status){}

	void increase(int power) override
	{
		status += power;
	}
	void decrease(int power) override
	{
		status -= power;
	}
	friend ostream& operator <<(ostream& os, const NewTechnology& obj)
	{
		return os << "status: " << obj.status;
	}
private:
	int status;
};

void smart_pointers()
{
	Technology* t = new NewTechnology{ 100 };
	t->increase(1);
	delete t;

	shared_ptr<NewTechnology> u = make_shared<NewTechnology>(1000);
	u->increase(1);

	NewTechnology* underlying = u.get();

	cout << *u << '\n';
}

struct Image
{
	virtual ~Image() = default;
	virtual void draw() = 0;
};

struct Bitmap : Image
{
	Bitmap(const string& fileName)
	{
		cout << "loading the file from " << fileName << '\n';
	}
	void draw() override
	{
		cout << "draw an image" << '\n';
	}
};

struct LazyBitmap : Image
{
	LazyBitmap(const string& fileName) : fileName(fileName), bmp(nullptr)
	{
	}
	~LazyBitmap()
	{
		delete bmp;
	}
	void draw() override
	{
		if (!bmp) { bmp = new Bitmap{ fileName }; }
		bmp->draw();
	}
private:
	Bitmap* bmp;
	string fileName;
};

void draw_image(Image& image)
{
	cout << "about to draw the image" << '\n';
	image.draw();
	cout << "done drawing the image" << '\n';
}

void virtual_proxy()
{
	LazyBitmap bmp{ "node.png" };
	draw_image(bmp); draw_image(bmp);
}


auto main() -> int
{
	virtual_proxy();
	//smart_pointers();
	getchar();
}