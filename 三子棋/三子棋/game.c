#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void Displayboard(char arr[ROW][COL], int row, int col)
{
	//下面打印棋盘
	int i = 0;


	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (j < col - 1)
				printf(" %c |", arr[i][j]);
			else
				printf(" %c \n", arr[i][j]);
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



void PlayerMove(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家移动,请输入位置->");
		scanf("%d %d", &x, &y);
		if (x < row + 1 && y < col + 1 && x>0 && y>0)
		{
			if (arr[x - 1][y - 1] == ' ')
			{
				arr[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标非法,重新输入->");
			}
		}
		else
		{
			printf("坐标非法,重新输入->");
		}
	}
	system("cls");
	Displayboard(arr, ROW, COL);//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
}
//电脑移动
void ComputerMove(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		x = rand() % row;
		y = rand() % col;
			if (arr[x][y] == ' ')
			{
				arr[x][y] = '#';
				break;
			}
	}
	system("cls");
	Displayboard(arr, ROW, COL);//aaaaaaaaaaaaaaaaaaaaaaaaaaaa
}
void Board(char arr[ROW][COL], int row, int col)
{
	//下面初始化
	int m = 0;
	for (m = 0; m < row; m++)
	{
		int n = 0;
		for (n = 0; n < 
			col; n++)
		{
			arr[m][n] = ' ';
		} 
	}
}
int IsFull(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	for (x = 0; x < row; x++)
	{
		for (y = 0; y < col; y++)
		{
			if (arr[x][y] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char Win(char arr[ROW][COL], int row, int col)
{
	//判断行
	int a = 0;
	int b = 0;
	for (a = 0; a < row; a++)
	{
		if (arr[a][0] == arr[a][1] && arr[a][1] == arr[a][2] && arr[a][1]!= ' ')
		{
			return arr[a][1];
		}
	}
	//判断列
	for (b = 0; b < col; b++)
	{
		if (arr[0][b] == arr[1][b] && arr[1][b] == arr[2][b] && arr[1][b] != ' ')
		{
			return arr[1][b];
		}
	}
	//判断斜切
	if ((arr[0][0]== arr[1][1]&& arr[1][1]== arr[2][2]&& arr[0][0] != ' ') ||(arr[0][2]==arr[1][1]&&arr[1][1]==arr[2][0]&&arr[2][0]!=' '))
	{
		return arr[1][1];
	}

	if (IsFull(arr, row, col))
	{
		return 'E';
	}
	return 'C';
}

//这个棋盘以后试试吧
//____ ____ ____ _  3+1
//| ?  | ?  | ?  |  1+4
//____ ____ ____ _  3+1
//| ?  | ?  | ?  |  1+4
//____ ____ ____ _  3+1
//| ?  | ?  | ?  |  1+4

