#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int getLCA(int a, int b) {
    while (a != b)
        //�ý�����ĳ���2
        a > b ? a /= 2 : b /= 2;
    return a;
}

int main()
{
    cout << getLCA(10373, 198918);
    return 0;
}