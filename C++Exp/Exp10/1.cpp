#include <iostream>
#include <iomanip>
#include <cstdio>

class Laborage
{
private:
	int No;
	char Name[8];
	double Ssalary;
	double Security;
	double Fsalary;
public:
	inline void Input();
	inline void Show();

};

int main()
{
	Laborage a[3];
	for (int i = 0; i < 3; ++i)
	{
		a[i].Input();
	}
	for (int i = 0; i < 3; ++i)
	{
		a[i].Show();
	}
    return 0;
}

inline void Laborage::Input()
{
	std::cin >> this->No;
	//std::cin >> this->Name;
	std::cin.getline(Name, 8);
    char tmp = getchar();
	std::cin >> this-> Ssalary >> this->Security;
}

inline void Laborage::Show()
{
	std::cout << std::left << std::setw(8) << this->No
			  << std::left << std::setw(8) << this->Name
			  << std::right << std::setw(10) << std::setprecision(2) << this->Ssalary
			  << std::right << std::setw(10) << std::setprecision(2) << this->Security
			  << std::right << std::setw(10) << std::setprecision(2) << this->Fsalary
			  << std::endl;

}
