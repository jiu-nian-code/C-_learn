#pragma once

#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

#include<string.h>

#include<assert.h>

#include<stdlib.h>

#include<errno.h>

#define NAME_MAX 20

#define SEX_MAX 5

#define ADDR_MAX 30

#define TELE_MAX 12

#define MAX 10

#define ADD_MAX 10

typedef struct Peopleinfo
{
	char name[NAME_MAX];
	char sex[SEX_MAX];
	int age;
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}Peoinfo;

typedef struct Contact
{
	char size;//通讯录的大小
	char con_num;//通讯录存储的联系人的总数
	Peoinfo * data;//设为结构体指针方便动态变换
}Contact;

enum option//枚举
{
	ADD = 1,//后面固定加1
	DELE,
	RETR,
	CHANGE,
	SHOW,
	EMPTY,
	SORT,
	EXIT
};

void print();

void init(Contact* pc);

void add(Contact* pc);

void dele(Contact* pc);

int search(Contact* pc, char Find);

void retr(Contact* pc);

void chan(Contact* pc);

void show(Contact* pc);

void empt(Contact* pc);

void sort(Contact* pc);

void Wait();

void expan(Contact* pc);

void purge(Contact* pc);

void Lord(Contact* pc);

void Save(Contact* pc);