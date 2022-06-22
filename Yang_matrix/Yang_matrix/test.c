#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define N 3

/*
有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的
请编写程序在这样的矩阵中查找某个数字是否存在。（找某个数字）
要求：时间复杂度小于O(N);
*/


/*
思路：
	1，2，3
	4，5，6
	7，8，9
	先从右上角或者左下角开始找，可以把时间复杂度从O(N)缩短
	通过传址可以使其能够更加灵活
	在一维数组中找数字用二分查找更适合
	在二维数组中使用这种方法更适合

*/
void Fine_num(int arr[N][N], int* px, int* py, int num)
{
	//初始化为右上角坐标
	int x = 0;
	int y = *py - 1;

	//查找数字
	while (x >= 0 && y < N)
	{
		if (arr[x][y] < num)
		{
			x++;
		}
		else if (arr[x][y] > num)
		{
			y--;
		}
		else
		{
			*px = x;
			*py = y;
			return;
		}
	}

	//设置不可能到达的值，为了区别并判断
	*px = -1;
	*py = -1;

}

int main()
{
	int arr[N][N] = { {1,2,3}, {4,5,6}, {7,8,9} };
	int x = N;
	int y = N;

	//待查找数字
	int num = 0;
	scanf("%d", &num);

	//查找函数
	Fine_num(arr, &x, &y, num);
	
	if (x == -1 && y == -1)
	{
		printf("找不到！\n");
	}
	else
	{
		printf("找到了！，x=%d y=%d\n", x, y);
	}
	return 0;
}