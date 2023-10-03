/*
 * File Name: main.c
 * Author: Phat Bui Gia
 * Date: 18/09/2023
 * Description: An interactive program for managing a linked list of students.
 */

#include "StudentLinkedList.h"

int main()
{
	Node *head = NULL; // Khởi tạo đỉnh của danh sách liên kết

	// Tải dữ liệu từ tệp CSV vào danh sách liên kết
	// load_from_csv(&head, "students.csv");
	// printf("Dữ liệu đã được tải từ tệp CSV:\n");
	// display_list(head);
	char first_name[MAX_NAME_LEN], last_name[MAX_NAME_LEN];
	char gender[5];
	int yearOfBirth;
	char field[20];
	int choice;
	do
	{
		display_menu();
		choice = getUserChoice(1, 9);
		switch (choice)
		{
		case 1:
			// Nhập dữ liệu sinh viên và thêm vào danh sách.
			printf("Nhập tên đầu: ");
			scanf("%s", first_name);
			printf("Nhập tên cuối: ");
			scanf("%s", last_name);
			printf("Nhập giới tính (Nam/Nu): ");
			scanf("%s", gender);
			printf("Nhập năm sinh: ");
			scanf("%d", &yearOfBirth);
			add_student(&head, first_name, last_name, gender, yearOfBirth);
			break;
		case 2:
			// Chọn sinh viên theo ID và chỉnh sửa thông tin.
			printf("Nhập ID của sinh viên cần sửa: ");
			int id_to_edit;
			scanf("%d", &id_to_edit);
			edit_student(head, id_to_edit);
			break;
		case 3:
			// Chọn sinh viên theo ID và xóa khỏi danh sách.
			printf("Nhập ID của sinh viên cần xóa: ");
			int id_to_delete;
			scanf("%d", &id_to_delete);
			delete_student(&head, id_to_delete);
			break;
		case 4:
			// Tìm sinh viên theo tên.
			char name_search[MAX_NAME_LEN];
			printf("Nhập tên sinh viên cần tìm: ");
			scanf("%s", name_search);
			search_student_by_name(head, name_search);
			break;
		case 5:
			// Sắp xếp danh sách liên kết theo tên sinh viên.
			strcpy(field, "first_name");
			sort_students(&head, field);
			break;
		case 6:
			// Sắp xếp danh sách liên kết theo năm sinh.
			strcpy(field, "yearOfBirth");
			sort_students(&head, field);
			break;
		case 7:
			// Lọc và hiển thị sinh viên có tên trùng lặp.
			filter_duplicate_names(head);
			break;
		case 8:
			// Hiển thị danh sách sinh viên.
			display_list(head);
			break;
		case 9:
			printf("Lưu thành công!!!.\n");
			// Lưu dữ liệu vào tệp CSV và thoát chương trình.
			save_to_csv(head, "filename.csv");
			free_list(&head); // giải phóng bộ nhớ cho danh sách
			return 0;
		}
	} while (1);
}