#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//有五个字母A(a), E(e), I(i), O(o),U(u)称为元音，其他所有字母称为辅音
//编写程序判断输入的字母是元音（Vowel）还是辅音（Consonant）
//多组输入，每行输入一个字母
//针对每组输入，输出为一行
//如果输入字母是元音（包括大小写），输出“Vowel”
//如果输入字母是非元音，输出“Consonant”

int main()
{
    char ch = 0;
	//scanf读取失败时会返回EOF，多数输入常用该方法解决
    while (scanf("%c", &ch) != EOF)
    {
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            printf("Vowel\n");
        }
        else if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        {
            printf("Vowel\n");
        }
        else
        {
            printf("Consonant\n");
        }
        //输入结束后会缓冲区会有\n，需要清理掉
        getchar();//清理缓冲区
    }
    return 0;
}