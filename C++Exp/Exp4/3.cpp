#include <iostream>
#include <cmath>
const double PI = 3.14159;

int 
computeday(int year, int month, int dayday);

double 
compute_physiological_index(int day);

double 
compute_emotional_index(int day);

double 
computeday_mentality_index(int day);

int main()
{
	int year(0), month(0), day(0);
	std::cout << "Please input year month and day" << std::endl;
	std::cin >> year >> month >> day;
	int sumday = computeday(year, month, day);
	std::cout << "Emotional index: " << compute_emotional_index(sumday) << std::endl;
	std::cout << "Physiological index: " << compute_physiological_index(sumday) << std::endl;
	std::cout << "Mentality index: " << computeday_mentality_index(sumday) << std::endl;

	return 0;
}

int 
computeday(int year, int month, int day)
{
	const int month_day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int sumday(0);

	sumday += year * 365;
	for (int i = 0; i < month-1; ++i)
	{
		sumday += month_day[i];
	}
	sumday += day;
	return sumday;
}

double 
compute_emotional_index(int day)
{
	return sin((PI/14.0)*static_cast<double>(day));
}

double 
computeday_mentality_index(int day)
{
	return sin((2*PI*static_cast<double>(day))/33.0);
}

double 
compute_physiological_index(int day)
{
	return sin((2*PI*static_cast<double>(day))/23.0);
}