#include <stdio.h>
#include <conio.h>

void insertSort(int arr[], int N);
void printArr(int arr[], int N);

void main()
{
   int Arr[] = {0, -5, -10, 10, 5, 15, 20, 35, 25, 40, 30};
   int sizeArr = sizeof(Arr)/sizeof(int);   // Xác định số phần tử trong mảng
   insertSort(Arr, sizeArr);    
   printArr(Arr, sizeArr);
   getch();// dừng màn hình sau khi chạy xong chương trình
}

// Insertion sort
// Sắp xếp từ nhỏ đến lớn
void insertSort(int arr[], int N)
{
   int i, j, temp;
   for (i = 1; i < N; i++)
   {
       j = i - 1;
       temp = arr[i];
       while(arr[j] < temp && j >= 0)
       {
           arr[j+1] = arr[j];
           j--;
       }
       arr[j+1] = temp;
   }
}

void printArr(int arr[], int N)
{
   int i; 
   for (i = 0; i < N; i++)
   {
       printf("%d\t", arr[i]);
   }
}