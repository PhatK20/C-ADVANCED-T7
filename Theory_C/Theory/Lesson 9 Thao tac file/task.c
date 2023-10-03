#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *file = fopen("student.csv","r");

    // đọc từng dòng fget
    
    if(file !=NULL)
    {
        char buffer[100];
        while (fgets(buffer, sizeof(buffer), file) !=NULL)
        {
            // Replace ',' with '|'
        for (int i = 0; buffer[i] != '\0'; i++) 
        {
            if (buffer[i] == ',') 
            {
                buffer[i] = '|';
            }
        }
            printf("%s", buffer);
        }
    }
    else
    {
      printf("Không thể mở file\n");
    }

    fclose(file);

    return 0;
}