#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("text.txt","r");

    // đọc từng dòng fget
    
    if(file !=NULL)
    {
        char buffer[100];
        // đọc từng ký tự trong file rồi lưu vào buffer cho đến khi gặp ký tự \n (xuống dòng)
        // rồi in ra màn hình
        // quay lại vòng lặp ktra xem còn ký tự nào ko 
        // lặp lại cho đến dòng cuối cùng
        while (fgets(buffer, sizeof(buffer), file) !=NULL)
        {
            printf("%s", buffer);
        }
    }
    else
    {
      printf("không thể mở file\n");
    }
    return 0;
}