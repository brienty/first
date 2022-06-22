#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void Initcontact(Contact* p)
{
	assert(p);
	p->sz = 0;

	//ʹ���ڴ溯����ʼ��
	memset(p->data, 0, sizeof(p->data));
}

void Addcontact(Contact* p)
{
	assert(p);
	//�����������
	if (p->sz == MAX)
	{
		printf("ͨѶ¼������\n");
		return;
	}

	//����������
	printf("������Ҫ�����ϵ�˵�����\n");
	int a = scanf("%s", p->data[p->sz].name);
	printf("������Ҫ�����ϵ�˵�����\n");
	int b = scanf("%d", &(p->data[p->sz].age));
	printf("������Ҫ�����ϵ�˵��Ա�\n");
	int c = scanf("%s", p->data[p->sz].gender);
	printf("������Ҫ�����ϵ�˵ĵ绰\n");
	int d = scanf("%s", p->data[p->sz].tele);
	printf("������Ҫ�����ϵ�˵ĵ�ַ\n");
	int e = scanf("%s", p->data[p->sz].address);

	//��ӳɹ�����ϵ�˼�һ
	p->sz++;

	//��ʾ��ӳɹ�
	printf("��ӳɹ���\n");
}

void Showcontact(const Contact* p)
{
	assert(p);

	//��ӡ������ϵ��
	printf("%-10s\t%-5s\t%-5s\t%-13s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
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

//������ϵ��
int Fine_contact(const Contact* p, char name[])
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

void Deletecontact(Contact* p)
{
	assert(p);

	//ͨѶ¼û����ϵ�ˣ����޷�ɾ��
	if (p->sz == 0)
	{
		printf("ɾ��ʧ�ܣ�ͨѶ¼Ϊ�գ�\n");
		return;
	}

	//����ʼɾ����ϵ��
	char name[NAME_MAX] = { 0 };
	printf("�����뱻ɾ����ϵ�˵�����\n");
	int a = scanf("%s", name);
	int ret = Fine_contact(p, name);

	//��ret����-1ʱ��˵��û�и���ϵ��
	if (ret == -1)
	{
		printf("û�и���ϵ�ˣ�\n");
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

		//ɾ���Ժ�����ϵ�˼�һ
		p->sz--;

		printf("ɾ����ϵ�˳ɹ���\n");
	}
}

void Searchcontact(const Contact* p)
{
	assert(p);
	char name[NAME_MAX] = { 0 };

	printf("��������Ҫ������ϵ�˵�����\n");
	int a = scanf("%s", name);

	int ret = Fine_contact(p, name);
	if (ret == -1)
	{
		printf("����ʧ�ܣ�û�и���ϵ��\n");
	}
	else
	{
		printf("%-10s\t%-5s\t%-5s\t%-13s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
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
	
	//ͨѶ¼û����ϵ��
	if (p->sz == 0)
	{
		printf("û����ϵ�ˣ��޸�ʧ��\n");
		return;
	}

	//ͨѶ¼����ϵ�ˣ����޸���Ϣ
	char name[NAME_MAX] = { 0 };
	printf("������Ҫ���޸���ϵ�˵�����\n");
	int a = scanf("%s", name);

	int ret = Fine_contact(p, name);
	if (ret == -1)
	{
		printf("�޸�ʧ�ܣ�û�и���ϵ��\n");
		return;
	}
	else
	{
		printf("��������Ҫ�޸ĵ���Ϣ>\n");
		while (1)
		{
			char infor[5] = { 0 };
			printf("��ѡ��Ϣ���£�\n");
			printf("���� �Ա� ���� �绰 סַ\n");
			int a = scanf("%s", infor);
			if (strcmp(infor, "����") == 0)
			{
				printf("��������ĺ������\n");
				int b = scanf("%s", p->data[ret].name);
				printf("���ĳɹ���\n");
				break;
			}
			else if (strcmp(infor, "�Ա�") == 0)
			{
				printf("��������ĺ���Ա�\n");
				int c = scanf("%s", p->data[ret].gender);
				printf("���ĳɹ���\n");
				break;
			}
			else if (strcmp(infor, "����") == 0)
			{
				printf("��������ĺ������\n");
				int d = scanf("%d", &(p->data[ret].age));
				printf("���ĳɹ���\n");
				break;
			}
			else if (strcmp(infor, "�绰") == 0)
			{
				printf("��������ĺ�ĵ绰����\n");
				int e = scanf("%s", p->data[ret].tele);
				printf("���ĳɹ���\n");
				break;
			}
			else if (strcmp(infor, "סַ") == 0)
			{
				printf("��������ĺ��סַ\n");
				int f = scanf("%s", p->data[ret].address);
				printf("���ĳɹ���\n");
				break;
			}
			else
			{
				printf("�����������������\n");
			}
		}
	}
}

//�����ȽϺ���
int com_name(Contact* p, int j)
{
	return strcmp(p->data[j].name, p->data[j + 1].name);
}

//����ȽϺ���
int com_age(Contact* p, int j)
{
	return p->data[j].age - p->data[j + 1].age;
}

//����ð��˼������
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

	printf("��ѡ������ʽ>\n");
	while (1)
	{
		printf("��ѡ��Ϣ���£�\n");
		printf("���� ����\n");
		char sort[5] = { 0 };
		int a = scanf("%s", sort);

		//����������
		if (strcmp(sort, "����") == 0)
		{
			Bubble_sort(p, com_name);
			printf("������ɣ����������£�\n");
			Showcontact(p);
			break;
		}
		//����������
		else if (strcmp(sort, "����") == 0)
		{
			Bubble_sort(p, com_age);
			printf("������ɣ����������£�\n");
			Showcontact(p);
			break;
		}
		else
		{
			printf("ѡ��������������룡\n");
		}
	}
}

void Savacontact(Contact* p)
{
	assert(p);
	FILE* pw = fopen("contact.txt", "w");
	
	//Ϊ��ʱ��ӡ������Ϣ��ֱ�ӷ���
	if (pw == NULL)
	{
		printf("Savacontact:%s\n", strerror(errno));
		return;
	}

	//��ϵ����Ϣ�洢
	fprintf(pw, "%d\n", p->sz);//�洢��ϵ�˸���
	int i = 0;
	//�洢��ϵ����Ϣ
	for (i = 0; i < p->sz; i++)
	{
		fprintf(pw, "%s %s %d %s %s\n",
			p->data[i].name, p->data[i].gender, p->data[i].age, p->data[i].tele, p->data[i].address);
	}
	//������ɺ�رղ�����NULL
	fclose(pw);
	pw = NULL;

	printf("����ɹ���\n");
}

void Readcontact(Contact* p)
{
	assert(p);

	FILE* pr = fopen("contact.txt", "r");

	//Ϊ��ʱ��ӡ������Ϣ������
	if (pr == NULL)
	{
		printf("Readcontact():%s\n", strerror(errno));
		return;
	}

	//��ȡ��ϰ�˸���
	int b = fscanf(pr, "%d", &(p->sz));

	printf("ͨѶ¼������£�\n");

	//��ӡ��ʽ
	printf("%-10s\t%-5s\t%-5s\t%-13s\t%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");

	//��ȡ����ӡ��ϵ����Ϣ
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

	//������ɺ�رղ�����NULL
	fclose(pr);
	pr = NULL;
}