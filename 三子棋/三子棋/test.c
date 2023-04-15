#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
#include<stdio.h>
//游戏逻辑
void Game(char arr[ROW][COL], int row, int col)
{
	char ret;
	while (1)
	{
		PlayerMove(arr, ROW, COL);
		ret = Win(arr, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		printf("电脑下棋中...（3s）\n");
		Sleep(3000);
		ComputerMove(arr, ROW, COL);
		ret = Win(arr, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	system("cls");
	if (ret == '*')
	{
		printf("玩家获胜\n");
	}
	if (ret == '#')
	{
		printf("电脑胜利\n");
	}
	if(ret == 'E')
	{
		printf("平局\n"); 
	}
	
	Displayboard(arr, row, col);
}
//打印菜单
menu()
{
	printf("************************************\n");
	printf("*******     三子棋小游戏    ********\n");
	printf("************************************\n");
	printf("*******	  1.play   0.exit   ********\n");
	printf("************************************\n");
}
//游戏整个算法的实现
game()
{
	//存放棋盘信息
	char arr[3][3] = {0};//全部放空格
	//初始化棋盘函数
	Board(arr, ROW, COL);
	//打印棋盘
	Displayboard(arr,ROW,COL);
	//游戏过程
	Game(arr,ROW,COL);
}
test()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			printf("三子棋开始\n");
			game();
			break;
		case 0:
			system("cls");
			printf("退出游戏\n");
			break;
		default:
			system("cls");
			printf("选择错误,重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	srand((unsigned int)time(NULL));
	test();
	return 0;
}