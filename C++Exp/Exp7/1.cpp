#include <iostream>
#include <cstring>

const std::string FRESHMAN = "Freshman";
const std::string SOPHOMORE = "Sophomore";
const std::string JUNIOR = "Junior";
const std::string SENIOR = "Senior";

const int PROFESSOR = 3;
const int ASSOCIATEPROCESSOR = 2;
const int ASSISTANTPROFESSOR = 1;

const double BasicWage = 1800;
const double Allowance = 500;

class MyDate
{
public:
	MyDate() { }
	MyDate(unsigned int year, unsigned int month, unsigned int day)
	{ this->year = year; this->month = month; this->day = day;}
	MyDate(const MyDate& date)	//copy construct function
	{ this->year = date.year; this->month = date.month; this->day = date.day; }
	~MyDate() { }
	
	int GetYear() const
	{ return this->year; }
	int GetMonth() const
	{ return this->month; }
	int GetDay() const
	{ return this->day; }

	MyDate diffYear(MyDate& date)
	{
		int year = date.GetYear() -  this->year;
		int month = date.GetMonth() - this->month;
		int day = 1;
		month = month>=0?month:month+12;
		MyDate retdate(year, month, day);
		return retdate;
	}
private:
	unsigned int year, month, day;
};

class Person
{
public:
	Person() { }
	Person(std::string NAME, std::string ID, std::string PHONENUMBER):
			name(NAME), id(ID), phonenumber(PHONENUMBER) { }
	~Person() { }
	void print()
	{ std::cout << "Name: " << name << std::endl;
	  std::cout << "ID: " << id << std::endl;
	  std::cout << "PhoneNumber: " << phonenumber << std::endl;}

protected:
	std::string name;
	std::string id;
	std::string phonenumber;
};

class Student : public Person
{
public:
	Student() { }
	Student(std::string NAME, std::string ID, std::string PHONENUMBER, std::string GRADE):
			name(NAME), id(ID), phonenumber(PHONENUMBER), grade(GRADE) { }
	~Student() { }
	void print()
	{ std::cout << "Name: " << name << std::endl;
	  std::cout << "ID: " << id << std::endl;
	  std::cout << "PhoneNumber: " << phonenumber << std::endl;
	  std::cout << "Grade: " << grade << std::endl; }

private:
	std::string grade;
	std::string name;
	std::string id;
	std::string phonenumber;
};

class Employee : public Person
{
public:
	Employee() { }
	Employee(std::string NAME, std::string ID, std::string PHONENUMBER, std::string OFFICE, MyDate DATEHIRED):
			name(NAME), id(ID), phonenumber(PHONENUMBER), office(OFFICE), dateHired(DATEHIRED) { }
	~Employee() { }
	void print()
	{ std::cout << "Name: " << name << std::endl;
	  std::cout << "ID: " << id << std::endl;
	  std::cout << "PhoneNumber: " << phonenumber << std::endl;
	  std::cout << "Office: " << office << std::endl;
	  std::cout << "Date Hired: " << dateHired.GetYear() << "-" << dateHired.GetMonth() << std::endl; }
	  
protected:
	std::string office;
	MyDate dateHired;
private:
	double salary;
	std::string name;
	std::string id;
	std::string phonenumber;
};

class Faculty : public Employee
{
public:
	Faculty(std::string NAME, std::string ID, std::string PHONENUMBER, std::string OFFICE, MyDate DATEHIRED, int RANK):
			name(NAME), id(ID), phonenumber(PHONENUMBER), office(OFFICE), dateHired(DATEHIRED), rank(RANK), salary(rank*BasicWage) { }
	~Faculty() { }
	double calcSalary()
	{ return rank*BasicWage; }
	void print()
	{ std::cout << "Name: " << name << std::endl;
	  std::cout << "ID: " << id << std::endl;
	  std::cout << "PhoneNumber: " << phonenumber << std::endl;
	  std::cout << "Rank: " << (rank==1?"AssistantProfessor":(rank==2?"AssociateProcessor":"Processor")) << std::endl; 
	  std::cout << "Office: " << office << std::endl;
	  std::cout << "Date Hired: " << dateHired.GetYear() << "-" << dateHired.GetMonth() << std::endl; }

private:
	int rank;
	std::string name;
	std::string id;
	std::string phonenumber;
	std::string office;
	MyDate dateHired;
	double salary;
};

class Staff : public Employee
{
public:
	Staff() { }
	Staff(std::string NAME, std::string ID, std::string PHONENUMBER, std::string OFFICE, MyDate DATEHIRED,std::string POSITION, MyDate dateNow):
			name(NAME), id(ID), phonenumber(PHONENUMBER), office(OFFICE), dateHired(DATEHIRED), position(POSITION) 
	{ //salary = BasicWage+Allowance*dateHired.diffYear(dateNow); 
		MyDate temp = dateHired.diffYear(dateNow);

		salary = BasicWage + Allowance*temp.GetYear()+temp.GetMonth()/12.0;
	}
	~Staff() { }
	double calcSalary(MyDate dateNow)
	{ 	MyDate temp = dateHired.diffYear(dateNow);
		return BasicWage+Allowance*temp.GetYear()+temp.GetMonth()/12.0; }
	void print()
	{ std::cout << "Name: " << name << std::endl;
	  std::cout << "ID: " << id << std::endl;
	  std::cout << "PhoneNumber: " << phonenumber << std::endl;
	  std::cout << "Position: " << position << std::endl; 
	  std::cout << "Office: " << office << std::endl;
	  std::cout << "Date Hired: " << dateHired.GetYear() << "-" << dateHired.GetMonth() << std::endl; }

private:
	std::string position;
	std::string name;
	std::string id;
	std::string phonenumber;
	std::string office;
	MyDate dateHired;
	double salary;
};

int main()
{
	MyDate dateNow(2010,1,1);
	MyDate dateHired(2000,1,1);
	Person person("bob", "12084100","15958151500");
	Student student("tom", "12084100", "15958151500", FRESHMAN);
	Employee employee("tom", "12084100", "15958151500","Office", dateHired);
	Faculty faculty("tom", "12084100", "15958151500", "office", dateHired, PROFESSOR);
	Staff staff("tom", "12084100", "15958151500", "office", dateHired, "teacher", dateNow);
	return 0;
}
