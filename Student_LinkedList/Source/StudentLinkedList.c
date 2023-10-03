/*
* File: StudentLinkedList.h
* Author: Phat Bui Gia
* Date: 18/09/2023
* Description: This file includes the definition of all functions to manage students using linked lists.
*/

#include "StudentLinkedList.h"

/*
 * Function: new_node
 * Description: Creates a new node for a linked list with the given data.
 * Input:
 *   id - an integer representing the node's ID
 *   first_name - a string representing the first name
 *   last_name - a string representing the last name
 *   gender - a string representing the gender
 *   yearOfBirth - an integer representing the year of birth
 * Output:
 *   Returns a pointer to the newly created node.
 */
Node *new_node(int id, char *first_name, char *last_name, char *gender, int yearOfBirth)
{
	Node *temp = (Node *)malloc(sizeof(Node));
	temp->data.id = id;
	temp->data.first_name = strdup(first_name); // Cấp phát động cho chuỗi
	temp->data.last_name = strdup(last_name);
	temp->data.gender = strdup(gender);
	temp->data.yearOfBirth = yearOfBirth;
	temp->next = NULL;
	return temp;
}

/*
 * Function: add_student
 * Description: Adds a new student to the end of a linked list of students.
 * Input:
 *   head - a pointer to the pointer to the head of the linked list
 *   first_name - a string representing the first name of the student
 *   last_name - a string representing the last name of the student
 *   gender - a string representing the gender of the student
 *   yearOfBirth - an integer representing the year of birth of the student
 * Output:
 *   None
 */
void add_student(Node **head, char *first_name, char *last_name, char *gender, int yearOfBirth)
{
	Node *newStu = new_node(1, first_name, last_name, gender, yearOfBirth);

	if (!(*head))
	{
		*head = newStu;
		return;
	}

	Node *temp = *head;
	while (temp->next)
	{
		temp = temp->next;
	}
	newStu->data.id = temp->data.id + 1;
	temp->next = newStu;
}

/*
 * Function: edit_student
 * Description: Edits the information of a student with the given ID in a linked list of students.
 * Input:
 *   head - a pointer to the head of the linked list
 *   id - an integer representing the ID of the student to be edited
 * Output:
 *   None
 */
void edit_student(Node *head, int id)
{
	Node *temp = head;
	while (temp)
	{
		if (temp->data.id == id)
		{
			printf("Nhập tên đầu mới: ");
			char first_name[MAX_NAME_LEN];
			scanf("%s", first_name);
			free(temp->data.first_name);
			temp->data.first_name = strdup(first_name);

			printf("Nhập tên cuối mới: ");
			char last_name[MAX_NAME_LEN];
			scanf("%s", last_name);
			free(temp->data.last_name);
			temp->data.last_name = strdup(last_name);

			printf("Nhập giới tính: ");
			char gender[5];
			scanf("%s", temp->data.gender);
			free(temp->data.gender);
			temp->data.gender = strdup(gender);

			printf("Nhập năm sinh mới: ");
			scanf("%d", &(temp->data.yearOfBirth));
			return;
		}
		temp = temp->next;
	}
	printf("Không tìm thấy sinh viên với ID: %d\n", id);
}

/*
 * Function: delete_student
 * Description: Deletes a student with the given ID from a linked list of students.
 * Input:
 *   head - a pointer to the pointer to the head of the linked list
 *   id - an integer representing the ID of the student to be deleted
 * Output:
 *   None
 */
void delete_student(Node **head, int id)
{
	Node *temp = *head;
	Node *prev = NULL;

	// Nếu sinh viên cần xóa ở đầu danh sách
	if (temp != NULL && temp->data.id == id)
	{
		*head = temp->next;
		free(temp->data.first_name);
		free(temp->data.last_name);
		free(temp);
		return;
	}

	// Tìm sinh viên cần xóa
	while (temp != NULL && temp->data.id != id)
	{
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL)
	{
		printf("Không tìm thấy sinh viên với ID: %d\n", id);
		return;
	}

	// Xóa node
	prev->next = temp->next;
	free(temp->data.first_name);
	free(temp->data.last_name);
	free(temp);
}

/*
 * Function: search_student_by_name
 * Description: Searches for students with a given name in a linked list of students and prints the results.
 * Input:
 *   head - a pointer to the head of the linked list
 *   name - a string representing the name to search for
 * Output:
 *   None
 */
void search_student_by_name(Node *head, const char *name)
{
	printf("\nKết quả tìm kiếm cho \"%s\":\n", name);
	Node *temp = head;
	while (temp)
	{
		if (strstr(temp->data.first_name, name))
		{
			printf("| ID | Tên đầu | Tên cuối | Giới tính | Năm sinh |\n");
			printf("| %d | %-7s | %-8s | %-9s | %-8d |\n", temp->data.id, temp->data.first_name, temp->data.last_name, temp->data.gender, temp->data.yearOfBirth);
		}
		temp = temp->next;
	}
}

/*
 * Function: compare_students
 * Description: Compares two students based on a specified field.
 * Input:
 *   s1 - a Student structure representing the first student
 *   s2 - a Student structure representing the second student
 *   field - a string specifying the field to compare ("first_name" or "yearOfBirth")
 * Output:
 *   None
 */
int compare_students(Student s1, Student s2, char *field)
{
	if (strcmp(field, "first_name") == 0)
	{
		return strcmp(s1.first_name, s2.first_name);
	}
	else if (strcmp(field, "yearOfBirth") == 0)
	{
		if (s1.yearOfBirth < s2.yearOfBirth)
		{
			return -1;
		}
		if (s1.yearOfBirth > s2.yearOfBirth)
		{
			return 1;
		}
		return 0;
	}
	return 0;
}

/*
 * Function: sort_students
 * Description: Sorts a linked list of students based on a specified field.
 * Input:
 *   head - a pointer to the pointer to the head of the linked list
 *   field - a string specifying the field to sort by ("first_name" or "yearOfBirth")
 * Output:
 *   None
 */
void sort_students(Node **head, char *field)
{
	if (*head == NULL || (*head)->next == NULL)
	{
		return; // Danh sách rỗng hoặc chỉ có một node, không cần sắp xếp
	}

	Node *sorted = *head;
	Node *curr = sorted->next;
	sorted->next = NULL;

	while (curr != NULL)
	{
		Node *prev = NULL;
		Node *next = curr->next;

		// Tìm vị trí thích hợp để chèn node hiện tại vào danh sách đã sắp xếp
		while (sorted != NULL && compare_students(curr->data, sorted->data, field) > 0)
		{
			prev = sorted;
			sorted = sorted->next;
		}

		if (prev == NULL)
		{
			curr->next = sorted;
			*head = curr;
		}
		else
		{
			prev->next = curr;
			curr->next = sorted;
		}

		curr = next;
		sorted = *head;
	}
}

/*
 * Function: filter_duplicate_names
 * Description: Finds and prints students with duplicate first names in a linked list.
 * Input:
 *   head - a pointer to the head of the linked list
 * Output:
 *   None
 */
void filter_duplicate_names(Node *head)
{
	Node *outer = head;
	while (outer)
	{
		Node *inner = outer->next;
		while (inner)
		{
			if (strcmp(outer->data.first_name, inner->data.first_name) == 0)
			{
				printf("| ID | Tên đầu | Tên cuối | Giới tính | Năm sinh |\n");
				printf("| %d | %-7s | %-8s | %-9s | %-8d |\n", inner->data.id, inner->data.first_name, inner->data.last_name, inner->data.gender, inner->data.yearOfBirth);
			}
			inner = inner->next;
		}
		outer = outer->next;
	}
}

/*
 * Function: display_list
 * Description: Displays the details of students in a linked list.
 * Input:
 *   head - a pointer to the head of the linked list
 * Output:
 *   None
 */
void display_list(Node *head)
{
	Node *temp = head;
	printf("\nDanh sách sinh viên:\n");
	printf("| ID | Tên đầu | Tên cuối | Giới tính | Năm sinh |\n");
	while (temp)
	{
		printf("| %-2d | %-7s | %-8s | %-9s | %-8d |\n", temp->data.id, temp->data.first_name, temp->data.last_name, temp->data.gender, temp->data.yearOfBirth);
		temp = temp->next;
	}
}

/*
 * Function: save_to_csv
 * Description: Saves the details of students from a linked list to a CSV file.
 * Input:
 *   head - a pointer to the head of the linked list
 *   filename - a string specifying the name of the CSV file
 * Output:
 *   None
 */
void save_to_csv(Node *head, const char *filename)
{
	FILE *file = fopen(filename, "w");
	if (file == NULL)
	{
		printf("Lỗi mở tệp để ghi.\n");
		return;
	}

	// Ghi tiêu đề cho file CSV (tùy vào cấu trúc của bạn)
	fprintf(file, "ID,FirstName,LastName,yearOfBirth\n");

	// Duyệt danh sách và ghi thông tin ra file
	Node *temp = head;
	while (temp != NULL)
	{
		fprintf(file, "%d,%s,%s,%s,%d\n", temp->data.id, temp->data.first_name, temp->data.last_name, temp->data.gender, temp->data.yearOfBirth);
		temp = temp->next;
	}

	fclose(file);
}

/*
 * Function: load_from_csv
 * Description: Loads student details from a CSV file into a linked list.
 * Input:
 *   head - a pointer to the pointer to the head of the linked list
 *   filename - a string specifying the name of the CSV file
 * Output:
 *   None
 */
void load_from_csv(Node **head, const char *filename)
{
	FILE *file = fopen(filename, "r");
	if (file == NULL)
	{
		printf("Không thể mở tệp %s để đọc\n", filename);
		return;
	}

	char first_name2[MAX_NAME_LEN], last_name2[MAX_NAME_LEN];
	int id;
	char gender[5];
	int yearOfBirth;
	while (fscanf(file, "%d,%[^,],%[^,],%[^,],%d\n", &id, first_name2, last_name2, gender, &yearOfBirth) != EOF)
	{
		add_student(head, first_name2, last_name2, gender, yearOfBirth);
	}

	fclose(file);
}

/*
 * Function: free_list
 * Description: Frees the memory associated with a linked list of students.
 * Input:
 *   head - a pointer to the pointer to the head of the linked list
 * Output:
 *   None
 */
void free_list(Node **head)
{
	Node *current = *head;
	Node *nextNode;

	while (current != NULL)
	{
		nextNode = current->next;		// lưu tham chiếu tới node kế tiếp
		free(current->data.first_name); // giải phóng bộ nhớ của tên đầu
		free(current->data.last_name);	// giải phóng bộ nhớ của tên cuối
		free(current->data.gender);
		free(current);		// giải phóng bộ nhớ của node hiện tại
		current = nextNode; // chuyển tới node kế tiếp
	}

	*head = NULL; // đặt lại head thành NULL
}

/*
 * Function: getUserChoice
 * Description: Prompts the user for a menu choice within a specified range and validates the input.
 * Input:
 *   numBegin - an integer representing the beginning of the valid range of choices
 *   numEnd - an integer representing the end of the valid range of choices
 * Output:
 *   Returns the user's validated choice within the specified range.
 */
int getUserChoice(int numBegin, int numEnd)
{
	int choice;
	printf("Enter your choice: ");
	scanf("%d", &choice);
	while (choice < numBegin || choice > numEnd)
	{
		printf("Invalid choice! Please try again\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
	}
	return choice;
}

/*
 * Function: display_menu
 * Description: Displays a menu of options to the user.
 * Input:
 *   None
 * Output:
 *   None
 */
void display_menu()
{
	printf("\n---- MENU ----\n");
	printf("1. Thêm sinh viên\n");
	printf("2. Sửa sinh viên\n");
	printf("3. Xóa sinh viên\n");
	printf("4. Tìm kiếm sinh viên theo tên\n");
	printf("5. Sắp xếp sinh viên theo tên\n");
	printf("6. Sắp xếp sinh viên theo năm sinh\n");
	printf("7. Lọc và hiển thị sinh viên có tên trùng lặp\n");
	printf("8. Hiển thị danh sách sinh viên\n");
	printf("9. Lưu và thoát\n");
}
