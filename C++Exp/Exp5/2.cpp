#include <iostream>

class Account
{
public:
	Account(int ID, double BALANCE, double ANNUAL):
			id(ID), balance(BALANCE), annualInterestRate(ANNUAL) { } ;
	~Account() { } ;
	double deposit(double money)
	{ this->balance += money; return this->balance; }
	double withDraw(double money)
	{ this->balance -= money; return this->balance; }
	double GetMonthlyInterestRate()
	{ return annualInterestRate/12.0; }

	int GetId() const
	{ return this->id; }
	double GetBalance() const
	{ return this->balance; }
	double GetRate() const
	{ return this->annualInterestRate; }

	int SetId(int ID)
	{ this->id = ID; }
	double SetBalance(double BALANCE)
	{ this->balance = BALANCE; }
	double SetRate(double RATE)
	{ this->annualInterestRate = RATE; }
private:
	int id;
	double balance;
	double annualInterestRate;

};


int main()
{
	Account a(1122, 20000, 4.5);
	a.withDraw(2500);
	a.deposit(3000);
	std::cout << "Balance: " << a.GetBalance() << std::endl;
	std::cout << "MonthlyInterestRate: " << a.GetMonthlyInterestRate() << std::endl;
	return 0;
}