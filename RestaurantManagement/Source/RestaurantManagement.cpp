/*
 * File Name: RestaurantManagement.cpp
 * Author: Phat Bui Gia
 * Date: 15/09/2023
 * Description: This C++ program manages a restaurant with menu and table orders.
 * It uses classes for dishes, managers, staff, and tables, offering various
 * operations like adding, editing, removing dishes, and handling orders and bills.
 */

#include "RestaurantManagement.h"

int Dish::idCounterDish = 100;

/*
 * Function: displayMainMenu
 * Description: Displays the main menu for a restaurant management system.
 * Input:
 *   None
 * Output:
 *   None
 */
void displayMainMenu()
{
	cout << "__________HOME___________" << endl;
	cout << "0. Exit" << endl;
	cout << "1. Manager" << endl;
	cout << "2. Staff" << endl;
	cout << "_________________________" << endl;
}

/*
 * Function: getUserChoice
 * Description: Prompts the user for a choice and validates it within a specified range.
 * Input:
 *   numBegin - The minimum valid choice.
 *   numEnd - The maximum valid choice.
 * Output:
 *   Returns the user's valid choice.
 */
int getUserChoice(int numBegin, int numEnd)
{
	int choice;
	printf("Enter your choice: ");
	scanf("%d", &choice);
	while (choice < numBegin || choice > numEnd)
	{
		printf("Invalid choice! Please try again\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
	}
	return choice;
}

/*
 * Class: Dish
 * Method: setIdDish
 * Description: Sets the ID for a Dish object.
 * Input:
 *   None
 * Output:
 *   None
 */
void Dish::setIdDish()
{
	this->idDish = ++idCounterDish;
}

/*
 * Class: Dish
 * Method: setNameDish
 * Description: Sets the name for a Dish object.
 * Input:
 *   None
 * Output:
 *   None
 */
void Dish::setNameDish()
{
	cin.ignore(); // xóa dấu xuống dòng khỏi bộ đệm
	string nameDish;
	cout << "Enter name: ";
	getline(cin, nameDish);
	this->nameDish = nameDish;
}

/*
 * Class: Dish
 * Method: setPriceDish
 * Description: Sets the price for a Dish object.
 * Input:
 *   None
 * Output:
 *   None
 */
void Dish::setPriceDish()
{
	int priceDish;
	cout << "Enter price: ";
	cin >> priceDish;
	this->priceDish = priceDish;
}

/*
 * Class: Dish
 * Method: getIdDish
 * Description: Gets the ID of a Dish object.
 * Input:
 *   None
 * Output:
 *   Returns the ID of the Dish object.
 */
int Dish::getIdDish()
{
	return this->idDish;
}

/*
 * Class: Dish
 * Method: getNameDish
 * Description: Gets the name of a Dish object.
 * Input:
 *   None
 * Output:
 *   Returns the name of the Dish object.
 */
string Dish::getNameDish()
{
	return this->nameDish;
}

/*
 * Class: Dish
 * Method: getPriceDish
 * Description: Gets the price of a Dish object.
 * Input:
 *   None
 * Output:
 *   Returns the price of the Dish object.
 */
int Dish::getPriceDish()
{
	return this->priceDish;
}

/*
 * Class: Dish
 * Method: setNumberOfDish
 * Description: Sets the number of a specific Dish object.
 * Input:
 *   num - The number of dishes to set.
 * Output:
 *   None
 */
void Dish::setNumberOfDish(int num)
{
	this->numberOfDish = num;
}

/*
 * Class: Dish
 * Method: getNumberOfDish
 * Description: Gets the number of a specific Dish object.
 * Input:
 *   None
 * Output:
 *   Returns the number of the Dish object.
 */
int Dish::getNumberOfDish()
{
	return this->numberOfDish;
}

/*
 * Function: dishTitle
 * Description: Displays the title for a table of dish information.
 * Input:
 *   None
 * Output:
 *   None
 */
void dishTitle()
{
	cout << "_______Food Information_______" << endl;
	cout << " ID  |   Name   |   Price   " << endl;
	cout << "------------------------------" << endl;
}

/*
 * Function: dishInformation
 * Description: Displays information about a Dish object in a formatted manner.
 * Input:
 *   dish - The Dish object to display information.
 * Output:
 *   None
 */
void dishInformation(Dish dish)
{
	printf(" %-4d| %-9s| %-10d\n", dish.getIdDish(), dish.getNameDish().c_str(), dish.getPriceDish());
}

/*
 * Class: Manager
 * Method: displayDishList
 * Description: Displays the list of dishes in the menu managed by the manager.
 * Input:
 *   None
 * Output:
 *   None
 */
void Manager::displayDishList()
{
	cout << "___________Manager___________" << endl;
	if (!dishList.empty())
	{
		cout << "____________Menu____________" << endl;
		cout << " NO | ID  |   Name   |   Price   " << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < (int)dishList.size(); i++)
		{
			printf(" %-3d| %-4d| %-9s| %-10d\n", i + 1,
				   dishList[i].getIdDish(), dishList[i].getNameDish().c_str(), dishList[i].getPriceDish());
		}
	}
	else
	{
		cout << "Dish list is empty." << endl;
		cout << endl;
	}
}

/*
 * Class: Manager
 * Method: setTable
 * Description: Sets the number of tables in the restaurant managed by the manager.
 * Input:
 *   None
 * Output:
 *   None
 */
void Manager::setTable()
{
	cout << "Enter number of tables: ";
	cin >> this->table;
}

/*
 * Class: Manager
 * Method: getTable
 * Description: Gets the number of tables set by the manager.
 * Input:
 *   None
 * Output:
 *   Returns the number of tables.
 */
int Manager::getTable()
{
	return this->table;
}

/*
 * Class: Manager
 * Method: setDishList
 * Description: Adds a dish to the menu managed by the manager.
 * Input:
 *   dish - The Dish object to be added to the menu.
 * Output:
 *   None
 */
void Manager::setDishList(Dish dish)
{
	this->dishList.push_back(dish);
}

/*
 * Class: Manager
 * Method: getDishList
 * Description: Gets the list of dishes in the menu managed by the manager.
 * Input:
 *   None
 * Output:
 *   Returns the list of dishes in the menu.
 */
vector<Dish> Manager::getDishList()
{
	return dishList;
}

/*
 * Class: Manager
 * Method: displayMenuManager
 * Description: Displays the main menu for the manager's actions.
 * Input:
 *   None
 * Output:
 *   None
 */
void Manager::displayMenuManager()
{
	cout << "___________Manager___________" << endl;
	cout << "0. Come back" << endl;
	cout << "1. Set number of table" << endl;
	cout << "2. Add dish" << endl;
	cout << "3. Edit dish" << endl;
	cout << "4. Remove dish" << endl;
	cout << "5. Display dish" << endl;
	cout << "_____________________________" << endl;
	menuManager();
}

/*
 * Class: Manager
 * Method: menuManager
 * Description: Handles the manager's menu choices and invokes corresponding methods.
 * Input:
 *   None
 * Output:
 *   None
 */
void Manager::menuManager()
{
	int choice = getUserChoice(0, 5);
	switch (choice)
	{
	case 0:
		cout << endl;
		break;
	case 1:
		menuNumerOfTable();
		break;
	case 2:
		menuAddDish();
		break;
	case 3:
		menuEditDish();
		break;
	case 4:
		menuRemoveDish();
		break;
	case 5:
		displayDishList();
		break;
	}
}

/*
 * Class: Manager
 * Method: menuNumberOfTable
 * Description: Displays the menu for setting the number of tables.
 * Input:
 *   None
 * Output:
 *   None
 */
void Manager::menuNumerOfTable()
{
	cout << "___________Manager___________" << endl;
	cout << "0. Come back" << endl;
	cout << "1. Set number of table" << endl;
	cout << "_____________________________" << endl;
	numberOfTable();
}

/*
 * Class: Manager
 * Method: numberOfTable
 * Description: Handles the input for setting the number of tables.
 * Input:
 *   None
 * Output:
 *   None
 */
void Manager::numberOfTable()
{
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	if (choice == 1)
	{
		setTable();
		cout << "Successfully set number of table." << endl;
		cout << endl;
		displayMenuManager();
	}
	else if (choice == 0)
	{
		return;
	}
	else
	{
		cout << "Invalid choice. Please try again." << endl;
		numberOfTable();
	}
}

/*
 * Class: Manager
 * Method: menuAddDish
 * Description: Displays the menu for adding a new dish to the menu.
 * Input:
 *   None
 * Output:
 *   None
 */
void Manager::menuAddDish()
{
	Dish dish;
	cout << "___________Manager___________" << endl;
	dish.setIdDish();
	dish.setNameDish();
	dish.setPriceDish();
	setDishList(dish);
	cout << "_____________________________" << endl;
	cout << "Successfully added dish." << endl;
	cout << endl;
	cout << "___________Manager___________" << endl;
	dishTitle();
	dishInformation(dish);
	cout << endl;
	cout << "_____________________________" << endl;
	cout << "0. Come back" << endl;
	cout << "1. Countinue" << endl;
	cout << "_____________________________" << endl;
	addDish();
}

/*
 * Class: Manager
 * Method: addDish
 * Description: Handles the addition of a new dish to the menu.
 * Input:
 *   None
 * Output:
 *   None
 */
void Manager::addDish()
{
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	cout << endl;
	if (choice == 1)
	{
		menuAddDish();
		cout << endl;
	}
	else if (choice == 0)
	{
		displayMenuManager();
		return;
	}
	else
	{
		cout << "Invalid choice. Please try again." << endl;
		addDish();
	}
}

/*
 * Class: Manager
 * Method: menuEditDish
 * Description: Displays the menu for editing an existing dish in the menu.
 * Input:
 *   None
 * Output:
 *   None
 */
void Manager::menuEditDish()
{
	displayDishList();
	if (dishList.empty())
	{
		displayMenuManager();
	}
	else
	{
		cout << "Enter ID of dish to edit: ";
		int id;
		cin >> id;
		if (id < dishList.front().getIdDish() || id > dishList.back().getIdDish())
		{
			cout << "ID does not exist." << endl;
			displayMenuManager();
		}
		else
		{
			bool found = false;
			int i = -1;
			for (auto &d : dishList)
			{
				i++;
				if (d.getIdDish() == id)
				{
					found = true;
					break;
				}
			}
			if (found)
			{
				cout << "0. Come back" << endl;
				cout << "1. Edit name" << endl;
				cout << "2. Edit price" << endl;
				cout << "_____________________________" << endl;
				editDish1(i);
			}
			else
			{
				cout << "ID does not exist." << endl;
				displayMenuManager();
			}
		}
	}
}

/*
 * Class: Manager
 * Method: editDish1
 * Description: Displays the menu for selecting what to edit about an existing dish.
 * Input:
 *   i - Index of the dish to be edited in the dishList vector.
 * Output:
 *   None
 */
void Manager::editDish1(int i)
{
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	cout << endl;
	if (choice == 1)
	{
		dishList[i].setNameDish();
		cout << "Successfully edited name." << endl;
		cout << endl;
	}
	else if (choice == 2)
	{
		dishList[i].setPriceDish();
		cout << "Successfully edited price." << endl;
		cout << endl;
	}
	else if (choice == 0)
	{
		displayMenuManager();
		return;
	}
	else
	{
		cout << "Invalid choice. Please try again." << endl;
		editDish1(i);
		return;
	}
	dishTitle();
	dishInformation(dishList[i]);
	cout << "_____________________________" << endl;
	cout << "0. Come back" << endl;
	cout << "1. Countinue edit" << endl;
	cout << "_____________________________" << endl;
	editDish2();
}

/*
 * Class: Manager
 * Method: editDish2
 * Description: Handles the continuation of editing a dish or returning to the previous menu.
 * Input:
 *   None
 * Output:
 *   None
 */
void Manager::editDish2()
{
	int key = getUserChoice(0, 1);
	switch (key)
	{
	case 0:
		displayMenuManager();
		break;
	case 1:
		menuEditDish();
		break;
	}
}

/*
 * Class: Manager
 * Method: menuRemoveDish
 * Description: Displays the menu for removing an existing dish from the menu.
 * Input:
 *   None
 * Output:
 *   None
 */
void Manager::menuRemoveDish()
{
	displayDishList();
	if (dishList.empty())
	{
		displayMenuManager();
	}
	else
	{
		cout << "Enter ID of dish to delete: ";
		int id;
		cin >> id;
		if (id < dishList.front().getIdDish() || id > dishList.back().getIdDish())
		{
			cout << "ID does not exist." << endl;
			displayMenuManager();
			return;
		}
		else
		{
			bool found = false;
			int i = -1;
			for (auto &d : dishList)
			{
				i++;
				if (d.getIdDish() == id)
				{
					found = true;
					break;
				}
			}
			if (found)
			{
				cout << "___________Manager___________" << endl;
				cout << "Are you sure you want to delete." << endl;
				cout << "0. Come back" << endl;
				cout << "1. Delete" << endl;
				cout << "_____________________________" << endl;
				removeDish1(i);
				return;
			}
			else
			{
				cout << "ID does not exist." << endl;
				displayMenuManager();
				return;
			}
		}
	}
}

/*
 * Class: Manager
 * Method: removeDish1
 * Description: Handles the removal of an existing dish from the menu.
 * Input:
 *   i - Index of the dish to be removed in the dishList vector.
 * Output:
 *   None
 */
void Manager::removeDish1(int i)
{
	int choice;
	cout << "Enter your choice: ";
	cin >> choice;
	cout << endl;
	if (choice == 1)
	{
		Dish dish;
		dish = dishList[i];
		dishList.erase(dishList.begin() + i);
		cout << "Successfully deleted." << endl;
		cout << endl;
		dishTitle();
		dishInformation(dish);
	}
	else if (choice == 0)
	{
		displayMenuManager();
	}
	else
	{
		cout << "Invalid choice. Please try again." << endl;
		removeDish1(i);
	}
	cout << "_____________________________" << endl;
	cout << "0. Come back" << endl;
	cout << "1. Countinue remove" << endl;
	cout << "_____________________________" << endl;
	removeDish2();
}

/*
 * Class: Manager
 * Method: removeDish2
 * Description: Handles the continuation of removing a dish from the menu or returning to the previous menu.
 * Input:
 *   None.
 * Output:
 *   None
 */
void Manager::removeDish2()
{
	int key = getUserChoice(0, 1);
	switch (key)
	{
	case 0:
		displayMenuManager();
		break;
	case 1:
		menuRemoveDish();
		break;
	}
}

/*
 * Class: Table
 * Method: setStatus
 * Description: Sets the status of the table (occupied or vacant).
 * Input:
 *   status - A boolean value representing the table status (true for occupied, false for vacant).
 * Output:
 *   None.
 */
void Table::setStatus(bool status)
{
	this->status = status;
}

/*
 * Class: Table
 * Method: getStatus
 * Description: Retrieves the status of the table (occupied or vacant).
 * Input:
 *   None.
 * Output:
 *   Returns a boolean value representing the table status (true for occupied, false for vacant).
 */
bool Table::getStatus()
{
	return this->status;
}

/*
 * Class: Table
 * Method: setTotalMoney
 * Description: Sets the total bill amount for the table.
 * Input:
 *   totalMoney - An integer representing the total bill amount.
 * Output:
 *   None.
 */
void Table::setTotalMoney(int totalMoney)
{
	this->totalMoney = totalMoney;
}

/*
 * Class: Table
 * Method: getTotalMoney
 * Description: Retrieves the total bill amount for the table.
 * Input:
 *   None.
 * Output:
 *   Returns an integer representing the total bill amount.
 */
int Table::getTotalMoney()
{
	return this->totalMoney;
}

/*
 * Class: Staff
 * Method: setDishListOnTable
 * Description: Adds a dish to the list of dishes on a specific table.
 * Input:
 *   dish - The Dish object to be added.
 *   table - The table number where the dish is added.
 * Output:
 *   None.
 */
void Staff::setDishListOnTable(Dish dish, int table)
{
	tableList[table - 1].dishListOnTable.push_back(dish);
}

/*
 * Class: Staff
 * Method: setDishList
 * Description: Sets the list of available dishes in the staff's menu.
 * Input:
 *   dishList - A vector containing Dish objects representing the menu items.
 * Output:
 *   None.
 */
void Staff::setDishList(vector<Dish> dishList)
{
	this->dishList = dishList;
}

/*
 * Class: Staff
 * Method: setNumberOfTable
 * Description: Sets the number of tables available in the restaurant.
 * Input:
 *   numberOfTable - An integer representing the total number of tables.
 * Output:
 *   None.
 */
void Staff::setNumberOfTable(int numberOfTable)
{
	this->numberOfTable = numberOfTable;
}

/*
 * Class: Staff
 * Method: getNumberOfTable
 * Description: Retrieves the number of tables available in the restaurant.
 * Input:
 *   None.
 * Output:
 *   Returns an integer representing the total number of tables.
 */
int Staff::getNumberOfTable()
{
	return this->numberOfTable;
}

/*
 * Class: Staff
 * Method: setSizeTableList
 * Description: Resizes the list of tables to match the total number of tables.
 * Input:
 *   numberOfTable - An integer representing the total number of tables.
 * Output:
 *   None.
 */
void Staff::setSizeTableList(int numberOfTable)
{
	this->tableList.resize(numberOfTable);
}

/*
 * Class: Staff
 * Method: displayDishList
 * Description: Displays the list of available dishes in the menu.
 * Input:
 *   table - The table number for which the menu is displayed.
 * Output:
 *   None.
 */
void Staff::displayDishList(int table)
{
	cout << "___________Table " << table << " _____________" << endl;
	if (!dishList.empty())
	{
		cout << "____________Menu____________" << endl;
		cout << " NO | ID  |   Name   |   Price   " << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < (int)dishList.size(); i++)
		{
			printf(" %-3d| %-4d| %-9s| %-10d\n", i + 1,
				   dishList[i].getIdDish(), dishList[i].getNameDish().c_str(), dishList[i].getPriceDish());
		}
		cout << endl;
	}
	else
	{
		cout << "There are no dishes on the menu." << endl;
		cout << endl;
	}
}

/*
 * Class: Staff
 * Method: displayADish
 * Description: Displays the details of a specific dish on a table.
 * Input:
 *   table - The table number where the dish is served.
 *   i - The index of the dish in the table's dish list.
 * Output:
 *   None
 */
void Staff::displayADish(int table, int i)
{
	cout << "___________Table " << table << " _____________" << endl;
	cout << " ID  |   Name   |   Price   | Amount " << endl;
	cout << "------------------------------" << endl;

	printf(" %-4d| %-9s| %-10d | %-7d\n",
		   tableList[table - 1].dishListOnTable[i].getIdDish(), tableList[table - 1].dishListOnTable[i].getNameDish().c_str(),
		   tableList[table - 1].dishListOnTable[i].getPriceDish(), tableList[table - 1].dishListOnTable[i].getNumberOfDish());
	cout << "______________________________" << endl;
}

/*
 * Class: Staff
 * Method: displayDishListOnTable
 * Description: Displays the list of dishes on a specific table.
 * Input:
 *   table - The table number for which the list of dishes is displayed.
 * Output:
 *   None
 */
void Staff::displayDishListOnTable(int table)
{
	cout << "_____________Staff_____________" << endl;
	cout << "_____List of dishes at table " << table << " ______" << endl;
	if (!tableList[table - 1].dishListOnTable.empty())
	{
		cout << " NO | ID  |   Name   |   Price   | Amount" << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < (int)tableList[table - 1].dishListOnTable.size(); i++)
		{
			printf(" %-3d| %-4d| %-9s| %-10d| %-7d\n", i + 1,
				   tableList[table - 1].dishListOnTable[i].getIdDish(),
				   tableList[table - 1].dishListOnTable[i].getNameDish().c_str(),
				   tableList[table - 1].dishListOnTable[i].getPriceDish(),
				   tableList[table - 1].dishListOnTable[i].getNumberOfDish());
		}
		cout << endl;
	}
	else
	{
		cout << "There are no dishes on this table." << endl;
		cout << endl;
		displayMenuTable(table);
	}
}

/*
 * Class: Staff
 * Method: displayMenuStaff
 * Description: Displays the list of tables and their status in the restaurant.
 * Input:
 *   None.
 * Output:
 *   None
 */
void Staff::displayMenuStaff()
{
	cout << "_____________Staff_____________" << endl;
	cout << "___________Table list__________" << endl;
	cout << "Table No ";
	for (int i = 0; i < numberOfTable; i++)
	{
		cout << "| " << i + 1 << " ";
	}
	cout << endl;
	cout << "---------";
	for (int i = 0; i < numberOfTable; i++)
	{
		if (i < 10)
			cout << "----";
		else
			cout << "-----";
	}
	cout << endl;
	cout << "Status   ";
	for (int i = 0; i < numberOfTable; i++)
	{
		string sign;
		if (tableList[i].getStatus() == 1)
			sign = "X";
		else
			sign = "0";
		cout << "| " << sign << " ";
		if (i > 9)
			cout << " ";
	}
	cout << endl;
	cout << "_________";
	for (int i = 0; i < numberOfTable; i++)
	{
		if (i < 10)
			cout << "____";
		else
			cout << "_____";
	}
	cout << endl;
	cout << "0. Come back" << endl;
	cout << "1. Select table" << endl;
	cout << "_____________________________" << endl;
	menuStaff();
}

/*
 * Class: Staff
 * Method: menuStaff
 * Description: Handles the staff's menu options for managing tables.
 * Input:
 *   None.
 * Output:
 *   None
 */
void Staff::menuStaff()
{
	int choice = getUserChoice(0, 1);
	switch (choice)
	{
	case 0:
		break;
	case 1:
		selectTable();
		break;
	}
}

/*
 * Class: Staff
 * Method: selectTable
 * Description: Allows a staff member to select a table to serve.
 * Input:
 *   None
 * Output:
 *   None
 */
void Staff::selectTable()
{
	cout << "Enter table number: ";
	int table;
	cin >> table;
	if (table < 1 || table > numberOfTable)
	{
		cout << "The selected table is invalid." << endl;
		return;
	}
	else
	{
		tableList[table - 1].setStatus(true);
		displayMenuTable(table);
	}
}

/*
 * Class: Staff
 * Method: displayMenuTable
 * Description: Displays the menu for managing a specific table's orders.
 * Input:
 *   table - The number of the selected table.
 * Output:
 *   None
 */
void Staff::displayMenuTable(int table)
{
	cout << "_____________Staff_____________" << endl;
	cout << "___________Table " << table << " _____________" << endl;
	cout << "0. Come back" << endl;
	cout << "1. Add dish" << endl;
	cout << "2. Edit dish" << endl;
	cout << "3. Remove dish" << endl;
	cout << "4. Display dish" << endl;
	cout << "5. Pay bill" << endl;
	cout << "_____________________________" << endl;
	menuTable(table);
}

/*
 * Class: Staff
 * Method: menuTable
 * Description: Displays the menu options for managing a specific table's orders.
 * Input:
 *   table - The number of the selected table.
 * Output:
 *   None
 */
void Staff::menuTable(int table)
{
	int choice = getUserChoice(0, 4);
	switch (choice)
	{
	case 0:
		break;
	case 1:
		menuAddDish(table);
		break;
	case 2:
		menuEditDish(table);
		break;
	case 3:
		menuRemoveDish(table);
		break;
	case 4:
		displayDishListOnTable(table);
		break;
	case 5:
		payBill(table);
		break;
	}
}

/*
 * Class: Staff
 * Method: menuAddDish
 * Description: Displays the menu for adding a dish to a specific table's order.
 * Input:
 *   table - The number of the selected table.
 * Output:
 *   None
 */
void Staff::menuAddDish(int table)
{
	displayDishList(table);
	if (dishList.empty())
	{
		displayMenuTable(table);
		return;
	}
	else
	{
		cout << "Enter ID of dish to add: ";
		int id;
		cin >> id;
		if (id < dishList.front().getIdDish() || id > dishList.back().getIdDish())
		{
			cout << "ID does not exist." << endl;
			cout << endl;
			displayMenuTable(table);
			return;
		}
		else
		{
			bool found = false;
			int i = -1;
			for (auto &d : dishList)
			{
				i++;
				if (d.getIdDish() == id)
				{
					cout << "Enter number of dish: ";
					int number;
					cin >> number;
					cout << endl;
					d.setNumberOfDish(number);
					setDishListOnTable(d, table);
					tableList[table - 1].setStatus(true);
					cout << "Successfully added." << endl;
					found = true;
					break;
				}
			}
			if (found)
			{
				displayADish(table, i);
				cout << "0. Come back" << endl;
				cout << "1. Countinue add" << endl;
				cout << "_____________________________" << endl;
				addDish(table);
				return;
			}
			else
			{
				cout << "ID does not exist." << endl;
				cout << endl;
				displayMenuTable(table);
				return;
			}
		}
	}
}

/*
 * Class: Staff
 * Method: addDish
 * Description: Handles the continuation of adding a dish to a table's order or returning to the previous menu.
 * Input:
 *   table - The number of the selected table.
 * Output:
 *   None
 */
void Staff::addDish(int table)
{
	int choice = getUserChoice(0, 1);
	switch (choice)
	{
	case 0:
		displayMenuTable(table);
		break;
	case 1:
		menuAddDish(table);
		break;
	}
}

/*
 * Class: Staff
 * Method: menuEditDish
 * Description: Displays the menu for editing a dish in a specific table's order.
 * Input:
 *   table - The number of the selected table.
 * Output:
 *   None
 */
void Staff::menuEditDish(int table)
{
	displayDishListOnTable(table);
	if (tableList[table - 1].dishListOnTable.empty())
	{
		displayMenuTable(table);
		return;
	}
	else
	{
		cout << "Enter ID of dish to edit: ";
		int id;
		cin >> id;
		if (id < tableList[table - 1].dishListOnTable.front().getIdDish() || id > tableList[table - 1].dishListOnTable.back().getIdDish())
		{
			cout << "ID does not exist." << endl;
			cout << endl;
			displayMenuTable(table);
			return;
		}
		else
		{
			bool found = false;
			int i = -1;
			for (auto &d : tableList[table - 1].dishListOnTable)
			{
				i++;
				if (d.getIdDish() == id)
				{
					cout << "Enter number of dish: ";
					int number;
					cin >> number;
					d.setNumberOfDish(number);
					setDishListOnTable(d, table);
					cout << "Successfully edited." << endl;
					found = true;
					break;
				}
			}
			if (found)
			{
				displayADish(table, i);
				cout << "0. Come back" << endl;
				cout << "1. Countinue edit" << endl;
				cout << "_____________________________" << endl;
				editDish(table);
				return;
			}
			else
			{
				cout << "ID does not exist." << endl;
				cout << endl;
				displayMenuTable(table);
				return;
			}
		}
	}
}

/*
 * Class: Staff
 * Method: editDish
 * Description: Handles the continuation of editing a dish in a table's order or returning to the previous menu.
 * Input:
 *   table - The number of the selected table.
 * Output:
 *   None
 */
void Staff::editDish(int table)
{
	int choice = getUserChoice(0, 1);
	switch (choice)
	{
	case 0:
		displayMenuTable(table);
		break;
	case 1:
		menuEditDish(table);
		break;
	}
}

/*
 * Class: Staff
 * Method: menuRemoveDish
 * Description: Displays the menu for removing a dish from a specific table's order.
 * Input:
 *   table - The number of the selected table.
 * Output:
 *   None
 */
void Staff::menuRemoveDish(int table)
{
	displayDishListOnTable(table);
	if (tableList[table - 1].dishListOnTable.empty())
	{
		displayMenuTable(table);
		return;
	}
	else
	{
		cout << "Enter ID of dish to remove: ";
		int id;
		cin >> id;
		if (id < tableList[table - 1].dishListOnTable.front().getIdDish() || id > tableList[table - 1].dishListOnTable.back().getIdDish())
		{
			cout << "ID does not exist." << endl;
			cout << endl;
			displayMenuTable(table);
			return;
		}
		else
		{
			bool found = false;
			int i = -1;
			for (auto &d : tableList[table - 1].dishListOnTable)
			{
				i++;
				if (d.getIdDish() == id)
				{
					tableList[table - 1].dishListOnTable.erase(tableList[table - 1].dishListOnTable.begin() + i);
					cout << "Successfully removed." << endl;
					found = true;
					break;
				}
			}
			if (found)
			{
				cout << "___________Manager___________" << endl;
				cout << "Are you sure you want to delete." << endl;
				cout << "0. Come back" << endl;
				cout << "1. Delete" << endl;
				cout << "_____________________________" << endl;
				removeDish1(table, i);
				return;
			}
			else
			{
				cout << "ID does not exist." << endl;
				cout << endl;
				displayMenuTable(table);
				return;
			}
		}
	}
}

/*
 * Class: Staff
 * Method: removeDish1
 * Description: Handles the removal of a dish from a table's order and the continuation or return to the previous menu.
 * Input:
 *   table - The number of the selected table.
 *   i - The index of the dish to be removed in the table's order.
 * Output:
 *   None
 */
void Staff::removeDish1(int table, int i)
{
	while (true)
	{
		cout << "Enter your choice: ";
		int choice;
		cin >> choice;
		cout << endl;
		if (choice == 0)
		{
			displayMenuTable(table);
			break;
		}
		else if (choice == 1)
		{
			tableList[table - 1].dishListOnTable.erase(tableList[table - 1].dishListOnTable.begin() + i);
			cout << "Successfully removed." << endl;
			cout << endl;
			displayADish(table, i);
			cout << "_____________________________" << endl;
			cout << "0. Come back" << endl;
			cout << "1. Countinue edit" << endl;
			cout << "_____________________________" << endl;
			removeDish2(table);
			break;
		}
		else
		{
			cout << "Invalid choice. Please try again." << endl;
			break;
		}
	}
}

/*
 * Class: Staff
 * Method: removeDish2
 * Description: Handles the continuation of removing a dish from a table's order or returning to the previous menu.
 * Input:
 *   table - The number of the selected table.
 * Output:
 *   None
 */
void Staff::removeDish2(int table)
{
	int key = getUserChoice(0, 1);
	switch (key)
	{
	case 0:
		displayMenuTable(table);
		break;
	case 1:
		menuRemoveDish(table);
		break;
	}
}

/*
 * Class: Staff
 * Method: menuPayBill
 * Description: Displays the menu for paying the bill for a specific table.
 * Input:
 *   table - The number of the selected table.
 * Output:
 *   None
 */
void Staff::menuPayBill(int table)
{
	cout << "_____________Staff_____________" << endl;
	cout << "_____Bill payment at table " << table << " ______" << endl;
	if (!tableList[table - 1].dishListOnTable.empty())
	{
		cout << " NO | ID  |   Name   |   Price   | Amount" << endl;
		cout << "------------------------------" << endl;
		int total = 0;
		for (int i = 0; i < (int)tableList[table - 1].dishListOnTable.size(); i++)
		{
			printf(" %-3d| %-4d| %-9s| %-10d| %-7d\n", i + 1,
				   tableList[table - 1].dishListOnTable[i].getIdDish(),
				   tableList[table - 1].dishListOnTable[i].getNameDish().c_str(),
				   tableList[table - 1].dishListOnTable[i].getPriceDish(),
				   tableList[table - 1].dishListOnTable[i].getNumberOfDish());
			total += tableList[table - 1].dishListOnTable[i].getPriceDish() * tableList[table - 1].dishListOnTable[i].getNumberOfDish();
		}
		tableList[table - 1].setTotalMoney(total);
		cout << "Total: " << tableList[table - 1].getTotalMoney() << "VND" << endl;
		cout << "____________________________" << endl;
		cout << "0. Come back" << endl;
		cout << "1. Pay" << endl;
		cout << "_____________________________" << endl;
	}
	else
	{
		cout << "There are no dishes on this table." << endl;
		cout << endl;
		displayMenuTable(table);
	}
}

/*
 * Class: Staff
 * Method: payBill
 * Description: Handles the payment of the bill for a specific table and updates its status.
 * Input:
 *   table - The number of the selected table.
 * Output:
 *   None
 */
void Staff::payBill(int table)
{
	int choice = getUserChoice(0, 1);
	switch (choice)
	{
	case 0:
		displayMenuTable(table);
		break;
	case 1:
		cout << "Successfully paid." << endl;
		tableList[table - 1].setStatus(false);
		displayMenuStaff();
		break;
	}
}
