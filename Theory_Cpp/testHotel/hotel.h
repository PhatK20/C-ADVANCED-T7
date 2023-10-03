#ifndef _HOTEL_H
#define _HOTEL_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

void displayMainMenu();
int getUserChoice(int numBegin, int numEnd);
void setupManager(string userName, string userPassword, string name, string phoneNumber);

enum Status
{
	EMPTY,
	BOOKED,
	CLEANING
};

class Room
{
private:
	Status status;
	static int roomCounter;
	int roomNumber;

public:
	Room();

	void setStatus(Status status);
	Status getStatus();

	void setRoomNumber();
	int getRoomNumber();
};

class Customer
{
private:
	string name;
	string phoneNumber;
	string address;
	int roomNumber;

public:
	void setName(string name);
	string getName();

	void setPhoneNumber(string phoneNumber);
	string getPhoneNumber();

	void setAddress(string address);
	string getAddress();

	void setRoomNumber(int roomNumber);
	int getRoomNumber();
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

enum Position
{
	MANAGER,
	RECEPTIONIST,
	SECURITY,
	CLEANER
};

string positionToString(Position pos);

class Staff
{
private:
	static int idCounter;
	int id;
	string name;
	string phoneNumber;
	Position position;

public:
	User user;

	void setId();
	int getId();

	void setName(string name);
	string getName();

	void setPhoneNumber(string phoneNumber);
	string getPhoneNumber();

	void setPosition(Position position);
	Position getPosition();
};

User enterAccount();
void enterNewPassword(User &user);
void enterStaffInfo(Staff &staff);
bool checkStaffLogin(User user);
bool checkManagerLogin(User user);

// 1
class BookRoomMenu
{
private:
	int numberOfRooms;

public:
	void setNumberOfRooms(int numberOfRooms);
	int getNumberOfRooms();

	void displayMenu();
	void executeMenu();

	void roomSetup();

	void bookRoom1();
	void executeBookRoom1();
	void bookRoom2(int roomNumber);
	void bookRoom3();
	void executeBookRoom3();
};

// 2
class CustomerMenu
{
private:
public:
	void printCustomerList();
	void displayMenu();
	void executeMenu();

	void displayMenu1();
	void executeMenu1();

	void editCustomer();
	void editName(int id);
	void editPhoneNumber(int id);
	void editAddress(int id);

	void deleteCustomer();
};

// 3
class PaymentMenu
{
private:
public:
	void displayMenu();
	void executeMenu();
	void payment(int roomNumber, int index);
};

// 4
class SecurityAndAccess
{
private:
public:
	void displayMenu();
	void executeMenu();

	void managerMenu1();
	void managerMenu2();
	void executeManagerMenu2();
	void managerMenu3();
	void executeManagerMenu3();
	void managerMenu4();

	void staffMenu1();
};

// 5
class FeedbackMenu
{
private:
	int rating;
	string comment;

public:
	void displayMenu();
	void executeMenu();
	void enterReviews();
	void readReviews();
};

#endif