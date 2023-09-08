#include <stdio.h>
#include <stdlib.h>
int main(){
    int key=0;
    do
    {
        /* code */
        
        printf("Chuong trinh abc:\n");
        printf("Nhan 1: Chuong trinh 1:\n");
        printf("Nhan 2: Chuong trinh 2\n");
        printf("Nhan 3: Chuong trinh 3\n");
        printf("Nhan 0: Thoat\n");
        printf("Vui long nhan phim:...\n");
        scanf("%d",&key);
        if(key > 3 && key < 0){
            //system("cls");
            printf("ban nhap sai, vui long nhap lai\n");
        }
    } while (key > 3 && key < 0);
    return 0;
}