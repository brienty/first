#define _CRT_SECURE_NO_WARNINGS 1

#include "student_inf.h"

//通用接口
//检查是否需要增容，封装成函数方便读取使用
void Check_System(Sy* p)
{
	assert(p);

	if (p->sz == p->capacity)
	{
		//增容
		SI* temp = (SI*)realloc(p->data, (p->capacity + 2) * sizeof(SI));
		if (temp == NULL)
		{
			printf("Check_System:%s\n", strerror(errno));
			return;
		}
		p->data = temp;

		//增容成功，容量加二
		p->capacity += 2;
	}
}
//读取文件里的数据
void ReadSystem(Sy* p)
{
	assert(p);

	FILE* pr = fopen("student_inf.txt", "r");

	//为空时打印错误信息并返回
	if (pr == NULL)
	{
		printf("ReadSystem():%s\n", strerror(errno));
		return;
	}

	//存储所读到的信息
	SI temp = { 0 };

	//读到的数据放temp，一次读的元素大小，一次读一个，从pr里读取
	while ((fscanf(pr, "%s %s %s %d %d %d %d", temp.number, temp.name, temp.major, &(temp.C), &(temp.cms), &(temp.ap), &(temp.elec)) != EOF))
	{
		//检查是否需要增容
		Check_System(p);//加载数据时，文件里的联系人数量可能大于默认值

		p->data[p->sz] = temp;
		p->sz++;
	}

	//操作完成后关闭并置于NULL
	fclose(pr);
	pr = NULL;
}

//初始化并读取数据
void InitSystem(Sy* p)
{
	assert(p);

	//初始化sz
	p->sz = 0;

	//初始化动态开辟内存空间
	SI* temp = (SI*)malloc(DEFAULT_MAX * sizeof(SI));

	//判空
	if (temp == NULL)
	{
		printf("InitSystem():%s\n", strerror(errno));
		return;
	}
	else
	{
		p->data = temp;
	}
	p->capacity = DEFAULT_MAX;

	//加载数据
	ReadSystem(p);
}
//查找函数
int Fine_System(const Sy* p, char name[])
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
//将动态申请的空间释放
void DestroySystem(Sy* p)
{
	assert(p);

	//释放data
	free(p->data);
	p->data = NULL;

	//将其他置于0
	p->sz = 0;
	p->capacity = 0;
}





/*****************************分割线********************************/
//管理员权限
//管理员权限
void System(Sy* p)
{
	assert(p);
	
	printf("已使用管理员身份登录！\n");
	int input = 1;
	while (input)
	{
		printf("请选择将要进行的操作：>\n");
		printf("0. 退出\n");
		printf("1. 增加学生的信息\n");
		printf("2. 删除学生的信息\n");
		scanf("%d", &input);
		system("cls");
		if (input == 1)
		{
			//添加学生信息
			AddSystem(p);
		}
		else if(input == 2)
		{
			//删除学生信息
			DeleteSI(p);
		}
		else if(input == 0)
		{
			printf("退出成功！\n");
			break;
		}
		else
		{
			printf("输入非法，请重新输入！\n");
		}
	}
}
//添加学生信息
void AddSystem(Sy* p)
{
	assert(p);

	//检查是否需要扩容
	Check_System(p);

	printf("请输入要添加学生的学号\n");
	scanf("%s", p->data[p->sz].number);
	printf("请输入要添加学生的姓名\n");
	scanf("%s", p->data[p->sz].name);
	printf("请输入要添加学生的专业\n");
	scanf("%s", p->data[p->sz].major);
	printf("请输入要添加学生的C语言成绩\n");
	scanf("%d", &(p->data[p->sz].C));
	printf("请输入要添加学生的计算材料学成绩\n");
	scanf("%d", &(p->data[p->sz].cms));
	printf("请输入要添加学生的原子物理成绩\n");
	scanf("%d", &(p->data[p->sz].ap));
	printf("请输入要添加学生的电动力学成绩\n");
	scanf("%d", &(p->data[p->sz].elec));

	//添加成功，学生信息加一
	p->sz++;

	//提示添加成功
	printf("添加成功！\n");
}
//删除学生信息
void DeleteSI(Sy* p)
{
	assert(p);

	//没有学生信息，则无法删除
	if (p->sz == 0)
	{
		printf("删除失败，学生信息为空！\n");
		return;
	}

	//否则开始删除
	char name[NAME_MAX] = { 0 };
	printf("请输入被删除学生信息的姓名\n");
	scanf("%s", name);
	int ret = Fine_System(p, name);

	//当ret等于-1时，说明没有学生信息
	if (ret == -1)
	{
		printf("没有该学生信息！\n");
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

		//删除以后学生信息减一
		p->sz--;

		printf("删除学生信息成功！\n");
	}
}





/*****************************分割线********************************/
//学生权限
void Student(Sy* p)
{
	assert(p);

	char name[NAME_MAX] = { 0 };
	printf("请输入登录用户名：>\n");
	scanf("%s", name);
	system("cls");
	int ret = Fine_System(p, name);
	if (ret == -1)
	{
		printf("无法找到该用户！\n");
	}
	else
	{
		printf("该用户权限只限于查找本人成绩！\n");
		printf("您的成绩情况如下：>\n");
		printf("%6s\t%12s\t%12s\t%-5s\t%-5s\t%-5s\t%-5s\t%-5s\n", "学号", "姓名", "专业", "C语言", "计算材料学", "原子物理", "电动力学", "总分");
		printf("%-6s\t", p->data[ret].number);
		printf("%-8s\t", p->data[ret].name);
		printf("%-7s\t", p->data[ret].major);
		printf("%-7d\t", p->data[ret].C);
		printf("%-8d\t", p->data[ret].cms);
		printf("%-10d\t", p->data[ret].ap);
		printf("%-10d\t", p->data[ret].elec);
		printf("%-5d\n", p->data[ret].C + p->data[ret].cms + p->data[ret].ap + p->data[ret].elec);
	}

}





/*****************************分割线********************************/
//教师权限
void Teacher(Sy* p)
{
	assert(p);

	//打印所有信息之前先按总分排序输出
	SortGrade(p);

	printf("已按总分降序展示所有学生的成绩信息！\n");
	printf("注：已使用教师身份登录，输入0即退出！\n");
	printf("请选择将要进行的操作：>\n");
	printf(" 成绩维护   查询\n");
	char arr[10] = { 0 };
	scanf("%s", arr);
	system("cls");
	if (strcmp("成绩维护", arr) == 0)
	{
		GradeOprate(p);
	}
	else if (strcmp("查询", arr) == 0)
	{
		Search(p);
	}
	else
	{
		printf("退出成功！\n");
		Sleep(1000);
		system("cls");
	}

}
//排序
//总分比较函数
int com_score(Sy* p, int j)
{
	assert(p);
	//按总分排序
	return (p->data[j].C + p->data[j].cms + p->data[j].ap + p->data[j].elec) -
		(p->data[j + 1].C + p->data[j + 1].cms + p->data[j + 1].ap + p->data[j + 1].elec);
}
//采用冒泡排序
void Bubble_sort(Sy* p, int (*com)(Sy* s, int num))
{
	assert(p);
	int i = 0;
	for (i = 0; i < p->sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < p->sz - 1 - i; j++)
		{
			if (com(p, j) < 0)
			{
				SI temp = p->data[j];
				p->data[j] = p->data[j + 1];
				p->data[j + 1] = temp;
			}
		}
	}
}
//成绩排序
void SortGrade(Sy* p)
{
	assert(p);

	Bubble_sort(p, com_score);
	ShowSystem(p);
}
//打印所有人信息
void ShowSystem(const Sy* p)
{
	assert(p);

	//打印
	printf("%6s\t%12s\t%12s\t%-5s\t%-5s\t%-5s\t%-5s\t%-5s\n", "学号", "姓名", "专业", "C语言", "计算材料学", "原子物理", "电动力学", "总分");
	int i = 0;
	for (i = 0; i < p->sz; i++)
	{
		printf("%-6s\t", p->data[i].number);
		printf("%-8s\t", p->data[i].name);
		printf("%-7s\t", p->data[i].major);
		printf("%-7d\t", p->data[i].C);
		printf("%-8d\t", p->data[i].cms);
		printf("%-10d\t", p->data[i].ap);
		printf("%-10d\t", p->data[i].elec);
		printf("%-5d\n", p->data[i].C + p->data[i].cms + p->data[i].ap + p->data[i].elec);
	}
}

//成绩维护系统
void GradeOprate(Sy* p)
{
here:
	printf("请选择想要进行的操作：>\n");
	printf("录入 修改 删除 \n");
	char operate[NAME_MAX] = { 0 };
	scanf("%s", operate);
	system("cls");
	while (1)
	{
		if (strcmp("录入", operate) == 0)
		{
			Logging(p);
			break;
		}
		else if (strcmp("修改", operate) == 0)
		{
			//修改成绩
			ModifySystem(p);
			break;
		}
		else if (strcmp("删除", operate) == 0)
		{
			//删除学生成绩
			DeleteSystem(p);
			break;
		}
		else
		{
			printf("输入错误，请重新输入！\n");
		}
	}

	printf("是否继续操作？\n");
	printf("  是  否\n");
	char arr[10] = { 0 };
	scanf("%s", arr);
	system("cls");
	if (strcmp("是", arr) == 0)
	{
		goto here;
	}

	printf("退出成功！\n");
}
//修改学生成绩
void ModifySystem(Sy* p)
{
	assert(p);

	//没有学生信息
	if (p->sz == 0)
	{
		printf("没有学生信息，修改失败！\n");
		return;
	}

	//有学生信息，并修改信息
	char name[NAME_MAX] = { 0 };
	printf("请输入要被修改学生的姓名\n");
	scanf("%s", name);
	system("cls");
	int ret = Fine_System(p, name);
	if (ret == -1)
	{
		printf("修改失败，没有该学生\n");
		return;
	}
	else
	{
		printf("请输入想要修改的信息：>\n");
		printf("可选信息如下：\n");
		while (1)
		{
			char infor[20] = { 0 };
			printf("C语言成绩 计算材料学成绩 原子物理成绩 电动力学成绩\n");
			scanf("%s", infor);
			system("cls");
			if (strcmp(infor, "C语言成绩") == 0)
			{
				printf("请输入更改后的C语言成绩：>\n");
				scanf("%d", &(p->data[ret].C));
				printf("更改成功！\n");
				Sleep(1000);
				system("cls");
				break;
			}
			else if (strcmp(infor, "计算材料学成绩") == 0)
			{
				printf("请输入更改后的计算材料学成绩：>\n");
				scanf("%d", &(p->data[ret].cms));
				printf("更改成功！\n");
				Sleep(1000);
				system("cls");
				break;
			}
			else if (strcmp(infor, "原子物理成绩") == 0)
			{
				printf("请输入更改后的原子物理成绩：>\n");
				scanf("%d", &(p->data[ret].ap));
				printf("更改成功！\n");
				Sleep(1000);
				system("cls");
				break;
			}
			else if (strcmp(infor, "电动力学成绩") == 0)
			{
				printf("请输入更改后的电动力学成绩：>\n");
				scanf("%d", &(p->data[ret].elec));
				printf("更改成功！\n");
				Sleep(1000);
				system("cls");
				break;
			}
			else
			{
				printf("输入错误，请重新输入\n");
				Sleep(1000);
				system("cls");
			}
		}
	}
}
//删除学生成绩
void DeleteSystem(Sy* p)
{
	assert(p);

	//没有学生信息，则无法删除
	if (p->sz == 0)
	{
		printf("删除失败，学生信息系统为空！\n");
		return;
	}

	//否则开始删除学生信息
	char name[NAME_MAX] = { 0 };
	printf("请输入被删除学生的姓名\n");
	int a = scanf("%s", name);
	int ret = Fine_System(p, name);

	//当ret等于-1时，说明没有该学生
	if (ret == -1)
	{
		printf("没有该学生信息！\n");
		return;
	}
	else
	{
		//否则开始删除，将成绩清零
		p->data[ret].C = 0;
		p->data[ret].cms = 0;
		p->data[ret].ap = 0;
		p->data[ret].elec = 0;
		printf("删除学生成绩成功！\n");
	}
}
//录入成绩
void Logging(Sy* p)
{
	assert(p);

	int i = 0;
	for (i = 0; i < p->sz; i++)
	{
		printf("待录入人：%s %s %s\n", p->data[i].number, p->data[i].name, p->data[i].major);
		printf("请输入要录入学生的C语言成绩：>\n");
		scanf("%d", &(p->data[i].C));
		printf("请输入要录入学生的计算材料学成绩：>\n");
		scanf("%d", &(p->data[i].cms));
		printf("请输入要录入学生的原子物理成绩：>\n");
		scanf("%d", &(p->data[i].ap));
		printf("请输入要录入学生的电动力学成绩：>\n");
		scanf("%d", &(p->data[i].elec));
		printf("录入成功！\n");
		Sleep(1000);
		system("cls");
	}
}

//成绩查询系统
void Search(Sy* p)
{
	int input = 1;
	while (input)
	{
		printf("请选择查询方式：>\n");
		printf("0. 退出\n");
		printf("1. 指定学生所有信息\n");
		printf("2. 不及格学生及人数\n");
		printf("3. 满分学生及人数\n");
		scanf("%d", &input);
		system("cls");
		
		if (input == 1)
		{
			//查询指定学生所有信息
			SearchSystem(p);
		}
		else if (input == 2)
		{
			//查询不及格的人，并打印人数
			SearchGrade_fail(p);
		}
		else if (input == 3)
		{
			//查询满分学生及人数
			SearchGrade_good(p);
		}
		else
		{
			printf("退出成功！\n");
		}
	}

}
//查找一个学生所有信息
void SearchSystem(const Sy* p)
{
	assert(p);
	char name[NAME_MAX] = { 0 };

	printf("请输入被查找学生成绩的姓名：>\n");
	int a = scanf("%s", name);

	system("cls");
	int ret = Fine_System(p, name);
	if (ret == -1)
	{
		printf("查找失败，没有该学生相关信息！请重新输入：>\n");
	}
	else
	{
		printf("成绩情况如下：>\n");
		printf("%6s\t%12s\t%12s\t%-5s\t%-5s\t%-5s\t%-5s\t%-5s\n", "学号", "姓名", "专业", "C语言", "计算材料学", "原子物理", "电动力学", "总分");
		printf("%-6s\t", p->data[ret].number);
		printf("%-8s\t", p->data[ret].name);
		printf("%-7s\t", p->data[ret].major);
		printf("%-7d\t", p->data[ret].C);
		printf("%-8d\t", p->data[ret].cms);
		printf("%-10d\t", p->data[ret].ap);
		printf("%-10d\t", p->data[ret].elec);
		printf("%-5d\n", p->data[ret].C + p->data[ret].cms + p->data[ret].ap + p->data[ret].elec);
	}

}
//查询满分学生及人数
void SearchGrade_good(Sy* p)
{
	assert(p);

	int i = 0;
	//统计不及格的人数
	int num = 0;
	printf("以下学生的学科部分学科为满分成绩：>\n");
	printf("%6s\t%12s\t%12s\t%-5s\t%-5s\t%-5s\t%-5s\t%-5s\n", "学号", "姓名", "专业", "C语言", "计算材料学", "原子物理", "电动力学", "总分");
	for (i = 0; i < p->sz; i++)
	{
		if (p->data[i].C == 100 || p->data[i].cms == 100 || p->data[i].ap == 100 || p->data[i].elec == 100)
		{
			++num;
			printf("%-6s\t", p->data[i].number);
			printf("%-8s\t", p->data[i].name);
			printf("%-7s\t", p->data[i].major);
			printf("%-7d\t", p->data[i].C);
			printf("%-8d\t", p->data[i].cms);
			printf("%-10d\t", p->data[i].ap);
			printf("%-10d\t", p->data[i].elec);
			printf("%-5d\n", p->data[i].C + p->data[i].cms + p->data[i].ap + p->data[i].elec);
		}

	}
	printf("总共%d人\n", num);

}
//查找不及格人，并打印人数
void SearchGrade_fail(Sy* p)
{
	assert(p);
	
	int i = 0;
	//统计不及格的人数
	int num = 0;
	printf("以下学生的学科具有不及格的成绩：>\n");
	printf("%6s\t%12s\t%12s\t%-5s\t%-5s\t%-5s\t%-5s\t%-5s\n", "学号", "姓名", "专业", "C语言", "计算材料学", "原子物理", "电动力学", "总分");
	for (i = 0; i < p->sz; i++)
	{
		if (p->data[i].C < 60 || p->data[i].cms  < 60 || p->data[i].ap < 60 || p->data[i].elec < 60)
		{
			++num;
			printf("%-6s\t", p->data[i].number);
			printf("%-8s\t", p->data[i].name);
			printf("%-7s\t", p->data[i].major);
			printf("%-7d\t", p->data[i].C);
			printf("%-8d\t", p->data[i].cms);
			printf("%-10d\t", p->data[i].ap);
			printf("%-10d\t", p->data[i].elec);
			printf("%-5d\n", p->data[i].C + p->data[i].cms + p->data[i].ap + p->data[i].elec);
		}
		
	}
	printf("总共%d人\n", num);
}