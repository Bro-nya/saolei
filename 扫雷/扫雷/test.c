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
//���������̵ĺ���
void game()
{
	char inside[ROWS][COLS] = { 0 };//�������
 	char outside[ROWS][COLS] = { 0 };//�������
	Lniche(outside,ROWS,COLS,'*');//��ʼ��������
	Lniche(inside, ROWS, COLS,'0');//��ʼ��������
	Disboard(outside, ROW, COL);//��ӡ������
	Putboard(inside, ROW, COL);//����������
	//Disboard2(inside, ROWS, COLS);//����������
	Process(inside, outside);//��Ϸ����
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