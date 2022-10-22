#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main()
{
    string s;
    while (cin >> s)
    {
        long long sum = 0;
        for (int i = 0; i < s.size(); ++i)
            sum += s[i] - '0';
        long long num = 0;
        while (sum)
        {
            num += sum % 10;
            sum /= 10;
            //当num相加大于等于10时，重新继续相除，例如当sum==29时
            if (sum == 0 && num / 10 != 0)
            {
                sum = num;
                num = 0;
            }
        }
        cout << num << endl;
    }
    return 0;
}