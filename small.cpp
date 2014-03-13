#include <iostream>
#include <stdexcept>
#include <cstring>
using namespace std;
/*class Bulk_item;
class Item_base;

void print_total(ostream &os, const Item_base &item, size_t n)
{
    os << "ISBN: " << item.book()
        << "\tnumber sold: " << n << "\ttotal price: "
        <<  item.net_price(n) << endl;
}

class Item_base
{
public:
    Item_base(const std::string &book = "", double sales_price = 0.0):
                isbn(book), price(sales_price) { }
    std::string book() const { return isbn; }

    virtual double net_price(std::size_t n) const { return n * price; }
    virtual ~Item_base() { }
private:
    std::string isbn;
protected:
    double price;
};


void Bulk_item::memfcn(const Bulk_item &d, const Item_base &b)
{
    double ret = price;

}

class Bulk_item :public Item_base
{
public:
    double net_price(std::size_t) const;
private:
    std::size_t min_qty;
    double discount;
};

double Bulk_item::net_price(std::size_t cnt) const
{
    if (cnt >= min_qty)
        return cnt * (1 - discount) * price;
    else return cnt * price;
}

///////////////////////////////////////////////
struct base
{
    string name() { return basename; }
    virtual void print(ostream &os) { os << basename; }
private:
    string basename;
};

struct derived
{
    void print() { print(ostream &os); os << " " << men; }
private:
    int mem;
}*/


class Base
{
    friend class Frnd;
protected:
    int i;
};

class Frnd
{
public:
    int mem(Base b) { return b.i; }
};




class D1 : public Base
{
protected:
    int j;
};
