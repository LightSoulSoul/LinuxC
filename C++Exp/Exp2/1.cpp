#include <iostream>

int main()
{
	int wTime(0), wage_pre_hour(0);
	std::cout << "Please input employee\'s work time"
		" and wage_per_hour:" << std::endl;
	std::cin >> wTime >> wage_pre_hour;
	std::cout << "The employee\'s wage: ";
	if(wTime < 40)
		std::cout << wTime*wage_pre_hour << std::endl;
	else if(wTime > 40 && wTime < 60)
		std::cout << (wTime-40)*wage_pre_hour*1.5 + 40*wage_pre_hour << std::endl;
	else if(wTime >= 60)
		std::cout << 40*wage_pre_hour + (wTime-60)*wage_pre_hour*3 + 20*wage_pre_hour*1.5 << std::endl;
	return 0;
}
