#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//判断是否是长度排序
bool judegelengthsoder(const vector<string>& v)
{
    for (int i = 0; i < v.size() - 1; ++i)
    {
        if (v[i].size() > v[i + 1].size())
            return false;
    }
    return true;
}

//判断是否是字典排序
bool judgelexicographicaloder(const vector<string>& v)
{
    for (int i = 0; i < v.size() - 1; ++i)
    {
        //string重载了>
        if (v[i] > v[i + 1])
            return false;
    }
    return true;
}

int main()
{
    //读取并初始化
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
    //判断
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