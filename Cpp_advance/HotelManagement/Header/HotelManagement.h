#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayMainMenu();
void getUserChoice(int numBegin, int numEnd);

typedef enum
{
	Empty,
	Booked,
	Cleaning
} Status;

class Room
{
private:
	int roomNo; // số thứ tự của phòng
	Status status;

public:
	// enum class Status
	// {
	// 	Empty,
	// 	Booked,
	// 	Cleaning
	// };

	Room() : status(Status::Empty) {}

	void setRoomNo(int roomNo);
	int getRoomNo();
	Status getStatus();

	// Đặt các trạng thái cho phòng
	void bookRoom();
	void cleanRoom();
	void emptyRoom();
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

class Customer
{
private:
	string name;
	string phoneNumber;
	string address;

public:
	void setName(string name);
	string getName(string name);

	void setPhoneNumber(string phoneNumber);
	string getPhoneNumber(string phoneNumber);

	void setAddress(string address);
	string getAddress(string address);
};

class Employee
{
private:
	string name;
	string phoneNumber;
	string position;

public:
	Employee(const string &name, const string &phoneNumber, const string &position)
		: name(name), phoneNumber(phoneNumber), position(position) {}

	const string &getName() const { return name; }
	const string &getPhoneNumber() const { return phoneNumber; }
	const string &getPosition() const { return position; }
};

// class Hotel
// {
// private:
// 	vector<Room> rooms;
// 	vector<Customer> customers;
// 	vector<Employee> employees;

// public:
// 	void addRoom(int roomNumber)
// 	{
// 		rooms.push_back(Room(roomNumber));
// 	}

// 	void listRooms()
// 	{
// 		cout << "Room List:" << endl;
// 		for (const auto &room : rooms)
// 		{
// 			cout << "Room " << room.getRoomNumber() << ": ";
// 			switch (room.getStatus())
// 			{
// 			case Room::Status::Empty:
// 				cout << "Empty";
// 				break;
// 			case Room::Status::Booked:
// 				cout << "Booked";
// 				break;
// 			case Room::Status::Cleaning:
// 				cout << "Cleaning";
// 				break;
// 			}
// 			cout << endl;
// 		}
// 	}

// 	void addCustomer(const string &name, const string &phoneNumber, const string &address)
// 	{
// 		customers.push_back(Customer(name, phoneNumber, address));
// 	}

// 	void listCustomers()
// 	{
// 		cout << "Customer List:" << endl;
// 		for (const auto &customer : customers)
// 		{
// 			cout << "Name: " << customer.getName() << ", Phone: " << customer.getPhoneNumber() << ", Address: " << customer.getAddress() << endl;
// 		}
// 	}

// 	void addEmployee(const string &name, const string &phoneNumber, const string &position)
// 	{
// 		employees.push_back(Employee(name, phoneNumber, position));
// 	}

// 	void listEmployees()
// 	{
// 		cout << "Employee List:" << endl;
// 		for (const auto &employee : employees)
// 		{
// 			cout << "Name: " << employee.getName() << ", Phone: " << employee.getPhoneNumber() << ", Position: " << employee.getPosition() << endl;
// 		}
// 	}
// };