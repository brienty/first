#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//��������
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

//�ȽϺ���
int compare(const void* e1, const void* e2)
{
	return (*((int*)e1) - *((int*)e2));
}

//ģ��qsortʵ��bubble
void Bubble_sort(void* base, size_t num, size_t width, int(*cmpare)(const void* e1, const void* e2))
{
	int i = 0;
	for (i = 0; i < num - 1; i++)
	{
		int j = 0;
		for (j = 0; j < num - 1 - i; j++)
		{

			//��������ת����char*���͵�ָ������Ը�
			if (compare((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				//���뽫width����ȥ������ʹ�õ���char*���͵�ָ�룬���뱣֤һ���������е��ֽڶ�����
				swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}

//��ӡ����
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

	//��Ҫ���׵�ַ��Ԫ�ظ�����Ԫ�ش�С���ȽϷ�������
	Bubble_sort(arr, sizeof(arr)/sizeof(arr[0]), sizeof(arr[0]), compare);

	//��ӡ����
	Print(arr, sizeof(arr)/sizeof(arr[0]));
	
	return 0;
}