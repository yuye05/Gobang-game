#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "game.h"

void menu()
{
	printf("*************************\n");
	printf("***** 1.play  0.exit*****\n");
	printf("*************************\n");
}

void game()
{
	char board[ROW][COL];	
	char ret;
	//初始化棋盘
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);

	//开始下棋
	while (1)
	{
		//PlayMove(board, ROW, COL);
		FirstPlayer(board, ROW, COL);
		//判断输赢
		ret  = WinLose(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);

		//ComputerMove(board, ROW, COL);
		SecondPlayer(board, ROW, COL);
		//判断输赢
		ret = WinLose(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	if (ret == 'X')
	{
		printf("\n玩家1赢了！\n");
	}
	else if (ret == 'O')
	{
		printf("玩家2赢了！\n");
	}
	else
	{
		printf("平局\n");
	}
	DisplayBoard(board, ROW, COL);
}
//主函数
int main()
{
	srand((unsigned int)time(NULL));	//定义时间戳生成随机数，只用初始化一次

	int input = 0;
	do
	{
		menu();
		printf("请选择： ");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("带坐标的五子棋棋盘如下：\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误！\n");
			break;
		}
	} while (input);
	return 0;
}