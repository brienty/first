#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

/*
	�ó����������ľ��涼�ɺ��Բ��ƣ������Ӱ��
*/

/*
	ͨѶ¼��
	1. ���Դ��һǧ���˵���Ϣ
	2. �˵���Ϣ�����֣����䣬 �绰�� סַ�� �Ա�
	3. ������ϵ��
	4. ɾ����ϵ��
	5. ������ϵ��
	6. �޸���ϵ��
	7. ��������/���䣩
	8. ������ϵ��
	9. ��ȡ��ϵ��
*/

//ʹ��ö�ٸ����㣬���׶�
enum opration
{
	Exit,//0
	Add,//1
	Delete,//2
	Modify,//3
	Search,//4
	Show,//5
	Sort,//6
	Sava,//7
	Reading//8
};

void menu()
{
	printf("                ͨѶ¼              \n");
	printf("1. ������ϵ��			2. ɾ����ϵ��\n");
	printf("3. �޸���Ϣ			4. ������ϵ��\n");
	printf("5. չʾ������ϵ����Ϣ		6. ����ϵ������ \n");
	printf("7. ������ϵ����Ϣ		8. ��ȡ��ϵ����Ϣ\n");
	printf("0. �˳�                                  \n");
}

int main()
{
	int input = 0;
	
	//�����ṹͨѶ¼con
	Contact con;
	
	//��ʼ���ṹ��
	Initcontact(&con);
	
	do
	{
		menu();
		int a = scanf("%d", &input);
		system("cls");

		switch (input)
		{
		case Add:
			Addcontact(&con);
			break;
		case Delete:
			Deletecontact(&con);
			break;
		case Modify:
			Modifycontact(&con);
			break;
		case Search:
			Searchcontact(&con);
			break;
		case Show:
			Showcontact(&con);
			break;
		case Sort:
			Sortcontact(&con);
			break;
		case Sava:
			Savacontact(&con);
			break;
		case Reading:
			Readcontact(&con);
			break;
		case Exit:
			printf("Exit contact!\n");
			break;
		default:
			printf("Please input again!\n");
			break;
		}
	} while (input);

	return 0;
}