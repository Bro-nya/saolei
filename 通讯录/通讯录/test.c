#define _CRT_SECURE_NO_WARNINGS 1

#include"contacts.h"


Test()
{
	int input = 0;
	do
	{
		//Menu();
		printf("��ѡ��->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("���\n");
			//Add();
			break;
		case 2:
			printf("ɾ��\n");
			//Delete();
			break;
		case 3:
			printf("����\n");
			//Find();
			break;
		case 4:
			printf("�޸�\n");
			//Revise();
			break;
		case 0:
			printf("�˳�����\n");
			break;
		default:
			printf("ѡ�����,����ѡ��\n");
			break;
		}
	} while (input);
}
int main()
{

	Test();
	return 0;
}