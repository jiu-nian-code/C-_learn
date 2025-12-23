#include"game.h"

int main()//游戏的总框架
{
again:
	print();//打印菜单
	int input = 0;
	scanf("%d", &input);//输入选项
	int result = 0;
	switch (input)
	{
	case 0:
		game();//进入游戏
		wait();
		goto again;
	case 1:
		break;//退出
	default:
		goto again;
	}
	return 0;
}