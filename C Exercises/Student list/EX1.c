/*
* File Name: EX1.cpp
* Author: Bui Gia Phat
* Date: 23/04/2023
* Description: Enter information into the list of students in the file student.csv and display it on the screen
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

typedef struct {
    uint16_t student_id;
    char *name;
    char *gender;
    uint16_t year_of_birth;
} Student;

char countEleStr(const char *str, char *nameLen) {
    char count = 0;

    // Duyệt qua từng ký tự trong chuỗi cho đến khi gặp ký tự kết thúc chuỗi '\0'
    while (*str != '\0') {
        count++;
        str++; // Di chuyển đến ký tự tiếp theo trong chuỗi
    }
    if (count > *nameLen) {
        *nameLen = count;
    }
    return *nameLen;
}

int main() {
    char fileName[] = "student.csv";
    FILE *file = fopen(fileName, "r");
    Student students[MAX_STUDENTS];
    int num_students = 0;
    int i;
    char max_name_length = 0;

    // Đọc dữ liệu từ file vào mảng students
    if (file != NULL) {
        char line[100];
        // Bỏ qua dòng tiêu đề
        fgets(line, sizeof(line), file);
        while (fgets(line, sizeof(line), file) != NULL) {
            students[num_students].name = (char*)malloc(50 * sizeof(char));
            students[num_students].gender = (char*)malloc(10 * sizeof(char));
            sscanf(line, "%[^,], %[^,], %d, %d",
                students[num_students].name,
                students[num_students].gender,
                &students[num_students].year_of_birth,
                &students[num_students].student_id);

            // Tính độ dài tên lớn nhất
            max_name_length = countEleStr(students[num_students].name, &max_name_length);
            num_students++;            
        }
        fclose(file);
    }
    else{
        printf("Khong the mo file");
        return 1;
    }

    // Nhập thêm thông tin sinh viên
    int num_new_students;
    printf("Nhap so luong sinh vien can them: ");
    scanf("%d", &num_new_students);
    for (i = 0; i < num_new_students; i++) {
        students[num_students + i].name = (char*)malloc(50 * sizeof(char));
        students[num_students + i].gender = (char*)malloc(10 * sizeof(char));

        printf("Nhap thong tin sinh vien thu %d:\n", num_students + i + 1);
        printf("Name: ");
        scanf(" %[^\n]", students[num_students + i].name);
        printf("Gender: ");
        scanf(" %[^\n]", students[num_students + i].gender);
        printf("Year of Birth: ");
        scanf("%d", &students[num_students + i].year_of_birth);
        printf("Student ID: ");
        scanf("%d", &students[num_students + i].student_id);

        // Tính độ dài tên lớn nhất
        max_name_length = countEleStr(students[num_students + i].name, &max_name_length);
    }
    num_students += num_new_students;

    // Ghi lại dữ liệu vào file
    file = fopen(fileName, "w");
    if (file != NULL) {
        fprintf(file, "Name, Gender, Year of Birth, Student ID\n");
        for (i = 0; i < num_students; i++) {
            fprintf(file, "%s, %s, %d, %d\n",
                students[i].name,
                students[i].gender,
                students[i].year_of_birth,
                students[i].student_id);
        }
        fclose(file);
    }
    else{
        printf("Khong the mo file");
        return 1;
    }

    // Hiển thị dữ liệu đã nhập
    printf("Danh sach sinh vien:\n");
    printf("NO | %-*s | Gender | Year of Birth | Student ID\n", max_name_length, "Name");
    for (i = 0; i < num_students; i++) {
        printf("%-2d | %-*s | %-6s | %-13d | %-10d\n",
            i+1,
            max_name_length, students[i].name,
            students[i].gender,
            students[i].year_of_birth,
            students[i].student_id);
    }

    // Giải phóng bộ nhớ đã cấp phát động
    for (i = 0; i < num_students; i++) {
        free(students[i].name);
        free(students[i].gender);
    }

    return 0;
}
