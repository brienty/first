#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    //����n������
    vector<int> v;
    int n = 0;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < v.size(); ++i)
    {
        int in = 0;
        cin >> in;
        v[i] = in;
    }
    //ʹ��ret���ҵ���ʼλ�ã�sum���洢����������ĺ�
    int sum = 0;
    int ret = 0;
    //�����������
    for (auto e : v)
    {
        //���ret���������Ԫ�ص��ڸ�����˵����λ�ò�����ʼλ��
        if (ret + e < 0)
            ret = 0;
        else
            //�ҵ���ʼλ���Ժ󣬾�����ret�ϼ���ȥ
            ret += e;
        //���sum��ret������һ����Ϊ����������������
        sum = max(ret, sum);
    }
    //sum������0˵�����ں�����������
    if (sum != 0)
        cout << sum;
    else
    {
        //���sum����0��˵��������ȫ��Ϊ�������򷵻������Ǹ�����
        sort(v.begin(), v.end());
        cout << v[v.size() - 1];
    }
    return 0;
}