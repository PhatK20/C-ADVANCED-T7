#include <stdio.h>
int search(int arr[], int n, int find)
{
	int low = 0, high = n - 1, mid;
	while (arr[high] != arr[low] && find >= arr[low] && find <= arr[high])
	{
		mid = low + ((find - arr[low]) * (high - low) / (arr[high] - arr[low]));
		if (find == arr[mid])
		{
			return mid;
		}
		else if (find < arr[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	if (find == arr[low])
	{
		return low;
	}
	else
	{
		return -1;
	}
}

int main(void)
{
	int arr[] = {2, 4, 6, 8, 11, 13, 15, 20, 30, 45, 55, 60, 75, 89, 92, 98, 100, 120, 130, 140};
	int value_to_find = 100;
	int n = sizeof(arr) / sizeof(arr[0]);
	int pos = search(arr, n, value_to_find);

	if (pos != -1)
	{
		printf("The element to look for is at position %d", pos);
	}
	else
	{
		printf("Not found");
	}

	return 0;
}