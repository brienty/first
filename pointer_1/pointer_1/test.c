#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stu//定义结构
{
	char name[20];
	int age;
	float score;
};

void Print(int* s, int sz)//打印整形
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *s);
		s++;
	}
	printf("\n");
	printf("\n");
}

void Print_Stu(struct Stu arr[], int sz)//结构体中有内存间歇，不用指针
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%s %d %f\n", arr[i].name, arr[i].age, arr[i].score);
	}
}

int com_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
	//比较字符串需要用到strcmp函数，正好和strcmp的返回值一样
}

int com_age(const void *e1, const void *e2)//整数可以直接加减
{
	return ((((struct Stu*)e1)->age) - ((struct Stu*)e2)->age);
}

int com_score(const void* e1, const void* e2)//分数相减以后出现小数，但是返回值是整形，直接返回容易出问题
{
	if ((((struct Stu*)e1)->score) > (((struct Stu*)e2)->score))
	{
		return 1;
	}
	else if ((((struct Stu*)e1)->score) > (((struct Stu*)e2)->score))
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int com_t(const void* e1, const void* e2)//整形比较
{
	return ((*(int*)e1) - (*(int*)e2));
}

//void test1()
//{
//	int arr[10] = { 2,7,3,9,4,6,1,5,10,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int width = sizeof(arr[0]);
//	//使用qsort排序整形（快速排序法）
//	qsort(arr, sz, width, com_t);
//	Print(arr, sz);
//
//	struct Stu arr[] = { {"zhangsan",19,86.5f}, {"lisi",17,88.0f}, {"wangwu",20,97.5f} };
//	//初始化结构体数组
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//求个数
//	int width = sizeof(arr[0]);
//	//求单个元素大小 
//
//	qsort(arr, sz, width, com_name);
//	Print_Stu(arr, sz);
//	printf("\n");
//
//	qsort(arr, sz, width, com_age);
//	Print_Stu(arr, sz);
//	printf("\n");
//
//	qsort(arr, sz, width, com_score);
//	printf("\n");
//	Print_Stu(arr, sz);
//}





/*
* 实现该排序算法时采用强制转化为char*更加灵活，可以很好的比较每个类型
* 使用 (j*width)这种方式就是为了更好的去比较不同类型的数据
* 当交换时考虑到不同函数的字节数不同，所以直接采用单个字节的比较方式
* 所以需要传输单个数据类型的大小
*/
void swap(char *s1, char *s2, int width)
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

void Bubble_sort(void *base, int sz, int width, int (*com) (const void *e1, const void *e2))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (com((char*)base+(j*width), (char*)base+((j+1)*width)) > 0)
			{
				swap((char*)base + (j * width), (char*)base + ((j + 1) * width), width);
			}
		}
	}
}

void test2()
{
	int arr[10] = { 2,6,9,4,1,5,8,10,7,3 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//元素个数
	int width = sizeof(arr[0]);
	//单个元素大小
	Bubble_sort(arr, sz, width, com_t);
	//冒泡排序，需要排其他数据只需要更改com_t这个比较函数
	Print(arr, sz);
	//打印数组
}

//void test3()
//{
//	struct Stu arr[] = { {"zhangsan",19,86.5f}, {"lisi",17,88.0f}, {"wangwu",20,97.5f} };
//	//初始化结构体数组
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//求个数
//	int width = sizeof(arr[0]);
//	//求单个元素大小 
//	
//	Bubble_sort(arr, sz, width, com_name);
//	Print_Stu(arr, sz);
//	printf("\n");
//	
//	Bubble_sort(arr, sz, width, com_age);
//	Print_Stu(arr, sz);
//	printf("\n");
//	
//	Bubble_sort(arr, sz, width, com_score);
//	printf("\n");
//	Print_Stu(arr, sz);
//}

int main()
{
	//使用qsort排序结构体数据
	//test1();

	//模仿qsort实现一个冒泡排序算法
	test2();

	//使用Bubble_sort排序结构体数据
	//test3();
	return 0;
}