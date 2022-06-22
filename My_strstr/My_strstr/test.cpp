#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>



char* My_strstr(const char* str, const char* substr)
{
	assert(str && substr);//判空
	
	//当被查找字符串是空字符串时无法查找，直接返回str
	if (*substr == '\0')
	{
		return (char*)str;//const修饰，返回char*指针需要强制类型转化
	}
	
	//为了能找到起始位置，让s1和s2动，本体不动
	const char* s1 = str;
	const char* s2 = substr;

	//记录当前可能找到的位置
	const char* cur = str;//const修饰了str类型需要一致

	//开始查找
	while (*cur)//当cur遍历到字符串的'\0'说明不可能找到了
	{
		s1 = cur;//使s1回到当前失败字符的下一个字符
		s2 = substr;//使s2回到起始位置
		while (*s1 && *s1 == *s2 && *s2)//如果*s1等于'\0'说明被查找字符串已经遍历完了，根据下面的if判断是否找到了
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')//*s2等于'\0'说明找到了，即返回字符串中的子字符串里的第一个字符的地址
		{
			return (char*)cur;//const修饰需要强制类型转化
		}
		cur++;//说明上一个位置不可能是能找到字串的位置，从下一个位置开始查找
	}
	return NULL;//找不到返回空指针

}

int main()
{
	char arr1[20] = "acdfacbbbcg";
	char arr2[10] = "bbc";

	printf("%s\n", My_strstr(arr1, arr2));

	return 0;
}