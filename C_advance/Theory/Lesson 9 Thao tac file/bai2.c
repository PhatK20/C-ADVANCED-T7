#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("text.txt","r");

    // đọc ra từng từ fscanf()
    
    if(file !=NULL)
    {
        char buffer[100];
        // đọc từng ký tự trong file rồi lưu vào buffer cho đến khi gặp ký tự " " (ko lưu " ")
        // rồi in ra màn hình
        // quay lại vòng lặp ktra xem còn ký tự nào ko 
        // lặp lại cho đến từ cuối cùng
        while (fscanf(file, "%s", buffer) !=EOF)
        {
            printf(" ");
            printf("%s", buffer);
        }

        fclose(file);
    }
    else
    {
        printf("ERROR!!!\n");
    }

    return 0;
}