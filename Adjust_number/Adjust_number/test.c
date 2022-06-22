#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#define N 10

/*
    ��Ŀ��
    ����һ���������飬ʵ��һ��������
    �����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
    ����ż��λ������ĺ�벿�֡�
*/

//��������˳�򽻻����ӵ�һ��Ԫ�ؿ�ʼ�����
void Adjust1(int arr1[])
{
    int i = 0;
    int j = 0;
    for (i = 0; i < N; i++)
    {
        if (arr1[i] % 2 == 1)
        {
            int temp = arr1[i];
            arr1[i] = arr1[j];
            arr1[j] = temp;
            ++j;
        }
    }
    
}

//ʹ��ָ�룬����ͷ��ʼ����
void Adjust2(int* L)
{
    int* R = L + N - 1;
    while (L < R)
    {
        //�����ż��
        while (*L % 2 == 1  && L < R)
        {
            L++;
        }

        //�ұ�������
        while (*R % 2 == 0 && L < R)
        {
            R--;
        }

        //�жϵ�L����Rʱ����ֹ����ȷ��˳����
        if (L < R)
        {
            int temp = *R;
            *R = *L;
            *L = temp;
        }

    }
}


int main()
{
    int arr1[N] = { 1,2,3,4,5,6,7,8,9,10 };
    int arr2[N] = { 1,2,3,4,5,6,7,8,9,10 };
    
    Adjust1(arr1);//��һ�ַ���

    Adjust2(arr2);//�ڶ��ַ���
    
    int i = 0;
    
    //��ӡarr1����
    for (i = 0; i < N; ++i)
    {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    
    //��ӡarr2����
    for (i = 0; i < N; ++i)
    {
        printf("%d ", arr2[i]);
    }
    printf("\n");
}