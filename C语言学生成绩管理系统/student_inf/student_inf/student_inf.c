#define _CRT_SECURE_NO_WARNINGS 1

#include "student_inf.h"

//ͨ�ýӿ�
//����Ƿ���Ҫ���ݣ���װ�ɺ��������ȡʹ��
void Check_System(Sy* p)
{
	assert(p);

	if (p->sz == p->capacity)
	{
		//����
		SI* temp = (SI*)realloc(p->data, (p->capacity + 2) * sizeof(SI));
		if (temp == NULL)
		{
			printf("Check_System:%s\n", strerror(errno));
			return;
		}
		p->data = temp;

		//���ݳɹ��������Ӷ�
		p->capacity += 2;
	}
}
//��ȡ�ļ��������
void ReadSystem(Sy* p)
{
	assert(p);

	FILE* pr = fopen("student_inf.txt", "r");

	//Ϊ��ʱ��ӡ������Ϣ������
	if (pr == NULL)
	{
		printf("ReadSystem():%s\n", strerror(errno));
		return;
	}

	//�洢����������Ϣ
	SI temp = { 0 };

	//���������ݷ�temp��һ�ζ���Ԫ�ش�С��һ�ζ�һ������pr���ȡ
	while ((fscanf(pr, "%s %s %s %d %d %d %d", temp.number, temp.name, temp.major, &(temp.C), &(temp.cms), &(temp.ap), &(temp.elec)) != EOF))
	{
		//����Ƿ���Ҫ����
		Check_System(p);//��������ʱ���ļ������ϵ���������ܴ���Ĭ��ֵ

		p->data[p->sz] = temp;
		p->sz++;
	}

	//������ɺ�رղ�����NULL
	fclose(pr);
	pr = NULL;
}

//��ʼ������ȡ����
void InitSystem(Sy* p)
{
	assert(p);

	//��ʼ��sz
	p->sz = 0;

	//��ʼ����̬�����ڴ�ռ�
	SI* temp = (SI*)malloc(DEFAULT_MAX * sizeof(SI));

	//�п�
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

	//��������
	ReadSystem(p);
}
//���Һ���
int Fine_System(const Sy* p, char name[])
{
	assert(p);
	int i = 0;
	for (i = 0; i < p->sz; i++)
	{
		//��strcmp����ֵ����0ʱ��˵���ҵ��ˣ�����sz
		if (strcmp((p->data[i].name), name) == 0)
		{
			return i;
		}
	}

	//���򷵻�
	return -1;
}
//����̬����Ŀռ��ͷ�
void DestroySystem(Sy* p)
{
	assert(p);

	//�ͷ�data
	free(p->data);
	p->data = NULL;

	//����������0
	p->sz = 0;
	p->capacity = 0;
}





/*****************************�ָ���********************************/
//����ԱȨ��
//����ԱȨ��
void System(Sy* p)
{
	assert(p);
	
	printf("��ʹ�ù���Ա��ݵ�¼��\n");
	int input = 1;
	while (input)
	{
		printf("��ѡ��Ҫ���еĲ�����>\n");
		printf("0. �˳�\n");
		printf("1. ����ѧ������Ϣ\n");
		printf("2. ɾ��ѧ������Ϣ\n");
		scanf("%d", &input);
		system("cls");
		if (input == 1)
		{
			//���ѧ����Ϣ
			AddSystem(p);
		}
		else if(input == 2)
		{
			//ɾ��ѧ����Ϣ
			DeleteSI(p);
		}
		else if(input == 0)
		{
			printf("�˳��ɹ���\n");
			break;
		}
		else
		{
			printf("����Ƿ������������룡\n");
		}
	}
}
//���ѧ����Ϣ
void AddSystem(Sy* p)
{
	assert(p);

	//����Ƿ���Ҫ����
	Check_System(p);

	printf("������Ҫ���ѧ����ѧ��\n");
	scanf("%s", p->data[p->sz].number);
	printf("������Ҫ���ѧ��������\n");
	scanf("%s", p->data[p->sz].name);
	printf("������Ҫ���ѧ����רҵ\n");
	scanf("%s", p->data[p->sz].major);
	printf("������Ҫ���ѧ����C���Գɼ�\n");
	scanf("%d", &(p->data[p->sz].C));
	printf("������Ҫ���ѧ���ļ������ѧ�ɼ�\n");
	scanf("%d", &(p->data[p->sz].cms));
	printf("������Ҫ���ѧ����ԭ������ɼ�\n");
	scanf("%d", &(p->data[p->sz].ap));
	printf("������Ҫ���ѧ���ĵ綯��ѧ�ɼ�\n");
	scanf("%d", &(p->data[p->sz].elec));

	//��ӳɹ���ѧ����Ϣ��һ
	p->sz++;

	//��ʾ��ӳɹ�
	printf("��ӳɹ���\n");
}
//ɾ��ѧ����Ϣ
void DeleteSI(Sy* p)
{
	assert(p);

	//û��ѧ����Ϣ�����޷�ɾ��
	if (p->sz == 0)
	{
		printf("ɾ��ʧ�ܣ�ѧ����ϢΪ�գ�\n");
		return;
	}

	//����ʼɾ��
	char name[NAME_MAX] = { 0 };
	printf("�����뱻ɾ��ѧ����Ϣ������\n");
	scanf("%s", name);
	int ret = Fine_System(p, name);

	//��ret����-1ʱ��˵��û��ѧ����Ϣ
	if (ret == -1)
	{
		printf("û�и�ѧ����Ϣ��\n");
		return;
	}
	else
	{
		//����ʼɾ��
		int j = 0;
		for (j = ret; j < (p->sz) - 1; j++)
		{
			p->data[j] = p->data[j + 1];
		}

		//ɾ���Ժ�ѧ����Ϣ��һ
		p->sz--;

		printf("ɾ��ѧ����Ϣ�ɹ���\n");
	}
}





/*****************************�ָ���********************************/
//ѧ��Ȩ��
void Student(Sy* p)
{
	assert(p);

	char name[NAME_MAX] = { 0 };
	printf("�������¼�û�����>\n");
	scanf("%s", name);
	system("cls");
	int ret = Fine_System(p, name);
	if (ret == -1)
	{
		printf("�޷��ҵ����û���\n");
	}
	else
	{
		printf("���û�Ȩ��ֻ���ڲ��ұ��˳ɼ���\n");
		printf("���ĳɼ�������£�>\n");
		printf("%6s\t%12s\t%12s\t%-5s\t%-5s\t%-5s\t%-5s\t%-5s\n", "ѧ��", "����", "רҵ", "C����", "�������ѧ", "ԭ������", "�綯��ѧ", "�ܷ�");
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





/*****************************�ָ���********************************/
//��ʦȨ��
void Teacher(Sy* p)
{
	assert(p);

	//��ӡ������Ϣ֮ǰ�Ȱ��ܷ��������
	SortGrade(p);

	printf("�Ѱ��ֽܷ���չʾ����ѧ���ĳɼ���Ϣ��\n");
	printf("ע����ʹ�ý�ʦ��ݵ�¼������0���˳���\n");
	printf("��ѡ��Ҫ���еĲ�����>\n");
	printf(" �ɼ�ά��   ��ѯ\n");
	char arr[10] = { 0 };
	scanf("%s", arr);
	system("cls");
	if (strcmp("�ɼ�ά��", arr) == 0)
	{
		GradeOprate(p);
	}
	else if (strcmp("��ѯ", arr) == 0)
	{
		Search(p);
	}
	else
	{
		printf("�˳��ɹ���\n");
		Sleep(1000);
		system("cls");
	}

}
//����
//�ֱܷȽϺ���
int com_score(Sy* p, int j)
{
	assert(p);
	//���ܷ�����
	return (p->data[j].C + p->data[j].cms + p->data[j].ap + p->data[j].elec) -
		(p->data[j + 1].C + p->data[j + 1].cms + p->data[j + 1].ap + p->data[j + 1].elec);
}
//����ð������
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
//�ɼ�����
void SortGrade(Sy* p)
{
	assert(p);

	Bubble_sort(p, com_score);
	ShowSystem(p);
}
//��ӡ��������Ϣ
void ShowSystem(const Sy* p)
{
	assert(p);

	//��ӡ
	printf("%6s\t%12s\t%12s\t%-5s\t%-5s\t%-5s\t%-5s\t%-5s\n", "ѧ��", "����", "רҵ", "C����", "�������ѧ", "ԭ������", "�綯��ѧ", "�ܷ�");
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

//�ɼ�ά��ϵͳ
void GradeOprate(Sy* p)
{
here:
	printf("��ѡ����Ҫ���еĲ�����>\n");
	printf("¼�� �޸� ɾ�� \n");
	char operate[NAME_MAX] = { 0 };
	scanf("%s", operate);
	system("cls");
	while (1)
	{
		if (strcmp("¼��", operate) == 0)
		{
			Logging(p);
			break;
		}
		else if (strcmp("�޸�", operate) == 0)
		{
			//�޸ĳɼ�
			ModifySystem(p);
			break;
		}
		else if (strcmp("ɾ��", operate) == 0)
		{
			//ɾ��ѧ���ɼ�
			DeleteSystem(p);
			break;
		}
		else
		{
			printf("����������������룡\n");
		}
	}

	printf("�Ƿ����������\n");
	printf("  ��  ��\n");
	char arr[10] = { 0 };
	scanf("%s", arr);
	system("cls");
	if (strcmp("��", arr) == 0)
	{
		goto here;
	}

	printf("�˳��ɹ���\n");
}
//�޸�ѧ���ɼ�
void ModifySystem(Sy* p)
{
	assert(p);

	//û��ѧ����Ϣ
	if (p->sz == 0)
	{
		printf("û��ѧ����Ϣ���޸�ʧ�ܣ�\n");
		return;
	}

	//��ѧ����Ϣ�����޸���Ϣ
	char name[NAME_MAX] = { 0 };
	printf("������Ҫ���޸�ѧ��������\n");
	scanf("%s", name);
	system("cls");
	int ret = Fine_System(p, name);
	if (ret == -1)
	{
		printf("�޸�ʧ�ܣ�û�и�ѧ��\n");
		return;
	}
	else
	{
		printf("��������Ҫ�޸ĵ���Ϣ��>\n");
		printf("��ѡ��Ϣ���£�\n");
		while (1)
		{
			char infor[20] = { 0 };
			printf("C���Գɼ� �������ѧ�ɼ� ԭ������ɼ� �綯��ѧ�ɼ�\n");
			scanf("%s", infor);
			system("cls");
			if (strcmp(infor, "C���Գɼ�") == 0)
			{
				printf("��������ĺ��C���Գɼ���>\n");
				scanf("%d", &(p->data[ret].C));
				printf("���ĳɹ���\n");
				Sleep(1000);
				system("cls");
				break;
			}
			else if (strcmp(infor, "�������ѧ�ɼ�") == 0)
			{
				printf("��������ĺ�ļ������ѧ�ɼ���>\n");
				scanf("%d", &(p->data[ret].cms));
				printf("���ĳɹ���\n");
				Sleep(1000);
				system("cls");
				break;
			}
			else if (strcmp(infor, "ԭ������ɼ�") == 0)
			{
				printf("��������ĺ��ԭ������ɼ���>\n");
				scanf("%d", &(p->data[ret].ap));
				printf("���ĳɹ���\n");
				Sleep(1000);
				system("cls");
				break;
			}
			else if (strcmp(infor, "�綯��ѧ�ɼ�") == 0)
			{
				printf("��������ĺ�ĵ綯��ѧ�ɼ���>\n");
				scanf("%d", &(p->data[ret].elec));
				printf("���ĳɹ���\n");
				Sleep(1000);
				system("cls");
				break;
			}
			else
			{
				printf("�����������������\n");
				Sleep(1000);
				system("cls");
			}
		}
	}
}
//ɾ��ѧ���ɼ�
void DeleteSystem(Sy* p)
{
	assert(p);

	//û��ѧ����Ϣ�����޷�ɾ��
	if (p->sz == 0)
	{
		printf("ɾ��ʧ�ܣ�ѧ����ϢϵͳΪ�գ�\n");
		return;
	}

	//����ʼɾ��ѧ����Ϣ
	char name[NAME_MAX] = { 0 };
	printf("�����뱻ɾ��ѧ��������\n");
	int a = scanf("%s", name);
	int ret = Fine_System(p, name);

	//��ret����-1ʱ��˵��û�и�ѧ��
	if (ret == -1)
	{
		printf("û�и�ѧ����Ϣ��\n");
		return;
	}
	else
	{
		//����ʼɾ�������ɼ�����
		p->data[ret].C = 0;
		p->data[ret].cms = 0;
		p->data[ret].ap = 0;
		p->data[ret].elec = 0;
		printf("ɾ��ѧ���ɼ��ɹ���\n");
	}
}
//¼��ɼ�
void Logging(Sy* p)
{
	assert(p);

	int i = 0;
	for (i = 0; i < p->sz; i++)
	{
		printf("��¼���ˣ�%s %s %s\n", p->data[i].number, p->data[i].name, p->data[i].major);
		printf("������Ҫ¼��ѧ����C���Գɼ���>\n");
		scanf("%d", &(p->data[i].C));
		printf("������Ҫ¼��ѧ���ļ������ѧ�ɼ���>\n");
		scanf("%d", &(p->data[i].cms));
		printf("������Ҫ¼��ѧ����ԭ������ɼ���>\n");
		scanf("%d", &(p->data[i].ap));
		printf("������Ҫ¼��ѧ���ĵ綯��ѧ�ɼ���>\n");
		scanf("%d", &(p->data[i].elec));
		printf("¼��ɹ���\n");
		Sleep(1000);
		system("cls");
	}
}

//�ɼ���ѯϵͳ
void Search(Sy* p)
{
	int input = 1;
	while (input)
	{
		printf("��ѡ���ѯ��ʽ��>\n");
		printf("0. �˳�\n");
		printf("1. ָ��ѧ��������Ϣ\n");
		printf("2. ������ѧ��������\n");
		printf("3. ����ѧ��������\n");
		scanf("%d", &input);
		system("cls");
		
		if (input == 1)
		{
			//��ѯָ��ѧ��������Ϣ
			SearchSystem(p);
		}
		else if (input == 2)
		{
			//��ѯ��������ˣ�����ӡ����
			SearchGrade_fail(p);
		}
		else if (input == 3)
		{
			//��ѯ����ѧ��������
			SearchGrade_good(p);
		}
		else
		{
			printf("�˳��ɹ���\n");
		}
	}

}
//����һ��ѧ��������Ϣ
void SearchSystem(const Sy* p)
{
	assert(p);
	char name[NAME_MAX] = { 0 };

	printf("�����뱻����ѧ���ɼ���������>\n");
	int a = scanf("%s", name);

	system("cls");
	int ret = Fine_System(p, name);
	if (ret == -1)
	{
		printf("����ʧ�ܣ�û�и�ѧ�������Ϣ�����������룺>\n");
	}
	else
	{
		printf("�ɼ�������£�>\n");
		printf("%6s\t%12s\t%12s\t%-5s\t%-5s\t%-5s\t%-5s\t%-5s\n", "ѧ��", "����", "רҵ", "C����", "�������ѧ", "ԭ������", "�綯��ѧ", "�ܷ�");
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
//��ѯ����ѧ��������
void SearchGrade_good(Sy* p)
{
	assert(p);

	int i = 0;
	//ͳ�Ʋ����������
	int num = 0;
	printf("����ѧ����ѧ�Ʋ���ѧ��Ϊ���ֳɼ���>\n");
	printf("%6s\t%12s\t%12s\t%-5s\t%-5s\t%-5s\t%-5s\t%-5s\n", "ѧ��", "����", "רҵ", "C����", "�������ѧ", "ԭ������", "�綯��ѧ", "�ܷ�");
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
	printf("�ܹ�%d��\n", num);

}
//���Ҳ������ˣ�����ӡ����
void SearchGrade_fail(Sy* p)
{
	assert(p);
	
	int i = 0;
	//ͳ�Ʋ����������
	int num = 0;
	printf("����ѧ����ѧ�ƾ��в�����ĳɼ���>\n");
	printf("%6s\t%12s\t%12s\t%-5s\t%-5s\t%-5s\t%-5s\t%-5s\n", "ѧ��", "����", "רҵ", "C����", "�������ѧ", "ԭ������", "�綯��ѧ", "�ܷ�");
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
	printf("�ܹ�%d��\n", num);
}