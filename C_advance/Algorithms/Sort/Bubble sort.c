#include <stdio.h>
#include <conio.h>

void BubbleSort(int arr[], int N);
void printArr(int arr[], int N);
void swap(int* a, int* b);

void main()
{
   int Arr[] = {0, -5, -10, 10, 5, 15, 20, 35, 25, 40, 30};
   int sizeArr = sizeof(Arr)/sizeof(int);
   BubbleSort(Arr, sizeArr);
   printArr(Arr, sizeArr);
   getch();
}

// Bubble sort
// Sắp xếp từ nhỏ đến lớn
void BubbleSort(int arr[], int N)
{
   int i, j;
   for (i = 0; i < N; i++)
   {
       for (j = N-1; j > i; j--)
       {
           if(arr[j] < arr[j-1])
               swap(&arr[j], &arr[j-1]);
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