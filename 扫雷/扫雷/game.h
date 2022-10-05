#define ROW 10
#define COL 10
#define ROWS ROW+2
#define COLS ROW+2
#define DIF 10

#include<stdio.h>

void Lniche(char outside[ROWS][COLS], int row,int col,char r);
void Disboard(char outside[ROWS][COLS], int row, int col);
void Putboard(char inside[ROWS][COLS], int row, int col);
void Process(char inside[ROWS][COLS], char outside[ROWS][COLS]);
void Disboard2(char side[ROWS][COLS], int row, int col);