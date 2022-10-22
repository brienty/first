#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

int gcd(int num1, int num2) {
    return (num2 ? gcd(num2, num1 % num2) : num1);
}

int main() {
    int quantity = 0, ability = 0;
    while (cin >> quantity >> ability) {
        vector<int> v(quantity);
        for (int i = 0; i < quantity; ++i)
            cin >> v[i];
        for (int i = 0; i < v.size(); ++i) {
            if (v[i] <= ability)
                ability += v[i];
            else
                ability += gcd(v[i], ability);
        }
        cout << ability << endl;
    }

    return 0;
}


#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    int array[128] = { 0 };//字符只有128个
    //将字符映射到数组上
    for (int i = 0; i < s.size(); ++i) {
        ++array[s[i]];
    }
    int count = 0;//统计>=2的字符
    for (int i = 0; i < s.size(); ++i) {
        //当映射下标的数组等于1时，即是我们要找的字符
        if (array[s[i]] == 1) {
            cout << s[i] << endl;
            break;
        }
        //没有进入if则一直++count
        ++count;
    }
    //当count等于字符串的大小时说明全部出现的次数都>=2，那么返回-1
    if (count == s.size())
        cout << -1 << endl;
    return 0;
}