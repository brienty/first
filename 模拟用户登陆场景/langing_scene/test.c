#define _CRT_SECURE_NO_WARNINGS 1
//strcmp -> string compare
//����0��˵�������ַ������
//���ش���������֣�ǰ����ַ������ں�����ַ���
//����С��������֣�ǰ����ַ���С�ں�����ַ���
/*�Ƚϴ�С�ķ�ʽ�������ַ���������������ַ����
������ASCIIֵ��С��Ƚϣ���ֱ�����ֲ�ͬ���ַ�����'\0'Ϊֹ*/
#include <stdio.h>
#include <string.h>
int main()
{
	int i = 0;
	//��������Ϊ��123456��
	char passworld[10] = "";
	//����д�ַ�����������""��ֻ�� \0 ����ֻ��һ���ַ����������������ַ����ᵼ������Խ��
	for (i = 0; i < 3; i++)
	{
		printf("Please enter passworld:");
		scanf("%s", passworld);
		//passworld�������������鱾�����ǵ�ַ����Ҫȡ��ַ
		if (strcmp(passworld, "123456") == 0)
		//�ַ����Ƚϲ���ʹ��==��strcmp�ǱȽ������ַ����Ƿ���ȵĺ�������Ҫ����ͷ�ļ�
		{
			printf("passworld is correct!\nLogin successful!\n");
			break;
		}
		else
		{
			printf("passworld is fault!\n");
		}
	}
	if (i == 3)
	//�� i ����3ʱ���Ѿ�û�л����ٴ�����
	{
		printf("Maximum number of inputs!\nQuit the program!\n");
	}
	return 0;
}