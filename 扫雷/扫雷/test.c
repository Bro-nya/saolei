#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("########################\n");
	printf("######  扫雷小游戏 #####\n");
	printf("########################\n");
	printf("#######  1.play  #######\n");
	printf("#######  0.exit  #######\n");
	printf("########################\n");
}
//侧试里棋盘的函数
void game()
{
	char inside[ROWS][COLS] = { 0 };//里层雷区
 	char outside[ROWS][COLS] = { 0 };//表层雷区
	Lniche(outside,ROWS,COLS,'*');//初始化表雷区
	Lniche(inside, ROWS, COLS,'0');//初始化里雷区
	Disboard(outside, ROW, COL);//打印表雷区
	Putboard(inside, ROW, COL);//布置里雷区
	//Disboard2(inside, ROWS, COLS);//侧试里棋盘
	Process(inside, outside);//游戏过程
}
void test()
{
	int input = 0;
	do
	{
		menu();

		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}