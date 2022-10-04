#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

Lniche(char outside[ROW][COL], int row, int col)
{
	int a = 0;
	int b = 0;
	for (a=0;a<row;a++)
	{
		for (b=0;b<col;b++)
		{
			outside[a][b] = '*';
		}
	}
}
Disboard(char outside[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (j < col - 1)
				printf(" %c |", outside[i][j]);
			else
				printf(" %c \n", outside[i][j]);
		}
		if (i < row - 1)
			for (j = 0; j < col; j++)
			{
				if (j < col - 1)
					printf("---|");
				else
					printf("---\n");
			}
	}
}
Putboard(int inside[ROW + 2][COL + 2], int row, int col)
{
	srand((unsigned int)time(NULL));
	int z = DIF;
	while(z)
	{
		unsigned int x = rand() % (row-5);
		unsigned int y = rand() % (col-5);
			if (inside[x][y] == 0)
			{
				inside[x][y] = 1;
				z--;
			}
	}
}