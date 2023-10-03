#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct infStudent_t
{
	char name[100];
	char gender[10];
	uint16_t yearOfBirth;
	uint16_t id;
} infStudent;

typedef struct node_t
{
	infStudent student;
	struct node_t *next;
} Node;

static Node *head = NULL;
// Function to create a new node with the given data
Node *createNode(infStudent data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	if (newNode != NULL)
	{
		newNode->student = data;
		newNode->next = NULL;
	}
	return newNode;
}

// Function to append a new node at the end of the linked list
void appendNode(infStudent new_data)
{
	// Create a new node with the given data
	Node *new_node = createNode(new_data);
	if (new_node != NULL)
	{
		// If the memory allocation was successful
		if (head == NULL)
		{
			// If the list is empty, make the new node the head
			head = new_node;
		}
		else
		{
			// Find the last node and add the new node after it
			Node *last = head;
			while (last->next != NULL)
			{
				last = last->next;
			}
			last->next = new_node;
		}
	}
}

// Function to delete the first occurrence of a node with the given key from the linked list
void deleteNode(uint16_t id)
{
	if (head == NULL)
	{
		return; // Empty list, nothing to delete
	}

	Node *temp = head;
	Node *prev = NULL;

	// If the head node contains the key value
	if (temp != NULL && temp->student.id == id)
	{
		head = temp->next;
		free(temp);
		return;
	}

	// Search for the node containing the key value
	while (temp != NULL && temp->student.id != id)
	{
		prev = temp;
		temp = temp->next;
	}

	// If the key value is not found
	if (temp == NULL)
		return;

	// Delete the node
	prev->next = temp->next;
	free(temp);
}

// Save data from student list to Linked list
void stuLisToLinLis()
{
	FILE *file = fopen("student_LinkedList.csv", "r");
	char buffer[100];
	fgets(buffer, sizeof(buffer), file);
	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		infStudent tempStu;
		sscanf(buffer, "%[^,], %[^,], %hu, %hu",
			   tempStu.name, tempStu.gender, &tempStu.yearOfBirth, &tempStu.id);
		appendNode(tempStu);
	}
	fclose(file);
}

// Save data from Linked list to student list
void linLisToStuLis()
{
	FILE *file = fopen("student_LinkedList.csv", "w");
	Node *tempNode = head;
	fprintf(file, "Name, Gender, Year of Birth, Student ID\n");
	while (tempNode != NULL)
	{
		fprintf(file, "%s, %s, %hu, %hu\n",
				tempNode->student.name,
				tempNode->student.gender,
				tempNode->student.yearOfBirth,
				tempNode->student.id);
		tempNode = tempNode->next;
	}
	fclose(file);
}

// Function to free the memory used by the linked list
void freeList()
{
	while (head != NULL)
	{
		Node *temp = head;
		head = head->next;
		free(temp);
	}
}

// create student list
void newDatabase(uint16_t *idLast)
{

	FILE *file = fopen("student_LinkedList.csv", "w");
	fprintf(file, "Name, Gender, Year of birth, Student ID\n");
	fclose(file);
}

// add data to the student list
void INSERT(uint16_t *idLast)
{
	uint16_t num;
	printf("The number of students is added to the list: ");
	scanf("%hu", &num);
	FILE *file = fopen("student_LinkedList.csv", "a");
	for (int i = 0; i < num; i++)
	{
		infStudent temp;
		printf("Student numer %d\n", i + 1);
		printf("Name: ");
		scanf(" %[^\n]", temp.name);
		printf("Gender: ");
		scanf(" %[^\n]", temp.gender);
		printf("Year of Birth: ");
		scanf("%hu", &temp.yearOfBirth);
		temp.id = ++(*idLast);
		fprintf(file, "%s, %s, %hu, %hu\n",
				temp.name,
				temp.gender,
				temp.yearOfBirth,
				temp.id);
	}
	fclose(file);
}

void UPDATE(uint16_t id, uint16_t idLast)
{
	if (id > idLast)
	{
		printf("\nThis student was not found");
	}
	else
	{
		freeList();
		stuLisToLinLis();
		Node *temp = head;
		while (temp->student.id != id)
		{
			temp = temp->next;
		}
		infStudent tempStudent;
		printf("Update student information with id = %hu\n", temp->student.id);
		printf("Name: ");
		scanf(" %[^\n]", tempStudent.name);
		printf("Gender: ");
		scanf(" %[^\n]", tempStudent.gender);
		printf("Year of Birth: ");
		scanf("%hu", &tempStudent.yearOfBirth);
		tempStudent.id = temp->student.id;
		temp->student = tempStudent;
		linLisToStuLis();
	}
}

void DELETE(uint16_t id, uint16_t idLast)
{
	if (id > idLast)
	{
		printf("\nThis student was not found");
	}
	else
	{
		freeList();
		stuLisToLinLis();
		deleteNode(id);
		linLisToStuLis();
	}
}


int main()
{
	uint16_t idLast = 0;
	newDatabase(&idLast);
	INSERT(&idLast);
	UPDATE(2, idLast);
	DELETE(3, idLast);
	freeList();
}
