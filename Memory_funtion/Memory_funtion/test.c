#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

void* My_memcpy(void* dest, const void* src, size_t num)//num是字节数
{
	void* ret = dest;
	assert(dest && src);//判空
	//复制
	while (num--)
	{
		*(char*)dest = *(char*)src;//解引用以后的内容赋值过去
		dest = (char*)dest + 1;//这里必须写成这样，强制类型转化具有时效性，只能在当前代码行生效
		src = (char*)src + 1;
	}
	return ret;//函数必须返回一个void*类型的指针，返回目的地dest
}


void* My_memmove(void* dest, const void* src, size_t num)
{
	void* ret = dest;
	assert(dest && src);//判空
	//1. 从前往后复制
	//当dest小于src
	if (dest < src)//数组的存放顺序是从低地址到高地址
	{
		while (num--)
		{
			*((char*)dest) = *((char*)src);
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	//2. 从后往前复制
	// 当dest大于src且有交集或者当src和dest两者无交集时
	else
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return ret; //函数必须返回一个void* 类型的指针，返回目的地dest
}

int main()
{
	int arr1[20] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[20] = { 0 };

	//模拟实现memcpy函数（无重叠的部分中需要复制时使用该函数）
	My_memcpy(arr2, arr1+4, 20);//src为源头，源头是要被复制的，不能改变，dest为目的地，目的地是要被改变的

	//模拟实现memmove函数（出现在同一个数组中或其他形式重叠内存区域需要复制时，使用该函数）
	My_memmove(arr1+2, arr1, 20);

	//打印menmove函数的结果
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}

	printf("\n");

	//打印memcpy函数的结果
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr2[i]);
	}

	printf("\n");

	return 0;
}