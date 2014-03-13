#include <iostream>

float min(int a, float b);

int main()
{
	int a;
	float b;
	std::cin >> a >> b;
	std::cout << min(a, b) << std::endl;
	return 0;
}

float min(int a, float b)
{
	return a < b ? a : b;
}
