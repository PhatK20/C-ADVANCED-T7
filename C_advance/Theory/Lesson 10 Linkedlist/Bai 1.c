#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to insert a new element at the beginning of the linked list
void prepend(struct Node** head_ref, int new_data) {
    struct Node* new_node = createNode(new_data);
    if (new_node != NULL) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
}

// Function to append a new node at the end of the linked list
void append(struct Node** head_ref, int new_data) {
    // Create a new node with the given data
    struct Node* new_node = createNode(new_data);
    if (new_node != NULL) {
        // If the memory allocation was successful
        if (*head_ref == NULL) {
            // If the list is empty, make the new node the head
            *head_ref = new_node;
        } else {
            // Find the last node and add the new node after it
            struct Node* last = *head_ref;
            while (last->next != NULL) {
                last = last->next;
            }
            last->next = new_node;
        }
    }
}

// Function to delete the first occurrence of a node with the given key from the linked list
void deleteNode(struct Node** head_ref, int key) {
    if (*head_ref == NULL) {
        return; // Empty list, nothing to delete
    }

    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // If the head node contains the key value
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    // Search for the node containing the key value
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If the key value is not found
    if (temp == NULL) return;

    // Delete the node
    prev->next = temp->next;
    free(temp);
}

// Function to change the value of a node at the specified position
void changeValue(struct Node** head, int position, int new_value) {
    // Check if the list is empty
    if (*head == NULL) {
        printf("List is empty, cannot change value.\n");
        return;
    }

    // Traverse the list to find the node at the specified position
    struct Node* current = *head;
    int current_position = 0;
    while (current != NULL && current_position < position) {
        current = current->next;
        current_position++;
    }

    // Check if the specified position is valid
    if (current == NULL) {
        printf("Invalid position, cannot change value.\n");
        return;
    }

    // Change the value of the node at the specified position
    current->data = new_value;
}

// Function to print the linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to free the memory used by the linked list
void freeList(struct Node** headref) {
    while (*headref != NULL) {
        struct Node* temp = *headref;
        (*headref) = (*headref)->next;
        free(temp);
    }
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert elements into the linked list
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

    // Free the memory
    freeList(&head);

    return 0;
}
