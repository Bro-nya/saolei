#define _CRT_SECURE_NO_WARNINGS 1

#include"contacts.h"


Test()
{
	int input = 0;
	do
	{
		//Menu();
		printf("请选择->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("添加\n");
			//Add();
			break;
		case 2:
			printf("删除\n");
			//Delete();
			break;
		case 3:
			printf("查找\n");
			//Find();
			break;
		case 4:
			printf("修改\n");
			//Revise();
			break;
		case 0:
			printf("退出程序\n");
			break;
		default:
			printf("选择错误,重新选择\n");
			break;
		}
	} while (input);
}
int main()
{

	Test();
	return 0;
}