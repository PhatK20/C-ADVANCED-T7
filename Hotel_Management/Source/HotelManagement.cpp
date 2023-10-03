/*
 * File Name: HotelManagement.cpp
 * Author: Phat Bui Gia
 * Date: 29/09/2023
 * Description: This file contains the implementation of functions and methods
 *              for a Hotel Management System, including room setup, customer
 *              management, payment processing, security and access control,
 *              and feedback and reviews handling.
 */

#include "HotelManagement.h"

vector<Room> roomList;
vector<Customer> customerList;
vector<Staff> staffList;
Staff manager;
int Staff::idCounter = 2024;
int Room::roomCounter = 0;

/*
 * Function: displayMainMenu
 * Description: Displays the main menu of the Hotel Management System.
 * Input:
 *   None
 * Output:
 *   None
 */
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

/*
 * Function: getUserChoice
 * Description: Gets the user's choice within a specified range.
 * Input:
 *   numBegin - The beginning of the valid range for user input.
 *   numEnd - The end of the valid range for user input.
 * Output:
 *   Returns the user's choice as an integer.
 */
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

/*
 * Function: setupManager
 * Description: Sets up the manager's information including username, password, name, and phone number.
 * Input:
 *   userName - The username for the manager.
 *   userPassword - The password for the manager.
 *   name - The name of the manager.
 *   phoneNumber - The phone number of the manager.
 * Output:
 *   None
 */
void setupManager(string userName, string userPassword, string name, string phoneNumber)
{
	manager.user.setUserName(userName);
	manager.user.setPassword(userPassword);

	manager.setId();
	manager.setName(name);
	manager.setPhoneNumber(phoneNumber);
	manager.setPosition(MANAGER);
}

/*
 * Function: enterAccount
 * Description: Prompts the user to enter their username and password to create a new User object.
 * Input:
 *   None
 * Output:
 *   Returns a User object representing the entered account information.
 */
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

/*
 * Function: enterNewPassword
 * Description: Prompts the user to enter a new password and updates it for the provided User object.
 * Input:
 *   user - The User object for which the password needs to be updated.
 * Output:
 *   None
 */
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

/*
 * Function: enterStaffInfo
 * Description: Prompts the user to enter staff information including name, phone number, and position,
 *              and sets this information for the provided Staff object.
 * Input:
 *   staff - The Staff object for which the information needs to be entered and set.
 * Output:
 *   None
 */
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

/*
 * Function: checkStaffLogin
 * Description: Checks if a user's login credentials match any staff member's credentials in the staffList.
 * Input:
 *   user - The User object representing the login credentials.
 * Output:
 *   Returns true if the login credentials match any staff member's credentials, false otherwise.
 */
bool checkStaffLogin(User user)
{
	int check = false;
	for (int i = 0; i < (int)staffList.size(); i++)
	{
		if (user.getUserName() == staffList[i].user.getUserName() && user.getPassword() == staffList[i].user.getPassword())
		{
			check = true;
			break;
		}
	}
	return check;
}

/*
 * Function: checkStaffLogin
 * Description: Checks if a user's login credentials match any staff member's credentials with the specified position in the staffList.
 * Input:
 *   user - The User object representing the login credentials.
 *   pos - The position to be checked against.
 * Output:
 *   Returns true if the login credentials match any staff member's credentials with the specified position, false otherwise.
 */
bool checkStaffLogin(User user, Position pos)
{
	int check = false;
	for (int i = 0; i < (int)staffList.size(); i++)
	{
		if (user.getUserName() == staffList[i].user.getUserName() && user.getPassword() == staffList[i].user.getPassword() && staffList[i].getPosition() == pos)
		{
			check = true;
			break;
		}
	}
	return check;
}

/*
 * Function: checkManagerLogin
 * Description: Checks if a user's login credentials match the manager's credentials.
 * Input:
 *   user - The User object representing the login credentials.
 * Output:
 *   Returns true if the login credentials match the manager's credentials, false otherwise.
 */
bool checkManagerLogin(User user)
{
	bool check = false;

	if (user.getUserName() == manager.user.getUserName() && user.getPassword() == manager.user.getPassword())
	{
		check = true;
	}

	return check;
}

/*
 * Function: positionToString
 * Description: Converts a Position enum value to its corresponding string representation.
 * Input:
 *   pos - The Position enum value to be converted.
 * Output:
 *   Returns the string representation of the Position.
 */
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

/*
 * Constructor: Room::Room
 * Description: Initializes a Room object with an EMPTY status.
 * Input:
 *   None
 * Output:
 *   None
 */
Room::Room()
{
	status = EMPTY;
}

/*
 * Class: Room
 * Method: setStatus
 * Description: Sets the status of the room (EMPTY, BOOKED, CLEANING).
 * Input:
 *   status - The Status enum value to be set for the room.
 * Output:
 *   None
 */
void Room::setStatus(Status status)
{
	this->status = status;
}

/*
 * Class: Room
 * Method: getStatus
 * Description: Gets the current status of the room.
 * Input:
 *   None
 * Output:
 *   Returns the Status enum value representing the room's status.
 */
Status Room::getStatus()
{
	return status;
}

/*
 * Class: Room
 * Method: setRoomNumber
 * Description: Sets the room number for the room by incrementing the roomCounter.
 * Input:
 *   None
 * Output:
 *   None
 */
void Room::setRoomNumber()
{
	this->roomNumber = ++roomCounter;
}

/*
 * Class: Room
 * Method: getRoomNumber
 * Description: Gets the room number of the room.
 * Input:
 *   None
 * Output:
 *   Returns the room number as an integer.
 */
int Room::getRoomNumber()
{
	return roomNumber;
}

/*
 * Class: Customer
 * Method: setName
 * Description: Sets the name of the customer.
 * Input:
 *   name - The name of the customer.
 * Output:
 *   None
 */
void Customer::setName(string name)
{
	this->name = name;
}

/*
 * Class: Customer
 * Method: getName
 * Description: Gets the name of the customer.
 * Input:
 *   None
 * Output:
 *   Returns the name of the customer as a string.
 */
string Customer::getName()
{
	return name;
}

/*
 * Class: Customer
 * Method: setPhoneNumber
 * Description: Sets the phone number of the customer.
 * Input:
 *   phoneNumber - The phone number of the customer.
 * Output:
 *   None
 */
void Customer::setPhoneNumber(string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

/*
 * Class: Customer
 * Method: getPhoneNumber
 * Description: Gets the phone number of the customer.
 * Input:
 *   None
 * Output:
 *   Returns the phone number of the customer as a string.
 */
string Customer::getPhoneNumber()
{
	return phoneNumber;
}

/*
 * Class: Customer
 * Method: setAddress
 * Description: Sets the address of the customer.
 * Input:
 *   address - The address of the customer.
 * Output:
 *   None
 */
void Customer::setAddress(string address)
{
	this->address = address;
}

/*
 * Class: Customer
 * Method: getAddress
 * Description: Gets the address of the customer.
 * Input:
 *   None
 * Output:
 *   Returns the address of the customer as a string.
 */
string Customer::getAddress()
{
	return address;
}

/*
 * Class: Customer
 * Method: setRoomNumber
 * Description: Sets the room number assigned to the customer.
 * Input:
 *   roomNumber - The room number assigned to the customer.
 * Output:
 *   None
 */
void Customer::setRoomNumber(int roomNumber)
{
	this->roomNumber = roomNumber;
}

/*
 * Class: Customer
 * Method: getRoomNumber
 * Description: Gets the room number assigned to the customer.
 * Input:
 *   None
 * Output:
 *   Returns the room number assigned to the customer as an integer.
 */
int Customer::getRoomNumber()
{
	return roomNumber;
}

/*
 * Class: User
 * Method: setUserName
 * Description: Sets the username of the user.
 * Input:
 *   userName - The username of the user.
 * Output:
 *   None
 */
void User::setUserName(string userName)
{
	this->userName = userName;
}

/*
 * Class: User
 * Method: getUserName
 * Description: Gets the username of the user.
 * Input:
 *   None
 * Output:
 *   Returns the username of the user as a string.
 */
string User::getUserName()
{
	return userName;
}

/*
 * Class: User
 * Method: setPassword
 * Description: Sets the password of the user.
 * Input:
 *   password - The password of the user.
 * Output:
 *   None
 */
void User::setPassword(string password)
{
	this->password = password;
}

/*
 * Class: User
 * Method: setPassword
 * Description: Sets the password of the user.
 * Input:
 *   password - The password of the user.
 * Output:
 *   None
 */
string User::getPassword()
{
	return password;
}

/*
 * Class: User
 * Method: setPassword
 * Description: Sets the password of the user.
 * Input:
 *   password - The password of the user.
 * Output:
 *   None
 */
void Staff::setId()
{
	this->id = idCounter++;
}

/*
 * Class: Staff
 * Method: getId
 * Description: Gets the ID of the staff member.
 * Input:
 *   None
 * Output:
 *   Returns the ID of the staff member as an integer.
 */
int Staff::getId()
{
	return id;
}

/*
 * Class: Staff
 * Method: setName
 * Description: Sets the name of the staff member.
 * Input:
 *   name - The name of the staff member.
 * Output:
 *   None
 */
void Staff::setName(string name)
{
	this->name = name;
}

/*
 * Class: Staff
 * Method: getName
 * Description: Gets the name of the staff member.
 * Input:
 *   None
 * Output:
 *   Returns the name of the staff member as a string.
 */
string Staff::getName()
{
	return name;
}

/*
 * Class: Staff
 * Method: setPhoneNumber
 * Description: Sets the phone number of the staff member.
 * Input:
 *   phoneNumber - The phone number of the staff member.
 * Output:
 *   None
 */
void Staff::setPhoneNumber(string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

/*
 * Class: Staff
 * Method: getPhoneNumber
 * Description: Gets the phone number of the staff member.
 * Input:
 *   None
 * Output:
 *   Returns the phone number of the staff member as a string.
 */
string Staff::getPhoneNumber()
{
	return phoneNumber;
}

/*
 * Class: Staff
 * Method: setPosition
 * Description: Sets the position of the staff member (MANAGER, RECEPTIONIST, SECURITY, CLEANER).
 * Input:
 *   position - The Position enum value representing the staff member's position.
 * Output:
 *   None
 */
void Staff::setPosition(Position position)
{
	this->position = position;
}

/*
 * Class: Staff
 * Method: getPosition
 * Description: Gets the position of the staff member.
 * Input:
 *   None
 * Output:
 *   Returns the Position enum value representing the staff member's position.
 */
Position Staff::getPosition()
{
	return position;
}

/*
 * Class: BookRoomMenu
 * Method: setNumberOfRooms
 * Description: Sets the number of rooms to be managed.
 * Input:
 *   numberOfRooms - The number of rooms to be set.
 * Output:
 *   None
 */
void BookRoomMenu::setNumberOfRooms(int numberOfRooms)
{
	this->numberOfRooms = numberOfRooms;
}

/*
 * Class: BookRoomMenu
 * Method: getNumberOfRooms
 * Description: Gets the number of rooms to be managed.
 * Input:
 *   None
 * Output:
 *   Returns the number of rooms as an integer.
 */
int BookRoomMenu::getNumberOfRooms()
{
	return numberOfRooms;
}

/*
 * Class: BookRoomMenu
 * Method: displayMenu
 * Description: Displays the room setup menu.
 * Input:
 *   None
 * Output:
 *   None
 */
void BookRoomMenu::displayMenu()
{
	cout << string(4, '_') << "Room Setup" << string(4, '_') << endl;
	cout << "0. Exit" << endl;
	cout << "1. Set the number of rooms" << endl;
	cout << "2. Book a room" << endl;
	cout << string(24, '_') << endl;
	executeMenu();
}

/*
 * Class: BookRoomMenu
 * Method: executeMenu
 * Description: Executes the room setup menu based on user input.
 * Input:
 *   None
 * Output:
 *   None
 */
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

/*
 * Class: BookRoomMenu
 * Method: roomSetup
 * Description: Allows the manager to set the number of rooms and initializes roomList.
 * Input:
 *   None
 * Output:
 *   None
 */
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

/*
 * Class: BookRoomMenu
 * Method: bookRoom1
 * Description: Displays the list of rooms and their statuses and allows the user to select a room for booking.
 * Input:
 *   None
 * Output:
 *   None
 */
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

/*
 * Class: BookRoomMenu
 * Method: bookRoom1
 * Description: Displays the list of rooms and their statuses and allows the user to select a room for booking.
 * Input:
 *   None
 * Output:
 *   None
 */
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

/*
 * Class: BookRoomMenu
 * Method: bookRoom2
 * Description: Allows the user to enter customer information for booking a room.
 * Input:
 *   roomNo - The room number being booked.
 * Output:
 *   None
 */
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

/*
 * Class: BookRoomMenu
 * Method: bookRoom3
 * Description: Displays a success message after booking a room and allows the user to continue booking or return to the main menu.
 * Input:
 *   None
 * Output:
 *   None
 */
void BookRoomMenu::bookRoom3()
{
	cout << "Booking Success." << endl;
	cout << string(30, '_') << endl;
	cout << "0. Exit" << endl;
	cout << "1. Continue booking." << endl;
	cout << string(30, '_') << endl;
	executeBookRoom3();
}

/*
 * Class: BookRoomMenu
 * Method: executeBookRoom3
 * Description: Executes actions based on the user's choice after a booking.
 * Input:
 *   None
 * Output:
 *   None
 */
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

/*
 * Class: CustomerMenu
 * Method: printCustomerList
 * Description: Prints the list of customers and their details.
 * Input:
 *   None
 * Output:
 *   None
 */
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
	for (int i = 0; i < (int)customerList.size(); i++)
	{
		cout << "| " << left << setw(4) << i + 1;
		cout << "| " << left << setw(10) << customerList[i].getName();
		cout << "| " << left << setw(14) << customerList[i].getPhoneNumber();
		cout << "| " << left << setw(14) << customerList[i].getAddress();
		cout << "| " << left << setw(14) << customerList[i].getRoomNumber();
		cout << "|" << endl;
	}
}

/*
 * Class: CustomerMenu
 * Method: printCustomerList
 * Description: Prints the list of customers and their details.
 * Input:
 *   None
 * Output:
 *   None
 */
void CustomerMenu::displayMenu()
{
	cout << string(4, '_') << "Customer Management" << string(4, '_') << endl;
	cout << "0. Exit" << endl;
	cout << "1. Enter Account" << endl;
	cout << string(24, '_') << endl;
	executeMenu();
}

/*
 * Class: CustomerMenu
 * Method: printCustomerList
 * Description: Prints the list of customers and their details.
 * Input:
 *   None
 * Output:
 *   None
 */
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

/*
 * Class: CustomerMenu
 * Method: displayMenu1
 * Description: Displays the submenu for customer management, including the list of customers.
 * Input:
 *   None
 * Output:
 *   None
 */
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

/*
 * Class: CustomerMenu
 * Method: executeMenu1
 * Description: Executes actions based on the user's choice in the customer management submenu.
 * Input:
 *   None
 * Output:
 *   None
 */
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

/*
 * Class: CustomerMenu
 * Method: editCustomer
 * Description: Allows the user to edit customer information by choosing from options such as name, phone number, or address.
 * Input:
 *   None
 * Output:
 *   None
 */
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

/*
 * Class: CustomerMenu
 * Method: editName
 * Description: Allows the user to edit the name of a customer.
 * Input:
 *   id - The ID of the customer to edit.
 * Output:
 *   None
 */
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

/*
 * Class: CustomerMenu
 * Method: editPhoneNumber
 * Description: Allows the user to edit the phone number of a customer.
 * Input:
 *   id - The ID of the customer to edit.
 * Output:
 *   None
 */
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

/*
 * Class: CustomerMenu
 * Method: editPhoneNumber
 * Description: Allows the user to edit the phone number of a customer.
 * Input:
 *   id - The ID of the customer to edit.
 * Output:
 *   None
 */
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

/*
 * Class: CustomerMenu
 * Method: editPhoneNumber
 * Description: Allows the user to edit the phone number of a customer.
 * Input:
 *   id - The ID of the customer to edit.
 * Output:
 *   None
 */
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

/*
 * Class: PaymentMenu
 * Method: displayMenu
 * Description: Displays the payment menu.
 * Input:
 *   None
 * Output:
 *   None
 */
void PaymentMenu::displayMenu()
{
	cout << string(4, '_') << "Payment" << string(4, '_') << endl;
	cout << "0. Exit" << endl;
	cout << "1. Pay" << endl;
	cout << string(30, '_') << endl;
	executeMenu();
}

/*
 * Class: PaymentMenu
 * Method: executeMenu
 * Description: Executes actions based on the user's choice in the payment menu.
 * Input:
 *   None
 * Output:
 *   None
 */
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

		for (i = 0; i < (int)customerList.size(); i++)
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

/*
 * Class: PaymentMenu
 * Method: payment
 * Description: Handles the payment process for a customer's bill, including displaying the bill and selecting a payment method.
 * Input:
 *   roomNumber - The room number associated with the bill.
 *   index - The index of the customer in the customer list.
 * Output:
 *   None
 */
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

/*
 * Class: SecurityAndAccess
 * Method: displayMenu
 * Description: Displays the main menu for security and access, allowing the user to choose between manager and staff login.
 * Input:
 *   None
 * Output:
 *   None
 */
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

/*
 * Class: SecurityAndAccess
 * Method: executeMenu
 * Description: Executes actions based on the user's choice in the security and access menu.
 * Input:
 *   None
 * Output:
 *   None
 */
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

/*
 * Class: SecurityAndAccess
 * Method: managerMenu1
 * Description: Handles manager login, allowing the user to enter their account details and verifying them.
 * Input:
 *   None
 * Output:
 *   None
 */
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

/*
 * Class: SecurityAndAccess
 * Method: managerMenu2
 * Description: Displays the manager's menu with options for editing staff and manager accounts.
 * Input:
 *   None
 * Output:
 *   None
 */
void SecurityAndAccess::managerMenu2()
{
	cout << string(4, '_') << "Manager Access" << string(4, '_') << endl;
	cout << "0. Come back" << endl;
	cout << "1. Edit staff account" << endl;
	cout << "2. Edit manager account" << endl;
	cout << string(24, '_') << endl;
	executeManagerMenu2();
}

/*
 * Class: SecurityAndAccess
 * Method: executeManagerMenu2
 * Description: Executes actions based on the user's choice in the manager's menu.
 * Input:
 *   None
 * Output:
 *   None
 */
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

/*
 * Class: SecurityAndAccess
 * Method: managerMenu3
 * Description: Displays the manager's menu with options for adding, editing, and deleting staff accounts, and listing all staff accounts.
 * Input:
 *   None
 * Output:
 *   None
 */
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

/*
 * Class: SecurityAndAccess
 * Method: executeManagerMenu3
 * Description: Executes actions based on the user's choice in the manager's submenu.
 * Input:
 *   None
 * Output:
 *   None
 */
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

		for (int i = 0; i < (int)staffList.size(); i++)
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
		for (int i = 0; i < (int)staffList.size(); i++)
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

			for (int i = 0; i < (int)staffList.size(); i++)
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

/*
 * Class: SecurityAndAccess
 * Method: managerMenu4
 * Description: Displays the manager's menu to change the manager's password.
 * Input:
 *   None
 * Output:
 *   None
 */
void SecurityAndAccess::managerMenu4()
{
	cout << string(4, '_') << "Manager Access" << string(4, '_') << endl;
	enterNewPassword(manager.user);
	displayMenu();
}

/*
 * Class: SecurityAndAccess
 * Method: staffMenu1
 * Description: Displays the staff's menu after successful login, including staff information and options to change the password.
 * Input:
 *   None
 * Output:
 *   None
 */
void SecurityAndAccess::staffMenu1()
{
	cout << string(5, '_') << "Staff Access" << string(5, '_') << endl;
	User user = enterAccount();
	int i;
	bool check = false;
	for (i = 0; i < (int)staffList.size(); i++)
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

/*
 * Class: FeedbackMenu
 * Method: displayMenu
 * Description: Displays the feedback and review menu with options to enter and read reviews.
 * Input:
 *   None
 * Output:
 *   None
 */
void FeedbackMenu::displayMenu()
{
	cout << string(4, '_') << "Feedback And Review" << string(4, '_') << endl;
	cout << "0. Exit" << endl;
	cout << "1. Enter review" << endl;
	cout << "2. Read reviews" << endl;
	cout << string(24, '_') << endl;
	executeMenu();
}

/*
 * Class: FeedbackMenu
 * Method: executeMenu
 * Description: Executes actions based on the user's choice in the feedback and review menu.
 * Input:
 *   None
 * Output:
 *   None
 */
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

/*
 * Class: FeedbackMenu
 * Method: executeMenu
 * Description: Executes actions based on the user's choice in the feedback and review menu.
 * Input:
 *   None
 * Output:
 *   None
 */
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

/*
 * Class: FeedbackMenu
 * Method: executeMenu
 * Description: Executes actions based on the user's choice in the feedback and review menu.
 * Input:
 *   None
 * Output:
 *   None
 */
void FeedbackMenu::readReviews()
{
	cout << string(4, '_') << "Read Reviews" << string(4, '_') << endl;
	cout << "Comment: " << comment << endl;
	cout << "Rating: " << rating << "Stars" << endl;
}