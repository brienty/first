#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*
	喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以喝多少汽水
*/

int main()
{
	int money = 0;
	int empty = 0;
	int total = 0;
	scanf("%d", &money);
	
	//喝的汽水总量
	total += money;

	//剩下的空瓶数量
	empty += money;

	//空瓶置换
	while (empty > 1)
	{
		//每两个空瓶换一个汽水
		total += empty / 2;

		//统计剩下的空瓶数量
		empty = empty / 2 + empty % 2;
	}

	printf("%d\n", total);
	return 0;
}
/*
	这里还有一种方法
	根据计算情况来看，20块钱=40个空瓶
	然后经实际转换后，20块钱=39瓶汽水+1个空瓶
	所以喝的汽水量=money*2-1
	也就是可以写成
	total = money*2-1；
	即可
*/