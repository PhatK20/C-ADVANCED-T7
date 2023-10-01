#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayMainMenu();
int getUserChoice(int numBegin, int numEnd);
void setupManager(string manager, string admin);

typedef enum
{
	EMPTY,
	BOOKED,
	CLEANING
} Status;

class Room
{
private:
	Status status;

public:
	Room() : status(Status::EMPTY) {}

	Status getStatus();

	// Đặt các trạng thái cho phòng
	void bookRoom();
	void cleanRoom();
	void emptyRoom();
};

class Customer
{
private:
	string name;
	string phoneNumber;
	string address;
	int roomNo; // số thứ tự của phòng
public:
	void setName(string name);
	string getName();

	void setPhoneNumber(string phoneNumber);
	string getPhoneNumber();

	void setAddress(string address);
	string getAddress();

	void setRoomNo(int roomNo);
	int getRoomNo();
};

class User
{
private:
	string userName;
	string password;

public:
	void setUserName(string userName);
	string getUserName();
	void setPassword(string password);
	string getPassword();
};

typedef enum
{
	MANAGER,
	RECEPTIONIST,
	SECURITY,
	CLEANER
} Position;

class Staff
{
private:
	string name;
	string phoneNumber;
	Position position;

public:
	User user;
	void setName(string name);
	string getName();

	void setPhoneNumber(string phoneNumber);
	string getPhoneNumber();

	void setPosition(Position position);
	Position getPosition();
};

class DisplayBookRoom
{
private:
	int roomNumber;

public:
	void setRoomNumber(int roomNumber);
	int getRoomNumber();

	void displayMenu();
	void executeMenu();

	void numberOfRooms();

	void bookRoom1();
	void executeBookRoom1();
	void bookRoom2(int roomNo);
	void bookRoom3();
	void executeBookRoom3();
};

class SecurityAndAccess
{
private:
public:
	bool checkStaffLogin(User user);
	bool checkManagerLogin(User user);

	User enterAccount();
	void displayMenu();
	void executeMenu();

	void managerMenu1();
	void managerMenu2();
	void executeManagerMenu2();
	void managerMenu3();
	void managerMenu4();
	void executeManagerMenu4();

	void staffMenu1();
	void executeStaffMenu1();
	void staffMenu2();
	void executeStaffMenu2();
};

vector<Room> roomList;
vector<Customer> customerList;
vector<Staff> staffList;
Staff manager;

void setupManager(string admin, string HiAdmin)
{
	manager.user.setUserName(admin);
	manager.user.setPassword(HiAdmin);
	manager.setPosition(MANAGER);
}

void displayMainMenu()
{
	cout << "Hotel Management System Menu:" << endl;
	cout << "0. Exit" << endl;
	cout << "1. Book a Room" << endl;
	cout << "2. Manage Customers" << endl;
	cout << "3. Manage Employees" << endl;
	cout << "4. Payment" << endl;
	cout << "5. Security and Access" << endl;
	cout << "6. Report" << endl;
	cout << "7. Manage feedback and reviews" << endl;
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
		cout << "Enter your choice: ";
		cin >> choice;
	}
	cout << endl;
	return choice;
}

Status Room::getStatus()
{
	return status;
}

void Room::bookRoom()
{
	status = Status::BOOKED;
}

void Room::cleanRoom()
{
	status = Status::CLEANING;
}

void Room::emptyRoom()
{
	status = Status::EMPTY;
}

void Customer::setName(string name)
{
	this->name = name;
}

string Customer::getName()
{
	return name;
}

void Customer::setPhoneNumber(string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

string Customer::getPhoneNumber()
{
	return phoneNumber;
}

void Customer::setAddress(string address)
{
	this->address = address;
}

string Customer::getAddress()
{
	return address;
}

void Customer::setRoomNo(int roomNo)
{
	this->roomNo = roomNo;
}

int Customer::getRoomNo()
{
	return roomNo;
}

void User::setUserName(string userName)
{
	this->userName = userName;
}

string User::getUserName()
{
	return userName;
}

void User::setPassword(string password)
{
	this->password = password;
}

string User::getPassword()
{
	return password;
}

void Staff::setName(string name)
{
	this->name = name;
}

string Staff::getName()
{
	return name;
}

void Staff::setPhoneNumber(string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

string Staff::getPhoneNumber()
{
	return phoneNumber;
}

void Staff::setPosition(Position position)
{
	this->position = position;
}

Position Staff::getPosition()
{
	return position;
}

User SecurityAndAccess::enterAccount()
{
	User user;
	cout << "Enter your username: ";
	string userName;
	cin.ignore();
	getline(cin, userName);
	user.setUserName(userName);

	cout << "Enter your password: ";
	string password;
	cin.ignore();
	getline(cin, password);
	user.setPassword(password);

	return user;
}
void SecurityAndAccess::displayMenu()
{
	cout << "Security and Access Menu:" << endl;
	cout << "0. Exit" << endl;
	cout << "1. Manager Login" << endl;
	cout << "2. Staff Login" << endl;
	cout << "____________________________" << endl;
	executeMenu();
}

void SecurityAndAccess::executeMenu()
{
	int key = getUserChoice(0, 2);
	switch (key)
	{
	case 0:
		break;
	case 1:
		managerMenu1();
		break;
	case 2:
		staffMenu1();
		break;
	}
}

void SecurityAndAccess::managerMenu1()
{
	cout << "______Manager Access_____" << endl;
	User user = enterAccount();
	if (checkManagerLogin(user))
	{
		managerMenu2();
	}
	else
	{
		cout << "Invalid username or password." << endl;
		cout << endl;
		displayMenu();
	}
}

void SecurityAndAccess::managerMenu2()
{
	cout << "______Manager Access_____" << endl;
	cout << "0. Come back" << endl;
	cout << "1. Edit staff account" << endl;
	cout << "2. Edit manager account" << endl;
	cout << "____________________________" << endl;
	executeManagerMenu2();
}

void SecurityAndAccess::executeManagerMenu2()
{
	int key = getUserChoice(0, 2);
	switch (key)
	{
	case 0:
		displayMainMenu();
		break;
	case 1:
		managerMenu3();
		break;
	case 2:
		managerMenu5();
		break;
	}
}

void SecurityAndAccess::managerMenu3()
{
	cout << "______Manager Access_____" << endl;
	cout << "Enter new password" << endl;

	if (checkManagerLogin(manager.user))
	{
		cout << "Enter new account" << endl;
		cout << "Enter username: ";
		string newUserName;
		cin.ignore();
		getline(cin, newUserName);

		cout << "Enter password: ";
		string newUserPassword;
		cin.ignore();
		getline(cin, newUserPassword);

		setupManager(newUserName, newUserPassword);
		cout << "Manager account updated." << endl;
	}
	else
	{
		cout << "Invalid username or password." << endl;
		cout << endl;
		displayMenu();
	}
}

void SecurityAndAccess::managerMenu4()
{
	cout << "______Manager Access_____" << endl;
	cout << "0. Come back" << endl;
	cout << "1. Add new staff account" << endl;
	cout << "2. Edit staff account" << endl;
	cout << "3. Delete staff account" << endl;
	cout << "4. List all staff accounts" << endl;
	cout << "____________________________" << endl;
	executeManagerMenu4();
}

void SecurityAndAccess::executeManagerMenu4()
{
	int key = getUserChoice(0, 4);
	cout << endl;
	cout << "______Manager Access_____" << endl;
	bool test = false;
	switch (key)
	{
	case 0:
		displayMenu();
		break;
	case 1:
		cout << "Enter new account" << endl;
		User user = enterAccount();
		userList.push_back(user);
		cout << "Account added." << endl;
		break;
	case 2:
		cout << "Change password" << endl;
		cout << "Enter username: ";
		string userName;
		cin.ignore();
		getline(cin, userName);
		
		for (int i = 0; i < userList.size(); i++)
		{
			if (userList[i].getUserName() == userName)
			{
				test = true;
				cout << "Enter new password: ";
				string newPassword;
				cin.ignore();
				getline(cin, newPassword);
				userList[i].setPassword(newPassword);
				cout << "Password updated." << endl;
				break;
			}
		}
		if (test)
		{
			cout << "Invalid username." << endl;
		}
		break;
	case 3:
		cout << "Delete account" << endl;
		cout << "Enter username: ";
		string userName;
		cin.ignore();
		getline(cin, userName);
		for (int i = 0; i < userList.size(); i++)
		{
			if (userList[i].getUserName() == userName)
			{
				test = true;
				userList.erase(userList.begin() + i);
				cout << "Account deleted." << endl;
				break;
			}
		}
		if (test)
		{
			cout << "Invalid username." << endl;
		}
		break;
	case 4:
		cout << "List all staff accounts" << endl;
		break;
	}
	managerMenu4();
}

void SecurityAndAccess::managerMenu5()
{
	cout << "______Staff Access______" << endl;
	User user = enterAccount();
	if (checkStaffLogin(User user))
	{
		staffMenu6();
	}
	else
	{
		cout << "Invalid username or password." << endl;
		cout << endl;
		displayMenu();
	}
}
bool SecurityAndAccess::checkStaffLogin(User user)
{
	int check = false;
	for (int i = 0; i < staffList.size(); i++)
	{
		if (user.getUserName() == staffList[i].user.getUserName() && user.getPassword() == staffList[i].user.getPassword())
		{
			check = true;
			break;
		}
	}
	return check;
}

bool SecurityAndAccess::checkManagerLogin(User user)
{
	bool check = false;

	if (user.getUserName() == manager.user.getUserName() && user.getPassword() == manager.user.getPassword())
	{
		check = true;
	}

	return check;
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
	executeMenu();
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
	cout << endl;
	displayMenu();
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
	cout << "Status  ";
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
	cout << "Enter customer information." << endl;
	Customer customer;
	cin.ignore(); // xóa dấu xuống dòng khỏi bộ đệm
	customer.setRoomNo(roomNo);

	string name;
	cout << "Enter name: ";
	getline(cin, name);
	customer.setName(name);

	cout << "Enter phone number: ";
	string phoneNumber;
	getline(cin, phoneNumber);
	customer.setPhoneNumber(phoneNumber);

	cout << "Enter address: ";
	string address;
	getline(cin, address);
	customer.setAddress(address);

	customerList.push_back(customer);
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

int main()
{
	DisplayBookRoom test;
	setupManager("manager", "admin");
	while (1)
	{
		displayMainMenu();
		int key = getUserChoice(0, 1);
		switch (key)
		{
		case 0:
			return 0;
		case 1:
			test.displayMenu();
			break;
		}
	}

	return 0;
}
