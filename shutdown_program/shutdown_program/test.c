#define _CRT_SECURE_NO_WARNINGS 1
//�ػ�����
#include <stdio.h>
int main()
{
	char input[] = { 0 };
	system("shutdown -s -t 60");
again:
	printf("Please enter ��������to stop the windows!\n");
	scanf("%s", &input);
	if (strcmp(input, "������") == 0)
	{
		system("shutdown -a");
	}
	else
	{
		goto again;
	}
	return 0;
}