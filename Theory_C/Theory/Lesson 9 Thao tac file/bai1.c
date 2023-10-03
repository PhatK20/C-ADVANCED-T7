#include <stdio.h>
#include <stdlib.h>

//w: mở để ghi data
//r: mở để đọc
//a: mở để ghi data vào cuối file

int main()
{
    FILE *file = fopen("C\text.txt","a");
    if(file !=NULL)
    {
        fprintf(file,"Hello world!\n");
        fclose(file);
        printf("OK\n");
    }
    else
    {
        printf("ERROR!!!\n");
    }
    return 0;
}