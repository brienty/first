#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int calculate(int i, int j, int n, int m)
{
    //当i等于n，j等于m时，则说明到了边界，只有一种走法
    if (i == n || j == m)
        return 1;
    //否则i可以向前走，也可以向下走
    return calculate(i + 1, j, n, m) + calculate(i, j + 1, n, m);
}

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    //采用递归，从左上角顶点开始
    cout << calculate(0, 0, n, m) << endl;;
}