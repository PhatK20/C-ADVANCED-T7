/*
* File Name: Linked_List.h
* Author: Giao Pham
* Date: 26/03/2023
* Description: This file is a header file that contains a data type definition and functions definition to use a linked list to store and manage a list of data.  
*/


#ifndef __LINKED_LIST_H
#define __LINKED_LIST_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Using union for node structure declaration to represent an element in a linked list */
typedef struct node {
    int  data;
    struct node *next;  
} node;

/* Function creates a new node and assign value */
node *makeNode(int data);

/* Function adds a node to the end of a linked list */
void pushBack(node **head, int data);

/* Function traverses a linked list and prints the values ​​of the nodes */
void duyet(node *head);

/* Function assigns a new value to the node at index in the linked list */
void assign(node *head, int index, int value);

/* Function removes node at position index in the linked list */
void erase(node **head, int index);

/* Function removes the last node in the linked list */
void pop_back(node **head);

/* Function removes all nodes in in the linked list */
void clear(node **head);

#endif