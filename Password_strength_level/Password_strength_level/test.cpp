#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    //sumͳ���ܷ֣�numͳ�����֣�otherͳ�Ʒ��ţ�Letterͳ�ƴ�д��ĸ��letterͳ��Сд��ĸ
    int sum = 0, num = 0, other = 0, Letter = 0, letter = 0;
    //����
    if (s.size() <= 4)
        sum += 5;
    else if (s.size() > 4 && s.size() < 8)
        sum += 10;
    else
        sum += 25;
    //������ĸ�����֣�����
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] >= '0' && s[i] <= '9')
            ++num;
        else if (s[i] >= 'a' && s[i] <= 'z')
            ++letter;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            ++Letter;
        else
            ++other;
    }
    //������ĸ
    if (Letter != 0 && letter != 0)
        sum += 20;
    else if ((Letter == 0 && letter != 0) || (Letter != 0 && letter == 0))
        sum += 10;
    //��������
    if (num == 1)
        sum += 10;
    else if (num > 1)
        sum += 20;
    //�������
    if (other == 1)
        sum += 10;
    else if (other > 1)
        sum += 25;
    //����
    if (num != 0 && (Letter != 0 || letter != 0) && other == 0)
        sum += 2;
    //��Ҫע��������ȣ������������ǰ��ֻҪ����ĸ�ͻ��ȥ
    else if (num != 0 && Letter != 0 && letter != 0 && other != 0)
        sum += 5;
    else if (num != 0 && (Letter != 0 || letter != 0) && other != 0)
        sum += 3;
    //���
    if (sum >= 90)
        cout << "VERY_SECURE" << endl;
    else if (sum >= 80 && sum < 90)
        cout << "SECURE" << endl;
    else if (sum >= 70 && sum < 80)
        cout << "VERY_STRONG" << endl;
    else if (sum >= 60 && sum < 70)
        cout << "STRONG" << endl;
    else if (sum >= 50 && sum < 60)
        cout << "AVERAGE" << endl;
    else if (sum >= 25 && sum < 50)
        cout << "WEAK" << endl;
    else if (sum >= 0 && sum < 25)
        cout << "VERY_WEAK" << endl;
    return 0;
}