#include <iostream>
//#define MILE 1.60934

const float MILE(1.60934);

float Convert(float km);

int main()
{
	float km = 0;
	std::cin >> km;
	std::cout << Convert(km) << std::endl;
	return 0;
}

float Convert(float km)
{
	return km / MILE;
}
