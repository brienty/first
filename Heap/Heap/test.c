#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"


//使用堆实现排序，低级版堆排序
void Test(int* arr, int size)
{
	HP hp;
	HeapInit(&hp);
	for (int i = 0; i < size; i++)
	{
		HeapPush(&hp, arr[i]);
	}
	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	HeapDestroy(&hp);
}

int main()
{
	int arr[] = { 2,5,6,4,54,23,1,45,67,98 };
	Test(arr, sizeof(arr) / sizeof(arr[0]));
	return 0;
}