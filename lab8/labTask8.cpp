#include <iostream>
using namespace std;

enum ReturnStat
{
	OK = 0,
	ERROR = -1
};

class A
{
public:
	A(int a);
	A()
	{
		cout << "Constructors of Class A without Parameters has been called" << endl;
	}
	~A()
	{
		cout << "Destructor of Class A has been called" << endl;

	}

private:
	int a;
};

A::A(int a)
{
	this->a = a;
	cout << "Value of 'a' set using the parameterized constructors: " << this->a << endl;

}

class B : public A
{
public:
	B(int a, int b) : A(a)
	{
		cout << "Constructor with Parameters in Derived Class B has been called." << endl;
		this->b = b;
		cout << "Value of 'b' in B class set using the parameterized constructors: " << this->b << endl;
	}

	B()
	{
		cout << "Constructors of class B without parameter has been called" << endl;
	}
	~B()
	{
		cout << "Destructor of Class B has been called" << endl;

	}
private:
	int b;
};

class C : public B
{
public:
	C()
	{
		cout << "Constructors without parameters in Class C has been called" << endl;
	}
	C(int a, int b, int c) : B(a, b)
	{
		cout << "Constructor with Parameters in Derived Class C has been called." << endl;
		this->c = c;
		cout << "Value of 'c' in C class set using the parameterized constructors: " << this->c << endl;
	}
	~C()
	{
		cout << "Destructor of Class C has been called" << endl;
	}
private:
	int c;
};


int main()
{
	cout << "\t[ Single Level Inheritance ]" << endl;
	A objA(1), objA2;
	cout << "\t[ Multiple Inheritance ]" << endl;
	B obj(5, 10); 
	B obj2;
	cout << "\t[ Multi-Level Inheritance ]" << endl;
	C objC(7, 8, 9);
	C objC2;

	return OK;
	
}

