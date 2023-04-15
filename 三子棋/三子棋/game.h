#define ROW 3
#define COL 3

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void Board(char arr[ROW][COL], int row, int col);
void Displayboard(char arr[ROW][COL], int row, int col);
void Game(char arr[ROW][COL], int row, int col);
char Win(char arr[ROW][COL], int row, int col);
void PlayerMove(char arr[ROW][COL], int row, int col);
void ComputerMove(char arr[ROW][COL], int row, int col);