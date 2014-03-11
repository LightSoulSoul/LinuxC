#ifndef HEAD_H
#define HEAD_H
#include <iostream>
#include <iomanip>

#endif
#define _RELEASE

void ave1(double student[][5]);
void ave2(double** student);

int main()
{

	double student[5][5];
	double **student2 = new double*[5];
	for (int i = 0; i < 5; ++i)
		student2[i] = new double [5];

	#ifdef _DEBUG
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			student[i][j] = 3*i+5*j+3;
		}
	}
	#endif
	#ifndef _DEBUG
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "Please input the " << i+1 << " student score:" << std::endl;
		for (int j = 0; j < 5; ++j)
		{
			std::cin >> student[i][j];
		}
	}
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			*(*(student2+i)+j) = student[i][j];
		}
	}
	#endif
	std::cout << "Function array, use array as parameter" << std::endl;
	ave1(student);

	std::cout << "Function pointer, use pointer as parameter" << std::endl;
	ave2(student2);

	for(int i = 0; i < 5; i++)
		delete []student2[i]; 
	delete []student2; 
	return 0;
}


void ave1(double student[][5])
{
	double sum(0);
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "Student" << i+1 << ": ";
		for (int j = 0; j < 5; ++j)
		{
			//std::cout << std::setw(10);
			std::cout << "Subject " << char('A'+j) << ":  " << student[i][j] << "  ";
			sum += student[i][j];
		}
		std::cout << "Average: " << sum/5.0 << std::endl;
		sum = 0;
	}
	sum = 0;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			sum = sum + student[j][i];
		}
		std::cout << "Average of Subject " << char('A'+i) << ": " << sum/5.0 << std::endl;
		sum = 0;
	}
	return;
}


void ave2(double** student)
{
	double sum(0);
	for (int i = 0; i < 5; ++i)
	{
		std::cout << "Student" << i+1 << ": ";
		for (int j = 0; j < 5; ++j)
		{
			//std::cout << std::setw(10);
			std::cout << "Subject " << char('A'+j) << ":  " << /*student[i][j]*/*(*(student+i)+j) << "  ";
			sum += student[i][j];
		}
		std::cout << "Average: " << sum/5.0 << std::endl;
		sum = 0;
	}
	sum = 0;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			sum = sum + student[j][i];
		}
		std::cout << "Average of Subject " << char('A'+i) << ": " << sum/5.0 << std::endl;
		sum = 0;
	}
	return;
}