#include <iostream>
#include <string>
#include <bitset>
using namespace std;

string addition(int num1, int num2, int flag)
{
	string finalSum;

	int tempNum1 = num1, tempNum2 = num2, rem1, rem2, sum = 0, carry = 0, answer = 0, digit = 1;
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
	//to Discard Carry
	if (flag == 1)
	{
		if (carry == 1)
		{
			finalSum = '1' + finalSum;
		}
	}
	
	return finalSum;
}

class BinVal
{
public:
	long binNum;
	string finalResult;
	void setVal()
	{
		cout << "Enter the value for number: ";
		cin >> binNum;
	}
	BinVal operator + (BinVal number)
	{
		BinVal finalSum;

		int tempNum1 = binNum, tempNum2 = number.binNum, rem1, rem2, sum = 0, carry = 0, answer = 0, digit = 1;
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
				finalSum.finalResult = '1' + finalSum.finalResult;
			}
			if (sum == 0)
			{
				finalSum.finalResult = '0' + finalSum.finalResult;
			}
			
		}
		if (carry == 1)
		{
			finalSum.finalResult = '1' + finalSum.finalResult;
		}
		return finalSum;
	}

	BinVal operator - (BinVal number)
	{
		BinVal finalSub;
		int tempNum1 = binNum;
		int tempNum2 = number.binNum;
		int rem1, rem2;
		string binStr1, binStr2;
		while (tempNum1 != 0 || tempNum2 != 0)
		{
			rem1 = tempNum1 % 10;
			rem2 = tempNum2 % 10;
			tempNum1 /= 10;
			tempNum2 /= 10;
			binStr1 = to_string(rem1) + binStr1;
			binStr2 = to_string(rem2) + binStr2;
		}

		//Taking One's Complement
		for (size_t i = 0; i < binStr2.length(); i++)
		{
			if (binStr2[i] == '0')
			{
				binStr2[i] = '1';
			}
			else
			{
				binStr2[i] = '0';
			}
		}
		string oneToAddTemp = "1";

		int num1 = stoi(binStr1);
		int num2 = stoi(binStr2);
		int oneToAdd = stoi(oneToAddTemp);

		string twoComplementTemp = addition(num2, oneToAdd, 1);
		int twoComplement = stoi(twoComplementTemp);

		finalSub.finalResult = addition(num1, twoComplement, 0);
		
		return finalSub;
	}

private:

};

int main()
{
	BinVal obj1, obj2;
	BinVal obj3;
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
		cout << "Addition of " << obj1.binNum << " and " << obj2.binNum << " = " << obj3.finalResult << endl;
		break;
	}
	case 2: 
	{
		obj3 = obj1 - obj2;
		cout << "Subtraction of " << obj1.binNum << " and " << obj2.binNum << " = " << obj3.finalResult << endl;
		break;
	}
	default:
		break;
	}
	return EXIT_SUCCESS;
}
