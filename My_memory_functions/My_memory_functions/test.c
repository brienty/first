#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>

void Print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//其中的num是字节数
void* My_memcpy(void* dest, const void* src, size_t num)
{
	void* temp = dest;// 需要返回目的地指针

	assert(dest && src);//判空
	
	while (num--)
	{
		*((char*)dest) = *((char*)src);
		((char*)dest)++;
		((char*)src)++;
	}

	return temp;
}

void* My_memmove(void* dest, const void* src, size_t num)
{
	void* temp = dest;//返回目的地指针

	assert(dest && src);//判空

	//当dest小于src时，从前往后复制
	if (dest < src)
	{
		while (num--)
		{
			*((char*)dest) = *((char*)src);
			(char*)dest = (char*)dest + 1;
			(char*)src = (char*)src + 1;
		}
	}
	//当dest大于src时，从后往前复制
	else
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}

	return temp;

}


int main()
{
	//测试My_memcpy函数
	int arr1[20] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[5] = { 0 };

	//测试My_memmove函数
	int arr3[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

	int num = 20;//字节数

	int num2 = 20;//字节数

	//调用memory函数中的memcpy，不包含重叠部分的交换
	My_memcpy(arr2, arr1, num);
	
	//调用memory函数中的memmove，包含自身重叠部分
	My_memmove(arr3+3, arr3+4, num2);
	
	//调用Print函数打印
	Print(arr3, sizeof(arr3)/sizeof(arr3[0]));

	//调用Print函数打印
	Print(arr2, (num/sizeof(arr1[0])));

	return 0;
}