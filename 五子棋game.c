#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"

//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	//打印纵序列
	printf(" ");
	for (int i = 0; i < row; i++)
	{
		printf("%4d", i + 1);
	}
	printf("\n");
	//打印上边界
	printf("   ");
	for (int i = 0; i < row; i++)
	{
		printf("___");
		if (i < row - 1)
			printf("_");
	}
	printf("\n");
	//打印行序列以及棋盘主体
	for (int i = 0; i < row; i++)
	{
		printf("%2d|", i + 1);
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == 'X')
			{
				printf(" %s%c%s ", RED, board[i][j], RESET);
			}
			else if (board[i][j] == 'O')
			{
				printf(" %s%c%s ", GREEN, board[i][j], RESET);
			}
			else
			{
				printf(" %c ", board[i][j]);
			}
			if (j < col)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			printf("  |");
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col)
					printf("|");
			}
			printf("\n");
		}
	}
	//打印下边界
	printf("   ");
	for (int i = 0; i < row; i++)
	{
		printf("---");
		if (i < row - 1)
			printf("-");
	}
	printf("\n\n");
}

//下棋函数
//void PlayMove(char board[ROW][COL], int row, int col)
//{
//	int x;
//	int y;
//	
//	while (1)
//	{
//		printf("玩家请下棋\n");
//		printf("请输入坐标：>");
//		scanf("%d %d", &x, &y);
//		//判断坐标是否合法
//		if (x >= 1 && x <= row && y >= 1 && y <= col)
//		{
//			if(board[x - 1][y - 1] == ' ')
//			{
//				board[x - 1][y - 1] = 'X';
//				break;
//			}
//			else
//			{
//				printf("坐标被占用,不能下棋，请选择其他位置\n");
//			}
//		}
//		else
//			printf("坐标错误，请重新输入！\n");
//	}
//}
//
//void ComputerMove(char board[ROW][COL], int row, int col)
//{
//	printf("电脑下棋\n");
//	int x;
//	int y;
//	while(1)
//	{
//	x = rand() % row;	//0-(row-1)范围取值
//	y = rand() % col;
//		if (board[x][y] == ' ')
//		{
//			board[x][y] = 'O';
//			break;
//		}
//	}
//}

//双人对战模式
void FirstPlayer(char board[ROW][COL], int row, int col)
{
	int x;
	int y;

	while (1)
	{
		printf("玩家1请下棋\n");
		printf("请输入坐标：>");
		scanf("%d %d", &x, &y);
		//判断坐标是否合法
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
				break;
			}
			else
			{
				printf("坐标被占用,不能下棋，请选择其他位置\n");
			}
		}
		else
			printf("坐标错误，请重新输入！\n");
	}
}

void SecondPlayer(char board[ROW][COL], int row, int col)
{
	int x;
	int y;

	while (1)
	{
		printf("玩家2请下棋\n");
		printf("请输入坐标：>");
		scanf("%d %d", &x, &y);
		//判断坐标是否合法
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'O';
				break;
			}
			else
			{
				printf("坐标被占用,不能下棋，请选择其他位置\n");
			}
		}
		else
			printf("坐标错误，请重新输入！\n");
	}
}

//判断输赢
char WinLose(char board[ROW][COL], int row, int col)
{
	//行
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j + 2] == board[i][j + 3] && board[i][j + 3] == board[i][j + 4])
			{
				return board[i][j + 2];
			}
		}
	}
	//列
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] != ' ' && board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j] && board[i + 2][j] == board[i + 3][j] && board[i + 3][j] == board[i + 4][j])
			{
				return board[i + 2][j];
			}
		}
	}
	//正对角线
	for (int i = 0; i < row - 4; i++)
	{
		for (int j = 0; j < col - 4; j++)
		{
			if (board[i][j] != ' ' && board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i + 2][j + 2] == board[i + 3][j + 3] && board[i + 3][j + 3] == board[i + 4][j + 4])
			{
				return board[i][j];
			}
		}
	}
	//反对角线
	for (int i = 0; i < row - 4; i++)
	{
		for (int j = 0; j < col - 4; j++)
		{
			if (board[i][j] != ' ' && board[i][j] == board[i - 1][j + 1] && board[i - 1][j + 1] == board[i - 2][j + 2] && board[i - 2][j + 2] == board[i - 3][j + 3] && board[i - 3][j + 3] == board[i - 4][j + 4])
			{
				return board[i][j];
			}
		}
	}
	//判断平局
	if (IsFull(board, ROW, COL))
	{
		return 'Q';
	}
	return 'C';
}

int IsFull(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}