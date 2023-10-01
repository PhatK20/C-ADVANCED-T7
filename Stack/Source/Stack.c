/*
 * File: Stack.c
 * Author: Phat Bui Gia
 * Date: 03/09/2023
 * Description: This file defines the functions for a stack data structure in C. These functions provide the
 * necessary operations to work with the stack, such as creating, pushing, popping, and cleaning.
 */

#include "Stack.h"

/*
 * Function: createStack
 * Description: Creates a new stack with the specified capacity.
 * Input:
 *   capacity - The maximum number of elements the stack can hold.
 * Output:
 *   Returns a pointer to the newly created stack.
 */
Stack *createStack(unsigned capacity)
{
	Stack *stack = (Stack *)malloc(sizeof(Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int *)malloc(stack->capacity * sizeof(int));
	return stack;
}

/*
 * Function: isFull
 * Description: Checks if the stack is full.
 * Input:
 *   stack - A pointer to the stack.
 * Output:
 *   Returns 1 if the stack is full, 0 otherwise.
 */
int isFull(Stack *stack)
{
	return stack->top == (int)stack->capacity - 1;
}

/*
 * Function: isEmpty
 * Description: Checks if the stack is empty.
 * Input:
 *   stack - A pointer to the stack.
 * Output:
 *   Returns 1 if the stack is empty, 0 otherwise.
 */
int isEmpty(Stack *stack)
{
	return stack->top == -1;
}

/*
 * Function: push
 * Description: Pushes an item onto the stack.
 * Input:
 *   stack - A pointer to the stack.
 *   item - The item to be pushed onto the stack.
 * Output:
 *   None
 */
void push(Stack *stack, int item)
{
	if (isFull(stack))
		return;
	stack->array[++stack->top] = item;
	printf("%d pushed to stack\n", item);
}

/*
 * Function: pop
 * Description: Pops (removes and returns) an item from the stack.
 * Input:
 *   stack - A pointer to the stack.
 * Output:
 *   Returns the popped item, or INT_MIN if the stack is empty.
 */
int pop(Stack *stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}

/*
 * Function: peek
 * Description: Peeks (returns) the top item of the stack without removing it.
 * Input:
 *   stack - A pointer to the stack.
 * Output:
 *   Returns the top item, or INT_MIN if the stack is empty.
 */
int peek(Stack *stack)
{
	if (isEmpty(stack))
		return INT_MIN;
	return stack->array[stack->top];
}

/*
 * Function: clean
 * Description: Cleans up and deallocates memory associated with the stack.
 * Input:
 *   stack - A pointer to a pointer to the stack.
 * Output:
 *   None
 */
void clean(Stack **stack)
{
	free((*stack)->array);
	free(*stack);
	*stack = NULL;
}
