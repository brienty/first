#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <windows.h>

#define NAME_MAX 20
#define NUMBER_MAX 10
#define MAJOR_MAX 5
#define DEFAULT_MAX 4

//ѧ����Ϣ
typedef struct StuInfo
{
	char number[NUMBER_MAX];//ѧ��
	char name[NAME_MAX];//����
	char major[MAJOR_MAX];//רҵ
	int C;//C����
	int cms;//�������ѧ
	int ap;//ԭ������
	int elec;//�綯��ѧ
}SI;

//��Ϣ����ϵͳ
typedef struct System
{
	SI* data;//ָ��һ�������Ŀռ�
	int sz;//�Ѿ������Ϣ������
	int capacity;//������С
}Sy;


//�Զ����ýӿ�
//��ʼ������ϵͳ
void InitSystem(Sy* p);
//��ȡ��Ϣ
void ReadSystem(Sy* p);
//����̬����Ŀռ��ͷ�
void DestroySystem(Sy* p);





//����ԱȨ��
void System(Sy* p);

//����ѧ����Ϣ
void AddSystem(Sy* p);

//ɾ��ѧ����Ϣ
void DeleteSI(Sy* p);





//ѧ��Ȩ��
void Student(Sy* p);



//��ʦȨ��
void Teacher(Sy* p);

//�ɼ����ܷ�����
void SortGrade(Sy* p);

//��ӡ����ѧ����Ϣ
void ShowSystem(const Sy* p);

//�ɼ���ѯϵͳ
void Search(Sy* p);

//����ѧ����Ϣ
void SearchSystem(const Sy* p);

//���Ҳ������ˣ�����ӡ����
void SearchGrade_fail(Sy* p);

//��ѯ����ѧ��������
void SearchGrade_good(Sy* p);

//�ɼ�ά��ϵͳ
void GradeOprate(Sy* p);

//�ɼ�¼��
void Logging(Sy* p);

//ɾ��ѧ���ɼ�������
void DeleteSystem(Sy* p);

//�޸�ѧ���ɼ�
void ModifySystem(Sy* p);