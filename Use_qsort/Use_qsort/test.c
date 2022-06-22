#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�ض���Ϊ�˸�����
typedef struct Stu
{
	char name[10];
	char gender[4];
	int age;
	float score;
}stu;

//��ӡ�ṹ�庯��
void Print(stu arr[], int sz)//ʹ�������������ָ������Ϊ�ṹ���ʴ����ڴ��϶
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%s %s %d %.1f\n", arr[i].name, arr[i].gender, arr[i].age, arr[i].score);//arr[]����Ϊ�ҵ��˸�Ԫ�أ������ǵ�ַ�������õ����ʾ��ͷ
	}
	printf("\n");
}


//���ֱȽϺ���
int com_name(const void* e1, const void* e2)
{
	return strcmp(((stu*)e1)->name, ((stu*)e2)->name);
}

//�Ա�ȽϺ���
int com_gender(const void* e1, const void* e2)
{
	return strcmp(((stu*)e1)->gender, ((stu*)e2)->gender);
}

//����ȽϺ��� 
int com_age(const void* e1, const void* e2)
{
	return ((((stu*)e1)->age) - (((stu*)e2)->age));
}

//�����ȽϺ���
int com_score(const void* e1, const void* e2)
{
	//��Ϊ�������õ������Σ��������Ǹ����ͣ�����ֱ���������
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
	stu arr[] = { {"zhangsan", "��", 19, 89.0f}, {"lisi","Ů", 17, 100.0f}, {"wangwu", "��", 20, 67.5f} };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int width = sizeof(arr[0]);

	//ʹ��qsort����
	printf("����������\n");
	qsort(arr, sz, width, com_name);
	Print(arr, sz);

	printf("���Ա�����\n");
	qsort(arr, sz, width, com_gender);
	Print(arr, sz);

	printf("����������\n");
	qsort(arr, sz, width, com_age);
	Print(arr, sz);

	printf("����������\n");
	qsort(arr, sz, width, com_score);
	Print(arr, sz);

	return 0;
}