#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <math.h>
using namespace std;

//ÅÐ¶ÏËØÊý
bool isPrime(int number)
{
    if (number < 2)
        return false;
    int ret = (int)sqrt(number);
    for (int i = 2; i <= ret; ++i)
        if (number % i == 0)
            return false;
    return true;
}

int main()
{
    int x = 0, y = 0;
    while (cin >> x >> y)
    {
        if (x == 0 && y == 0)
            break;
        int flag = 1;
        for (int i = x; i <= y; ++i)
        {
            int temp = i * i + i + 41;
            if (!isPrime(temp))
            {
                cout << "Sorry" << endl;
                flag = 0;
                break;
            }
        }
        if (flag)
            cout << "OK" << endl;
    }
    return 0;
}