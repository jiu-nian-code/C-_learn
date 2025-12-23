#include"contact.h"

void print()//打印菜单
{
	system("cls");
	printf("******************************\n");
	printf("*****选择要进行的操作*********\n");
	printf("*****1.添加联系人*************\n");
	printf("*****2.删除联系人*************\n");
	printf("*****3.查找联系人*************\n");
	printf("*****4.更改联系人*************\n");
	printf("*****5.显示联系人*************\n");
	printf("*****6.清空联系人*************\n");
	printf("*****7.按名字排序*************\n");
	printf("*****8.退出*******************\n");
	printf("******************************\n");
}

void init(Contact * pc)//初始化
{
	assert(pc);//检验地址是否为真
	pc->con_num = 0;
	Peoinfo * ptr = (Peoinfo*)calloc(MAX ,sizeof(Peoinfo));
	if (ptr == NULL)
	{
		perror("init:calloc");
		return;
	}
	pc->data = ptr;
	pc->size = MAX;
	Lord(pc);//载入文件信息
}

void add(Contact* pc)//添加
{
	assert(pc);
	system("cls");
	if ((pc->con_num) >= pc->size)
	{
		expan(pc);
	}
	printf("请输入名字：\n");
	scanf("%20s", (*(pc->data + pc->con_num)).name);
	printf("请输入性别：\n");
	scanf("%5s", (*(pc->data + pc->con_num)).sex);
	printf("请输入年龄：\n");
	scanf("%5d", &((*(pc->data + pc->con_num)).age));
	printf("请输入电话：\n");
	scanf("%12s", (*(pc->data + pc->con_num)).tele);
	printf("请输入地址：\n");
	scanf("%30s", (*(pc->data + pc->con_num)).addr);
	(pc->con_num)++;
	system("cls");
	printf("添加成功。\n");
	Wait();
}

void dele(Contact* pc)//删除
{
	assert(pc);
	system("cls");
	char find[NAME_MAX] = { 0 };
	printf("请输入要删除的联系人：\n");
	scanf("%s", find);
	system("cls");
	int result = search(pc, find);
	if (result == -1)
	{
		printf("您要删除的联系人不存在。\n");
	}
	else
	{
		memmove(&(pc->data[result]), &(pc->data[result + 1]), sizeof(Peoinfo) * ((pc->con_num) - result - 1));
		//把要移除的元素后面的所有字节的数值移到这个元素的地址后面，把这个元素盖掉完成删除操作
		(pc->con_num)--;
		printf("删除成功。\n");
	}
	Wait();
}

int search(Contact* pc, char Find[])//查找
{
	assert(pc);
	for (int i = 0; i < pc->size; i++)
	{
		if (strcmp(Find, pc->data[i].name) == 0)//利用strcmp两个字符串完全相同返回0的特性来比较
		{
			return i;//返回数组中的元素序号
		}
	}
	return -1;
}

void retr(Contact* pc)//搜索
{
	assert(pc);
	system("cls");
	char find[NAME_MAX] = { 0 };
	printf("请输入您要搜索的联系人：\n");
	scanf("%s", find);
	system("cls");
	int result = search(pc, find);
	if (result == -1)
	{
		printf("您要搜索的联系人不存在。\n");
	}
	else
	{
		printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "名字", "性别", "年龄", "电话", "地址");
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-30s\n", pc->data[result].name,
											     pc->data[result].sex,
												 pc->data[result].age,
												 pc->data[result].tele,
												 pc->data[result].addr);
	}
	Wait();
}


void chan(Contact* pc)//更改
{
	assert(pc);
	system("cls");
	printf("请输入您要更改的联系人：\n");
	char find[NAME_MAX] = { 0 };
	scanf("%s", find);
	system("cls");
	int result = search(pc, find);
	if (result == -1)
	{
		printf("您要更改的联系人不存在。\n");
	}
	else
	{
		printf("请输入名字：\n");
		scanf("%20s", pc->data[result].name);
		printf("请输入性别：\n");
		scanf("%5s", pc->data[result].sex);
		printf("请输入年龄：\n");
		scanf("%5d", &(pc->data[result].age));
		printf("请输入电话：\n");
		scanf("%12s", pc->data[result].tele);
		printf("请输入地址：\n");
		scanf("%30s", pc->data[result].addr);
	}
	system("cls");
	printf("更改成功。\n");
	Wait();
}

void show(Contact* pc)//展示
{
	assert(pc);
	system("cls");
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "名字", "性别", "年龄", "电话", "地址");
	for (int i = 0; i < (pc->con_num); i++)
	{
		printf("%-20s\t%-5s\t%-5d\t%-12s\t%-30s\n", pc->data[i].name,
												 pc->data[i].sex,
												 pc->data[i].age,
												 pc->data[i].tele,
												 pc->data[i].addr);
	}//加入数值固定每个信息的长度，负号向右对齐，看起来井井有条
	Wait();
}

void empt(Contact* pc)//清空
{
	assert(pc);
	system("cls");
	memset(&(pc->data[0]), 0, (sizeof(pc->data) / sizeof(pc->data[0])) * (pc->size));//清除联系人数量所对应的字节的空间，优化算法
	(pc->con_num) = 0;
	system("cls");
	printf("清空成功。\n");
	Wait();
}

void sort(Contact* pc)//排序
{
	assert(pc);
	for (int i = 0; i < (pc->con_num) - 1; i++)
	{
		for (int j = 0; j < (pc->con_num) - i - 1; j++)
		{
			if (strcmp((pc->data[j].name), (pc->data[j + 1].name)) > 0)
			{
				Peoinfo ex;//创建一个中间结构体，memmove交换，与简单的数值交换类似
				memmove(&ex, &(pc->data[j]), sizeof(pc->data[j]));
				memmove(&(pc->data[j]), &(pc->data[j + 1]), sizeof(pc->data[j]));
				memmove(&(pc->data[j + 1]), &ex, sizeof(pc->data[j]));
			}
		}
	}
	system("cls");
	printf("排序成功。\n");
	Wait();
}

void Wait()
{
	printf("\n");
	printf("\n");
	printf("\n");
	printf("按回车继续->");
	getchar();
	char wait = 0;
	scanf("%c", &wait);//用输入卡住程序
}

void expan(Contact* pc)
{
	assert(pc);
	Peoinfo * ptr = realloc(pc->data, ((pc->size) + ADD_MAX) * sizeof(Peoinfo));
	if (ptr == NULL)
	{
		perror("expan:realloc");
	}
	pc->data = ptr;
	pc->size = pc->size + ADD_MAX;
	//printf("增容成功");
}

void purge(Contact* pc)
{
	assert(pc);
	Save(pc);//保存数据
	free(pc->data);//释放内存
	pc->data = NULL;//指针置为空
}

void Lord(Contact* pc)
{
	assert(pc);
	FILE * pf = fopen("contact.txt", "rb");
	if (pf == NULL)
	{
		perror("Lord:fopen");
	}
	else
	{
		int i = 0;
		while (fread((pc->data) + i, sizeof(Peoinfo), 1, pf))
		{
			pc->con_num ++;
			if (pc->con_num == pc->size)
			{
				expan(pc);
			}
			i++;
		}
		fclose(pf);
		pf = NULL;
	}
}

void Save(Contact* pc)
{
	assert(pc);
	FILE* pf = fopen("contact.txt", "wb");
	if (pf == NULL)
	{
		perror("save:fopen");
	}
	else
	{
		for (int i = 0; i < (pc->con_num); i++)
		{
			fwrite(&(pc->data[i]), sizeof(Peoinfo), 1, pf);
		}
		fclose(pf);
		pf = NULL;
	}
}