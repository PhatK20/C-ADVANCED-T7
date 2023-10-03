#include<stdio.h>
#include<stdlib.h>

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


struct Node* inputData(struct Node* head, int n)
{
  for(int i = 0; i < n; i++)
  {
    int k;
    scanf("%d", &k);
    append(&head, k);
  }
  return head;
}

void insert(struct Node* head, int k, int x)
{
  struct Node* new_node = createNode(x);
  while(head != NULL)
  {
    static int i =0;
    if(i == k -1)
    {
      new_node->next = head->next;
      head->next = new_node;
    }
    else if(k == 0)
    {
      new_node->next = head;
      head = new_node;
    }
    printf("%d ", head->data);
    head = head->next;
    i++;
  }
}

int main()
{
  struct Node* head = NULL;
  int n;
  scanf("%d", &n);
  head = inputData(head, n);
  
  int k, x;
  scanf("%d %d", &k, &x);
  
  insert(head, k, x);
  return 0;
  
  
}