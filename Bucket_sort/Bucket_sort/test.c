#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*
��һ�а���һ��������n����ʾ��ʦ������������n������
��������n�У�ÿ��һ��������k��Ϊ������ÿһ��Ԫ�ص�ֵ��(1 �� n �� 105��1 �� k �� n)
���������
���һ�У�Ϊȥ�����������У�ÿ����������һ���ո�

ʾ��1									ʾ��2
���룺									���룺
4										5
2										5
2										4
1										3
1										2
�����									1
1 2										�����
										1 2 3 4 5
*/



/*
	˼·�����͵�Ͱ��������
*/

int main()
{
    int arr[1000] = { 0 };
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int temp = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        arr[temp] = temp;
    }
    for (i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            printf("%d ", arr[i]);
        }
    }
    return 0;
}