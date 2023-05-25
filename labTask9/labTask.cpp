#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
enum MyReturn
{
	OK = 0,
	ERROR = -1
};

void chkId(int id);
void studentPortal(int opt);
void adminPortal(int opt);


int facultyCount = 0;
int studentCount = 0;

class Node
{
public:
	Node* nptr;
};

class LinkedList
{
	LinkedList()
	{
		fptr = nullptr;
	}
	void insertNode()
	{
		Node* ptr = new Node;
		ptr->nptr = nullptr;
		if (fptr == nullptr)
		{
			fptr = ptr;
		}
		else
		{
			Node* currentPtr = fptr;
			while (currentPtr->nptr != nullptr)
			{
				currentPtr = currentPtr->nptr;
			}
			currentPtr->nptr = ptr;

		}
	}
	/*void displayData()
	{
		
		while (displayPtr != nullptr)
		{
			
		}
	}*/


private:
	Node* fptr;
};

class BioData
{

protected:
	int regId = 0;
	char name[50],
		department[50],
		address[50],
		phone[50];
};
class Student : protected BioData
{
public:
	void studentData()
	{
		cout << "Student Registration Form" << endl;
		cout << "Enter Student Registration ID: " << endl;
		cin >> regId;
		cin.clear();
		cin.ignore();
		cout << "Enter Student Name: " << endl;
		cin.clear();
		cin.ignore();
		cin.get(name, 50);
		cout << "Enter Student Phone No.: " << endl;
		cin.clear();
		cin.ignore();
		cin.get(phone, 50);
		cout << "Enter Student Department: " << endl;
		cin.clear();
		cin.ignore();
		cin.get(department, 50);
		cout << "Enter Student Address: " << endl;
		cin.clear();
		cin.ignore();
		cin.get(address, 50);
		cout << "Student Data has been Successfuly." << endl;
		studentCount++;
	}

};
class Faculty : public Student, protected BioData 
{
public:
	void facultyData()
	{
		cout << "Faculty Registration Information" << endl;
		cout << "Enter Professor Name: " << endl;
		cin.clear();
		cin.ignore();
		cin.get(BioData::name, 50);
		cout << "Enter Professor Phone Number: " << endl;
		cin.clear();
		cin.ignore();
		cin.get(BioData::phone, 50);


	}

private:

};

class Admin : public Student, public Faculty
{
public:
	void offeredCourses()
	{
		cout << "Offered Courses for Spring 2023" << endl;
		cout << setw(30) << left << "Course Code" << setw(30) << left << "Course Name" << endl;
		cout << setw(30) << left << "103" << setw(30) << left << "OOP" << endl;
		return;
	}
protected:
	int courseCode = 103;
private:

};

//int chkId(int id)
//{
//
//}
void mainMenu()
{
	cout << "--------------------<<<<< Student Management Portal>>>>>--------------------" << endl;
	cout << "1- Student Login" << endl
		<< "2- Faculty Login" << endl
		<< "3- Admin Login" << endl;
	int opt;
	cin >> opt;
	switch (opt)
	{
	case 1:
	{
		system("CLS");
		cout << "\tStudent Portal" << endl;
		cout << "1- Registration Information" << endl
			<< "2- Attendance" << endl
			<< "3- Course Enrollment" << endl;
		int opt;
		cin >> opt;
		studentPortal(opt);
		break;
	}
	case 3:
	{
		system("CLS");
		cout << "Admin Portal" << endl;
		cout << "1- Student Registration" << endl
			<< "2- Faculty Assignment" << endl;
		int opt;
		cin >> opt;
		adminPortal(opt);
		break;
	}


	default:
		break;

	}
	return;
}
void adminPortal(int opt)
{
	switch (opt)
	{
	case 1:
	{
		//cout << "1- View Student Data" << endl;
		cout << "1- Register a New Student" << endl;
		cout << "2- Add Faculty Member" << endl;
		int opt;
		cin >> opt;
		switch (opt)
		{
		case -1:
		{
			cout << "Displaying All Student Data" << endl;
			
			break;
		}
		case 1:
		{
			cout << "Regiter a New Student" << endl;
			Admin stdObj;
			Student* obj = &stdObj;
			obj->studentData();
			//stdObj.offeredCourses();
			break;
		}
		case 2:
		{
			cout << "Addind a Fcaulty Member" << endl;
			Admin fcltyObj;
		}
		default:
			break;
		}
	}
	default:
		break;
	}
	return;
}
void studentPortal(int opt)
{
	switch (opt)
	{
	case 1:
	{
	
	}
	default:
		break;
	}
}

int main()
{
	while (1)
	{
		mainMenu();
	}
	return OK;
}
