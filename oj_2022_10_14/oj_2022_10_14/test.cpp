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
    int array[128] = { 0 };//�ַ�ֻ��128��
    //���ַ�ӳ�䵽������
    for (int i = 0; i < s.size(); ++i) {
        ++array[s[i]];
    }
    int count = 0;//ͳ��>=2���ַ�
    for (int i = 0; i < s.size(); ++i) {
        //��ӳ���±���������1ʱ����������Ҫ�ҵ��ַ�
        if (array[s[i]] == 1) {
            cout << s[i] << endl;
            break;
        }
        //û�н���if��һֱ++count
        ++count;
    }
    //��count�����ַ����Ĵ�Сʱ˵��ȫ�����ֵĴ�����>=2����ô����-1
    if (count == s.size())
        cout << -1 << endl;
    return 0;
}