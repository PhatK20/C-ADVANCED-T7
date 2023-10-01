/*
 * File Name: Bitmask.c
 * Author: Phat Bui Gia
 * Date: 25/08/2023
 * Description: Implementation of functions to manage a shopping cart using bitmasks.
 */

#include "Bitmask.h"

// Define item names
const char *itemNames[] = {
	"SHIRT",
	"PANTS",
	"DRESS",
	"SKIRT",
	"RING",
	"BRACELET",
	"SHOES",
	"HAT"};

// Define corresponding bit masks
const uint8_t itemMasks[] = {
	1 << 0, // 0b00000001  shift 1 bit to the left
	1 << 1, // 0b00000010
	1 << 2, // 0b00000100
	1 << 3, // 0b00001000
	1 << 4, // 0b00010000
	1 << 5, // 0b00100000
	1 << 6, // 0b01000000
	1 << 7	// 0b10000000
};

/*
 * Function: displayItemList
 * Description: Displays the list of available items with their IDs and names.
 * Input: None
 * Output: None
 */
void displayItemList()
{
	printf("**** ITEM LIST ****\n");
	printf("ID\t | NAME\n");
	printf("----\t | ----\n");
	for (int i = 0; i < (int)(sizeof(itemNames) / sizeof(itemNames[0])); ++i)
	{
		printf("%d\t | %s\n", i + 1, itemNames[i]);
	}
	printf("\n");
}

/*
 * Function: AddToCart
 * Description: Adds an item to the shopping cart using a bitmask.
 * Input:
 *   cart - A pointer to the shopping cart (bitmask).
 *   itemMask - The bitmask representing the item to be added.
 * Output: None
 */
void AddToCart(uint8_t *cart, uint8_t itemMask)
{
	*cart |= itemMask;
}

/*
 * Function: RemoveFromCart
 * Description: Removes an item from the shopping cart using a bitmask.
 * Input:
 *   cart - A pointer to the shopping cart (bitmask).
 *   itemMask - The bitmask representing the item to be removed.
 * Output: None
 */
void RemoveFromCart(uint8_t *cart, uint8_t itemMask)
{
	*cart &= ~itemMask;
}

/*
 * Function: CheckCart
 * Description: Checks if a specific item is in the shopping cart and displays the result.
 * Input:
 *   cart - The shopping cart (bitmask).
 *   itemMask - The bitmask representing the item to be checked.
 * Output: None
 */
void CheckCart(uint8_t cart, uint8_t itemMask)
{
	int index = -1;
	for (int i = 0; i < (int)sizeof(itemMasks); ++i)
	{
		if (itemMasks[i] == itemMask)
		{
			index = i;
			break;
		}
	}

	if (index != -1)
	{
		printf("Checking cart:\n");
		printf("| %s%s\n", itemNames[index], (cart & itemMask) ? " is in the cart" : " is not in the cart");
		printf("\n");
	}
	else
	{
		printf("Invalid item mask\n");
	}
}

/*
 * Function: DisplayCart
 * Description: Displays the contents of the shopping cart (items that are currently in the cart).
 * Input:
 *   cart - The shopping cart (bitmask).
 * Output: None
 */
void DisplayCart(uint8_t cart)
{
	printf("Cart contains:\n");
	printf("ID\t | NAME\n");
	printf("----\t | ----\n");
	for (int i = 0; i < (int)sizeof(itemMasks); ++i)
	{
		if (cart & itemMasks[i])
		{
			printf("%d\t | %s\n", i + 1, itemNames[i]);
		}
	}
	printf("\n");
}