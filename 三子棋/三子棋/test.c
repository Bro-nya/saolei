#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
#include<stdio.h>
//��Ϸ�߼�
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
		printf("����������...��3s��\n");
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
		printf("��һ�ʤ\n");
	}
	if (ret == '#')
	{
		printf("����ʤ��\n");
	}
	if(ret == 'E')
	{
		printf("ƽ��\n"); 
	}
	
	Displayboard(arr, row, col);
}
//��ӡ�˵�
menu()
{
	printf("************************************\n");
	printf("*******     ������С��Ϸ    ********\n");
	printf("************************************\n");
	printf("*******	  1.play   0.exit   ********\n");
	printf("************************************\n");
}
//��Ϸ�����㷨��ʵ��
game()
{
	//���������Ϣ
	char arr[3][3] = {0};//ȫ���ſո�
	//��ʼ�����̺���
	Board(arr, ROW, COL);
	//��ӡ����
	Displayboard(arr,ROW,COL);
	//��Ϸ����
	Game(arr,ROW,COL);
}
test()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			printf("�����忪ʼ\n");
			game();
			break;
		case 0:
			system("cls");
			printf("�˳���Ϸ\n");
			break;
		default:
			system("cls");
			printf("ѡ�����,����ѡ��\n");
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