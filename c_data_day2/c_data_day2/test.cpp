#define _CRT_SECURE_NO_WARNINGS 1

//#include <iostream>
//using namespace std;
//int FirstNotRepeatingChar(string str) {
//    int arr[52] = { 0 };
//    const char* s = str.c_str();
//    const char* temp = s;
//    while (*s) {
//        if (*s >= 65 && *s <= 91)
//            ++arr[*s - 65];
//        else
//            ++arr[*s - 71];
//        ++s;
//    }
//    int count = 0;
//    while (*temp) {
//        if (*temp >= 65 && *temp <= 91)
//            if (arr[*temp - 65] == 1)
//                return count;
//            else
//                if (arr[*temp - 71] == 1)
//                    return count;
//        ++count;
//        ++temp;
//    }
//    return -1;
//}
//int main()
//{
//    string str("google");
//    FirstNotRepeatingChar(str);
//    return 0;
//}

#include <iostream>
using namespace std;
bool isUnique(string astr) {
    int arr[26] = { 0 };
    const char* s = astr.c_str();
    while (*s) {
        ++arr[*s - 97];
        ++s;
    }
    for (int i = 0; i < 26; ++i) {
        if (arr[i] > 1)
            return false;
    }
    return true;
}