#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

/*
	该程序中所报的警告都可忽略不计，不造成影响
*/

/*
	通讯录：
	1. 可以存放一千个人的信息
	2. 人的信息：名字，年龄， 电话， 住址， 性别
	3. 增加联系人
	4. 删除联系人
	5. 查找联系人
	6. 修改联系人
	7. 排序（名字/年龄）
	8. 保存联系人
	9. 读取联系人
*/

//使用枚举更方便，更易懂
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
	printf("                通讯录              \n");
	printf("1. 增加联系人			2. 删除联系人\n");
	printf("3. 修改信息			4. 查找联系人\n");
	printf("5. 展示所有联系人信息		6. 将联系人排序 \n");
	printf("7. 保存联系人信息		8. 读取联系人信息\n");
	printf("0. 退出                                  \n");
}

int main()
{
	int input = 0;
	
	//创建结构通讯录con
	Contact con;
	
	//初始化结构体
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