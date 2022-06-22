//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <string.h>
//#include <errno.h>
//
//int main()
//{	
//	//写入文件
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
//	//读取文件内容
//	FILE* pr = fopen("data.txt", "r");
//	
//	if (pr == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//
//	int ch = 0;
//	while ((ch = fgetc(pr)) != EOF)//上面已经对空指针做应对处理
//	{
//		fputc(ch, stdout);
//	}
//	printf("\n");
//
//	fclose(pr);//同理
//	pr = NULL;
//
//	return 0;
//}