#include <iostream>

struct Complex
{
	double r;
	double v;
	Complex()
	{
		r = v = 0;
	}
};

Complex res;

Complex& 
product(double a, Complex b);

Complex&
product(Complex a, Complex b);


int main()
{
	double a(0);
	Complex b,c;
	Complex d;
	std::cout << "please input a double:" << std::endl;
	std::cin >> a;
	std::cout << "please input two Complexs:" << std::endl;
	std::cin >> b.r >> b.v >> c.r >> c.v;
	std::cout << "double a * Complex b" << std::endl;	
	d = product(a, b);
	std::cout << d.r << "+" << d.v << "i" << std::endl;
	std::cout << "Complex b * Complex c" << std::endl;
	d = product(b,c);
	std::cout << d.r << "+" << d.v << "i" << std::endl;

	return 0;
}



Complex&
product(double a, Complex b)
{

	res.r = a * b.r;
	res.v = a * b.v;
	return res;
}

Complex&
product(Complex a, Complex b)
{
	res.r = a.r*b.r - a.v*b.v;
	res.v = a.r*b.v + a.v*b.r;
	return res;
}