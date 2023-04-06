#include <iostream>
using namespace std;

class Car
{
public:
	void input()
	{
		cout << "Enter Maker of the Car: ";
		cin >> make;
		cout << "Enter Model: ";
		cin >> model;
		cout << "Enter Type: ";
		cin >> type;
		cout << "Enter Chasis Number: ";
		cin >> chasisNum;
		cout << "Enter Engine Number: ";
		cin >> engNum;
	}
	string* getValue()
	{
		string attributesCar[5] = { make, model, type, chasisNum, engNum };
		return attributesCar;
	}
	void displayData()
	{
		cout << "Maker of the Car: " << make << endl
			<< "Model of the CAr: " << model << endl
			<< "Type: " << type << endl
			<< "Chasis Number: " << chasisNum << endl
			<< "Engine Number: " << engNum << endl;
	}
	Car()
	{
		cout << "Constructor of Car class called without any arguments." << endl;
	}
	Car(string make, string model, string type, string chasisNum, string engNum)
	{
		Car::make = make;
		Car::model = model;
		Car::type = type;
		Car::chasisNum = chasisNum;
		Car::engNum = engNum;
		cout << "Constructor of Car class called with arguments" << endl;
	}
private:
	string make, model, type, chasisNum, engNum;
};

int main()
{
	Car car1;
	while (1)
	{
		cout << "Normal Setting of attributes: " << endl
			<< "Constructor of Car class called with arguments" << endl
			<<
	}
}
