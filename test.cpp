#include <string>
#include <iostream>
using namespace std;

class A
{
public:
    int pub;
    A(): pub(10), pri(9) { }
private:
    int pri;
};

class B : public A
{
public:
	pub = 5;  
};
