#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>

size_t my_strlen(char* s)
{
    assert(s);
    char* start = s;//s�Ѿ��ǵ�ַ�ˣ�����Ҫ&��*��ֱ�Ӹ�ֵ
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
    //src��ֵ��des�Ժ󣬵���\0��ASCII��ֵΪ0��ʱ�������ʽ��ֵ��Ϊ0
    //��������\0�ĸ�ֵ���������˿��Ƶ�Ч��
    {
        ;
    }
    return ret;
    //����arr2�ռ����ʼλ�ã�������ʽ����
}

char* My_strcat(char* dest, const char* src)
{
    char* ret = dest;
    assert(dest && src);
    //1. Ѱ��\0
    while (*dest)
    /*���ﲻ��* dest++���������׷���ϵ���ĸ����Ŀ�ĵ��ַ���\0�ĺ��棬���Ǵ�ӡ������
    ��ӡ��ʱ��ֻ�ܴ�ӡ\0֮ǰ�ģ�*++destҲ���У����Ŀ�ĵ��ַ����ǿ��ַ���ֱ������\0�����Ǵ�ӡ������*/
    {
        dest++;
    }
    //2. ʵ��׷��
    while (*dest++ = *src++)
    {
        ;
    }
    //3. ʵ����ʽ����
    return ret;
}

int My_strcmp(const char* str1, const char* str2)
{
    assert(str1 && str2);
    //1. �ж��Ƿ����
    while (*str1 == *str2)
    {
        //�������Ҷ�����\0��˵���ַ������
        if (*str1 == '\0')
        {
            return 0;
        }
        str1++;
        str2++;
    }
    //2. �������ȣ�ֱ�ӷ����������Ĳ� 
    return *str1 - *str2;
}

int main()
{
    char arr1[] = "abcd";
    char arr2[] = "xxxxxx";
    char arr3[20] = "qwertu";

    //ģ��ʵ��strlen����
    printf("%u\n", my_strlen(arr1));

    //ģ��ʵ��strcpy����
    printf("%s\n", My_strcpy(arr2, arr1));

    //ģ��ʵ��strcat����
    printf("%s\n", My_strcat(arr1, arr2));

    //ģ��ʵ��strcmp����
   printf("%d\n", My_strcmp(arr3, arr2));

    return 0;
}