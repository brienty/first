#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//�ж��Ƿ��ǳ�������
bool judegelengthsoder(const vector<string>& v)
{
    for (int i = 0; i < v.size() - 1; ++i)
    {
        if (v[i].size() > v[i + 1].size())
            return false;
    }
    return true;
}

//�ж��Ƿ����ֵ�����
bool judgelexicographicaloder(const vector<string>& v)
{
    for (int i = 0; i < v.size() - 1; ++i)
    {
        //string������>
        if (v[i] > v[i + 1])
            return false;
    }
    return true;
}

int main()
{
    //��ȡ����ʼ��
    int num = 0;
    cin >> num;
    vector<string> v;
    v.resize(num);
    for (int i = 0; i < num; ++i)
    {
        string s;
        cin >> s;
        v[i] = s;
    }
    //�ж�
    if (judegelengthsoder(v) && judgelexicographicaloder(v))
        cout << "both" << endl;
    else if (!judegelengthsoder(v) && judgelexicographicaloder(v))
        cout << "lexicographically" << endl;
    else if (judegelengthsoder(v) && !judgelexicographicaloder(v))
        cout << "lengths" << endl;
    else
        cout << "none" << endl;
    return 0;
}