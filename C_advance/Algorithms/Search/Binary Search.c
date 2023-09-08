#include <stdio.h>

int search(int arr[], int x, int low, int high)
{
	while (low <= high)
	{
		int mid = (high + low) / 2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] < x)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return -1;
}

int main(void)
{
	int arr[] = {2, 4, 6, 8, 11, 13, 15, 20, 30, 45, 55, 60, 75, 89, 92, 98, 100, 120, 130, 140};
	int n = sizeof(arr) / sizeof(arr[0]);
	int x = 100;
	int kq = search(arr, x, 0, n - 1);
	if (kq == -1)
		printf("Not found");
	else
		printf("The element to look for is at position %d", kq);
	return 0;
}