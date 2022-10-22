#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    cin >> num;
    int count = 0;//存储最多1的个数 
    int tmp = 0;//存储1的个数
    for (int i = 0; i < 32; ++i)
    {
        //是1就++tmp
        if ((num & (1 << i)) != 0)
            ++tmp;
        //否则归0
        else
            tmp = 0;
        //如果tmp比count大，说明tmp的1更多
        if (tmp > count)
            count = tmp;
    }
    cout << count;
    return 0;
}