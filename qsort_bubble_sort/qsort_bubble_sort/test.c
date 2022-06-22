#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//交换函数
void swap(char* s1, char* s2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char temp = *s1;
		*s1 = *s2;
		*s2 = temp;
		s1++;
		s2++;
	}
}

//比较函数
int compare(const void* e1, const void* e2)
{
	return (*((int*)e1) - *((int*)e2));
}

//模拟qsort实现bubble
void Bubble_sort(void* base, size_t num, size_t width, int(*cmpare)(const void* e1, const void* e2))
{
	int i = 0;
	for (i = 0; i < num - 1; i++)
	{
		int j = 0;
		for (j = 0; j < num - 1 - i; j++)
		{

			//升序排序，转化成char*类型的指针灵活性高
			if (compare((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				//必须将width传过去，交换使用的是char*类型的指针，必须保证一个数据所有的字节都交换
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}

//打印函数
void Print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int main()
{
	int arr[] = { 2,3,8,6,5,9,10,34,457,1,23,64,83 };

	//需要传首地址，元素个数，元素大小，比较方法函数
	Bubble_sort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), compare);

	//打印数组
	Print(arr, sizeof(arr)/sizeof(arr[0]));
	
	return 0;
}