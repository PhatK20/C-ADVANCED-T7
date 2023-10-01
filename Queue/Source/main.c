/*
 * File Name: main.c
 * Author: Phat Bui Gia
 * Date: 20/08/2023
 * Description: This program implements basic queue operations
 * for a linear data structure using the First-In-First-Out (FIFO) principle.
 * It provides functions to initialize a queue, check if it's full or empty,
 * enqueue and dequeue elements, and print the queue's contents.
 */

#include "Queue.h"

int main()
{
	Queue myQueue;
	initializeQueue(&myQueue);

	enqueue(&myQueue, 10);
	enqueue(&myQueue, 20);
	enqueue(&myQueue, 30);

	printQueue(&myQueue);

	dequeue(&myQueue);
	dequeue(&myQueue);

	enqueue(&myQueue, 40);

	printQueue(&myQueue);

	return 0;
}