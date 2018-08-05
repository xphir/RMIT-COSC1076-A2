/*
 * COSC1076 Assignment 1, Semester 2 2018
 * Student name  :
 * Student number:
 */
#include "board.h"

Board BOARD_1 =
{
   	{ board_EMPTY,  board_EMPTY,  board_EMPTY,  board_PIT,    board_EMPTY},
	{ board_EMPTY,  board_EMPTY,  board_EMPTY,  board_EMPTY,  board_EMPTY},
	{ board_BATS,   board_EMPTY,  board_EMPTY,  board_WUMPUS, board_EMPTY},
	{ board_EMPTY,  board_PIT,    board_EMPTY,  board_EMPTY,  board_EMPTY},
	{ board_EMPTY,  board_EMPTY,  board_BATS,   board_EMPTY,  board_EMPTY}
};

Board BOARD_2 =
{
	{ board_PIT,    board_EMPTY,  board_PIT,    board_EMPTY,  board_EMPTY},
	{ board_EMPTY,  board_EMPTY,  board_EMPTY,  board_EMPTY,  board_EMPTY},
	{ board_EMPTY,  board_EMPTY,  board_BATS,   board_EMPTY,  board_EMPTY},
	{ board_EMPTY,  board_EMPTY,  board_EMPTY,  board_EMPTY,  board_BATS },
	{ board_EMPTY,  board_WUMPUS, board_EMPTY,  board_EMPTY,  board_EMPTY},
};

Boolean board_Load(Board * board, Board * boardToLoad) {
	memcpy(board, *boardToLoad, sizeof(*boardToLoad));

	/*

	int x;
	int y;
	for(x = 0; x < BOARD_HEIGHT; x++)
	{ 
		for(y = 0; y < BOARD_WIDTH; y++)
		{
			board[y][x] = boardToLoad[y][x];
		}
	}

	for(int i = 0; i<BOARD_HEIGHT; i++)
  	{
    	for(int j = 0; j < BOARD_WIDTH; j++)
    	{
      		board[i][j] = boardToLoad[i][j];
    	}
  	}
	*/
	return TRUE;
}

Boolean board_PlacePlayer(Board * board, Position position) {
	/* TODO */
	Cell *c;
	c = board[position.y][position.x];

	
	if(position.x < 0 || position.x >= BOARD_WIDTH || position.y < 0 || position.y >= BOARD_HEIGHT) /* Check if selection is out of bounds */
	{
		return FALSE;
	} 
	else if(*c == board_WUMPUS || *c == board_BATS || *c == board_PIT) 	/* Check if selection is in a hazard */
	{
		return FALSE;
	}
	else
	{
		*board[position.y][position.x] =  board_PLAYER;
		printf("Position %d,%d\n",position.x,position.y);
		printf("C Value %d\n",board_PLAYER);
		printf("Interal Set Cell Value %d\n",*board[position.y][position.x]);
		return TRUE;
	}
	
}


PlayerMove board_MovePlayer(Board board, Position playerPosition, 
			    Position nextPosition) {
   /* TODO */
   return board_PLAYER_MOVED;
}

ArrowHit board_FireArrow(Board board, Position position) {
   /* TODO */
   return board_ARROW_MISSED;
}

void board_Display(Board board) {
int x, y;
	/* Print x axis (top side) numbers */
	printf("   ");
	for ( y = 0; y < BOARD_HEIGHT; ++y )
	{
		printf("%d  ", y);
	}
		
	putchar(10);

	for ( x = 0; x < BOARD_WIDTH; ++x )
	{

		/* Print line split */
		printf("  -");
		for ( y = 0; y < BOARD_HEIGHT; ++y )
		{
			printf("---");
		}

		/* Print y axis (left side) numbers */
		printf("\n%d ", x);

		for ( y = 0; y < BOARD_HEIGHT; ++y )
		{
			putchar(124);
			/* Check what type of cell it is */
			switch (board[x][y])
			{
				case 0: /* board_EMPTY */
					printf("EE");
					break;
				case 2: /* board_BATS */
					printf("BB");
					break;
				case 3: /* board_PIT */
					printf("PT");
					break;
				case 4: /* board_WUMPUS */
					printf("  ");
					break;
				case 1: /* board_TRAVERSED */
					printf("**");
					break;
				case 5: /* board_PLAYER */
					printf("##");
					break;
				default:
					assert(0);
			}
		}

		putchar(124);
		putchar(10);
	}
	printf("  -");

	for ( x = 0; x < BOARD_WIDTH; ++x )
	{
		printf("---");
	}

	putchar(10);
}

void board_DisplayWarnings(Board board, Position position){
   /* TODO */
}