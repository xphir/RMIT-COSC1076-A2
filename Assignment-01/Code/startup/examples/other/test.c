#include "test.h"

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

int main()
{
 	board_Display(BOARD_1);
	return 0;
}

void board_Display(Board board) {
	int x, y;
	/* Print x axis (top side) numbers */
	printf("   ");
	for ( y = 0; y < BOARD_WIDTH; ++y )
	{
		printf("%d  ", y);
	}
		
	putchar(10);

	for ( x = 0; x < BOARD_HEIGHT; ++x )
	{

		/* Print line split */
		printf("  -");
		for ( y = 0; y < BOARD_WIDTH; ++y )
		{
			printf("---");
		}

		/* Print y axis (left side) numbers */
		printf("\n%d ", x);

		for ( y = 0; y < BOARD_WIDTH; ++y )
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

	for ( x = 0; x < BOARD_HEIGHT; ++x )
	{
		printf("---");
	}

	putchar(10);
}