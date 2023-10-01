
#include "HotelManagement.h"

vector<Room> roomList;
vector<Customer> customerList;

void displayMainMenu()
{
	cout << "Hotel Management System Menu:" << endl;
	cout << "0. Exit" << endl;
	cout << "1. Book a Room" << endl;
	cout << "2. Manage Customers" << endl;
	cout << "3. Manage Employees" << endl;
	cout << "____________________________" << endl;
}

int getUserChoice(int numBegin, int numEnd)
{
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	while (choice < numBegin || choice > numEnd)
	{
		cout << "Invalid choice. Please try again." << endl;
		cin >> choice;
	}
	return choice;
}
void Room::setRoomNo(int roomNo)
{
	this->roomNumber = roomNo;
}

int Room::getRoomNo()
{
	return roomNo;
}

Status Room::getStatus()
{
	return status;
}

void Room::bookRoom()
{
	status = Status::Booked;
}

void Room::cleanRoom()
{
	status = Status::Cleaning;
}

void Room::emptyRoom()
{
	status = Status::Empty;
}

void Customer::setName(string name)
{
	this->name = name;
}

string Customer::getName(string name)
{
	return name;
}

void Customer::setPhoneNumber(string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

string Customer::getPhoneNumber(string phoneNumber)
{
	return phoneNumber;
}

void Customer::setAddress(string address)
{
	this->address = address;
}

string Customer::getAddress(string address)
{
	return address;
}

void DisplayBookRoom::setRoomNumber(int roomNumber)
{
	this->roomNumber = roomNumber;
}

int DisplayBookRoom::getRoomNumber()
{
	return roomNumber;
}
void DisplayBookRoom::displayMenu()
{
	cout << "Book A Room" << endl;
	cout << "0. Exit" << endl;
	cout << "1. Set the number of rooms" << endl;
	cout << "2. Book a room" << endl;
	cout << "____________________________" << endl;
	executeMenu1();
}

void DisplayBookRoom::executeMenu()
{
	int key = getUserChoice(0, 2);
	// Trường hợp ngoại lệ đã đc xử lý ở getUserChoice
	switch (key)
	{
	case 0:
		break;
	case 1:
		numberOfRooms();
		break;
	case 2:
		bookRoom1();
		break;
	}
}
void DisplayBookRoom::numberOfRooms()
{
	cout << "Enter the number of rooms: ";
	int num;
	cin >> num;
	setRoomNumber(num);
	cout << "Successfully set the number of rooms." << endl;
	bookRoom1();
}

void DisplayBookRoom::bookRoom1()
{
	roomList.resize(getRoomNumber());
	cout << "___________Room list__________" << endl;
	cout << "Room No ";
	for (int i = 0; i < roomNumber; i++)
	{
		cout << "| " << i + 1 << " ";
	}
	cout << endl;
	cout << "---------";
	for (int i = 0; i < roomNumber; i++)
	{
		if (i < 10)
			cout << "----";
		else
			cout << "-----";
	}
	cout << endl;
	cout << "Status   ";
	for (int i = 0; i < roomNumber; i++)
	{
		string sign;
		if (roomList[i].getStatus() == 0)
			sign = "E";
		else if (roomList[i].getStatus() == 1)
			sign = "B";
		else
			sign = "C";
		cout << "| " << sign << " ";
		if (i > 9)
			cout << " ";
	}
	cout << endl;
	cout << "_________";
	for (int i = 0; i < roomNumber; i++)
	{
		if (i < 10)
			cout << "____";
		else
			cout << "_____";
	}
	cout << endl;
	cout << "0. Come back" << endl;
	cout << "1. Select room number" << endl;
	cout << "_____________________________" << endl;
	executeBookRoom1();
}

void DisplayBookRoom::executeBookRoom1()
{
	int key = getUserChoice(0, 1);
	// Trường hợp ngoại lệ đã đc xử lý ở getUserChoice
	switch (key)
	{
	case 0:
		displayMenu();
		break;
	case 1:
		cout << "Enter the room number: ";
		int roomNo;
		cin >> roomNo;
		if (roomList[roomNo - 1].getStatus() == 1)
		{
			cout << "Room is booked." << endl;
			cout << endl;
			displayMenu();
		}
		else
		{
			roomList[roomNo - 1].bookRoom();
			cout << endl;
			bookRoom2(roomNo);
		}

		break;
	}
}

void DisplayBookRoom::bookRoom2(int roomNo)
{
	cin.ignore(); // xóa dấu xuống dòng khỏi bộ đệm
	string name;
	cout << "Enter name: ";
	getline(cin, name);
	customerList[roomNo - 1].setName(name);

	cin.ignore();
	cout << "Enter phone number: ";
	string phoneNumber;
	getline(cin, phoneNumber);
	customerList[roomNo - 1].setPhoneNumber(phoneNumber);

	cin.ignore();
	cout << "Enter address: ";
	string address;
	getline(cin, address);
	customerList[roomNo - 1].setAddress(address);

	cout << endl;
}

void DisplayBookRoom::bookRoom3()
{
	cout << "Booking Success." << endl;
	cout << "____________________________" << endl;
	cout << "0. Come back" << endl;
	cout << "1. Continue booking." << endl;
	cout << "____________________________" << endl;
}

void DisplayBookRoom::executeBookRoom3()
{
	int key = getUserChoice(0, 1);
	// Trường hợp ngoại lệ đã đc xử lý ở getUserChoice
	switch (key)
	{
	case 0:
		displayMainMenu();
		break;
	case 1:
		bookRoom1();
		break;
	}
}


