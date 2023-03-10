#include <iostream>
using namespace std;

struct inventoryItem
{
	string itemName;
	int itemId = 0;
	int qty = 0;
	float pricePerItem;
	inventoryItem* nptr;
};

inventoryItem* fptr = NULL;
inventoryItem* currentPtr;



int addInventory();
int addInventoryItem();
int checkId(int id);
int displayInventory();

int index = 0;

int main()
{

	while (1)
	{
		cout
			<< "1- Add Inventry Item. " << endl
			<< "2- Sell Inventor Item. " << endl
			<< "3- Remove Inventory Item" << endl
			<< "4- Display All Stock in the Inventory" << endl;
		int option;
		cin >> option;
		cin.ignore();
		cin.clear();
		switch (option)
		{
		case 1:
		{
			addInventoryItem();
			break;
		}
		case 4:
		{
			displayInventory();
			break;
		}
		default:
			break;
		}
	}
}


int addInventoryItem()
{
	inventoryItem* localPtr = fptr;
	int localQty = 0, localId = 0, localCheck = 0;
	float localPrice = 0.0;
	string localItemName;
	cout << endl << "Enter Item Id: ";
	cin >> localId;
	localCheck = checkId(localId);
	if (localCheck == 0)
	{
		addInventory();
		if (index == 0)
		{
			localPtr = fptr;
		}
		else if(index == 1)
		{
			localPtr = currentPtr;
		}
		localPtr->itemId = localId;
		cout << "Enter Item Name: ";
		cin >> localItemName;
		localPtr->itemName = localItemName;
		cout << endl << "Enter Quantity: ";
		cin >> localQty;
		localPtr->qty += localQty;
		cout << endl << "Enter Price of the Item: ";
		cin >> localPrice;
		localPtr->pricePerItem = localPrice;
	}
	else if (localCheck == 1)
	{
		cout << endl << "Enter Quantity: ";
		cin >> localQty;
		localPtr = currentPtr;
		localPtr->qty += localQty;
	}

	return 0;
}

int checkId(int id)
{
	inventoryItem* checkPtr = fptr;
	while (checkPtr != NULL)
	{
		if (checkPtr->itemId == id)
		{
			cout << "Item Exists." << endl;
			currentPtr = checkPtr;
			return 1;
		}
		checkPtr = checkPtr->nptr;
	}
	cout << "Item Does Not Exist. Add Item Details." << endl;
	return 0;
}

int addInventory()
{
	inventoryItem* ptr = new inventoryItem;
	ptr->nptr = NULL;
	if (fptr == NULL)
	{
		fptr = ptr;
		cout << "FPTR";
		index = 0;
	}
	else
	{
		currentPtr = fptr;
		while (currentPtr->nptr != NULL)
		{
			currentPtr = currentPtr->nptr;
		}
		currentPtr->nptr = ptr;
		cout << "Current";
		index = 1;
	}

	return 0;
}


int displayInventory()
{
	inventoryItem* displayAllItem;
	displayAllItem = fptr;
	while (displayAllItem != NULL)
	{
		cout
			<< "Item Name: " << displayAllItem->itemName << endl
			<< "Item Id: " << displayAllItem->itemId << endl
			<< "Item Quantity: " << displayAllItem->qty << endl
			<< "Item Price: " << displayAllItem->pricePerItem << endl;
		displayAllItem = displayAllItem->nptr;
	}
	return 0;
}
