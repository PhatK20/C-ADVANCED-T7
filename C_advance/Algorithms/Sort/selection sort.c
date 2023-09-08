#include <stdio.h>
#include <conio.h>

void selSort(int arr[], int N);
void printArr(int arr[], int N);
void swap(int* a, int* b);

void main()
{
   int Arr[] = {0, -5, -10, 10, 5, 15, 20, 35, 25, 40, 30};
   int sizeArr = sizeof(Arr)/sizeof(int);
   selSort(Arr, sizeArr);
   printArr(Arr, sizeArr);
   getch();
}

// Sắp xếp từ lớn đến nhỏ
void selSort(int arr[], int N)
{
   int i, j, idx, temp;
   for (i = 0; i < N-1; i++)
   {
       idx = i;
       for (j = i+1; j < N; j++)
       {
           if (arr[i] < arr[j])
           {
               idx = j;
               swap(&arr[i], &arr[idx]);
           }   
       }
   }
}

void swap(int* a, int* b)
{
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}

void printArr(int arr[], int N)
{
   int i;
   for (i = 0; i < N; i++)
   {
       printf("%d\t", arr[i]);
   }
}