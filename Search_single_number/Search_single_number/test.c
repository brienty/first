#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
��дһ�������ҳ�������ֻ����һ�ε����֡�
*/


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumbers(int* nums, int numsSize, int* returnSize) {
    int ret = 0;
    int i = 0;
    int temp = 0;
    int m = 0;
    int n = 0;
    //����һ�������ռ�洢ֻ����һ�ε�����
    int* arr = (int*)malloc(sizeof(int) * 2);
    if (arr == NULL)
    {
        return;
    }
    //��ֻ����һ�ε��������һ��
    for (i = 0; i < numsSize; i++)
    {
        ret ^= nums[i];
    }
    //�����һ������ִ��ҵ���ʼ�Ҷ�����λΪ1��λ
    for (i = 0; i < 32; i++)
    {
        if (((ret >> i) & 1) == 1)
        {
            //�洢��temp��
            temp = i;
            break;
        }
    }
    //���ݸö�����λΪ1��λ���࣬�ҵ���һ��ֻ����һ�ε�����
    for (i = 0; i < numsSize; i++)
    {
        if (((nums[i] >> temp) & 1) == 1)
        {
            n ^= nums[i];
        }
    }
    //�ڶ���ֻ����һ�� ������
    m = ret ^ n;
    //�ŵ����ٵĿռ���
    arr[0] = m;
    arr[1] = n;
    //���ٵĿռ����������ֵĸ���
    *returnSize = 2;
    //���ؿ��ٵĿռ�
    return arr;
}

int main()
{
    int arr[] = { 1,2,3,4,5,1,2,3,4,6 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    int* returnSize = NULL;
    //��̬�ڴ�汾
    int* p = singleNumbers(arr, sz, returnSize);
    free(p);
    p = NULL;

    return 0;
}