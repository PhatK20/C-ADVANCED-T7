
#include "hotel.h"

vector<Room> roomList;
vector<Customer> customerList;
vector<Staff> staffList;
Staff manager;
int Staff::idCounter = 2024;
int Room::roomCounter = 0;

void displayMainMenu()
{
	cout << "Hotel Management System Menu:" << endl;
	cout << "0. Exit" << endl;
	cout << "1. Room Setup" << endl;
	cout << "2. Manage Customers" << endl;
	cout << "3. Payment" << endl;
	cout << "4. Security and Access" << endl;
	cout << "5. Feedback and reviews" << endl;
	cout << string(30, '-') << endl;
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

void setupManager(string userName, string userPassword, string name, string phoneNumber)
{
	manager.user.setUserName(userName);
	manager.user.setPassword(userPassword);

	manager.setId();
	manager.setName(name);
	manager.setPhoneNumber(phoneNumber);
	manager.setPosition(MANAGER);
}

User enterAccount()
{
	User newUser;

	cin.ignore();
	string newUserName;
	cout << "Enter your username: ";
	getline(cin, newUserName);

	string newPassword;
	cout << "Enter your password: ";
	getline(cin, newPassword);

	newUser.setUserName(newUserName);
	newUser.setPassword(newPassword);

	return newUser;
}

void enterNewPassword(User &user)
{
	cin.ignore();
	string newPassword;
	cout << "Enter new password: ";
	getline(cin, newPassword);

	string newPasswordAgain;
	cout << "Enter new password again: ";
	getline(cin, newPasswordAgain);

	if (newPassword == newPasswordAgain)
	{
		user.setPassword(newPassword);
		cout << "Password updated." << endl;
		cout << endl;
	}
	else
	{
		cout << "Passwords do not match." << endl;
		cout << endl;
	}
}

void enterStaffInfo(Staff &staff)
{
	cin.ignore();
	cout << "Enter staff name: ";
	string name;
	getline(cin, name);
	staff.setName(name);

	string phoneNumber;
	cout << "Enter staff phone number: ";
	getline(cin, phoneNumber);
	staff.setPhoneNumber(phoneNumber);
	cout << endl;

	cout << "1. Manager" << endl;
	cout << "2. Receptionist" << endl;
	cout << "3. Security" << endl;
	cout << "4. Cleaner" << endl;
	cout << "Enter staff position: ";
	int pos;
	cin >> pos;
	staff.setPosition((Position)pos);

	staff.setId();
}

bool checkStaffLogin(User user)
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

bool checkStaffLogin(User user, Position pos)
{
	int check = false;
	for (int i = 0; i < staffList.size(); i++)
	{
		if (user.getUserName() == staffList[i].user.getUserName() && user.getPassword() == staffList[i].user.getPassword() && staffList[i].getPosition() == pos)
		{
			check = true;
			break;
		}
	}
	return check;
}

bool checkManagerLogin(User user)
{
	bool check = false;

	if (user.getUserName() == manager.user.getUserName() && user.getPassword() == manager.user.getPassword())
	{
		check = true;
	}

	return check;
}

string positionToString(Position pos)
{
	switch (pos)
	{
	case MANAGER:
		return "Manager";
	case RECEPTIONIST:
		return "Receptionist";
	case SECURITY:
		return "Security";
	case CLEANER:
		return "Cleaner";
	default:
		return "Unknown";
	}
}

Room::Room()
{
	status = EMPTY;
}

void Room::setStatus(Status status)
{
	this->status = status;
}
Status Room::getStatus()
{
	return status;
}

void Room::setRoomNumber()
{
	this->roomNumber = ++roomCounter;
}

int Room::getRoomNumber()
{
	return roomNumber;
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

void Customer::setRoomNumber(int roomNumber)
{
	this->roomNumber = roomNumber;
}

int Customer::getRoomNumber()
{
	return roomNumber;
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

void Staff::setId()
{
	this->id = idCounter++;
}

int Staff::getId()
{
	return id;
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

void BookRoomMenu::setNumberOfRooms(int numberOfRooms)
{
	this->numberOfRooms = numberOfRooms;
}

int BookRoomMenu::getNumberOfRooms()
{
	return numberOfRooms;
}
void BookRoomMenu::displayMenu()
{
	cout << string(4, '_') << "Room Setup" << string(4, '_') << endl;
	cout << "0. Exit" << endl;
	cout << "1. Set the number of rooms" << endl;
	cout << "2. Book a room" << endl;
	cout << string(24, '_') << endl;
	executeMenu();
}

void BookRoomMenu::executeMenu()
{
	int key = getUserChoice(0, 2);
	// Trường hợp ngoại lệ đã đc xử lý ở getUserChoice
	switch (key)
	{
	case 0:
		break;
	case 1:
		roomSetup();
		break;
	case 2:
		bookRoom1();
		break;
	}
}
void BookRoomMenu::roomSetup()
{
	User newUser = enterAccount();
	if (manager.user.getUserName() == newUser.getUserName() && manager.user.getPassword() == newUser.getPassword())
	{
		cout << "Enter the number of rooms: ";
		int num;
		cin >> num;
		setNumberOfRooms(num);
		roomList.resize(getNumberOfRooms());
		cout << "Successfully set the number of rooms." << endl;
		cout << endl;
	}
	else
	{
		cout << "Invalid username or password." << endl;
		cout << endl;
	}
	displayMenu();
}

void BookRoomMenu::bookRoom1()
{

	cout << string(5, '_') << "Room list" << string(5, '_') << endl;
	cout << "Room Number ";
	for (int i = 0; i < numberOfRooms; i++)
	{
		cout << "| " << i + 1 << " ";
	}
	cout << endl;
	cout << "---------";
	for (int i = 0; i < numberOfRooms; i++)
	{
		if (i < 10)
			cout << "----";
		else
			cout << "-----";
	}
	cout << endl;
	cout << left << setw(12) << "Status  ";
	for (int i = 0; i < numberOfRooms; i++)
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
	for (int i = 0; i < numberOfRooms; i++)
	{
		if (i < 10)
			cout << "____";
		else
			cout << "_____";
	}
	cout << endl;
	cout << "0. Come back" << endl;
	cout << "1. Select room number" << endl;
	cout << string(30, '_') << endl;
	executeBookRoom1();
}

void BookRoomMenu::executeBookRoom1()
{
	int key = getUserChoice(0, 1);
	int roomNo;
	switch (key)
	{
	case 0:
		displayMenu();
		break;
	case 1:
		cout << "Enter the room number: ";
		cin >> roomNo;
		if (roomList[roomNo - 1].getStatus() == 1)
		{
			cout << "Room is booked." << endl;
			cout << endl;
			displayMenu();
		}
		else
		{
			roomList[roomNo - 1].setStatus(BOOKED);
			cout << endl;
			bookRoom2(roomNo);
		}

		break;
	}
}

void BookRoomMenu::bookRoom2(int roomNo)
{
	cout << "Customer information." << endl;
	Customer customer;
	customer.setRoomNumber(roomNo);

	cin.ignore();
	string name;
	cout << "Enter name: ";
	getline(cin, name);
	customer.setName(name);

	string phoneNumber;
	cout << "Enter phone number: ";
	getline(cin, phoneNumber);
	customer.setPhoneNumber(phoneNumber);

	string address;
	cout << "Enter address: ";
	getline(cin, address);
	customer.setAddress(address);

	customerList.push_back(customer);
	cout << endl;
	bookRoom3();
}

void BookRoomMenu::bookRoom3()
{
	cout << "Booking Success." << endl;
	cout << string(30, '_') << endl;
	cout << "0. Exit" << endl;
	cout << "1. Continue booking." << endl;
	cout << string(30, '_') << endl;
	executeBookRoom3();
}

void BookRoomMenu::executeBookRoom3()
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

void CustomerMenu::printCustomerList()
{
	cout << string(4, '_') << "Customer List" << string(4, '_') << endl;
	cout << left << setw(6) << "| ID ";
	cout << left << setw(12) << "| Name ";
	cout << left << setw(16) << "| Phone Number ";
	cout << left << setw(16) << "| Address ";
	cout << left << setw(16) << "| Room Number ";
	cout << "|" << endl;
	cout << string(67, '-') << endl;
	for (int i = 0; i < customerList.size(); i++)
	{
		cout << "| " << left << setw(4) << i + 1;
		cout << "| " << left << setw(10) << customerList[i].getName();
		cout << "| " << left << setw(14) << customerList[i].getPhoneNumber();
		cout << "| " << left << setw(14) << customerList[i].getAddress();
		cout << "| " << left << setw(14) << customerList[i].getRoomNumber();
		cout << "|" << endl;
	}
}
void CustomerMenu::displayMenu()
{
	cout << string(4, '_') << "Customer Management" << string(4, '_') << endl;
	cout << "0. Exit" << endl;
	cout << "1. Enter Account" << endl;
	cout << string(24, '_') << endl;
	executeMenu();
}

void CustomerMenu::executeMenu()
{
	int key = getUserChoice(0, 1);
	User user;
	switch (key)
	{
	case 0:
		displayMainMenu();
		break;
	case 1:
		user = enterAccount();
		if (checkManagerLogin(user) || checkStaffLogin(user))
		{
			displayMenu1();
		}
		else
		{
			cout << "Invalid username or password." << endl;
			cout << endl;
			displayMenu();
		}
		break;
	}
}

void CustomerMenu::displayMenu1()
{
	cout << string(4, '_') << "Customer Management" << string(4, '_') << endl;
	printCustomerList();
	cout << "0. Come back" << endl;
	cout << "1. Edit customer information" << endl;
	cout << "2. Delete customer information" << endl;
	cout << string(30, '_') << endl;
	executeMenu1();
}

void CustomerMenu::executeMenu1()
{
	int key = getUserChoice(0, 2);
	switch (key)
	{
	case 0:
		displayMenu();
		break;
	case 1:
		editCustomer();
		break;
	case 2:
		deleteCustomer();
		break;
	}
}

void CustomerMenu::editCustomer()
{
	cout << string(4, '_') << "Edit customer information" << string(4, '_') << endl;
	cout << "Enter customer id: ";
	int customerId;
	cin >> customerId;
	if (customerId > (int)customerList.size() || customerId < 1)
	{
		cout << "Invalid customer id." << endl;
		cout << endl;
		displayMenu1();
	}
	else
	{
		int key = getUserChoice(0, 3);
		switch (key)
		{
		case 0:
			break;
		case 1:
			editName(customerId);
			break;
		case 2:
			editPhoneNumber(customerId);
			break;
		case 3:
			editAddress(customerId);
			break;
		}
		displayMenu1();
	}
}

void CustomerMenu::editName(int id)
{
	cin.ignore();
	string name;
	cout << "Enter new name: ";
	getline(cin, name);
	customerList[id - 1].setName(name);

	cout << "Name updated successfully." << endl;
	cout << endl;
}

void CustomerMenu::editPhoneNumber(int id)
{
	cin.ignore();
	string phoneNumber;
	cout << "Enter new phone number: ";
	getline(cin, phoneNumber);
	customerList[id - 1].setPhoneNumber(phoneNumber);

	cout << "Phone number updated successfully." << endl;
	cout << endl;
}

void CustomerMenu::editAddress(int id)
{
	cin.ignore();
	string address;
	cout << "Enter new address: ";
	getline(cin, address);
	customerList[id - 1].setAddress(address);

	cout << "Address updated successfully." << endl;
	cout << endl;
}
void CustomerMenu::deleteCustomer()
{
	cout << string(4, '_') << "Delete customer information" << string(4, '_') << endl;
	cout << "Enter customer id: ";
	int customerId;
	cin >> customerId;
	if (customerId > (int)customerList.size() || customerId < 1)
	{
		cout << "Invalid customer id." << endl;
		cout << endl;
		displayMenu1();
	}
	else
	{
		cout << "Are you sure you want to delete?" << endl;
		cout << "0. No" << endl;
		cout << "1. Yes" << endl;
		cout << string(30, '_') << endl;
		int key = getUserChoice(0, 1);

		switch (key)
		{
		case 0:
			break;
		case 1:
			customerList.erase(customerList.begin() + customerId - 1);
			roomList[customerId - 1].setStatus(EMPTY);
			cout << "Customer information deleted successfully." << endl;
			cout << endl;
			break;
		}
		displayMenu1();
	}
}

void PaymentMenu::displayMenu()
{
	cout << string(4, '_') << "Payment" << string(4, '_') << endl;
	cout << "0. Exit" << endl;
	cout << "1. Pay" << endl;
	cout << string(30, '_') << endl;
	executeMenu();
}

void PaymentMenu::executeMenu()
{
	int key = getUserChoice(0, 1);
	bool check = false;
	int i;
	switch (key)
	{
	case 0:
		displayMainMenu();
		break;
	case 1:
		cout << "Enter room number: ";
		int roomNumber;
		cin >> roomNumber;

		for (i = 0; i < customerList.size(); i++)
		{
			if (customerList[i].getRoomNumber() == roomNumber)
			{
				check = true;
				break;
			}
		}
		if (check)
		{
			payment(roomNumber, i);
			displayMenu();
		}
		else
		{
			cout << "Invalid room number." << endl;
			cout << endl;
			displayMenu();
		}
	}
}

void PaymentMenu::payment(int roomNumber, int index)
{
	cout << string(4, '_') << "Bill" << string(4, '_') << endl;
	cout << "Name: " << customerList[index].getName() << endl;
	cout << "Phone number: " << customerList[index].getPhoneNumber() << endl;
	cout << "Address: " << customerList[index].getAddress() << endl;
	cout << "Room number: " << customerList[index].getRoomNumber() << endl;
	cout << "Total: 1000 000 VND" << endl;
	cout << string(30, '_') << endl;
	cout << string(4, '_') << "Select a payment method:" << string(4, '_') << endl;
	cout << "0. Come back" << endl;
	cout << "1. Credit card" << endl;
	cout << "2. Cash" << endl;
	cout << string(30, '_') << endl;
	int key = getUserChoice(0, 2);

	switch (key)
	{
	case 0:
		displayMenu();
		break;
	case 1:
		customerList.erase(customerList.begin() + index);
		roomList[roomNumber - 1].setStatus(CLEANING);
		cout << "Payment successful." << endl;
		cout << endl;
		break;
	case 2:
		customerList.erase(customerList.begin() + index);
		roomList[roomNumber - 1].setStatus(CLEANING);
		cout << "Payment successful." << endl;
		cout << endl;
		break;
	}
}

void SecurityAndAccess::displayMenu()
{
	cout << "Security and Access" << endl;
	cout << string(20, '-') << endl;
	cout << "0. Exit" << endl;
	cout << "1. Manager Login" << endl;
	cout << "2. Staff Login" << endl;
	cout << string(20, '-') << endl;
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
	cout << string(4, '_') << "Manager Access" << string(4, '_') << endl;
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
	cout << string(4, '_') << "Manager Access" << string(4, '_') << endl;
	cout << "0. Come back" << endl;
	cout << "1. Edit staff account" << endl;
	cout << "2. Edit manager account" << endl;
	cout << string(24, '_') << endl;
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
		managerMenu4();
		break;
	}
}

void SecurityAndAccess::managerMenu3()
{
	cout << string(4, '_') << "Manager Access" << string(4, '_') << endl;
	cout << "0. Come back" << endl;
	cout << "1. Add new staff account" << endl;
	cout << "2. Edit staff account" << endl;
	cout << "3. Delete staff account" << endl;
	cout << "4. List all staff accounts" << endl;
	cout << string(24, '_') << endl;
	executeManagerMenu3();
}

void SecurityAndAccess::executeManagerMenu3()
{
	int key = getUserChoice(0, 4);
	cout << string(4, '_') << "Manager Access" << string(4, '_') << endl;
	bool test = false;
	Staff newStaff;
	int idChange;
	int idDelete;
	switch (key)
	{
	case 0:
		break;
	case 1:
		cout << "Enter new account" << endl;
		newStaff.user = enterAccount();
		enterStaffInfo(newStaff);
		staffList.push_back(newStaff);
		cout << "Account added." << endl;
		break;
	case 2:
		cout << "Change password" << endl;
		cout << "Enter staff id: ";

		cin >> idChange;

		for (int i = 0; i < staffList.size(); i++)
		{
			if (staffList[i].getId() == idChange)
			{
				test = true;
				enterNewPassword(staffList[i].user);
				break;
			}
		}
		if (!test)
		{
			cout << "Invalid staff id." << endl;
		}
		break;
	case 3:
		cout << "Delete account" << endl;
		cout << "Enter staff id: ";
		cin >> idDelete;
		for (int i = 0; i < staffList.size(); i++)
		{
			if (staffList[i].getId() == idDelete)
			{
				test = true;
				staffList.erase(staffList.begin() + i);
				cout << "Account deleted." << endl;
				break;
			}
		}
		if (!test)
		{
			cout << "Invalid staff id." << endl;
		}
		break;
	case 4:
		cout << "List all staff accounts" << endl;
		cout << string(24, '-') << endl;
		if (staffList.size() == 0)
		{
			cout << "No staff accounts." << endl;
		}
		else
		{
			cout << left << setw(8) << "| ID ";
			cout << left << setw(12) << "| Name ";
			cout << left << setw(14) << "| Username ";
			cout << left << setw(14) << "| Password "
				 << "|" << endl;
			cout << string(49, '-') << endl;

			for (int i = 0; i < staffList.size(); i++)
			{

				cout << "| " << left << setw(6) << staffList[i].getId();
				cout << "| " << left << setw(10) << staffList[i].getName();
				cout << "| " << left << setw(12) << staffList[i].user.getUserName();
				cout << "| " << left << setw(12) << staffList[i].user.getPassword() << "|" << endl;
			}
			cout << string(49, '-') << endl;
		}
		break;
	}
	displayMenu();
}

void SecurityAndAccess::managerMenu4()
{
	cout << string(4, '_') << "Manager Access" << string(4, '_') << endl;
	enterNewPassword(manager.user);
	displayMenu();
}

void SecurityAndAccess::staffMenu1()
{
	cout << string(5, '_') << "Staff Access" << string(5, '_') << endl;
	User user = enterAccount();
	int i;
	bool check = false;
	for (i = 0; i < staffList.size(); i++)
	{
		if (user.getUserName() == staffList[i].user.getUserName() && user.getPassword() == staffList[i].user.getPassword())
		{
			check = true;
			cout << string(10, '_') << "Staff Information" << string(10, '_') << endl;
			cout << left << setw(8) << "| ID ";
			cout << left << setw(12) << "| Name ";
			cout << left << setw(16) << "| Phone Number ";
			cout << left << setw(16) << "| Position ";
			cout << left << setw(14) << "| Username ";
			cout << left << setw(14) << "| Password "
				 << "|" << endl;

			cout << string(81, '-') << endl;

			cout << "| " << left << setw(6) << staffList[i].getId();
			cout << "| " << left << setw(10) << staffList[i].getName();
			cout << "| " << left << setw(14) << staffList[i].getPhoneNumber();
			cout << "| " << left << setw(14) << positionToString(staffList[i].getPosition());
			cout << "| " << left << setw(12) << staffList[i].user.getUserName();
			cout << "| " << left << setw(12) << staffList[i].user.getPassword() << "|" << endl;

			cout << string(81, '-') << endl;

			cout << "0. Come back" << endl;
			cout << "1. Change password" << endl;
			cout << string(24, '_') << endl;

			int key = getUserChoice(0, 1);
			switch (key)
			{
			case 0:
				break;
			case 1:
				enterNewPassword(staffList[i].user);
				break;
			}
			break;
		}
	}

	if (!check)
	{
		cout << "Invalid username or password." << endl;
		cout << endl;
	}

	displayMenu();
}

void FeedbackMenu::displayMenu()
{
	cout << string(4, '_') << "Feedback And Review" << string(4, '_') << endl;
	cout << "0. Exit" << endl;
	cout << "1. Enter review" << endl;
	cout << "2. Read reviews" << endl;
	cout << string(24, '_') << endl;
	executeMenu();
}

void FeedbackMenu::executeMenu()
{
	int key = getUserChoice(0, 2);
	switch (key)
	{
	case 0:
		displayMainMenu();
		break;
	case 1:
		enterReviews();
		break;
	case 2:
		readReviews();
		break;
	}
	displayMainMenu();
}

void FeedbackMenu::enterReviews()
{
	cout << string(4, '_') << "Enter Review" << string(4, '_') << endl;

	cin.ignore();
	cout << "Enter comment: ";
	getline(cin, comment);

	cout << "Enter rating (1-5): ";
	cin >> rating;

	cout << "Thank you for your feedback." << endl;
	cout << endl;
}

void FeedbackMenu::readReviews()
{
	cout << string(4, '_') << "Read Reviews" << string(4, '_') << endl;
	cout << "Comment: " << comment << endl;
	cout << "Rating: " << rating << "Stars" << endl;
}