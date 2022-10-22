#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int binInsert(int n, int m, int j, int i) {
    //将m的二进制位左移j个比特位，和要插入位置的初始位置对其
    m <<= j;
    //最后将m二进制位上的1或给n即可
    return n |= m;
}

int main()
{
    cout << binInsert(1024, 19, 2, 6);
	return 0;
}