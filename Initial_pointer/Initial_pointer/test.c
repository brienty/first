//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
////写一个函数，可以逆序一个字符串的内容，指针实现
//
////字符串逆序
//void Conver(char* begin, char* end)
//{
//    while (begin < end)
//    {
//        char temp = *begin;
//        *begin = *end;
//        *end = temp;
//        begin++;
//        end--;
//    }
//}
//int main()
//{
//    char arr[10000] = { 0 };
//    //gets函数能输入空格，而scanf函数遇到空格就不再输入
//    gets(arr);
//    //求最后一个字符的位置
//    int sz = strlen(arr) - 1;
//    char* p = &arr[sz];
//    Conver(arr, p);
//    printf("%s\n", arr);
//    return 0;
//}