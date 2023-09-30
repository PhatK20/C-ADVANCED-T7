/*
 * File Name: ElectricMotorcycle.h
 * Author: Phat Bui Gia
 * Date: 30/09/2023
 * Description: This program simulates an electric motorcycle's dashboard display and user interaction.
 *              It provides a menu for the user to control various aspects of the motorcycle. Here's how
 *              you can interact with the program:
 *
 *              1. Press '1' to start the motorcycle.
 *              2. Press '0' to turn off the motorcycle.
 *              3. Press 'K' to activate the left turn signal (equivalent to an left arrow).
 *              4. Press 'M' to activate the right turn signal (equivalent to an right arrow).
 *              5. Press 'o' to turn off the turn signals.
 *              6. Press 'H' to increase the motorcycle's speed (equivalent to an up arrow).
 *              7. Press 'P' to decrease the motorcycle's speed (equivalent to an down arrow).
 *
 *              The program uses threads to handle user input and continuously update and display motorcycle
 *              data on the screen.
 */
#include "ElectricMotorcycle.h"

int main()
{

	MainMenu menu;
	char key = ' ';
	bool exitProgram = false;

	// Create two threads to handle user input and display data
	thread inputThread(&getInput, ref(exitProgram), ref(key));
	thread displayDataThread(&displayData, ref(exitProgram), ref(key), ref(menu));

	// Wait for the threads to finish
	inputThread.join();
	displayDataThread.join();

	return 0;
}