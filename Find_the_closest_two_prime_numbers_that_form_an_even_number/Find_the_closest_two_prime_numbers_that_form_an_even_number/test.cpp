#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

//判断素数，由于输入大于所以不需要判断2以下的数
bool isprime(int num)
{
    int s = sqrt(num);
    for (int i = 2; i <= s; ++i)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    //p1存储较小的那个素数，p2存储较大的那个素数
    int num = 0, p1 = 0, p2 = 0;
    cin >> num;
    //i到偶数的一半进行判断即可
    for (int i = 2; i <= num / 2; ++i)
    {
        //d存储减出来后较大的那个数
        int d = num - i;
        //第一次初始化
        if (i == 2)
        {
            p1 = i;
            p2 = d;
        }
        //只有两个数都是素数并d-i的差要比p2-p1差要小才是我们要找的两个素数
        if (isprime(i) && isprime(d) && ((d - i) < (p2 - p1)))
        {
            p1 = i;
            p2 = d;
        }
    }
    cout << p1 << endl << p2 << endl;
    return 0;
}