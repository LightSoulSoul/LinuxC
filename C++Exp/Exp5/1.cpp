#include <iostream>
#include <cstring>

class Fan
{
public:
	Fan():speed(0), on(false), radius(0) { };
	~Fan() { } ;
	//default is zeor
	inline void SetSpeed(double speed = 0.0);
	//false is off, true is on
	inline void SetStatus(bool on = false);
	//default radius is zeor
	inline void SetRadius(double radius = 0.0);
	//default color is null
	inline void SetColor(std::string color = "");
	//show all options
	inline void display();
private:
	double speed;
	bool on;
	double radius;
	std::string color;
};

int main()
{
	Fan f1, f2;
	f1.SetSpeed(3);
	f1.SetRadius(10);
	f1.SetStatus(true);
	f1.SetColor("yellow");
	f1.display();
	std::cout << std::endl;
	f2.SetSpeed(2);
	f2.SetRadius(5);
	f2.SetStatus(false);
	f2.SetColor("blue");
	f2.display();
    return 0;
}

inline void 
Fan::SetSpeed(double speed)
{
	this->speed = speed;
}

inline void 
Fan::SetRadius(double radius)
{
	this->radius = radius;
}

inline void 
Fan::SetStatus(bool on)
{
	this->on = on;
}

inline void
Fan::SetColor(std::string color)
{
	this->color = color;
}

inline void 
Fan::display()
{
	std::cout << "Speed: " << this->speed << std::endl;
	std::cout << "Radius: " << this->radius << std::endl;
	std::cout << "Status: " << (this->on == true ? "On" : "Off") << std::endl;
	std::cout << "Color: " << this->color << std::endl;
}