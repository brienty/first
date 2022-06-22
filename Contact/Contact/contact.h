#pragma once

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

//Ϊ�˸��ĸ����㣬ʹ�ú궨��
#define NAME_MAX 20
#define GENDER_MAX 5
#define TELE_MAX 12
#define ADDRE_MAX 30
#define MAX 1000

//��������Ϣ�Ľṹ�壬Ϊ�˷��㣬�ض�������򵥵�����
typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char gender[GENDER_MAX];
	char tele[TELE_MAX];
	char address[ADDRE_MAX];
}PeoInfo;


//����鿴ͨѶ¼���ж����ˣ�����ͨѶ¼�ṹ��
typedef struct Contact
{
	PeoInfo data[MAX];//1000���˵���Ϣ
	int sz;//�Ѿ������Ϣ������
}Contact;

//��ʼ���ṹ��
void Initcontact(Contact* p);

//������ϵ��
void Addcontact(Contact* p);

//�鿴��ϵ��
void Showcontact(const Contact* p);

//ɾ����ϵ��
void Deletecontact(Contact* p);

//������ϵ��
void Searchcontact(const Contact* p);

//�޸���ϵ��
void Modifycontact(Contact* p);

//��ϵ����������/���䣩
void Sortcontact(Contact* p);

//�洢��ϵ��
void Savacontact(Contact* p);

//��ȡ�Ѵ洢��ϵ�˵���Ϣ
void Readcontact(Contact* p);