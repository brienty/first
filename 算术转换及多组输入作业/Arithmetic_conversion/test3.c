#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//�������ĸA(a), E(e), I(i), O(o),U(u)��ΪԪ��������������ĸ��Ϊ����
//��д�����ж��������ĸ��Ԫ����Vowel�����Ǹ�����Consonant��
//�������룬ÿ������һ����ĸ
//���ÿ�����룬���Ϊһ��
//���������ĸ��Ԫ����������Сд���������Vowel��
//���������ĸ�Ƿ�Ԫ���������Consonant��

int main()
{
    char ch = 0;
	//scanf��ȡʧ��ʱ�᷵��EOF���������볣�ø÷������
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
        //���������Ỻ��������\n����Ҫ�����
        getchar();//��������
    }
    return 0;
}