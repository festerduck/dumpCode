#include <iostream>
using namespace std;
class BinVal
{
public:
	long binNum;
	void setVal()
	{
		cout << "Enter the value for number: ";
		cin >> binNum;
	}
	string operator + (BinVal number)
	{
		string finalSum;

		int tempNum1 = binNum, tempNum2 = number.binNum, rem1, rem2, sum = 0, carry = 0, answer = 0;
		while (tempNum1 != 0 || tempNum2 != 0)
		{
			rem1 = tempNum1 % 10;
			rem2 = tempNum2 % 10;

			tempNum1 = tempNum1 / 10;
			tempNum2 = tempNum2 / 10;

			if (rem1 + rem2 + carry == 0)
			{
				sum = 0;
				carry = 0;
			}
			else if (rem1 + rem2 + carry == 1)
			{
				sum = 1;
				carry = 0;
			}
			else if (rem1 + rem2 + carry == 2)
			{
				sum = 0;
				carry = 1;
			}
			else if (rem1 + rem2 + carry == 3)
			{
				sum = 1;
				carry = 1;
			}
			if (sum == 1)
			{
				finalSum = '1' + finalSum;
			}
			if (sum == 0)
			{
				finalSum = '0' + finalSum;
			}
		}
		if (carry == 1)
		{
			finalSum = '1' + finalSum;
		}
		return finalSum;
	}

private:

};

int main()
{
	BinVal obj1, obj2;
	string obj3;
	obj1.setVal();
	obj2.setVal();
	cout << "Enter the Operation: " << endl;
	cout << "1- For Addition" << endl
		<< "2- For Subtraction" << endl;
	int opt;
	cin >> opt;
	switch (opt)
	{
	case 1:
	{
		obj3 = obj1 + obj2;
		cout << "Addition: " << obj3 << endl;
	}
	case 2:
	{

	}
	default:
		break;
	}
}
