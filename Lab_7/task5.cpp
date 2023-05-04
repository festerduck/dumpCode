#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Car
{
public:
	

	Car()
	{
		fstream myFile;
		myFile.open("oop.txt", ios::in);
		if (!myFile)
		{
			cout << "Error Opening File" << endl;
			exit(0);
		}
		else
		{
			string line = "";
			while (!myFile.eof())
			{
				if (line == "\0")
				{
					line = " ";
				}
				else
				{
					getline(myFile, line);
					cout << line << endl;
				}
				
			}
		}
		myFile.close();
	}
	Car(int chasis, int engine, int model, string make, string type)
	{
		Car::chasisNum = chasis;
		Car::engineNum = engine;
		Car::modelYear = model;
		Car::type = type;
		fstream myFile;
		myFile.open("oop.txt", ios::app | ios::out);
		if (!myFile)
		{
			cout << "Error File Creation" << endl;
			exit(0);
		}
		else
		{
			myFile << chasisNum << endl;
			myFile << engineNum << endl;
			myFile << modelYear << endl;
			myFile << type << endl;
			myFile << " ";
		}
		myFile.close();
	}
	
private:
	int chasisNum, engineNum, modelYear;
	string make, type;
};


int main()
{
	int chasisNum, engineNum, modelYear;
	string make, type;
	cout << "Enter Chasis Number: ";
	cin >> chasisNum; 
	cout << "Enter Engine Number: ";
	cin >> engineNum;
	cout << "Enter Model Year: ";
	cin >> modelYear;
	cout << "Enter Maker: ";
	cin >> make;
	cout << "Enter Type: ";
	cin >> type;
	Car obj1(chasisNum, engineNum, modelYear, make, type), obj2(chasisNum, engineNum, modelYear, make, type), obj3;
	
		return EXIT_SUCCESS;
}
