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

//���е�num���ֽ���
void* My_memcpy(void* dest, const void* src, size_t num)
{
	void* temp = dest;// ��Ҫ����Ŀ�ĵ�ָ��

	assert(dest && src);//�п�
	
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
	void* temp = dest;//����Ŀ�ĵ�ָ��

	assert(dest && src);//�п�

	//��destС��srcʱ����ǰ������
	if (dest < src)
	{
		while (num--)
		{
			*((char*)dest) = *((char*)src);
			(char*)dest = (char*)dest + 1;
			(char*)src = (char*)src + 1;
		}
	}
	//��dest����srcʱ���Ӻ���ǰ����
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
	//����My_memcpy����
	int arr1[20] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[5] = { 0 };

	//����My_memmove����
	int arr3[20] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };

	int num = 20;//�ֽ���

	int num2 = 20;//�ֽ���

	//����memory�����е�memcpy���������ص����ֵĽ���
	My_memcpy(arr2, arr1, num);
	
	//����memory�����е�memmove�����������ص�����
	My_memmove(arr3+3, arr3+4, num2);
	
	//����Print������ӡ
	Print(arr3, sizeof(arr3)/sizeof(arr3[0]));

	//����Print������ӡ
	Print(arr2, (num/sizeof(arr1[0])));

	return 0;
}