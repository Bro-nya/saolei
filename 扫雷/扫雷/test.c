#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("########################\n");
	printf("######  ɨ��С��Ϸ #####\n");
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
	int inside[ROW + 2][COL + 2] = { 0 };//�������
 	char outside[ROW][COL] = { 0 };//�������
	Lniche(outside,ROW,COL);//��ʼ��������
	Disboard(outside, ROW, COL);//��ӡ������
	Putboard(inside, ROW, COL);//����������
	Disboard2(inside, ROW + 2, COL + 2);
}
void test()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}