/*
 * File: LinkedList.c
 * Author: Phat Bui Gia
 * Date: 27/08/2023
 * Description: This file includes the definition of all functions in linked lists.
 */

#include "LinkedList.h"

/*
 * Function: createNode
 * Description: Creates a new node with the given data.
 * Input:
 *   data - an integer representing the data to be stored in the new node
 * Output:
 *   Returns a pointer to the newly created node or NULL if memory allocation fails.
 */
Node *createNode(int data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	if (newNode != NULL)
	{
		newNode->data = data;
		newNode->next = NULL;
	}
	return newNode;
}

/*
 * Function: prepend
 * Description: Adds a new node with the specified data to the beginning of the linked list.
 * Input:
 *   head_ref - a pointer to the pointer to the head of the linked list
 *   new_data - an integer representing the data to be added
 * Output:
 *   None
 */
void prepend(Node **head_ref, int new_data)
{
	Node *new_node = createNode(new_data);
	if (new_node != NULL)
	{
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
}

/*
 * Function: append
 * Description: Adds a new node with the specified data to the end of the linked list.
 * Input:
 *   head_ref - a pointer to the pointer to the head of the linked list
 *   new_data - an integer representing the data to be added
 * Output:
 *   None
 */
void append(Node **head_ref, int new_data)
{
	// Create a new node with the given data
	Node *new_node = createNode(new_data);
	if (new_node != NULL)
	{
		// If the memory allocation was successful
		if (*head_ref == NULL)
		{
			// If the list is empty, make the new node the head
			*head_ref = new_node;
		}
		else
		{
			// Find the last node and add the new node after it
			Node *last = *head_ref;
			while (last->next != NULL)
			{
				last = last->next;
			}
			last->next = new_node;
		}
	}
}

/*
 * Function: deleteNode
 * Description: Deletes the node at the specified position in the linked list.
 *              If the list is empty or the specified position is invalid, it displays an error message.
 * Input:
 *   head_ref - a pointer to the pointer to the head of the linked list
 *   position - an integer representing the position of the node to be deleted
 * Output:
 *   None
 */
void deleteNode(Node **head_ref, int position)
{
	// Check if the list is empty
	if (*head_ref == NULL)
	{
		printf("List is empty, cannot delete node.\n");
		return;
	}

	// Check if the specified position is valid
	if (position == 0)
	{
		// Delete the node at the beginning of the list
		Node *temp = *head_ref;
		*head_ref = (*head_ref)->next;
		free(temp);
	}
	else
	{
		// Traverse the list to find the node at the specified position
		Node *current = *head_ref;
		int current_position = 0;
		Node *prev = NULL;

		while (current != NULL && current_position < position)
		{
			prev = current;
			current = current->next;
			current_position++;
		}

		// Check if the specified position is valid
		if (current == NULL)
		{
			printf("Invalid position, cannot delete node.\n");
			return;
		}

		// Delete the node at the specified position
		prev->next = current->next;
		free(current);
	}
}

/*
 * Function: changeValue
 * Description: Changes the value of the node at the specified position in the linked list.
 * Input:
 *   head - a pointer to the pointer to the head of the linked list
 *   position - an integer representing the position of the node to be changed
 *   new_value - an integer representing the new value to be set
 * Output:
 *   None
 */
void changeValue(Node **head, int position, int new_value)
{
	// Check if the list is empty
	if (*head == NULL)
	{
		printf("List is empty, cannot change value.\n");
		return;
	}

	// Traverse the list to find the node at the specified position
	Node *current = *head;
	int current_position = 0;
	while (current != NULL && current_position < position)
	{
		current = current->next;
		current_position++;
	}

	// Check if the specified position is valid
	if (current == NULL)
	{
		printf("Invalid position, cannot change value.\n");
		return;
	}

	// Change the value of the node at the specified position
	current->data = new_value;
}

/*
 * Function: insertNode
 * Description: Inserts a new node with the specified data at the specified position in the linked list.
 * Input:
 *   head_ref - a pointer to the pointer to the head of the linked list
 *   position - an integer representing the position where the new node should be inserted
 *   new_data - an integer representing the data to be added
 * Output:
 *   None
 */
void insertNode(Node **head_ref, int position, int new_data)
{
	// Create a new node with the given data
	Node *new_node = createNode(new_data);
	if (new_node == NULL)
	{
		printf("Memory allocation failed, cannot insert node.\n");
		return;
	}

	// Check if the specified position is valid
	if (position == 0)
	{
		// Insert at the beginning of the list
		new_node->next = *head_ref;
		*head_ref = new_node;
	}
	else
	{
		// Traverse the list to find the node at the specified position
		Node *current = *head_ref;
		int current_position = 0;
		while (current != NULL && current_position < position - 1)
		{
			current = current->next;
			current_position++;
		}

		// Check if the specified position is valid
		if (current == NULL)
		{
			printf("Invalid position, cannot insert node.\n");
			return;
		}

		// Insert the new node at the specified position
		new_node->next = current->next;
		current->next = new_node;
	}
}

/*
 * Function: printList
 * Description: Prints the elements of the linked list.
 * Input:
 *   node - a pointer to the head of the linked list
 * Output:
 *   None
 */
void printList(Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

/*
 * Function: freeList
 * Description: Frees the memory allocated for the linked list.
 * Input:
 *   headref - a pointer to the pointer to the head of the linked list
 * Output:
 *   None
 */
void freeList(Node **headref)
{
	while (*headref != NULL)
	{
		Node *temp = *headref;
		(*headref) = (*headref)->next;
		free(temp);
	}
}
