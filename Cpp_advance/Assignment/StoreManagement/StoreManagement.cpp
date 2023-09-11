
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
	static int idCounterDish;

public:
	void setIdDish();
	void setNameDish();
	void setPriceDish();
	int getIdDish();
	string getNameDish();
	int getPriceDish();
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

class Manager
{
private:
	vector<Dish> dishList;
	int table;

public:
	void setTable();
	int getTable();

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
	cout << "Enter number of table: ";
	cin >> this->table;
}

int Manager::getTable()
{
	return this->table;
}

vector<Dish> Manager::getDishList()
{
	return this->dishList;
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
	dishList.push_back(dish);
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
	vector<Dish> dishListOnTable;
	int tableNo;
	bool status;

public:
	void setDishListOnTable();
	vector<Dish> getDishListOnTable();

	void setTableNo();
	int getTableNo();

	void setStatus();
	bool getStatus();
};

void Table::setDishListOnTable()
{
	
}

vector<Dish> Table::getDishListOnTable()
{
	
}

void Table::setTableNo()
{
	
}

int Table::getTableNo()
{
	
}
class Staff
{
private:
	vector<Table> tableList;
	vector<Dish> dishList;

public:
	void setDishList();
	vector<Dish> getDishList();

	void displayMenuStaff();
	void menuStaff();
};

void Staff::setDishList()
{
	
}

vector<Dish> Staff::getDishList()
{
	
}

void Staff::displayMenuStaff()
{
	
}

void Staff::menuStaff()
{
	
}

void Staff::displayMenuStaff()
{
	cout << "___________Staff___________" << endl;
	cout << "0. Come back" << endl;
	cout << "1. Countinue" << endl;
	cout << "_____________________________" << endl;
	menuStaff();
}

int main()
{
	Manager manager;
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
			break;
		default:
			break;
		}
	}
}
