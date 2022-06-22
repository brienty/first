#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

void* My_memcpy(void* dest, const void* src, size_t num)//num���ֽ���
{
	void* ret = dest;
	assert(dest && src);//�п�
	//����
	while (num--)
	{
		*(char*)dest = *(char*)src;//�������Ժ�����ݸ�ֵ��ȥ
		dest = (char*)dest + 1;//�������д��������ǿ������ת������ʱЧ�ԣ�ֻ���ڵ�ǰ��������Ч
		src = (char*)src + 1;
	}
	return ret;//�������뷵��һ��void*���͵�ָ�룬����Ŀ�ĵ�dest
}


void* My_memmove(void* dest, const void* src, size_t num)
{
	void* ret = dest;
	assert(dest && src);//�п�
	//1. ��ǰ������
	//��destС��src
	if (dest < src)//����Ĵ��˳���Ǵӵ͵�ַ���ߵ�ַ
	{
		while (num--)
		{
			*((char*)dest) = *((char*)src);
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	//2. �Ӻ���ǰ����
	// ��dest����src���н������ߵ�src��dest�����޽���ʱ
	else
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return ret; //�������뷵��һ��void* ���͵�ָ�룬����Ŀ�ĵ�dest
}

int main()
{
	int arr1[20] = { 1,2,3,4,5,6,7,8,9,10 };
	int arr2[20] = { 0 };

	//ģ��ʵ��memcpy���������ص��Ĳ�������Ҫ����ʱʹ�øú�����
	My_memcpy(arr2, arr1+4, 20);//srcΪԴͷ��Դͷ��Ҫ�����Ƶģ����ܸı䣬destΪĿ�ĵأ�Ŀ�ĵ���Ҫ���ı��

	//ģ��ʵ��memmove������������ͬһ�������л�������ʽ�ص��ڴ�������Ҫ����ʱ��ʹ�øú�����
	My_memmove(arr1+2, arr1, 20);

	//��ӡmenmove�����Ľ��
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}

	printf("\n");

	//��ӡmemcpy�����Ľ��
	for (i = 0; i < 5; i++)
	{
		printf("%d ", arr2[i]);
	}

	printf("\n");

	return 0;
}