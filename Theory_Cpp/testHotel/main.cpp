
#include "hotel.h"

extern vector<Room> roomList;
extern vector<Customer> customerList;
extern vector<Staff> staffList;
extern Staff manager;

int main()
{
	BookRoomMenu obj1;
	CustomerMenu obj2;
	PaymentMenu obj3;
	SecurityAndAccess obj4;
	FeedbackMenu obj5;

	setupManager("manager", "Hotel123", "Nguyen Van A", "0123456789");

	while (1)
	{
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