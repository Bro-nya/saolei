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
Disboard2(int inside[ROW][COL], int row, int col)
{
	int a = 0;
	int b = 0;
	for (a=0;a<row;a++)
	{
		for (b=0;b<col;b++)
		{
			printf("%d  ", inside[a][b]);
		}
		printf("\n");
	}
}
void game()
{
	int inside[ROW + 2][COL + 2] = { 0 };//里层雷区
 	char outside[ROW][COL] = { 0 };//表层雷区
	Lniche(outside,ROW,COL);//初始化表雷区
	Disboard(outside, ROW, COL);//打印表雷区
	Putboard(inside, ROW, COL);//布置里雷区
	Disboard2(inside, ROW + 2, COL + 2);
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