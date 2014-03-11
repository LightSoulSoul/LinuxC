#ifndef IOSTREAM_H
#define IOSTREAM_H
#include <iostream>
#endif

using namespace std;

class Sales_item
{
public:
	friend std::istream& operator>>(std::istream&, Sales_item&);
	friend std::ostream& operator<<(std::ostream&, Sales_item&);
	Sales_item& operator+=(const Sales_item&);
	Sales_item operator+(const const Sales_item&, const Sales_item&);
	Sales_item():units_sold(0), revenue(0.0){}
	~Sales_item();
	bool same_isbn(const Sales_item &rhs) const
	{
		return isbn == rhs.isbn;
	}
	inline double avg_price() const;
	Sales_item& operator=(const Sales_item&);
private:
	string isbn;
	unsigned units_sold;
	double revenue;
};

inline double Sales_item::avg_price() const
{
	if (units_sold)
	{	
		return revenue/units_sold;
	}
	else return 0;
}


class Screen
{
public:
	Screen();
	~Screen();
	Screen& display(std::ostream &os)
	{do_display(os); return *this;}
	Screen& display(std::ostream &os) const
	{do_display(os); return *this;}
	typedef std::string::size_type index;
	char get() const {return contents[cursor];}
	char get(index ht, index wd) const;
private:
	std::string contents;
	index cursor;
	index height, width;
	void do_display(std::ostream &os)const
	{os<<contents;}
};

class Account
{
public:
	// interace functions here
	void applyint() {amount += amount * interestRate;}
	static double rate() {return interestRate;}
	static void rate(double);
private:
	std::string owner;
	double amount;
	static double interestRate;
	static double initRate();
	static const int period = 30;
	double daily_tb1[period];
};


int main()
{
	Account ac1;
	Account *ac2 = &ac1;
	ac1.

	double rate;
	rate = ac1.rate();
	rate = ac2->rate();
	rate = Account::rate();
	{
		Sales_item *p = new Sales_item[10];
		vector<Sales_item> vec(p, p+10);
		delete [] p;
	}

	return 0;
}

Sales_item& Sales_item::operator=(const Sales_item &rhs)
{
	isbn = rhs.isbn;
	units_sold = rhs.units_sold;
	revenue = rhs.revenue;
	return *this;
}

inline bool 
operator==(const Sales_item &lhs, const Sales_item &rhs)
{
	return lhs.units_sold == rhs.units_sold && lhs.revenue == rhs.revenue && lhs.same_isbn(rhs);
}

inline bool
operator!=(const Sales_item &lhs, const Sales_item &rhs)
{
	return !(lhs == rhs)
}
