/*
 * File: main.c
 * Author: Phat Bui Gia
 * Date: 03/09/2023
 * Description: A simple program to demonstrate the usage of a stack data structure.
 */

#include "Stack.h"

int main()
{
	Stack *stack = NULL;
	stack = createStack(100);
	push(stack, 10);
	push(stack, 20);
	push(stack, 30);

	printf("%d popped from stack\n", pop(stack));
	printf("%d popped from stack\n", pop(stack));
	printf("%d popped from stack\n", pop(stack));
	printf("%d popped from stack\n", pop(stack));
	printf("%d peeked from stack\n", peek(stack));

	// Free the allocated memory for the stack and array
	clean(&stack);
	return 0;
}