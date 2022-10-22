#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

const double p = 2 * 3.14;

int main()
{
    //必须使用double，使用其他类型要么小了，要么类型不匹配
    double height = 0.0, radius = 0.0;
    while (cin >> height >> radius)
    {
        if (height < p * radius)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}