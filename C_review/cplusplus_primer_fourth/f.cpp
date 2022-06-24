//#include "test.h"

//inline int Add(int l, int r)
//{
//	int sum = l + r;
//	return sum;
//}

#define _CRT_SECURE_NO_WARNINGS 1 

//#include <stdio.h>
//#include <assert.h>
//#include <string.h>
//
////学生结构体
//typedef struct StuInfo {
//
//	char number[13];//学号
//	char name[21];//姓名
//	int subject1;//学科1
//	int subject2;//学科2
//	int subject3;//学科3
//}SI;
//
////成绩表结构体
//typedef struct grade_table{
//
//	SI data[100];//学生人数
//	int sz;//存放的数量
//}GT;
//
////初始化结构体
//void InitGT(GT* p)
//{
//	assert(p);
//	p->sz = 0;
//	//调用memset初始化学生信息结构体
//	memset(p->data, 0, sizeof(p->data));
//}
//
////添加学生成绩
//void AddGT(GT* p)
//{
//	assert(p);
//	//满了则不再添加
//	if (p->sz == 100)
//	{
//		return;
//	}
//
//	//否则继续添加
//	scanf("%s", p->data[p->sz].number);
//	scanf("%s", p->data[p->sz].name);
//	scanf("%d", &(p->data[p->sz].subject1));
//	scanf("%d", &(p->data[p->sz].subject2));
//	scanf("%d", &(p->data[p->sz].subject3));
//
//	//添加成功，学生+1
//	p->sz++;
//}
//
////成绩比较函数
//int com_subject(GT* p, int j, int i)
//{
//	if (i == 1)
//	{
//		return p->data[j].subject1 - p->data[j + 1].subject1;
//	}
//	if (i == 2)
//	{
//		return p->data[j].subject2 - p->data[j + 1].subject2;
//
//	}
//	//正常情况下到这应该就是输入3了
//	return p->data[j].subject3 - p->data[j + 1].subject3;
//}
//
////学号比较函数
//int com_number(GT* p, int j)
//{
//	return strcmp(p->data[j].number, p->data[j + 1].number);
//}
//
////采用冒泡思想排序
//void Bubble_sort(GT* p, int (*com)(GT* s, int num, int num2), int num2)
//{
//	int i = 0;
//	for (i = 0; i < p->sz - 1; i++)
//	{
//		int j = 0;
//		for (j = 0; j < p->sz - 1 - i; j++)
//		{
//			if (com_subject(p, j, num2) < 0)
//			{
//				SI temp = p->data[j];
//				p->data[j] = p->data[j + 1];
//				p->data[j + 1] = temp;
//			}
//			if (com_subject(p, j, num2) == 0)
//			{
//				if (com_number(p, j) > 0)
//				{
//					SI temp = p->data[j];
//					p->data[j] = p->data[j + 1];
//					p->data[j + 1] = temp;
//				}
//			}
//		}
//	}
//}
//
////排序函数
//void SortGT(GT* p, int i)
//{
//	assert(p);
//	Bubble_sort(p, com_subject, i);
//}
//
//void ShowGT(const GT* p)
//{
//	assert(p);
//
//	int i = 0;
//	for (i = 0; i < p->sz; i++)
//	{
//		printf("%s ", p->data[i].number);
//		printf("%s ", p->data[i].name);
//		printf("%d ", p->data[i].subject1);
//		printf("%d ", p->data[i].subject2);
//		printf("%d ", p->data[i].subject3);
//		printf("\n");
//	}
//}
//
//int main()
//{
//	GT t;
//	int number = 0;
//	scanf("%d", &number);
//
//	//初始化
//	InitGT(&t);
//
//	//添加学生信息
//	for (int i = 0; i < number; i++)
//	{
//		AddGT(&t);
//	}
//
//	int i = 0;
//	scanf("%d", &i);
//	
//	//排序
//	SortGT(&t, i);
//	//查看成绩表
//	ShowGT(&t);
//	return 0;
//}



#include <stdio.h>
void Merge(int* nums1, int m, int* nums2, int n) {
	int i = m - 1;
	int j = n - 1;
	int dest = m + n - 1;
	while (i >= 0 && j >= 0)
	{
		if (nums1[i] > nums2[j])
		{
			nums1[dest--] = nums1[i--];
		}
		else
		{
			nums1[dest--] = nums2[j--];
		}
	}


	while (j >= 0)
	{
		nums1[dest--] = nums2[j--];
	}
}

int removeDuplicates(int* nums, int numsSize) {
	int dest = 0;
	int src = 1;
	while (src < numsSize)
	{
		if (nums[src - 1] == nums[src])
		{
			src++;
		}
		else
		{
			nums[dest] = nums[src - 1];
			++dest;
			++src;
		}
	}


	nums[dest] = nums[src - 1];
	dest++;


	return dest;
}


int main()
{
	int num1 = 0;
	int num2 = 0;

	int arr1[100] = { 0 };
	int arr2[100] = { 0 };

	scanf("%d", &num1);
	//第一个数组
	for (int i = 0; i < num1; i++)
	{
		scanf("%d", &arr1[i]);
	}

	scanf("%d", &num2);
	//第二个数组
	for (int i = 0; i < num2; i++)
	{
		scanf("%d", &arr2[i]);
	}

	Merge(arr1, num1, arr2, num2);
	int sz = sizeof(arr1) / sizeof(arr1[0]);
	int num = removeDuplicates(arr1, sz);
	for (int i = 0; i < num - 1; i++)
	{
		printf("%d", arr1[i]);
		if (i < num - 1)
		{
			printf(" ");
		}
	}
	return 0;
}
