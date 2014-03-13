#include <iostream>
#define PI 3.14159
using std::cout;
using std::cin;
using std::endl;;

class CStereoShape
{
public:
	CStereoShape() { }
	~CStereoShape() { }
	virtual double GetArea() const { }
	virtual double GetVolume() const { }
private:
};

class CCube : public CStereoShape
{
public:
	CCube() { }
	CCube(const double L, const double W, const double H):
			l(L), w(W), h(H) { }
	~CCube() { }
	void SetPar(const double L, const double W, const double H)
	{ l = L; w = W; h = H; }

	double GetArea() const
	{ return l*w*2 + l*h*2 + h*w*2; }
	double GetVolume() const
	{ return l*w*h; }

private:
	double l, w, h;
};

class CSphere : public CStereoShape
{
public:
	CSphere() { }
	~CSphere() { }
	CSphere(const double R) : r(R) { }
	void SetR(const double R)
	{ this->r = R; }
	double GetArea() const 
	{ return 4*PI*r*r; }
	double GetVolume() const 
	{ return (4.0*PI*r*r*r)/3.0; }

private:
	double r;
};


int main()
{
	CCube a_cube;
	CSphere a_sphere;
	CStereoShape *p;
	a_cube.SetPar(4,5,6);
	p = &a_cube;
	cout << "Cube:\n" << "Area: " << p->GetArea() 
		 << "\tVolume: " << p->GetVolume() << endl;
	a_sphere.SetR(7);
	p = &a_sphere;
	cout << "Sphere:\n" << "Area: " << p->GetArea()
		 << "\tVolume: " << p->GetVolume() << endl;
	return 0;
}
