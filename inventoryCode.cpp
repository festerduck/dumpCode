#include <iostream>
#include <stdlib.h>
using namespace std;

struct items
{
	int item_id = 0;
	string name;
	int qty = 0;
	float price = 0.0;
	items* nptr;
};
items* fptr = NULL;

void newLine()
{
	cout << endl << "<<----------------------------------------------------->>" << endl;
}

int addItem();
int addNode(int localId);
void newData(items *ptr);
void display();
int main()
{
	while (1)
	{
		newLine();
		cout << "Choose from the following options: " << endl;
		cout << "1- Add Item in the inventory" << endl
			<< "2- Display All Items in the Inventory" << endl
			<< "5- Clear Screen" << endl;
		int opt;
		cin >> opt;
		switch (opt)
		{
		case 1:
		{
			addItem();
			system("CLS");
			break;
		}
		case 2:
		{
			display();
			break;
		}
		case 5: 
		{
			system("CLS");
			break;
		}
		default:
			break;
		}
	//	newLine();
	}
}

int addItem()
{
	int localId, flag = 0;
	cout << "Adding Items" << endl << "Enter Local Id: ";
	cin >> localId;
	items* checkPtr = fptr;
	while (checkPtr != NULL)
	{
		if (checkPtr->item_id == localId)
		{
			cout << "Item Exists as: " << checkPtr->name << endl << "Enter Quantity: " << endl;
			cin >> checkPtr->qty;
			flag = 1;
			break;
		}
		checkPtr = checkPtr->nptr;
	}
	if (flag == 0)
	{
		addNode(localId);
	}
	return 0;

}
int addNode(int localId)
{
	items* ptr = new items;
	ptr->item_id = localId;
	if (fptr == NULL)
	{
		newData(ptr);
		fptr = ptr;
		ptr->nptr = NULL;
	}
	else
	{
		items* currentPtr = fptr;
		while (currentPtr->nptr != NULL)
		{
			currentPtr = currentPtr->nptr;
		}
		newData(ptr);
		currentPtr->nptr = ptr;
		ptr->nptr = NULL;
	}
	return 1;
}
void newData(items *ptr)
{
	int localQuantity = 0;
	cout << "Enter Name of the Item: " << endl;
	cin >> ptr->name;
	cout << "Enter Quantity of " << ptr->name  << endl;
	cin >> localQuantity;
	ptr->qty = ptr->qty + localQuantity;
	cout << "Enter the Price of " << ptr->name << endl;
	cin >> ptr->price;
}

void display()
{
	system("CLS");
	newLine();
	cout << endl << "[------ DISPLAYNG ALL ITEMS IN THE INVENTORY ------]" << endl;
	items* displayPtr = fptr;
	while (displayPtr != NULL)
	{
		cout << "\tId = " << displayPtr->item_id << endl
			<< "\tName of the Items: " << displayPtr->name << endl
			<< "\tQuantity of " << displayPtr->name << ": " << displayPtr->qty << endl
			<< "\tPrice of " << displayPtr->name << ": " << displayPtr->price << endl;
		displayPtr = displayPtr->nptr;
	}
}
