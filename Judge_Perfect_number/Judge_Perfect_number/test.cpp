#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

bool JudgePerfect(int num)
{
    vector<int> v;//�洢Լ��
    int i = 0, sum = 0;
    //�ж�Լ��
    for (int i = 1; i < num; ++i)
        if (num % i == 0)
            v.push_back(i);
    //��Լ�����
    for (int i = 0; i < v.size(); ++i)
        sum += v[i];
    //����͵���num����ô���������ȫ��
    if (sum == num)
        return true;
    return false;
}

int main()
{
    int n = 0, count = 0;
    cin >> n;
    for (int i = 4; i <= n; ++i)
        if (JudgePerfect(i))
            ++count;
    cout << count << endl;
    return 0;
}