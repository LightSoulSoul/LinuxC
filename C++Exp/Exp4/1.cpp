#include <iostream>
#include <cmath>

const double PI = 3.14159;

int
conver(double r, double ang, double *x, double *y);

int
conver(double r, double ang, double& x, double& y);

int main()
{
    double r(0), ang(0);
    double x(0), y(0);
    std::cout << "Please input the r and the angel:" << std::endl;
    std::cin >> r >> ang ;

    std::cout << "1.address:" << std::endl;
    conver(r, ang, &x, &y);
    std::cout << "(" << r << "," <<  ang << ")" << "-->" << "(" << x << "," << y << ")";
    std::cout << std::endl;

    std::cout << "2.quote:" << std::endl;
    conver(r, ang, x, y);
    std::cout << "(" << r << "," <<  ang << ")" << "-->" << "(" << x << "," << y << ")";
    std::cout << std::endl;

    return 0;
}

int
conver(double r, double ang, double *x, double *y)
{
	ang = ang * PI/180.0;
	*x = r * cos(ang);
	*y = r * sin(ang);
	return 0;
}



int
conver(double r, double ang, double& x, double& y)
{
	ang = ang * PI/180.0;
	x = r * cos(ang);
	y = r * sin(ang);
	return 0;
}