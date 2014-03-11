#include <iostream>

class CPoint
{
public:
	CPoint(double X = 0.0, double Y = 0.0):
			x(X), y(Y) { }
//	CPoint(): x(0), y(0) { }
	~CPoint() { } ;
	
	//Set sth.
	double SetX(double x)
	{ this->x = x; }
	double SetY(double y)
	{ this->y = y;}

	//Get sth.
	double GetX() const
	{ return this->x; }
	double GetY() const
	{ return this->y; }

private:
	double x, y;
};

class CRectangle
{
public:
	CRectangle(const CPoint& ld, const CPoint& ru)
	{ this->leftdown.SetX(ld.GetX()); this->leftdown.SetY(ld.GetY()); 
	  this->rightup.SetX(ru.GetX());  this->rightup.SetY(ru.GetY()); }
	~CRectangle() { }

	void SetLPoitn(const CPoint& ld)
	{ this->leftdown.SetX(ld.GetX()); this->leftdown.SetY(ld.GetY()); }
	void SetRPoint(const CPoint& ru)
	{ this->rightup.SetX(ru.GetX()); this->rightup.SetY(ru.GetY()); }

	double GetPerimeter() const
	{ return 2.0*(rightup.GetX()-leftdown.GetX()) + 2.0*(rightup.GetY()-leftdown.GetY()); }
	double GetArea() const
	{ return (rightup.GetX()-leftdown.GetX()) * (rightup.GetY()-leftdown.GetY()); }

private:
	CPoint leftdown, rightup;
};


int main()
{
	CPoint ld(2,5); CPoint ru(6,8);
	CRectangle* a_rectangle = new CRectangle(ld, ru);

	std::cout << "Perimeter: " << a_rectangle->GetPerimeter() << std::endl;
	std::cout << "Area: " << a_rectangle->GetArea() << std::endl;

	return 0;
}