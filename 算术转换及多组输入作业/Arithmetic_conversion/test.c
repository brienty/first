#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
/*
* 表达式(++i)+(++i)+(++i)，只有操作符的优先级和结合性，没法确定唯一计算路径
* 所以这个表达式可能因为计算顺序的差异导致结果是不一致的，所以表达式是错误的表达式
* 可以在VS和Linux gcc测试，结果可能有差异
*/
int main()
{
	int i = 1;
	int ret = (++i) + (++i) + (++i);
	printf("ret = %d\n", ret);//VS中答案是12
	return 0;
}