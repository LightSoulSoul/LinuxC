#include <iostream>

int min(int a, int b);

int main()
{
	int a = 0, b = 0;
	std::cin >> a >> b;
	std::cout << min(a, b) << std::endl;
	return 0;
}

int min(int a, int b)
{
	return a < b ? a : b;
}
