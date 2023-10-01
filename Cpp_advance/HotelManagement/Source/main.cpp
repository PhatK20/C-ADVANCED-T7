#include "HotelManagement.h"

int main()
{
	DisplayBookRoom test;
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
