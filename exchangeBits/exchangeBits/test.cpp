#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//思路：
//因为一个数字的值就是二进制位的每个 1 相加，所以
//把偶数位和奇数位分别提取出来

int exchangeBits(int num) {
    //num按位与这个数字(01010101010101010101010101010101)会得到奇数位
    int n1 = (num & 0x55555555) << 1;
    //num按位与这个数字(10101010101010101010101010101010)会得到偶数位
    int n2 = (num & 0xaaaaaaaa) >> 1;
    //将奇数位左移1位，偶数位右移1位再相加即得到交换后的值
    return n1 + n2;
}

int main()
{
    cout << exchangeBits(11);
	return 0;
}