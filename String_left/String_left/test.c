#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*
ʵ��һ�����������������ַ����е�k���ַ���
���磺
ABCD����һ���ַ��õ�BCDA
ABCD���������ַ��õ�CDAB
*/


void Left1(char arr[], int sz, int k)
{
	int i = 0;
	for (i = 0; i < k; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1; j++)
		{
			//��ֹ'\0'�����ַ�û��
			if (arr[j + 1] != '\0')
			{
				char temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void Left2(char* s, int sz, int k)
{
	int i = 0;
	for (i = 0; i < k; i++)
	{
		//��תһ��
		char temp = *s;
		int j = 0;
		for (j = 0; j < sz - 1; j++)
		{
			*(s + j) = *(s + j + 1);
		}
		*(s + sz - 1) = temp;
	}
}


void  reverse(char* left, char* right)
{
	while (left < right)
	{
		char temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}

//������
void Left3(char* s, int sz, int k)
{
	//��ֹԽ�磬�Ͼ�̫��Ҳ���ڽ����ظ�����
	k %= sz;

	reverse(s, s+k);
	reverse(s + k, s + sz - 1);
	reverse(s, s + sz - 1);
}

int main()
{
	char arr[] = "abcdefjhijk";
	int k = 0;
	scanf("%d", &k);
	int sz = sizeof(arr) / sizeof(arr[0]);
	
	//��һ�ַ�������
	Left1(arr, sz, k);

	//�ڶ��ַ���ָ��
	Left2(arr, sz, k);

	//�����ַ������ֱ���ת�����������ת
	Left3(arr, sz, k);



	printf("%s\n", arr);
	return 0;
}