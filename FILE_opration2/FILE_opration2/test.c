//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//struct stu
//{
//	char name[20];
//	int age;
//	double d;
//};
//
//
//int main()
//{
//	struct stu s = { "����", 20, 95.5 };
//	FILE* pw = fopen("data.txt", "w");
//	if (pw == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	//д��ʽ������
//	fprintf(pw, "% s % d % lf", s.name, s.age, s.d);
//
//	fclose(pw);
//	pw = NULL;
//
//
//	//����ʽ������
//	FILE* pr = fopen("data.txt", "r");
//	if (pr == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 0;
//	}
//	fscanf(pr, "%s %d %lf", s.name, &(s.age), &(s.d));
//
//	printf("%s %d %lf\n", s.name, s.age, s.d);
//
//	fclose(pr);
//	pr = NULL;
//
//	return 0;
//}