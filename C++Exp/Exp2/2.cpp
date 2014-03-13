#ifndef HEAD_H
#define HEAD_H

#include <iostream>
#include <vector>
#include <string>

#endif

//function declare
int ComputeDay(unsigned int year, unsigned int day);

//Global Var
int month_day[13] = {0, 31, 28, 31, 30, 31 ,30, 31, 31, 30, 31 ,30, 31};
std::vector<std::string> week;
std::vector<std::string> month;

int main()
{
	unsigned int year(0), day(0);
	week.push_back("Monday");
	week.push_back("Tuesday");
	week.push_back("Wednesday");
	week.push_back("Thursday");
	week.push_back("Friday");
	week.push_back("Saturday");
	week.push_back("Sunday");
	month.push_back("January");
	month.push_back("Februay");
	month.push_back("March");
	month.push_back("April");
	month.push_back("May");
	month.push_back("June");
	month.push_back("July");
	month.push_back("Augest");
	month.push_back("September");
	month.push_back("October");
	month.push_back("Novmber");
	month.push_back("December");

	std::cout << "Please input the year and day: " << std::endl;
	std::cin >> year >> day;
	int res = ComputeDay(year, day);
	return 0;
}

int ComputeDay(unsigned int year, unsigned int day)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	{
		month_day[2] = 29;
	}
	for(int i = 0; i < 12; i++)
	{
		day = (day + month_day[i]%7) % 7;
		//std::cout << "day: " << day << std::endl;
		//std::cout << "week[0]" << week[0];
		std::cout << month[i] << " 1," << year << " is " << (day==0?week[day]:week[day-1]) << std::endl;
	}
	return 0;
}


