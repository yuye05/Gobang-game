#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

#define ROW 12
#define COL 12

#define RED "\033[31m"
#define WHITE "\033[37m"
#define RESET "\033[0m"
#define GREEN "\033[32m"
//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayMove(char board[ROW][COL], int row, int col);

//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);

//判断输赢
char Iswin(char board[ROW][COL], int row, int col);
//玩家赢-'*'
//电脑赢-'#'
//平局-'Q'
//继续-'C'

//双人模式
void FirstPlayer(char board[ROW][COL], int row, int col);
void SecondPlayer(char board[ROW][COL], int row, int col);
