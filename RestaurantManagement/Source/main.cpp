/*
 * File Name: main.cpp
 * Author: Phat Bui Gia
 * Date: 15/09/2023
 * Description: This program provides an interactive interface for managing a restaurant.
 */

#include "RestaurantManagement.h"

int main()
{
	Manager manager;
	Staff staff;
	while (1)
	{
		displayMainMenu();
		int key = getUserChoice(0, 2);
		switch (key)
		{
		case 0:
			return 0;
		case 1:
			manager.displayMenuManager();
			break;
		case 2:
			staff.setDishList(manager.getDishList());
			staff.setNumberOfTable(manager.getTable());
			staff.setSizeTableList(manager.getTable());
			staff.displayMenuStaff();
			break;
		}
	}
}