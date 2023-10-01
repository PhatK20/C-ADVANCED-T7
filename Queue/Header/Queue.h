/*
 * File Name: Queue.h
 * Author: Phat Bui Gia
 * Date: 20/08/2023
 * Description: This header file contains the declaration of struct and functions for a queue.
 */

#ifndef __QUEUE_H
#define __QUEUE_H

#include <stdio.h>

#define SIZE 5

// Define a data structure Queue to represent a queue
typedef struct
{
	int items[SIZE]; // Array to store elements in the queue
	int front;		 // Position of the first element in the queue
	int rear;		 // Position of the last element in the queue
} Queue;

// Function to initialize an empty queue
void initializeQueue(Queue *queue);

// Function to check if the queue is full
int isFull(Queue *queue);

// Function to check if the queue is empty
int isEmpty(Queue *queue);

// Function to enqueue an element at the rear of the queue
void enqueue(Queue *queue, int value);

// Function to dequeue and return the first element from the queue
int dequeue(Queue *queue);

// Function to print all elements in the queue
void printQueue(Queue *queue);

#endif
