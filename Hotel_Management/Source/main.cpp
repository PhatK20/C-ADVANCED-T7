/*
 * File Name: main.cpp
 * Author: Phat Bui Gia
 * Date: 29/09/2023
 * Description: Hotel Management System main program
 */

#include "HotelManagement.h"

// Global variables
extern vector<Room> roomList;
extern vector<Customer> customerList;
extern vector<Staff> staffList;
extern Staff manager;

int main()
{
	// Create instances of various menus and initialize the manager account
	BookRoomMenu obj1;
	CustomerMenu obj2;
	PaymentMenu obj3;
	SecurityAndAccess obj4;
	FeedbackMenu obj5;

	setupManager("manager", "Hotel123", "Nguyen Van A", "0123456789");

	while (1)
	{
		// Create instances of various menus and initialize the manager account
		displayMainMenu();
		int key = getUserChoice(0, 5);
		switch (key)
		{
		case 0:
			return 0;
		case 1:
			obj1.displayMenu();
			break;
		case 2:
			obj2.displayMenu();
			break;
		case 3:
			obj3.displayMenu();
			break;
		case 4:
			obj4.displayMenu();
			break;
		case 5:
			obj5.displayMenu();
			break;
		}
	}
}