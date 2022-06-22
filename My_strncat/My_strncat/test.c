#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

char* My_strncat(char* dest, const char* src, size_t num)
{
	assert(dest && src);//�п�

	char* temp = dest;//��Ҫ����Ŀ�ĵ���ʼλ��

	//�ҽ�����־
	while (*dest != '\0')
	{
		dest++;
	}
	
	//��ʼ׷��
	while (num--)
	{
		*dest = *src;
		dest++;
		src++;
		if (*src == '\0')
		{
			*dest = *src;
			break;
		}
	}
	if (*dest != '\0')
	{
		*dest = '\0';
	}

	return temp;
}


int main()
{
	char arr1[30] = "abcdefg";
	char arr2[] = "qwer";

	//����Ҫ׷�ӵĳ���
	int num = 0;
	scanf("%d", &num);

	//ģ��ʵ��strncat����
	printf("%s\n", My_strncat(arr1, arr2, num));

	return 0;
}