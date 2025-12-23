#include"game.h"

int k = 0;//用于计算排雷数量，为了防止函数结束后销毁，故定义为全局变量

void game()//游戏运行的主体框架
{
	char demo[lengths][lengths] = { 0 };//生成棋盘
	char qipan[lengths][lengths] = { 0 };//显示的棋盘
	chushi(demo, lengths, '0');//初始化
	chushi(qipan, lengths, '*');
	insert(demo, length, mine);//放10个雷}
	int result = 1;//用于函数返回跳出循环
	int x = 0;
	int y = 0;//坐标
	while (result)
	{
		//display(demo, lengths);//显示所有的雷（测试用，外挂）
		display(qipan, lengths);//开局棋盘显示
		printf("输入坐标排查雷：\n");
		scanf("%d %d", &x, &y);
		if (x > length && y > length)
		{
			printf("输错啦，再来：\n");
			continue;
		}
		result = detection(demo, qipan, lengths, x, y);//探测并填入数字
	}
}

void print()//菜单显示
{
	system("cls");//清屏
	printf("***************************\n");
	printf("*********0.play************\n");
	printf("*********1.exit************\n");
	printf("***************************\n");
	printf("请输入数字来选择对应的操作:\n");
}

void chushi(char a[][lengths], int wides, char filler)//填充棋盘
{
	for (int i = 0; i < wides; i++)
	{
		for (int j = 0; j < wides; j++)
		{
			a[i][j] = filler;
		}
	}
}

void display(char a[][lengths], int wides)//打印棋盘
{
	for (int i = 1; i < wides - 1; i++)
	{
		for (int j = 1; j < wides - 1; j++)
		{
			printf("%c ", a[i][j]);
		}
		printf("\n");
	}
}

void insert(char a[][lengths], int wide, int total)//放置雷
{
	srand(time(NULL));
	int num = 0;
	int i = 0;
	int j = 0;
	while (num != total)
	{
		i = rand() % wide + 1;
		j = rand() % wide + 1;
		if (a[i][j] != '1')
		{
			a[i][j] = '1';
			num++;
		}
	}
}

int summing(char a[][lengths], int x, int y)//求周围8个格子雷的总数
{
	return (a[x + 1][y - 1] + a[x + 1][y] + a[x + 1][y + 1] 
		+ a[x][y - 1] + a[x][y + 1] + a[x - 1][y - 1] 
		+ a[x - 1][y] + a[x - 1][y + 1] - 48 * 7);
}

void spread(char a[][lengths], char b[][lengths], int x, int y)
{

}//扩散函数，应该要用递归写，暂时搁置

int detection(char a[][lengths], char b[][lengths], int wides, int x, int y)//输入并探测雷
{
	if (a[x][y] == '1')
	{
		system("cls");//清屏
		printf("炸死了,");//半句话，与下面的wait函数连接
		return 0;
	}
	else
	{
		if (a[x][y] == '0')
		{
			int n =summing(a, x, y);
			b[x][y] = n;
			k++;
		}
		if (k == length * length - mine)
		{
			system("cls");
			printf("恭喜你，排雷成功，");
			return 0;
		}
		else
		{
			return 1;
		}
	}
}

void wait()//暂停界面
{
	printf("按回车继续。");//半句话，为了接住detection函数的printf
	int input = 0;
	getchar();
	scanf("%c", &input);
}