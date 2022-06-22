#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define N 10
int main()
{
    int arr[N][N] = { 0 };
    int i = 0;
    for (i = 0; i < N; i++)
    {
        int k = 0;
        for (k = 0; k < N - 1 - i; k++)
        {
            printf(" ");
        }
        int j = 0;
        for (j = 0; j < i; j++)
        {
            if (j == 0)
            {
                arr[i][j] = 1;
            }
            if (i == j)
            {
                arr[i][j] = 1;
            }
            if (i > 1)
            {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}