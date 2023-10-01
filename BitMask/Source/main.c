/*
 * File Name: main.c
 * Author: Phat Bui Gia
 * Date: 25/08/2023
 * Description: This program demonstrates the use of bitmasks to manage a shopping cart.
 * It displays a list of available items, adds items to the cart, checks their presence,
 * and displays the cart contents before and after removal.
 */

#include "Bitmask.h"

extern const char *itemNames[];
extern const uint8_t itemMasks[];

int main()
{
	uint8_t cart = 0;

	// Display list of items
	displayItemList();

	// Add items to the cart
	AddToCart(&cart, itemMasks[0] | itemMasks[1] | itemMasks[6] | itemMasks[4] | itemMasks[7]);

	// Check the presence of an item in the cart
	CheckCart(cart, itemMasks[6]);
	CheckCart(cart, itemMasks[3]);
	// Display cart
	DisplayCart(cart);

	// Remove items from the cart
	RemoveFromCart(&cart, itemMasks[1] | itemMasks[6]);

	// Check the presence of an item in the cart after removal
	CheckCart(cart, itemMasks[6]);

	// Display cart after removal
	DisplayCart(cart);

	return 0;
}