#include <iostream>

#define FRIEND

class Complex
{
public:
	Complex() { }
	~Complex() { }
	Complex(const double r, const double v)
	{ this->r = r; this->v = v; }
	double GetR()
	{ return this->r; }
	double GetV()
	{ return this->v; }
	#ifdef MEMBER
	//override as a member of class
	void operator-=(const Complex &rhs)
	{ v = v - rhs.v; r = r - rhs.r; }
	#endif
	#ifdef FRIEND
	friend Complex& operator-=(Complex &lhs, const Complex& rhs);
	#endif
private:
	double r, v;
};

int main()
{
	Complex c1(10,20), c2(15,30);
	c2 -= c1;
	std::cout << c2.GetR() << " " << c2.GetV() << std::endl;

	return 0;
}

#ifdef FRIEND
Complex& operator-=(Complex &lhs, const Complex &rhs)
{
	lhs.v = lhs.v - rhs.v;
	lhs.r = lhs.r - rhs.r;
	return lhs;
}

#endif