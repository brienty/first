#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

/*
第一行包含一个正整数n，表示老师给出的序列有n个数。
接下来有n行，每行一个正整数k，为序列中每一个元素的值。(1 ≤ n ≤ 105，1 ≤ k ≤ n)
输出描述：
输出一行，为去重排序后的序列，每个数后面有一个空格。

示例1									示例2
输入：									输入：
4										5
2										5
2										4
1										3
1										2
输出：									1
1 2										输出：
										1 2 3 4 5
*/



/*
	思路：典型的桶排序问题
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