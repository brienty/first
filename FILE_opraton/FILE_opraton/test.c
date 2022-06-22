#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <errno.h>


//¿½±´ÎÄ¼þ
int main()
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
		return 0;
	}
	
	FILE* pw = fopen("data.txt", "w");
	if (pw == NULL)
	{
		printf("%s\n", strerror(errno));
		fclose(pf);
		pf = NULL;
		return 0;
	}

	int ch = 0;
	while ((ch = fgetc(pf)) != EOF)
	{
		fputc(ch, pw);
	}

	fclose(pf);
	pf = NULL;
	fclose(pw);
	pw = NULL;

	return 0;
}