#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int binInsert(int n, int m, int j, int i) {
    //��m�Ķ�����λ����j������λ����Ҫ����λ�õĳ�ʼλ�ö���
    m <<= j;
    //���m������λ�ϵ�1���n����
    return n |= m;
}

int main()
{
    cout << binInsert(1024, 19, 2, 6);
	return 0;
}