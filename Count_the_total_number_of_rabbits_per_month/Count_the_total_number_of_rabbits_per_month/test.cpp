#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <math.h>
using namespace std;

int main() {
    //쳲��������У��ӵڶ����¿�ʼ����
    int month = 0, num1 = 1, num2 = 1, num3 = 0;
    cin >> month;
    if (month == 1 || month == 2)
        return 1;
    for (int i = 2; i < month; ++i)
    {
        num3 = num1 + num2;
        num1 = num2;
        num2 = num3;
    }
    cout << num3 << endl;
    return 0;
}