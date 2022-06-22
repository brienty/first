#define _CRT_SECURE_NO_WARNINGS 1
//√∞≈›≈≈–ÚÀ„∑®
#include <stdio.h>
#define NUMB 4
int main()
{
	int i = 0;
	int j = 0;
	int z = 0;
	int arr[NUMB];
	for (i = 0; i < NUMB; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	for (j = NUMB - 1; j >= 0; j--)
	{
		for (i = 0; i <= j - i - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				int z = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = z;
			}
		}
		printf("%d\n", arr[i + 1]);
	}
	return 0;
}
/*void Bubble_sort(int* arr)
{
	int j = 0;
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int arr[3] = {0};
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		scanf("%d", arr);
	}
	Bubble_sort(arr);
	for (i = 0; i < 3; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}*/