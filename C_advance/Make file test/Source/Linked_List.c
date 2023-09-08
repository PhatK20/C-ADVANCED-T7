/*
* File Name: Linked_List.c
* Author: Giao Pham
* Date: 26/03/2023
* Description: This is a file containing functions that use a linked list to store and manage a list of data.  
*/
#include "Linked_List.h"

/*
* Function: makeNode
* Description: This function creates a new node and initializes its data field with the given value. The next pointer of the new node is set to NULL.
* Input:
*   data: A integer value data.
* Output:
*   A pointer to a newly created node.
*/
node *makeNode(int data) {
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/*
* Function: pushBack
* Description: This function creates a new node with the given data value and adds it to the end of the linked list.
* Input:
*   **head: A pointer to a pointer to the head of a linked list head (node).
*   data: A integer value data.
* Output:
*   None.
*/
void pushBack(node **head, int data) {
    node* newNode = makeNode(data);
    if(*head == NULL) {
        *head = newNode;
        return;
    }
    node* tmp=*head;
    while(tmp->next !=NULL) {
        tmp=tmp->next;
    }
    tmp->next=newNode;
}

/*
* Function: duyet
* Description: This function traverses the linked list and prints the value of each node.
* Input:
*   *head: A pointer to the head of a linked list head (node).
* Output:
*   None.
*/
void duyet(node *head) {
    while(head != NULL) {
        printf("%d ",head->data);
        head = head->next;
    }
}

/*
* Function: assign
* Description: This function traverses the linked list and prints out the value of each node.
* Input:
*   *head: A pointer to the head of a linked list head (node).
*   index: A integer value index.
*   value: A integer value value.
* Output:
*   None.
*/
void assign(node *head, int index, int value) {
    node* tmp = head;
    int i = 0;
    while(tmp != NULL && i < index) {
        tmp = tmp->next;
        i++;
    }
    if(tmp != NULL) {
        tmp->data = value;
    }
}

/*
* Function: erase
* Description: This function removes the node at the specified index in the linked list.
* Input:
*   **head: A pointer to a pointer to the head of a linked list head (node).
*   index: A integer value index.
* Output:
*   None.
*/
void erase(node **head, int index) {
    if(*head == NULL) {
        return;
    }
    node* tmp = *head;
    if(index == 0) {
        *head = (*head)->next;
        free(tmp);
        return;
    }
    int i = 0;
    while(tmp != NULL && i < index-1) {
        tmp = tmp->next;
        i++;
    }
    if(tmp == NULL || tmp->next == NULL) {
        return;
    }
    node* nextNode = tmp->next->next;
    free(tmp->next);
    tmp->next = nextNode;
}

/*
* Function: pop_back
* Description: This function removes the last node in the linked list.
* Input:
*   **head: A pointer to a pointer to the head of a linked list head (node).
* Output:
*   None.
*/
void pop_back(node **head) {
    if(*head == NULL) {
        return;
    }
    if((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    node* tmp = *head;
    while(tmp->next->next != NULL) {
        tmp = tmp->next;
    }
    free(tmp->next);
    tmp->next = NULL;
}

/*
* Function: clear
* Description: This function removes all nodes in the linked list and sets the head pointer to NULL.
* Input:
*   **head: A pointer to a pointer to the head of a linked list head (node).
* Output:
*   None.
*/
void clear(node **head) {
    node* tmp = *head;
    while(tmp != NULL) {
        node* nextNode = tmp->next;
        free(tmp);
        tmp = nextNode;
    }
    *head = NULL;
}

