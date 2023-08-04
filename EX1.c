#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    uint16_t student_id;
    char *name;
    char *gender;
    uint16_t year_of_birth;
} Student;

int main() {
    char fileName[] = "student.csv";
    FILE *file = fopen(fileName, "r");
    Student students[MAX_STUDENTS];
    int num_students = 0;
    int i;
    size_t max_name_length, name_length;

    // Đọc dữ liệu từ file vào mảng students
    if (file != NULL) {
        char line[100];
        // Bỏ qua dòng tiêu đề
        fgets(line, sizeof(line), file);
        while (fgets(line, sizeof(line), file) != NULL) {
            students[num_students].name = (char*)malloc(50 * sizeof(char));
            students[num_students].gender = (char*)malloc(10 * sizeof(char));
            sscanf(line, "%d, %[^,], %[^,], %d",
                &students[num_students].student_id,
                students[num_students].name,
                students[num_students].gender,
                &students[num_students].year_of_birth);

            // Tính độ dài tên lớn nhất
            name_length = strlen(students[num_students].name);
            if (name_length > max_name_length) {
                max_name_length = name_length;
            }
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
        printf("Student ID: ");
        scanf("%d", &students[num_students + i].student_id);
        printf("Name: ");
        scanf(" %[^\n]", students[num_students + i].name);
        printf("Gender: ");
        scanf(" %[^\n]", students[num_students + i].gender);
        printf("Year of Birth: ");
        scanf("%d", &students[num_students + i].year_of_birth);

        // Tính độ dài tên lớn nhất
        name_length = strlen(students[num_students+i].name);
            if (name_length > max_name_length) {
                max_name_length = name_length;
            }
    }
    num_students += num_new_students;

    // Ghi lại dữ liệu vào file
    file = fopen(fileName, "w");
    if (file != NULL) {
        fprintf(file, "Student ID, Name, Gender, Year of Birth\n");
        for (i = 0; i < num_students; i++) {
            fprintf(file, "%d, %s, %s, %d\n",
                students[i].student_id,
                students[i].name,
                students[i].gender,
                students[i].year_of_birth);
        }
        fclose(file);
    }
    else{
        printf("Khong the mo file");
        return 1;
    }

    // Hiển thị dữ liệu đã nhập
    printf("Danh sach sinh vien:\n");
    printf("NO | Student ID | %-*s | Gender | Year of Birth\n", max_name_length, "Name");
    for (i = 0; i < num_students; i++) {
        printf("%-2d | %-10d | %-*s | %-6s | %-10d\n",
            i+1,
            students[i].student_id,
            max_name_length, students[i].name,
            students[i].gender,
            students[i].year_of_birth);
    }

    // Giải phóng bộ nhớ đã cấp phát động
    for (i = 0; i < num_students; i++) {
        free(students[i].name);
        free(students[i].gender);
    }

    return 0;
}
