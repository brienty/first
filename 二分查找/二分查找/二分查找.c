#define _CRT_SECURE_NO_WARNINGS 1
//二分查找/折半查找算法(只能用于有序)
#include <stdio.h>
int main()
{
	int brr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(brr) / sizeof(brr[0]);
	int i = 0;
	scanf("%d", &i);
	int left = 0;
	int right = sz - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (brr[mid] < i)
		{
			left  = mid + 1;//mid不是待猜值取旁边那个数为下一个查找范围的边界
						//不+1如果输入值大于数组元素最大的那个，则会出现死循环
		}
		else if (brr[mid] > i)
		{
			right = mid - 1;//与上同理可得
		}
		else
		{
			printf("找到了，下标为%d\n", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("找不到\n");
	}
	return 0;
}