/*
* File: StudentLinkedList.h
* Author: Phat Bui Gia
* Date: 18/09/2023
* Description: This header file contains the declaration of the Student struct
* and related functions for a student management system using Linked List. 
*/

#ifndef __STUDENT_LINKED_LIST_H
#define __STUDENT_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LEN 100

typedef struct
{
	int id; // giả định mỗi sinh viên có ID duy nhất
	char *first_name;
	char *last_name;
	char *gender;
	int yearOfBirth;
} Student;

typedef struct Node
{
	Student data;
	struct Node *next;
} Node;

// Hàm dùng tạo một node mới để lưu trữ sinh viên
Node *new_node(int id, char *first_name, char *last_name, char *gender, int yearOfBirth);

// Hàm thêm một sinh viên vào cuối danh sách
void add_student(Node **head, char *first_name, char *last_name, char *gender, int yearOfBirth);

// Hàm chỉnh sửa thông tin sinh viên
void edit_student(Node *head, int id);

// Hàm xóa sinh viên ra khỏi danh sách
void delete_student(Node **head, int id);

// Tìm kiếm sinh viên theo tên và hiển thị thông tin sinh viên đó
void search_student_by_name(Node *head, const char *name);

// Hàm so sánh tên hoặc năm sinh của sinh viên
int compare_students(Student s1, Student s2, char *field);

// Hàm sắp xếp danh sách sinh viên theo tên hoặc năm sinh
void sort_students(Node **head, char *field);

// Lọc và hiển thị những sinh viên có tên trùng lặp
void filter_duplicate_names(Node *head);

// Hàm hiển thị danh sách viên
void display_list(Node *head);

// Hàm để lưu danh sách sinh viên vào tệp CSV
void save_to_csv(Node *head, const char *filename);

// Hàm dữ liệu từ tệp CSV vào danh sách liên kết
void load_from_csv(Node **head, const char *filename);

// Hàm giải phóng bộ nhớ cho tất cả các Node
void free_list(Node **head);

// Hàm nhập lựa chọn từ dùng
int getUserChoice(int numBegin, int numEnd);

// Hàm hiển thị menu
void display_menu();

#endif