#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> v;
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if (nums[i] + nums[j] == target)
            {
                v.push_back(i);
                v.push_back(j);
                return v;
            }
        }
    }
    return v;
}


bool isPalindrome(int x) {
    //小于0一定不是回文
    if (x < 0)
        return false;
    //转成字符串判断
    string s = to_string(x);
    int begin = 0;
    int end = s.size() - 1;
    while (begin < end)
    {
        if (s[begin] != s[end])
            return false;
        ++begin;
        --end;
    }
    return true;
}


int romanToInt(string s) {
    int sum = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'I')
        {
            if (s[i + 1] == 'V')
            {
                sum += 4;
                ++i;
            }
            else if (s[i + 1] == 'X')
            {
                sum += 9;
                ++i;
            }
            else
            {
                sum += 1;
            }
        }
        else if (s[i] == 'V')
        {
            sum += 5;
        }
        else if (s[i] == 'X')
        {
            if (s[i + 1] == 'L')
            {
                sum += 40;
                ++i;
            }
            else if (s[i + 1] == 'C')
            {
                sum += 90;
                ++i;
            }
            else
            {
                sum += 10;
            }
        }
        else if (s[i] == 'L')
        {
            sum += 50;
        }
        else if (s[i] == 'C')
        {
            if (s[i + 1] == 'D')
            {
                sum += 400;
                ++i;
            }
            else if (s[i + 1] == 'M')
            {
                sum += 900;
                ++i;
            }
            else
            {
                sum += 100;
            }
        }
        else if (s[i] == 'D')
        {
            sum += 500;
        }
        else
        {
            sum += 1000;
        }
    }
    return sum;
}



string longestCommonPrefix(vector<string>& strs) {
    string tmp;
    //当strs为空字符串时返回""
    if (strs.empty())
    {
        return tmp;
    }
    //找到所有字符串中的长度最小的那个的大小
    int count = INT_MAX;//设置为整形的最大值方便查找
    for (int i = 0; i < strs.size(); ++i)
    {
        if (count > strs[i].size())
        {
            count = strs[i].size();
        }
    }
    //用长度最小字符串的字符串作为遍历字符的条件
    for (int i = 0; i < count; ++i)
    {
        int j = 0;
        for (; j < strs.size() - 1; ++j)
        {
            if (strs[j][i] != strs[j + 1][i])
                return tmp;
        }
        tmp += strs[j][i];
    }
    return tmp;
}


int lengthOfLastWord(string s) {
    int end = s.size() - 1;
    //跳掉后面的空格
    while (s[end] == ' ')
    {
        --end;
    }
    int count = 0;
    //从最后一个非空格字母开始计算，注意字符串中只有一个字母的时候，所以需要end大于等于0
    while (end >= 0 && s[end] != ' ')
    {
        ++count;
        --end;
    }
    return count;
}


vector<int> plusOne(vector<int>& digits) {
    int flag = 0;//进位
    digits[digits.size() - 1] += 1;//末位+1
    for (int i = digits.size() - 1; i >= 0; --i)
    {
        digits[i] += flag;//加上进位
        //大于十就需要进来处理进位
        if (digits[i] > 9)
        {
            flag = 1;//进位
            digits[i] %= 10;
            //当i等于0时需要我们手动往前+1
            if (i == 0)
                digits.insert(digits.begin(), 1);
        }
        else
            flag = 0;
    }
    return digits;
}


string addBinary(string a, string b) {
    int flag = 0;//进位
    int end1 = a.size() - 1;//获取最后一位
    int end2 = b.size() - 1;//获取最后一位
    string tmp;
    //当两个都遍历完才是真的完了
    for (; end1 >= 0 || end2 >= 0;)
    {
        int num = 0;
        //两个都没有遍历完
        if (end1 >= 0 && end2 >= 0)
            num = (a[end1] - '0') + (b[end2] - '0');
        //其中一个遍历完的情况
        else
            num = (end1 >= 0) ? (a[end1] - '0') : (b[end2] - '0');
        num += flag;//记得加上进位
        if (num > 1)
        {
            flag = 1;
            num %= 2;
        }
        else
            flag = 0;
        tmp.insert(0, 1, num + '0');
        //遍历完的不能减
        if (end1 >= 0)
            --end1;
        if (end2 >= 0)
            --end2;
    }
    //处理头顶相加需要进位的情况
    if (flag == 1)
        tmp.insert(0, 1, '1');
    return tmp;
}


void merge(vector<int>& A, int m, vector<int>& B, int n) {
    //取巧，先赋值，直接排序
    // for(int i = 0; i < B.size(); ++i)
    //     A[m++] = (B[i]);
    // sort(A.begin(), A.end());
    //逆置指针法
    int endA = m - 1, endB = n - 1, end = m + n - 1;
    //哪个大哪个放后面
    while (endB >= 0 && endA >= 0)
    {
        if (B[endB] > A[endA])
        {
            A[end] = B[endB];
            --endB;
        }
        else
        {
            A[end] = A[endA];
            --endA;
        }
        --end;
    }
    //当B中还有数据时直接放入即可
    while (endB >= 0)
    {
        A[end] = B[endB];
        --endB;
        --end;
    }
}


int findString(vector<string>& words, string s) {
    /*//直接遍历，时间复杂度O(n)
    for(int i = 0; i < words.size(); ++i)
    {
        if(words[i] == s)
            return i;
    }
    return -1;*/
    int left = 0;
    int right = words.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        int tmp = mid;//存储中间值
        //当mid是空字符串并且小于等于right时就直接掠过
        while (mid <= right && words[mid] == "")
        {
            ++mid;
        }
        //一旦超过了right，说明就不在右边了
        if (mid > right)
        {
            right = tmp - 1;//把right赋值到mid的左边去
            continue;//这里需要进行下一次循环，否则继续往下执行上面的代码白写了，又绕回去了
        }
        //正常二分法
        if (words[mid] > s)
            right = mid - 1;
        else if (words[mid] < s)
            left = mid + 1;
        else
            return mid;
    }
    return -1;
}