#include <iostream>

float Convert(float c);

int main()
{
	float c = 0;
	std::cin >> c;
	std::cout << Convert(c) << std::endl;	
	return 0;
}

float Convert(float c)
{
	return c * (float)(5.0/9.0) + 32;
}
