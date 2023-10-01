/*
 * File Name: Bitmask.h
 * Author: Phat Bui Gia
 * Date: 25/08/2023
 * Description: This header file contains functions for managing a shopping cart using bit masks.
 */

#ifndef __BIT_MASK_H
#define __BIT_MASK_H

#include <stdio.h>
#include <stdint.h>
#include <string.h>

extern const char *itemNames[];
extern const uint8_t itemMasks[];

// Display the list of items
void displayItemList();

// Add an item to the cart
void AddToCart(uint8_t *cart, uint8_t itemMask);

// Remove an item from the cart
void RemoveFromCart(uint8_t *cart, uint8_t itemMask);

// Check if an item is in the cart
void CheckCart(uint8_t cart, uint8_t itemMask);

// Display the list of items in the cart
void DisplayCart(uint8_t cart);

#endif