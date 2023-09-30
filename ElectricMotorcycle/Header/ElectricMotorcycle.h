/*
 * File Name: ElectricMotorcycle.h
 * Author: Phat Bui Gia
 * Date: 30/09/2023
 * Description: This header file contains the declaration of classes, enum and functions
 * for a electric motorcycle.
 */

#ifndef __ELECTRIC_MOTORCYCLE_H
#define __ELECTRIC_MOTORCYCLE_H

#include <iostream>
#include <conio.h> // To use _kbhit and _getch
#include <thread>
#include <chrono>
#include <string>
#include <random>
#include <iomanip> // Set the space width
#include <mutex>

using namespace std;

// Generates a random number between 'min' and 'max'.
int getRandomNumber(int min, int max);

class Battery
{
private:
	int batteryTemperature;
	int currentBatteryCapacity;
	int maxBatteryCapacity;
	int minBatteryCapacity;
	int batteryLevel;
	bool fanMode;
	thread decreaseBatteryThread;
	thread randomTemperatureThread;

public:
	// Battery class constructor.
	Battery();

	// Battery class destructor.
	~Battery();

	// Sets the battery level based on specified minimum, maximum, and current values.
	void setBatteryLevel(int min, int max, int current);

	// Gets the current battery level.
	int getBatteryLevel();

	// Starts the battery capacity decrease thread.
	void startDecreaseBattery();

	// Starts the battery capacity decrease thread.
	void stopDecreaseBattery();

	// Gets the battery temperature.
	int getBatteryTemperature();

	// Starts the random temperature change thread.
	void startRandomTemperature();

	// Stops the random temperature change thread.
	void stopRandomTemperature();

	// Gets the current battery capacity.
	int getCurrentBatteryCapacity();

	// Sets the fan mode based on battery temperature.
	void setFanMode(int batteryTemperature);

	// Gets the fan mode status.
	bool getFanMode();
};

// Enumerated type for turn signals.
enum TurnSignal
{
	OFF,
	LEFT,
	RIGHT
};

class MainMenu
{
private:
	TurnSignal signal;
	bool startUp;
	int speed;

public:
	Battery battery;

	// Enumerated type for turn signals.
	MainMenu();

	// Activates the left turn signal.
	void leftTurn();

	// Activates the right turn signal.
	void rightTurn();

	// Activates the off turn signal.
	void offTurn();

	// Displays the current turn signal.
	void turnSignal();

	// Sets the turn signal to the specified value.
	void setSignal(TurnSignal signal);

	// Gets the current turn signal.
	TurnSignal getSignal();

	// Sets the startup status.
	void setStartUp(bool startUp);

	// Gets the startup status.
	bool getStartUp();

	// Sets the speed of the vehicle.
	void setSpeed(int speed);

	// Gets the current speed of the vehicle.
	int getSpeed();

	// Displays the main menu.
	void startMenu();

	// Displays the main menu and handles user input.
	void displayMenu();

	// Executes menu actions based on user input.
	void executeMenu(char key);
};

// Monitors user input for program exit and key presses.
void getInput(bool &exitProgram, char &key);

// Displays program data, updates the menu, and handles program exit.
void displayData(bool &exitProgram, char &key, MainMenu &menu);

#endif