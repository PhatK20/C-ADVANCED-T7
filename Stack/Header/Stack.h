/*
 * File: Stack.h
 * Author: Phat Bui Gia
 * Date: 03/09/2023
 * Description: This header file includes the declaration of functions and structs in the Stack.
 */

#ifndef __STACK_H
#define __STACK_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack_t
{
	int top;
	unsigned capacity;
	int *array;
} Stack;

// Function to create a stack of given capacity.
Stack *createStack(unsigned capacity);

// Checks if the stack is full.
int isFull(Stack *stack);

// Checks if the stack is empty.
int isEmpty(Stack *stack);

// Pushes an item onto the stack.
void push(Stack *stack, int item);

// Pops (removes and returns) an item from the stack.
int pop(Stack *stack);

// Peeks (returns) the top item of the stack without removing it.
int peek(Stack *stack);

// Cleans up and deallocates memory associated with the stack.
void clean(Stack **stack);

#endif