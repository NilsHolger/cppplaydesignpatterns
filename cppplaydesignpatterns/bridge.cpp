#include "headers.h";
using namespace std;

class TimeImp {
public:
	TimeImp(int hr, int min) {
		hr_ = hr;
		min_ = min;
	}
	virtual void tellmeallyoursecrets() {
		cout << "time is " << hr_ << ':' << min_ << endl;
	}
protected:
	int hr_, min_;
};

class CivilianTimeImp : public TimeImp {
public:
	CivilianTimeImp(int hr, int min, int pm) : TimeImp(hr, min) {
		pm ? strcpy(whichM_, " PM") : strcpy(whichM_, " AM");
	}

	void tellmeallyoursecrets() {
		cout << "time is " << hr_ << ':' << min_ << whichM_ << endl;
	}
protected:
	char whichM_[4];
};

class ZuluTimeImp : public TimeImp {
public:
	ZuluTimeImp(int hr, int min, int zone) : TimeImp(hr, min) {
		zone ? strcpy(zone_, " D Standard Time") : strcpy(zone_, " ROW Standard Time");
	}
	void tellmeallyoursecrets() {
		cout << "time is " << hr_  << ':' << min_ << zone_ <<
			endl;
	}
protected:
	char zone_[30];
};

class Time {
public:
	Time(){}
	Time(int hr, int min) {
		imp_ = new TimeImp(hr, min);
	}
	virtual void tellmeallyoursecrets() {
		imp_->tellmeallyoursecrets();
	}
protected:
	TimeImp *imp_;
};

class CivilianTime : public Time {
public:
	CivilianTime(int hr, int min, int pm) {
		imp_ = new CivilianTimeImp(hr, min, pm);
	}
};

class ZuluTime : public Time {
public:
	ZuluTime(int hr, int min, int zone) {
		imp_ = new ZuluTimeImp(hr, min, zone);
	}
};

auto main() -> int 
{
	Time *times[3];
	times[0] = new Time(11, 11);
	times[1] = new CivilianTime(11, 11, 1);
	times[2] = new ZuluTime(11, 11, 1);
	for (int i = 2; i >= 0; --i){
		times[i]->tellmeallyoursecrets();
	}
	getchar();
}