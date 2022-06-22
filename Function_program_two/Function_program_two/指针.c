#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int My_strlen(char* s)
{
	if (*s != '\0')
	{
		return 1 + My_strlen(s + 1);
	}
	else
	{
		return 0;
	}
}
Reverse_string(char arr[], int str)
{
	int left = 0;
	while (left < str)
	{
		char temp = arr[left];
		arr[left] = arr[str];
		arr[str] = temp;
		left++;
		str--;
	}
}
int main()
{
	char arr[] = "abcdef";
	int str = My_strlen(arr) - 1;
	Reverse_string(arr,str);
	printf("%s\n", arr);
	return 0;
}