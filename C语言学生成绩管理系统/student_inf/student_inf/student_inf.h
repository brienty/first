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

//学生信息
typedef struct StuInfo
{
	char number[NUMBER_MAX];//学号
	char name[NAME_MAX];//姓名
	char major[MAJOR_MAX];//专业
	int C;//C语言
	int cms;//计算材料学
	int ap;//原子物理
	int elec;//电动力学
}SI;

//信息管理系统
typedef struct System
{
	SI* data;//指向一块连续的空间
	int sz;//已经存放信息的数量
	int capacity;//容量大小
}Sy;


//自动调用接口
//初始化管理系统
void InitSystem(Sy* p);
//读取信息
void ReadSystem(Sy* p);
//将动态申请的空间释放
void DestroySystem(Sy* p);





//管理员权限
void System(Sy* p);

//增加学生信息
void AddSystem(Sy* p);

//删除学生信息
void DeleteSI(Sy* p);





//学生权限
void Student(Sy* p);



//教师权限
void Teacher(Sy* p);

//成绩按总分排序
void SortGrade(Sy* p);

//打印所有学生信息
void ShowSystem(const Sy* p);

//成绩查询系统
void Search(Sy* p);

//查找学生信息
void SearchSystem(const Sy* p);

//查找不及格人，并打印人数
void SearchGrade_fail(Sy* p);

//查询满分学生及人数
void SearchGrade_good(Sy* p);

//成绩维护系统
void GradeOprate(Sy* p);

//成绩录入
void Logging(Sy* p);

//删除学生成绩并清零
void DeleteSystem(Sy* p);

//修改学生成绩
void ModifySystem(Sy* p);