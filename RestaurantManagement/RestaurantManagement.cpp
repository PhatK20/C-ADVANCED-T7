/*
 * File Name: RestaurantManagement.cpp
 * Author: Phat Bui Gia
 * Date: 13/09/2023
 * Description: This C++ program manages a restaurant with menu and table orders.
 * It uses classes for dishes, managers, staff, and tables, offering various
 * operations like adding, editing, removing dishes, and handling orders and bills.
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void displayMainMenu()
{
	cout << "__________HOME___________" << endl;
	cout << "0. Exit" << endl;
	cout << "1. Manager" << endl;
	cout << "2. Staff" << endl;
	cout << "_________________________" << endl;
	cout << "Enter your choice: ";
}

class Dish
{
private:
	int idDish;
	string nameDish;
	int priceDish;
	int numberOfDish;
	static int idCounterDish;

public:
	Dish() : numberOfDish(0){};
	void setIdDish();
	void setNameDish();
	void setPriceDish();
	int getIdDish();
	string getNameDish();
	int getPriceDish();
	void setNumberOfDish(int num);
	int getNumberOfDish();
};

int Dish::idCounterDish = 100;

void Dish::setIdDish()
{
	this->idDish = ++idCounterDish;
}

void Dish::setNameDish()
{
	cin.ignore(); // xóa dấu xuống dòng khỏi bộ đệm
	string nameDish;
	cout << "Enter name: ";
	getline(cin, nameDish);
	this->nameDish = nameDish;
}

void Dish::setPriceDish()
{
	int priceDish;
	cout << "Enter price: ";
	cin >> priceDish;
	this->priceDish = priceDish;
}

int Dish::getIdDish()
{
	return this->idDish;
}

string Dish::getNameDish()
{
	return this->nameDish;
}

int Dish::getPriceDish()
{
	return this->priceDish;
}

void Dish::setNumberOfDish(int num)
{
	this->numberOfDish = num;
}

int Dish::getNumberOfDish()
{
	return this->numberOfDish;
}

class Manager
{
private:
	vector<Dish> dishList;
	int table;

public:
	void setTable();
	int getTable();
	void setDishList(Dish dish);
	vector<Dish> getDishList();

	void displayMenuManager();
	void menuManager();

	void menuNumerOfTable();
	void numberOfTable();

	void menuAddDish();
	void addDish();

	void menuEditDish();
	void editDish1(int id);
	void editDish2();

	void menuRemoveDish();
	void removeDish1(int id);
	void removeDish2();

	void displayDishList();
};

void dishTitle()
{
	cout << "_______Food Information_______" << endl;
	cout << " ID  |   Name   |   Price   " << endl;
	cout << "------------------------------" << endl;
}
void dishInformation(Dish dish)
{
	printf(" %-4d| %-9s| %-10d\n", dish.getIdDish(), dish.getNameDish().c_str(), dish.getPriceDish());
}

void Manager::displayDishList()
{
	cout << "___________Manager___________" << endl;
	if (!dishList.empty())
	{
		cout << "____________Menu____________" << endl;
		cout << " NO | ID  |   Name   |   Price   " << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < dishList.size(); i++)
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

void Manager::setTable()
{
	cout << "Enter number of tables: ";
	cin >> this->table;
}

int Manager::getTable()
{
	return this->table;
}

void Manager::setDishList(Dish dish)
{
	this->dishList.push_back(dish);
}
vector<Dish> Manager::getDishList()
{
	return dishList;
}

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

void Manager::menuManager()
{
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 0:
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
	default:
		cout << "Invalid choice. Please try again." << endl;
		menuManager();
		break;
	}
}
void Manager::menuNumerOfTable()
{
	cout << "___________Manager___________" << endl;
	cout << "0. Come back" << endl;
	cout << "1. Set number of table" << endl;
	cout << "_____________________________" << endl;
	numberOfTable();
}

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

void Manager::editDish2()
{
	int key;
	cout << "Enter your choice: ";
	cin >> key;
	switch (key)
	{
	case 0:
		displayMenuManager();
		break;
	case 1:
		menuEditDish();
		break;
	default:
		cout << "Invalid choice. Please try again." << endl;
		editDish2();
		break;
	}
}
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

void Manager::removeDish2()
{
	int key;
	cout << "Enter your choice: ";
	cin >> key;
	switch (key)
	{
	case 0:
		displayMenuManager();
		break;
	case 1:
		menuRemoveDish();
		break;
	default:
		cout << "Invalid choice. Please try again." << endl;
		removeDish2();
		break;
	}
}

class Table
{
private:
	bool status;
	int totalMoney;
public:
	vector<Dish> dishListOnTable;
	Table() : status(false), totalMoney(0) {}

	void setStatus(bool status);
	bool getStatus();

	void setTotalMoney(int totalMoney);
	int getTotalMoney();
};


void Table::setStatus(bool status)
{
	this->status = status;
}

bool Table::getStatus()
{
	return this->status;
}

void Table::setTotalMoney(int totalMoney)
{
	this->totalMoney = totalMoney;
}

int Table::getTotalMoney()
{
	return this->totalMoney;
}
class Staff
{
private:
	vector<Dish> dishList;
	int numberOfTable;
	vector<Table> tableList;

public:
	void setDishListOnTable(Dish dish, int table);

	void setDishList(vector<Dish> dishList);

	void setNumberOfTable(int numberOfTable);
	int getNumberOfTable();

	void setSizeTableList(int numberOfTable);
	void selectTable();

	void displayMenuStaff();
	void menuStaff();

	void displayMenuTable(int table);
	void menuTable(int table);

	void menuAddDish(int table);
	void addDish(int table);

	void menuEditDish(int table);
	void editDish(int table);

	void menuRemoveDish(int table);
	void removeDish1(int table, int id);
	void removeDish2(int table);

	void menuPayBill(int table);
	void payBill(int table);

	void displayDishList(int table);
	void displayADish(int table, int i);
	void displayDishListOnTable(int table);
};

void Staff::setDishListOnTable(Dish dish, int table)
{
	tableList[table - 1].dishListOnTable.push_back(dish);
}

void Staff::setDishList(vector<Dish> dishList)
{
	this->dishList = dishList;
}

void Staff::setNumberOfTable(int numberOfTable)
{
	this->numberOfTable = numberOfTable;
}

int Staff::getNumberOfTable()
{
	return this->numberOfTable;
}

void Staff::setSizeTableList(int numberOfTable)
{
	this->tableList.resize(numberOfTable);
}
void Staff::displayDishList(int table)
{
	cout << "___________Table " << table << " _____________" << endl;
	if (!dishList.empty())
	{
		cout << "____________Menu____________" << endl;
		cout << " NO | ID  |   Name   |   Price   " << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < dishList.size(); i++)
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

void Staff::displayDishListOnTable(int table)
{
	cout << "_____________Staff_____________" << endl;
	cout << "_____List of dishes at table " << table << " ______" << endl;
	if (!tableList[table - 1].dishListOnTable.empty())
	{
		cout << " NO | ID  |   Name   |   Price   | Amount" << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < tableList[table - 1].dishListOnTable.size(); i++)
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

void Staff::menuStaff()
{
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 0:
		break;
	case 1:
		selectTable();
		break;
	default:
		cout << "Invalid choice. Please try again." << endl;
		menuStaff();
		break;
	}
}

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

void Staff::menuTable(int table)
{
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	cout << endl;
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
	// case 5:
	// 	payBill();
	// 	break;
	default:
		cout << "Invalid choice. Please try again." << endl;
		menuTable(table);
		break;
	}
}

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

void Staff::addDish(int table)
{
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 0:
		displayMenuTable(table);
		break;
	case 1:
		menuAddDish(table);
		break;
	default:
		cout << "Invalid choice. Please try again." << endl;
		addDish(table);
		break;
	}
}

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

void Staff::editDish(int table)
{
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	cout << endl;
	switch (choice)
	{
	case 0:
		displayMenuTable(table);
		break;
	case 1:
		menuEditDish(table);
		break;
	default:
		cout << "Invalid choice. Please try again." << endl;
		editDish(table);
		break;
	}
}

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

void Staff::removeDish2(int table)
{
	int key;
	cout << "Enter your choice: ";
	cin >> key;
	cout << endl;
	switch (key)
	{
	case 0:
		displayMenuTable(table);
		break;
	case 1:
		menuRemoveDish(table);
		break;
	default:
		cout << "Invalid choice. Please try again." << endl;
		removeDish2(table);
		break;
	}
}

void Staff::menuPayBill(int table)
{
	cout << "_____________Staff_____________" << endl;
	cout << "_____Bill payment at table " << table << " ______" << endl;
	if (!tableList[table - 1].dishListOnTable.empty())
	{
		cout << " NO | ID  |   Name   |   Price   | Amount" << endl;
		cout << "------------------------------" << endl;
		int total = 0;
		for (int i = 0; i < tableList[table - 1].dishListOnTable.size(); i++)
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

void Staff::payBill(int table)
{
	cout << "Enter your choice: ";
	int choice;
	cin >> choice;
	cout << endl;
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
	default:
		cout << "Invalid choice. Please try again." << endl;
		payBill(table);
		break;
	}
}

int main()
{
	Manager manager;
	Staff staff;
	while (1)
	{
		displayMainMenu();
		int key;
		cin >> key;
		cout << endl;
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
		default:
			break;
		}
	}
}
