//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//
//int main()
//{	
//	//д���ļ�
//	FILE* pf = fopen("data.txt", "w");
//	if (pf == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	char arr[1000] = { 0 };
//	scanf("%s", arr);
//	fputs(arr, pf);
//	fclose(pf);
//	pf = NULL;
//
//	//��ȡ�ļ�����
//	FILE* pr = fopen("data.txt", "r");
//	
//	if (pr == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//
//	int ch = 0;
//	while ((ch = fgetc(pr)) != EOF)//�����Ѿ��Կ�ָ����Ӧ�Դ���
//	{
//		fputc(ch, stdout);
//	}
//	printf("\n");
//
//	fclose(pr);//ͬ��
//	pr = NULL;
//
//	return 0;
//}