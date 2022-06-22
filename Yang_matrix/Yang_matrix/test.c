#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define N 3

/*
��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ�����
���д�����������ľ����в���ĳ�������Ƿ���ڡ�����ĳ�����֣�
Ҫ��ʱ�临�Ӷ�С��O(N);
*/


/*
˼·��
	1��2��3
	4��5��6
	7��8��9
	�ȴ����Ͻǻ������½ǿ�ʼ�ң����԰�ʱ�临�Ӷȴ�O(N)����
	ͨ����ַ����ʹ���ܹ��������
	��һά�������������ö��ֲ��Ҹ��ʺ�
	�ڶ�ά������ʹ�����ַ������ʺ�

*/
void Fine_num(int arr[N][N], int* px, int* py, int num)
{
	//��ʼ��Ϊ���Ͻ�����
	int x = 0;
	int y = *py - 1;

	//��������
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

	//���ò����ܵ����ֵ��Ϊ�������ж�
	*px = -1;
	*py = -1;

}

int main()
{
	int arr[N][N] = { {1,2,3}, {4,5,6}, {7,8,9} };
	int x = N;
	int y = N;

	//����������
	int num = 0;
	scanf("%d", &num);

	//���Һ���
	Fine_num(arr, &x, &y, num);
	
	if (x == -1 && y == -1)
	{
		printf("�Ҳ�����\n");
	}
	else
	{
		printf("�ҵ��ˣ���x=%d y=%d\n", x, y);
	}
	return 0;
}