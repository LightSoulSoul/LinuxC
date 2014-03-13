#include <iostream>

class Array
{
public:
	Array()
	{
		for (int i = 0; i < 10; ++i)
		{
			a[i] = 0;
		}
	}
	Array(const int A[]) 
	{
		for (int i = 0; i < 10; ++i)
		{
			a[i] = A[i];
		}
	}
	~Array() { }
	void show() const
	{
		for (int i = 0; i < 10; ++i)
		{
			std::cout << a[i] << " ";
		}
		std::cout << std::endl;
	}
	Array operator+(const Array rhs)
	{
		Array temp;
		for (int i = 0; i < 10; ++i)
		{
			temp.a[i] = this->a[i] + rhs.a[i];
		}
		return temp;
	}
	friend Array& operator+=(Array &lhs, const Array& rhs);
private:
	int a[10];
};

int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,10};
	int b[10]={4,5,6,7,8,9,10,11,12,13};
	Array arr1(a), arr2(b), arr3;
	arr3 = arr1 + arr2;
	arr3.show();
	arr1 += arr2;
	arr1.show();
	return 0;
}

Array& operator+=(Array &lhs, const Array& rhs)
{
	for (int i = 0; i < 10; ++i)
	{
		lhs.a[i] += rhs.a[i];
	}
	return lhs;
}