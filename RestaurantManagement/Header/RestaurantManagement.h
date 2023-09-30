/*
 * File Name: RestaurantManagement.h
 * Author: Phat Bui Gia
 * Date: 15/09/2023
 * Description: This header file contains the declaration of classes and functions
 * for a restaurant management system.
 */

#ifndef __RESTAURANT_MANAGEMENT_H
#define __RESTAURANT_MANAGEMENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Display the main menu
void displayMainMenu();

// Get user choice within the specified range
int getUserChoice(int numBegin, int numEnd);

// Class to manage information about a dish
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

// Display the title for dish information
void dishTitle();

// Display the title for dish information
void dishInformation(Dish dish);

// Class to manage restaurant operations
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

// Class to manage information about a table
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

// Class to manage staff operations
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

#endif