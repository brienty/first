#define _CRT_SECURE_NO_WARNINGS 1
//���ֲ���/�۰�����㷨(ֻ����������)
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
			left  = mid + 1;//mid���Ǵ���ֵȡ�Ա��Ǹ���Ϊ��һ�����ҷ�Χ�ı߽�
						//��+1�������ֵ��������Ԫ�������Ǹ�����������ѭ��
		}
		else if (brr[mid] > i)
		{
			right = mid - 1;//����ͬ��ɵ�
		}
		else
		{
			printf("�ҵ��ˣ��±�Ϊ%d\n", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("�Ҳ���\n");
	}
	return 0;
}