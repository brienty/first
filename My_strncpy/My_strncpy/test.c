#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

char* My_strncpy(char* dest, const char* src, size_t num)
{
	char* temp = dest;

	assert(dest && src);//�ճ��пջ���

	//���Ŀ�ĵ��ַ����ǿ��ַ���ֱ�ӷ���
	if (*dest == '\0')
	{
		return temp;
	}
	
	//����
	while (num--)
	{
		*dest = *src;
		dest++;
		src++;

		//��src��'\0'˵������С�ڵ���num
		if (*src == '\0')
		{
			break;
		}
	}

	//���������ַ�������С��numʱ����'\0'����ʣ�µ�����
	if (*src == '\0')
	{
		while (num--)
		{
			*dest = '\0';
		}
	}

	return temp;

}

int main()
{
	char arr1[30] = "abcdefg";
	char arr2[] = "123456789";

	//����Ҫ���Ƶĸ���
	int num = 0;
	scanf("%d", &num);

	//ģ��ʵ��strncpy
	printf("%s\n", My_strncpy(arr1, arr2, num));

	return 0;
}