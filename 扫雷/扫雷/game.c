#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void Judg(char inside[ROWS][COLS], char outside[ROWS][COLS],int x,int y,int* win)
{
	int p = 0;
	p = inside[x - 1][y - 1] + inside[x - 1][y] + inside[x - 1][y + 1] + inside[x][y - 1] +
		inside[x][y + 1] +inside[x + 1][y - 1] + inside[x + 1][y] + inside[x + 1][y + 1] -
		'0' * 8;
	if(p!=0)
	{
		outside[x][y] = p + 48;
	}
	else
	{
		outside[x][y] = ' ';
		(*win)++;
		if (outside[x - 1][y - 1]=='*'&& x - 1>0&& x - 1<ROWS&& y - 1>0&&y - 1<COLS)
		{
			Judg(inside, outside, x - 1, y - 1, win);
		}
		if (outside[x - 1][y] == '*' && x - 1 > 0 && x - 1 < ROWS && y > 0 && y < COLS)
		{
			Judg(inside, outside, x - 1, y, win);
		}
		if (outside[x - 1][y + 1] == '*' && x - 1 > 0 && x - 1 < ROWS && y + 1 > 0 && y + 1 < COLS)
		{
			Judg(inside, outside, x - 1, y + 1, win);
		}
		if (outside[x ][y - 1] == '*' && x > 0 && x < ROWS && y - 1 > 0 && y - 1 < COLS)
		{
			Judg(inside, outside, x, y - 1, win);
		}
		if (outside[x ][y + 1] == '*' && x > 0 && x < ROWS && y + 1 > 0 && y + 1 < COLS)
		{
			Judg(inside, outside, x, y + 1, win);
		}
		if (outside[x +1][y - 1] == '*' && x + 1 > 0 && x + 1 < ROWS && y - 1 > 0 && y - 1 < COLS)//
		{
			Judg(inside, outside, x + 1, y - 1, win);
		}
		if (outside[x + 1][y ] == '*' && x + 1 > 0 && x + 1 < ROWS && y > 0 && y < COLS)
		{
			Judg(inside, outside, x + 1, y, win);
		}
		if (outside[x + 1][y + 1] == '*' && x + 1 > 0 && x + 1 < ROWS && y + 1 > 0 && y + 1 < COLS)
		{
			Judg(inside, outside, x + 1, y + 1, win);
		}
	}
}
void Disboard2(char side[ROWS][COLS], int row, int col)//侧式
{
	int a = 0;
	int b = 0;
	for (a = 1; a < row-1; a++)
	{
		for (b = 1; b < col-1; b++)
		{
			printf("%c   ", side[a][b]);
		}
		printf("\n\n");
	}
}
void Process(char inside[ROWS][COLS], char outside[ROWS][COLS])
{
	int x = 0;
	int y = 0;
	int win = 0;
	printf("请输入坐标->");
	while (win<ROW*COL-DIF)
	{
		scanf("%d %d", &x, &y);
		if (0 < x&& x<= ROW && 0 < y &&y<= COL)//((0 < x<= ROW )&& (0 < y<= COL))   这个为什么不行？
		{
			if (inside[x][y] == '1')
			{
				printf("你踩雷了\n");
				Disboard(outside, ROW, COL);
				Disboard2(inside, ROWS, COLS);
				break;
			}
			if (inside[x][y] == '0')
			{
				//判断修改
				Judg(inside, outside,x,y,&win);
				//打印表雷盘
				Disboard(outside, ROW, COL);
				
			}
		}
		else
		{
			printf("坐标非法，重新输入->");
		}
	}
	printf("恭喜你通关了\n");
}
void Lniche(char side[ROWS][COLS], int row, int col, char r)
{
	int a = 0;
	int b = 0;
	for (a = 0; a < row; a++)
	{
		for (b = 0; b < col; b++)
		{
			side[a][b] = r;
		}
	}
}
void Disboard(char outside[ROWS][COLS], int row, int col)
{
	int i = 1;
	for (i = 1; i <= row; i++)
	{
		int j = 1;
		for (j = 1; j <= col; j++)
		{
			if (j < col )
				printf(" %c |", outside[i][j]);
			else
				printf(" %c \n", outside[i][j]);
		}
		if (i < row)
			for (j = 0; j < col; j++)
			{
				if (j <col - 1)
					printf("---|");
				else
					printf("---\n");
			}
	}
	printf("\n");
}
void Putboard(char inside[ROWS][COLS], int row, int col)
{
	srand((unsigned int)time(NULL));
	int z = DIF;
	while (z)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;
			if (inside[x][y] != '1')
			{
				inside[x][y] = '1';
				z--;
			}
	}
}