#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
double fact(int n);
int main()
{
    int i = 1;
    double x, item, s = 0;
    printf("输入x的值：");
    scanf("%lf", &x);
    item = x;
    while (fabs(item) >= 0.00001)
    {
        s = s + item;
        i++;
        item = pow(x, i) / fact(i);
    }
    printf("和是:%lf\n", s);
    return 0;
}
double fact(int n)
{
    int i;
    double jc = 1;
    for (i = 1; i <= n; i++)
        jc = jc * i;
    return jc;
}