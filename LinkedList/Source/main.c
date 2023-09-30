/*
 * File: main.c
 * Author: Phat Bui Gia
 * Date: 27/08/2023
 * Description: A program to perform functions in a linked list.
 */

#include "LinkedList.h"

int main()
{
	Node *head = NULL;

	// Insert elements at the beginning of the linked list
	prepend(&head, 4);
	prepend(&head, 3);
	prepend(&head, 2);
	prepend(&head, 1);

	printf("Initial linked list (prepend): ");
	printList(head);

	// Insert elements at the end of the linked list
	append(&head, 5);
	append(&head, 6);

	printf("Linked list after appending 5 and 6: ");
	printList(head);

	// Delete a node
	deleteNode(&head, 3);
	printf("Linked list after deleting 3: ");
	printList(head);

	// Change the value of a node
	changeValue(&head, 3, 7);
	printf("Linked list after changing 7 at position 3: ");
	printList(head);

	// Insert a node
	insertNode(&head, 3, 8);
	printf("Linked list after inserting 8 at position 3: ");
	printList(head);
	
	// Free the memory
	freeList(&head);

	return 0;
}
