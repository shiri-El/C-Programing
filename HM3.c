/*
ASSINGMENT NO ' 3
NAME : SHIRI ABUDARAM
ID :032552945
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define BOARDSIZE 10
#define NOBOAT 0
#define YESBOAT 1
#define MISS 2
#define HIT 3
#define NUMOFSHIPS 5
void initializeBoard(int );
void draw_board(char );
void randomizeShips(int, int);
int shoot(int, int, int);
void printCurent(int);
void play(int);
int check_if_game_ended(int);
int main()
{
	int i, j;
	int board[BOARDSIZE][BOARDSIZE];
	srand(time(NULL));
	play(board);
	return 0;
}
void initializeBoard(int arr[BOARDSIZE][BOARDSIZE]) {
	//set all board values to no battleship/not selected
	int r, c;
	for (r = 0; r < BOARDSIZE; r++) {
		for (c = 0; c < BOARDSIZE; c++) {
			arr[r][c] = NOBOAT;
		}
	}
}
void draw_board(char array[BOARDSIZE][BOARDSIZE])
{//draw the board 
	int i, r, c;
	printf("   ");
	for (i = 0; i < BOARDSIZE; i++)
		printf("%d ", i);//numeric the matrix
	printf("\n ");
	for (i = 0; i < BOARDSIZE + 2; i++)
		printf("<>");
	printf("\n");

	for (i = 0; i < BOARDSIZE; i++) {
		printf("%d", i);//call for the raw draw function
		int j;

		printf("<>");
		//
		for (j = 0; j < BOARDSIZE; j++) {
			printf("%c ", array[i][j]);
		}

		printf("<>\n");
		
	}
	printf(" ");
	for (i = 0; i < BOARDSIZE + 2; i++)
		printf("<>");

	printf("\n");
		
}
void randomizeShips(int arr[BOARDSIZE][BOARDSIZE], int num_ships)
{//function that place the boat random
	int direction=0, row=0, col=0, i=0, j=0, noBoatCase=0, dirTest=0,lenship=0, countLenShip=0, countModCase = 0;
	for (i = 0; i < num_ships; i++)
	{
		do//while the direction is good
		{
			noBoatCase = 0;
			dirTest = 0;
			do {//rand cordinat while there is no boat placed
				col = rand() % 10;
				row = rand() % 10;
			} while (arr[col][row] != NOBOAT);
			direction = rand() % 4; //diection select random
			switch (i)//type of sub's
			{
			case 0:
				lenship = 2; break;
			case 1:
				lenship = 3; break;
			case 2:
				lenship = 3; break;
			case 3:
				lenship = 4; break;
			case 4:
				lenship = 5; break;
			};
			switch (direction) //empty cases checker
			{
			case 0://right
			{//check if there is no boat from the right
				if (col + lenship - 1 < BOARDSIZE)
				{
					for (countLenShip = 1; countLenShip < lenship; countLenShip++)
					{
						if (arr[row][col + countLenShip] == NOBOAT)
						{
							noBoatCase += 1;
						}

					}
				}
				if (noBoatCase == lenship - 1)
				{//place the boat in the place
					dirTest = 1;
					for (countModCase = 0; countModCase < lenship; countModCase++)
					{
						arr[row][col + countModCase] = YESBOAT;
					}
				}
			}
				break;
			case 1://up
			{//check if there is boat from the cordinat up
				if (row - (lenship - 1) >= 0)
				{
					for (countLenShip = 1; countLenShip < lenship; countLenShip++)
						if (arr[row + countLenShip][col] == NOBOAT)
							noBoatCase += 1;
				}
				if (noBoatCase == lenship - 1)
				{//place the boat
					dirTest = 1;
					for (countModCase = 0; countModCase < lenship; countModCase++)
					{
						arr[row + countModCase][col] = YESBOAT;
					}
				}
			}
			break;
			case 2://left
			{//check if there is boat place to the left of the boat
				if (col - (lenship -1) >= 0)
				{
					for (countLenShip = 1; countLenShip < lenship; countLenShip++)
						if (arr[row][col - countLenShip] == NOBOAT)
							noBoatCase += 1;
				}
				if (noBoatCase == lenship - 1) {
					dirTest = 1;
					for (countModCase = 0; countModCase < lenship; countModCase++)
						arr[row][col - countModCase] = YESBOAT;
				}
			}
			break;
			case 3://down
			{//check if there is no boat down the cordinate
				if (row + lenship -1  < BOARDSIZE)
					for (countLenShip = 1; countLenShip < lenship; countLenShip++)
						if (arr[row - countLenShip][col] == NOBOAT)
							noBoatCase += 1;

				if (noBoatCase == lenship - 1)
				{//place the boat 
					dirTest = 1;
					for (countModCase = 0; countModCase < lenship; countModCase++)
					{
						arr[col - countModCase][row] = YESBOAT;
					}
				}
			}
				break;
			};
		} while (dirTest == 0);
	}
}
int shoot(int board[BOARDSIZE][BOARDSIZE], int row, int col)
{//check the place in the board if hit or miss and id the cordinate are ok
	int i = row, j = col;
	if ((row > BOARDSIZE - 1 || row < 0) || (col > BOARDSIZE - 1 || col < 0))
	{

		if (col == -1 && row == -1)
		{
			printf("see you next time :)\n");
			exit(1);
		}
		printf("ILLEGAL VALUS!!\nPLEASE TRY AGAIN!\n");
		return -1;

	}
	if (board[row][col] == NOBOAT)
	{
		printf("Miss!!!\n");
		board[i][j] = MISS;
		return MISS;
	}
	if (board[row][col] == HIT || board[row][col] == MISS)
	{
		printf("Already shot there.\n");
		return 0;
	}
	if (board[row][col] == YESBOAT)
	{
		printf("HIT!!!\n");
		board[i][j] = HIT;
		return HIT;
	}
	return 0;
}
void printCurent(int arr[BOARDSIZE][BOARDSIZE]) //print the result of the board
{
	char arrResult[BOARDSIZE][BOARDSIZE];//ok
	int i, g,r,c;
	for (r = 0; r < BOARDSIZE; r++) {
		for (c = 0; c < BOARDSIZE; c++) {
			arrResult[r][c] = ' ';
		}
	}
	for (i = 0; i < BOARDSIZE; i++)
	{
		for (g = 0; g < BOARDSIZE; g++)
		{
			if ( arr[i][g] == HIT)
			{
				arrResult[i][g] = 'X';
				
			}
			if (arr[i][g] == MISS)
			{
				arrResult[i][g] ='~';
			}
			if (arr[i][g] == NOBOAT || arr[i][g] == YESBOAT)
			{
				arrResult[i][g] = ' ';
			}
		}
		printf("\n");
	}
	draw_board(arrResult);
	
}
void play(int board[BOARDSIZE][BOARDSIZE])
{//call for all the functions in the game
	int  row = 0, col = 0, res = 0, continuee = 1;
	///as long as the user want to play
	initializeBoard(board);
	printCurent(board);
	randomizeShips(board, NUMOFSHIPS);
	printf("Enter pair coordinates:\n");
	scanf("%d%d", &row, &col);
	shoot(board, row, col);
	printCurent(board);
	if (col == -1 && row == -1)//if the user want to exit
	{
		printf("see you next time :)\n");
		exit(1);
	}

	while (row != -1 && col != -1 && continuee )//as long as the user didnt want to exit
	{
		printf("Enter pair coordinates:\n");
		scanf("%d%d", &row, &col);
		res = shoot(board, row, col);
		if (res == 0 )
		{
			printf("youv've chosen a coordinates that already been chosen! please choose something else!\n");
		}
		else
			hits += printCurent(board);
		continuee =1 - check_if_game_ended(board);
	}
	if (continuee==0)
	{
		printf("the game ended\nYOU WON!\nyou hit %d times\n",17);
	}
	
}
int check_if_game_ended(int board[BOARDSIZE][BOARDSIZE])
{//function that check if all the subs been shut
	int row, col = 0, subflag = 0;
	for (row = 0; row < BOARDSIZE; row++)
	{
		for (col = 0; col < BOARDSIZE; col++)
		{
			if (board[row][col]==YESBOAT)
			{
				subflag = 0;
				return subflag;
			}
		}
	}
	subflag = 1;
	return subflag;
}