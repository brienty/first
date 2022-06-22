#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stu
{
	char name[20];
	int age;
	double d;
};

int main()
{
	//二进制写入文件
	struct stu s[2] = { {"张三", 20, 95.5}, {"李四", 16, 66.5} };

	FILE* pf = fopen("wb.txt", "wb");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}

	fwrite(s, sizeof(struct stu), 2, pf);

	fclose(pf);
	pf = NULL;







	//二进制读文件
	struct stu s[2] = { 0 };
	FILE* pf = fopen("wb.txt", "rb");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}

	fread(s, sizeof(struct stu), 2, pf);

	printf("%s %d %lf\n", s[0].name, s[0].age, s[0].d);
	printf("%s %d %lf\n", s[1].name, s[1].age, s[1].d);

	fclose(pf);
	pf = NULL;

	return 0;
}
