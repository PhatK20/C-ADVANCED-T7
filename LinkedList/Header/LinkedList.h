/*
* File: LinkedList.h
* Author: Phat Bui Gia
* Date: 20/08/2023
* Description: This header file includes the declaration of functions and structs in the Linked List.
*/

#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
typedef struct Node_t
{
	int data;
	struct Node_t *next;
} Node;

// Function to create a new node with the given data
Node *createNode(int data);

// Function to insert a new element at the beginning of the linked list
void prepend(Node **head_ref, int new_data);

// Function to append a new node at the end of the linked list
void append(Node **head_ref, int new_data);

// Function to delete a node at the specified position
void deleteNode(Node **head_ref, int position);

// Function to change the value of a node at the specified position
void changeValue(Node **head, int position, int new_value);

// Function to insert a new node at the specified position
void insertNode(Node **head_ref, int position, int new_data);

// Function to print the linked list
void printList(Node *node);

// Function to free the memory used by the linked list
void freeList(Node **headref);

#endif