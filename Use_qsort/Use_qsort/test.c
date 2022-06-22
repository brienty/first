#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//重定义为了更方便
typedef struct Stu
{
	char name[10];
	char gender[4];
	int age;
	float score;
}stu;

//打印结构体函数
void Print(stu arr[], int sz)//使用数组而不适用指针是因为结构体帐存在内存间隙
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%s %s %d %.1f\n", arr[i].name, arr[i].gender, arr[i].age, arr[i].score);//arr[]是因为找到了该元素，而不是地址，所以用点而表示箭头
	}
	printf("\n");
}


//名字比较函数
int com_name(const void* e1, const void* e2)
{
	return strcmp(((stu*)e1)->name, ((stu*)e2)->name);
}

//性别比较函数
int com_gender(const void* e1, const void* e2)
{
	return strcmp(((stu*)e1)->gender, ((stu*)e2)->gender);
}

//年龄比较函数 
int com_age(const void* e1, const void* e2)
{
	return ((((stu*)e1)->age) - (((stu*)e2)->age));
}

//分数比较函数
int com_score(const void* e1, const void* e2)
{
	//因为返回设置的是整形，而分数是浮点型，不能直接相减返回
	if ((((stu*)e1)->score) - (((stu*)e2)->score) > 0)
	{
		return 1;
	}
	else if ((((stu*)e1)->score) - (((stu*)e2)->score) < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	stu arr[] = { {"zhangsan", "男", 19, 89.0f}, {"lisi","女", 17, 100.0f}, {"wangwu", "男", 20, 67.5f} };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int width = sizeof(arr[0]);

	//使用qsort排序
	printf("按名字排序：\n");
	qsort(arr, sz, width, com_name);
	Print(arr, sz);

	printf("按性别排序：\n");
	qsort(arr, sz, width, com_gender);
	Print(arr, sz);

	printf("按年龄排序：\n");
	qsort(arr, sz, width, com_age);
	Print(arr, sz);

	printf("按分数排序：\n");
	qsort(arr, sz, width, com_score);
	Print(arr, sz);

	return 0;
}