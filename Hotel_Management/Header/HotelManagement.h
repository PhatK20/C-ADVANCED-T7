/*
 * File Name: HotelManagement.h
 * Author: Phat Bui Gia
 * Date: 29/09/2023
 * Description: This header file declares functions, classes, enums, and variables
 *              to support the hotel management program.
 */

#ifndef _HOTEL_H
#define _HOTEL_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Function to display the main menu of the hotel management program.
void displayMainMenu();

// Function to get user choice within a specified range.
int getUserChoice(int numBegin, int numEnd);

// Function to set up the manager's account.
void setupManager(string userName, string userPassword, string name, string phoneNumber);

// Function to enter staff information.
enum Status
{
	EMPTY,
	BOOKED,
	CLEANING
};

// Class representing rooms
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

// Class representing customer information
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

// Class representing a user (with a username and password)
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

// Enum to represent the position of staff members.
enum Position
{
	MANAGER,
	RECEPTIONIST,
	SECURITY,
	CLEANER
};

// Convert a Position enum value to its corresponding string representation.
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

// Function to enter user account information.
User enterAccount();

// Function to enter and set a new password for a user.
void enterNewPassword(User &user);

// Function to enter staff information.
void enterStaffInfo(Staff &staff);

// Function to enter staff information.
bool checkStaffLogin(User user);

// Function to enter staff information.
bool checkManagerLogin(User user);

// Class declaration for room management menu
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

// Class declaration for customer management menu
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

// Class declaration for payment menu
class PaymentMenu
{
private:
public:
	void displayMenu();
	void executeMenu();
	void payment(int roomNumber, int index);
};

// Class declaration for security and access menu
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

// Class declaration for feedback and review menu
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