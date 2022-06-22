#pragma once

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

//为了更改更方便，使用宏定义
#define NAME_MAX 20
#define GENDER_MAX 5
#define TELE_MAX 12
#define ADDRE_MAX 30
#define MAX 1000

//定义人信息的结构体，为了方便，重定义个更简单的名字
typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char gender[GENDER_MAX];
	char tele[TELE_MAX];
	char address[ADDRE_MAX];
}PeoInfo;


//定义查看通讯录里有多少人，创建通讯录结构体
typedef struct Contact
{
	PeoInfo data[MAX];//1000个人的信息
	int sz;//已经存放信息的数量
}Contact;

//初始化结构体
void Initcontact(Contact* p);

//增加联系人
void Addcontact(Contact* p);

//查看联系人
void Showcontact(const Contact* p);

//删除联系人
void Deletecontact(Contact* p);

//查找联系人
void Searchcontact(const Contact* p);

//修改联系人
void Modifycontact(Contact* p);

//联系人排序（姓名/年龄）
void Sortcontact(Contact* p);

//存储联系人
void Savacontact(Contact* p);

//读取已存储联系人的信息
void Readcontact(Contact* p);