#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void Initcontact(Contact* p)
{
	assert(p);
	p->sz = 0;

	//使用内存函数初始化
	memset(p->data, 0, sizeof(p->data));
}

void Addcontact(Contact* p)
{
	assert(p);
	//满了则不再添加
	if (p->sz == MAX)
	{
		printf("通讯录已满！\n");
		return;
	}

	//否则继续添加
	printf("请输入要添加联系人的姓名\n");
	int a = scanf("%s", p->data[p->sz].name);
	printf("请输入要添加联系人的年龄\n");
	int b = scanf("%d", &(p->data[p->sz].age));
	printf("请输入要添加联系人的性别\n");
	int c = scanf("%s", p->data[p->sz].gender);
	printf("请输入要添加联系人的电话\n");
	int d = scanf("%s", p->data[p->sz].tele);
	printf("请输入要添加联系人的地址\n");
	int e = scanf("%s", p->data[p->sz].address);

	//添加成功，联系人加一
	p->sz++;

	//提示添加成功
	printf("添加成功！\n");
}

void Showcontact(const Contact* p)
{
	assert(p);

	//打印已有联系人
	printf("%-10s\t%-5s\t%-5s\t%-13s\t%-20s\n", "姓名", "性别", "年龄", "电话", "地址");
	int i = 0;
	for (i = 0; i < p->sz; i++)
	{
		printf("%-10s\t", p->data[i].name);
		printf("%-5s\t", p->data[i].gender);
		printf("%-5d\t", p->data[i].age);
		printf("%-13s\t", p->data[i].tele);
		printf("%-20s\n", p->data[i].address);
		
	}
}

//查找联系人
int Fine_contact(const Contact* p, char name[])
{
	assert(p);
	int i = 0;
	for (i = 0; i < p->sz; i++)
	{
		//当strcmp返回值等于0时，说明找到了，返回sz
		if (strcmp((p->data[i].name), name) == 0)
		{
			return i;
		}
	}

	//否则返回
	return -1;
}

void Deletecontact(Contact* p)
{
	assert(p);

	//通讯录没有联系人，则无法删除
	if (p->sz == 0)
	{
		printf("删除失败，通讯录为空！\n");
		return;
	}

	//否则开始删除联系人
	char name[NAME_MAX] = { 0 };
	printf("请输入被删除联系人的姓名\n");
	int a = scanf("%s", name);
	int ret = Fine_contact(p, name);

	//当ret等于-1时，说明没有该联系人
	if (ret == -1)
	{
		printf("没有该联系人！\n");
		return;
	}
	else
	{
		//否则开始删除
		int j = 0;
		for (j = ret; j < (p->sz) - 1; j++)
		{
			p->data[j] = p->data[j + 1];
		}

		//删除以后人联系人减一
		p->sz--;

		printf("删除联系人成功！\n");
	}
}

void Searchcontact(const Contact* p)
{
	assert(p);
	char name[NAME_MAX] = { 0 };

	printf("请输入想要查找联系人的名字\n");
	int a = scanf("%s", name);

	int ret = Fine_contact(p, name);
	if (ret == -1)
	{
		printf("查找失败，没有该联系人\n");
	}
	else
	{
		printf("%-10s\t%-5s\t%-5s\t%-13s\t%-20s\n", "姓名", "性别", "年龄", "电话", "地址");
		printf("%-10s\t", p->data[ret].name);
		printf("%-5s\t", p->data[ret].gender);
		printf("%-5d\t", p->data[ret].age);
		printf("%-13s\t", p->data[ret].tele);
		printf("%-20s\n", p->data[ret].address);
	}
}

void Modifycontact(Contact* p)
{
	assert(p);
	
	//通讯录没有联系人
	if (p->sz == 0)
	{
		printf("没有联系人，修改失败\n");
		return;
	}

	//通讯录有联系人，并修改信息
	char name[NAME_MAX] = { 0 };
	printf("请输入要被修改联系人的姓名\n");
	int a = scanf("%s", name);

	int ret = Fine_contact(p, name);
	if (ret == -1)
	{
		printf("修改失败，没有该联系人\n");
		return;
	}
	else
	{
		printf("请输入想要修改的信息>\n");
		while (1)
		{
			char infor[5] = { 0 };
			printf("可选信息如下：\n");
			printf("姓名 性别 年龄 电话 住址\n");
			int a = scanf("%s", infor);
			if (strcmp(infor, "姓名") == 0)
			{
				printf("请输入更改后的姓名\n");
				int b = scanf("%s", p->data[ret].name);
				printf("更改成功！\n");
				break;
			}
			else if (strcmp(infor, "性别") == 0)
			{
				printf("请输入更改后的性别\n");
				int c = scanf("%s", p->data[ret].gender);
				printf("更改成功！\n");
				break;
			}
			else if (strcmp(infor, "年龄") == 0)
			{
				printf("请输入更改后的年龄\n");
				int d = scanf("%d", &(p->data[ret].age));
				printf("更改成功！\n");
				break;
			}
			else if (strcmp(infor, "电话") == 0)
			{
				printf("请输入更改后的电话号码\n");
				int e = scanf("%s", p->data[ret].tele);
				printf("更改成功！\n");
				break;
			}
			else if (strcmp(infor, "住址") == 0)
			{
				printf("请输入更改后的住址\n");
				int f = scanf("%s", p->data[ret].address);
				printf("更改成功！\n");
				break;
			}
			else
			{
				printf("输入错误，请重新输入\n");
			}
		}
	}
}

//姓名比较函数
int com_name(Contact* p, int j)
{
	return strcmp(p->data[j].name, p->data[j + 1].name);
}

//年龄比较函数
int com_age(Contact* p, int j)
{
	return p->data[j].age - p->data[j + 1].age;
}

//采用冒泡思想排序
void Bubble_sort(Contact* p, int (*com)(Contact* s, int num))
{
	int i = 0;
	for (i = 0; i < p->sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < p->sz - 1 - i; j++)
		{
			if ( com(p, j)> 0)
			{
				PeoInfo temp = p->data[j];
				p->data[j] = p->data[j+1];
				p->data[j+1] = temp;
			}
		}
	}
}

void Sortcontact(Contact* p)
{
	assert(p);

	printf("请选择排序方式>\n");
	while (1)
	{
		printf("可选信息如下：\n");
		printf("姓名 年龄\n");
		char sort[5] = { 0 };
		int a = scanf("%s", sort);

		//按姓名排序
		if (strcmp(sort, "姓名") == 0)
		{
			Bubble_sort(p, com_name);
			printf("排序完成，排序结果如下：\n");
			Showcontact(p);
			break;
		}
		//按年龄排序
		else if (strcmp(sort, "年龄") == 0)
		{
			Bubble_sort(p, com_age);
			printf("排序完成，排序结果如下：\n");
			Showcontact(p);
			break;
		}
		else
		{
			printf("选择错误，请重新输入！\n");
		}
	}
}

void Savacontact(Contact* p)
{
	assert(p);
	FILE* pw = fopen("contact.txt", "w");
	
	//为空时打印错误信息并直接返回
	if (pw == NULL)
	{
		printf("Savacontact:%s\n", strerror(errno));
		return;
	}

	//联系人信息存储
	fprintf(pw, "%d\n", p->sz);//存储联系人个数
	int i = 0;
	//存储联系人信息
	for (i = 0; i < p->sz; i++)
	{
		fprintf(pw, "%s %s %d %s %s\n",
			p->data[i].name, p->data[i].gender, p->data[i].age, p->data[i].tele, p->data[i].address);
	}
	//操作完成后关闭并置于NULL
	fclose(pw);
	pw = NULL;

	printf("保存成功！\n");
}

void Readcontact(Contact* p)
{
	assert(p);

	FILE* pr = fopen("contact.txt", "r");

	//为空时打印错误信息并返回
	if (pr == NULL)
	{
		printf("Readcontact():%s\n", strerror(errno));
		return;
	}

	//读取练习人个数
	int b = fscanf(pr, "%d", &(p->sz));

	printf("通讯录情况如下：\n");

	//打印格式
	printf("%-10s\t%-5s\t%-5s\t%-13s\t%-20s\n", "姓名", "性别", "年龄", "电话", "地址");

	//读取并打印联系人信息
	int i = 0;
	for (i = 0; i < p->sz; i++)
	{
		int a = fscanf(pr,"%s %s %d %s %s\n", p->data[i].name, p->data[i].gender, &(p->data[i].age), p->data[i].tele, p->data[i].address);
		printf("%-10s\t", p->data[i].name);
		printf("%-5s\t", p->data[i].gender);
		printf("%-5d\t", p->data[i].age);
		printf("%-13s\t", p->data[i].tele);
		printf("%-20s\n", p->data[i].address);
	}

	//操作完成后关闭并置于NULL
	fclose(pr);
	pr = NULL;
}