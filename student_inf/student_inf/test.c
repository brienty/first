#define _CRT_SECURE_NO_WARNINGS 1

#include "student_inf.h"

void menu()
{
	printf("��ѡ���¼��ݣ�>\n");

	printf("0. �˳�\n");
	printf("1. ����Ա\n");
	printf("2. ��ʦ\n");
	printf("3. ѧ��\n");
}


int main()
{
	menu();
	int input = 1;
	Sy s;
	InitSystem(&s);
	while (input)
	{
		scanf("%d", &input);
		system("cls");
		switch (input)
		{
		case 0:
			printf("�˳��ɹ���\n");
			break;
		case 1:System(&s);
			goto here;
			break;
		case 2:Teacher(&s);
			goto here;
			break;
		case 3:Student(&s);
			printf("��ѯ��ϣ��˳��ɹ���\n");
			goto here;
			break;
		default:
			printf("�Ƿ����룬���������룡\n");
			break;
		}
	}
here:
	return 0;
}