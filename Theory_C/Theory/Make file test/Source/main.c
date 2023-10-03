/*
* File Name: main.c
* Author: Giao Pham
* Date: 26/03/2023
* Description: Using a linked list to store and manage a list of data.
*/

#include "Linked_List.h"

// int main(int argc, char const *argv[])
int main()
{
    node *arr = NULL;
    pushBack(&arr, 1);
    pushBack(&arr, 2);
    pushBack(&arr, 3);
    pushBack(&arr, 4);
    printf("Danh sach ban dau: ");
    duyet(arr);
    printf("\n");

    assign(arr, 1, 5);
    printf("Danh sach sau khi su dung ham assign(1, 5): ");
    duyet(arr);
    printf("\n");

    erase(&arr, 2);
    printf("Danh sach sau khi xoa node tai vi tri 2: ");
    duyet(arr);
    printf("\n");

    pop_back(&arr);
    printf("Danh sach sau khi xoa node cuoi cung: ");
    duyet(arr);
    printf("\n");

    clear(&arr);
    printf("Danh sach sau khi xoa toan bo danh sach: ");
    duyet(arr);
    printf("\n");

    return 0;
}