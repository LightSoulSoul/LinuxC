#ifndef HEAD_H
#define HEAD_H
#include <iostream>
#include <iomanip>
#include <cmath>
#endif

const int SETW = 15;

int main()
{
    int numberOfMonth(0), annualInterestRate(0);
    double monthlyPayment(0);
    double monthlyInterest(0), interest(0), principal(0), loadAmout(0);

    std::cout << "Please input LoadAmount, Number of year and Rate(%):" << std::endl;

    std::cout << "Load Amount:";
    std::cin >> loadAmout;
    std::cout << "Number of Year:";
    std::cin >> numberOfMonth;
    numberOfMonth *= 12;
    std::cout  << "Annual Interest Rate(%):" ;
    std::cin >> annualInterestRate;

    monthlyInterest = annualInterestRate * 0.01 / 12.0;
    monthlyPayment = loadAmout * monthlyInterest * pow(1+monthlyInterest, numberOfMonth) / (pow(1+monthlyInterest, numberOfMonth)-1);

    std:: cout << "Payment#     Interest      Principal      Balance" << std::endl;
    for(int i = 0; i < numberOfMonth; ++i)
    {
        std::cout << std::setw(4);
        std::cout << i + 1;
        interest = loadAmout * monthlyInterest;
        principal = monthlyPayment - interest;
        loadAmout -= principal;
        std::cout << std::setiosflags(std::ios::fixed);
        std::cout << std::setprecision(2);
        std::cout << std::setiosflags(std::ios::right);
        std::cout << std::setw(SETW);
        std::cout << interest << std::setw(SETW) << principal;
        std::cout << std::setw(SETW) << loadAmout << std::endl;
    }
    return 0;
}
