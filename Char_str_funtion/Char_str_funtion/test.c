#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

size_t my_strlen(char* s)
{
    assert(s);
    char* start = s;//s已经是地址了，不需要&和*，直接赋值
    while (*s)
    {
        s++;
    }
    return (s - start);
}

char* My_strcpy(char* dest, const char* src)
{
    assert(dest && src);
    char* ret = dest;
    while (*dest++ = *src++)
    //src赋值给des以后，当是\0（ASCII码值为0）时整个表达式的值都为0
    //既做到了\0的赋值，又做到了控制的效果
    {
        ;
    }
    return ret;
    //返回arr2空间的起始位置，方便链式访问
}

char* My_strcat(char* dest, const char* src)
{
    char* ret = dest;
    assert(dest && src);
    //1. 寻找\0
    while (*dest)
    /*这里不能* dest++，否则后面追加上的字母都在目的地字符串\0的后面，但是打印不出来
    打印的时候只能打印\0之前的，*++dest也不行，如果目的地字符串是空字符串直接跳过\0，还是打印不出来*/
    {
        dest++;
    }
    //2. 实现追加
    while (*dest++ = *src++)
    {
        ;
    }
    //3. 实现链式访问
    return ret;
}

int My_strcmp(const char* str1, const char* str2)
{
    assert(str1 && str2);
    //1. 判断是否相等
    while (*str1 == *str2)
    {
        //如果相等且都等于\0，说明字符串相等
        if (*str1 == '\0')
        {
            return 0;
        }
        str1++;
        str2++;
    }
    //2. 如果不相等，直接返回两个数的差 
    return *str1 - *str2;
}

int main()
{
    char arr1[] = "abcd";
    char arr2[] = "xxxxxx";
    char arr3[20] = "qwertu";

    //模拟实现strlen函数
    printf("%u\n", my_strlen(arr1));

    //模拟实现strcpy函数
    printf("%s\n", My_strcpy(arr2, arr1));

    //模拟实现strcat函数
    printf("%s\n", My_strcat(arr1, arr2));

    //模拟实现strcmp函数
   printf("%d\n", My_strcmp(arr3, arr2));

    return 0;
}