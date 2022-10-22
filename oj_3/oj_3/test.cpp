#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int pos = 0;
    int count = 0;
    string s2;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            pos = i;
        }
        while (s[i] >= '0' && s[i] <= '9')
        {
            ++count;
            ++i;
        }
        if (s2.size() < count)
        {
            s2 = s.substr(pos, count);
        }
        count = 0;

    }
    cout << s2;
    return 0;
}
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        //统计每个数字出现的次数
        int array[10001] = { 0 };
        for (int i = 0; i < numbers.size(); ++i)
        {
            ++array[numbers[i]];
        }
        //遍历数组，将大于一半长度的输出
        for (int i = 0; i < 10001; ++i)
        {
            if (array[i] > numbers.size() / 2)
            {
                return i;
            }
        }
        //处理只有一个数字的情况
        return numbers[0];
    }
};