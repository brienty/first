#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int calculate(int i, int j, int n, int m)
{
    //��i����n��j����mʱ����˵�����˱߽磬ֻ��һ���߷�
    if (i == n || j == m)
        return 1;
    //����i������ǰ�ߣ�Ҳ����������
    return calculate(i + 1, j, n, m) + calculate(i, j + 1, n, m);
}

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;
    //���õݹ飬�����ϽǶ��㿪ʼ
    cout << calculate(0, 0, n, m) << endl;;
}