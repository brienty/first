#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stu//����ṹ
{
	char name[20];
	int age;
	float score;
};

void Print(int* s, int sz)//��ӡ����
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

void Print_Stu(struct Stu arr[], int sz)//�ṹ�������ڴ��Ъ������ָ��
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
	//�Ƚ��ַ�����Ҫ�õ�strcmp���������ú�strcmp�ķ���ֵһ��
}

int com_age(const void *e1, const void *e2)//��������ֱ�ӼӼ�
{
	return ((((struct Stu*)e1)->age) - ((struct Stu*)e2)->age);
}

int com_score(const void* e1, const void* e2)//��������Ժ����С�������Ƿ���ֵ�����Σ�ֱ�ӷ������׳�����
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

int com_t(const void* e1, const void* e2)//���αȽ�
{
	return ((*(int*)e1) - (*(int*)e2));
}

//void test1()
//{
//	int arr[10] = { 2,7,3,9,4,6,1,5,10,8 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int width = sizeof(arr[0]);
//	//ʹ��qsort�������Σ��������򷨣�
//	qsort(arr, sz, width, com_t);
//	Print(arr, sz);
//
//	struct Stu arr[] = { {"zhangsan",19,86.5f}, {"lisi",17,88.0f}, {"wangwu",20,97.5f} };
//	//��ʼ���ṹ������
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//�����
//	int width = sizeof(arr[0]);
//	//�󵥸�Ԫ�ش�С 
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
* ʵ�ָ������㷨ʱ����ǿ��ת��Ϊchar*���������ԺܺõıȽ�ÿ������
* ʹ�� (j*width)���ַ�ʽ����Ϊ�˸��õ�ȥ�Ƚϲ�ͬ���͵�����
* ������ʱ���ǵ���ͬ�������ֽ�����ͬ������ֱ�Ӳ��õ����ֽڵıȽϷ�ʽ
* ������Ҫ���䵥���������͵Ĵ�С
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
	//Ԫ�ظ���
	int width = sizeof(arr[0]);
	//����Ԫ�ش�С
	Bubble_sort(arr, sz, width, com_t);
	//ð��������Ҫ����������ֻ��Ҫ����com_t����ȽϺ���
	Print(arr, sz);
	//��ӡ����
}

//void test3()
//{
//	struct Stu arr[] = { {"zhangsan",19,86.5f}, {"lisi",17,88.0f}, {"wangwu",20,97.5f} };
//	//��ʼ���ṹ������
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	//�����
//	int width = sizeof(arr[0]);
//	//�󵥸�Ԫ�ش�С 
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
	//ʹ��qsort����ṹ������
	//test1();

	//ģ��qsortʵ��һ��ð�������㷨
	test2();

	//ʹ��Bubble_sort����ṹ������
	//test3();
	return 0;
}