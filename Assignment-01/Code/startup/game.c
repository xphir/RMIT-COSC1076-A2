/*
 * COSC1076 Assignment 1, Semester 2 2018
 * Student name  :
 * Student number:
 */
#include "game.h"

void game_PlayGame()
{
	char input;
	Board board;
	Player player;

	srand(0);
	game_DisplayOptions();

	readInput(&input, 2, stdin);
	if (game_AttemptLoadCommand(&board))
	{

		if (game_AttemptInitCommand(&board, &player))
		{
			/* game_Hunt(board, player); */
		}
	}
	printf("Set Cell Value %d\n", board[1][1]);
	board_Display(board);
}

/* DONE */
int game_DisplayOptions()
{
	return printf(
		"You can use the following commands to play the game: \n"
		"\n"
		"load <g> \n"
		" g: number of the game board to load (either 1 or 2)\n"
		"init <x>,<y>\n"
		" x: horizontal position of the player on the board (between 0 & 4) \n"
		" y: vertical position of the player on the board (between 0 & 4) \n"
		"north (or n) \n"
		"south (or s) \n"
		"east (or e) \n"
		"west (or w) \n"
		"quit \n"
		"\n"
		"Press enter to continue... ");
}

Boolean game_AttemptLoadCommand(Board *board)
{
	char input;
	char *promptMessage;

	promptMessage = "At this stage of the program, only two commands are acceptable: \nload <g> \nquit \n\n";
	while (TRUE)
	{
		while (TRUE)
		{
			getInput(promptMessage, &input, 52);
			putchar(10);
			if (!strcmp(&input, "quit"))
				return FALSE;
			if (!strncmp(&input, "load", 4))
				break;
			printInvalidInput();
		}
		/*break;*/

		if (game_CommandLoad(&input, board))
		{
			break;
		}

		printInvalidInput();
	}

	puts("Board successfully loaded\n");
	return TRUE;
}

Boolean game_CommandLoad(char *loadSelection, Board *board)
{
	Boolean result;
	char *endptr;
	char *nptr;
	int selectedBoard;

	strtok(loadSelection, " ");
	nptr = strtok(NULL, "\0");
	if (nptr)
	{
		selectedBoard = strtol(nptr, &endptr, 10);
		if (nptr == endptr || *endptr || selectedBoard <= 0 || selectedBoard > BOARD_AMMOUNT)
		{
			result = FALSE;
		}
		else
		{
			if (selectedBoard == 1)
			{
				board_Load(board, &BOARD_1);
			}
			else
			{
				if (selectedBoard != 2)
					assert(0);
				board_Load(board, &BOARD_2);
			}
			result = TRUE;
		}
	}
	else
	{
		result = FALSE;
	}
	return result;
}

Boolean game_AttemptInitCommand(Board *board, Player *player)
{
	char input;
	int selectionInt;
	char *promptMessage;

	promptMessage = "At this stage of the program, only two commands are acceptable: \ninit <x>,<y> \nquit \n\n";
	do
	{
		while (TRUE)
		{
			getInput(promptMessage, &input, 52);
			if (!strcmp(&input, "quit"))
				return FALSE;
			if (!strncmp(&input, "init", 4))
				break;
			printInvalidInput();
		}
		selectionInt = game_CommandInit(&input, board, player);
	} while (selectionInt != 1);
	return TRUE;
}

Boolean game_CommandInit(char *input, Board *board, Player *player)
{
	Boolean placePlayerResult;
	Boolean result;
	Position selectedPosition;
	Player *localPlayer;
	char *endptr;
	char *nptr;

	printf("Debug Print 1.1: Input = %s\n", input);

	localPlayer = player;
	strtok(input, " ");

	printf("Debug Print 1.2: Input = %s\n", input);
	nptr = strtok(NULL, ",");

	printf("Debug Print 1.3: nptr = %s\n", nptr);
	if (nptr)
	{
		selectedPosition.x = strtol(nptr, &endptr, 10);
		printf("Debug Print 2: X = %d\n", selectedPosition.x);
		if (nptr == endptr || *endptr || selectedPosition.x < 0 || selectedPosition.x > BOARD_WIDTH)
		{
			printf("Debug Print 2.2: %s, %s, %d, %d\n", nptr, endptr, selectedPosition.x, BOARD_WIDTH);
			printf("Debug Print 2.3: Exit 1\n");
			printInvalidInput();
			result = FALSE;
		}
		else
		{
			nptr = strtok(NULL, ",");
			printf("Debug Print 2.4: nptr = %s\n", nptr);
			if (nptr)
			{
				selectedPosition.y = strtol(nptr, &endptr, 10);
				printf("Debug Print 3: Y = %d\n", selectedPosition.y);
				if (nptr == endptr || *endptr || selectedPosition.y < 0 || selectedPosition.y > BOARD_HEIGHT)
				{
					printf("Debug Print 3.1: Exit 1\n");
					printInvalidInput();
					result = FALSE;
				}
				else
				{
					printf("Debug Print 4: Placing Player\n");
					placePlayerResult = board_PlacePlayer(board, selectedPosition);
					if (placePlayerResult)
					{
						printf("Debug Print 4.1: Placing Player Result: %d\n", placePlayerResult);
						player_Initialise(localPlayer, selectedPosition);
					}
					else
					{
						printf("Unable to place player at position x: %d, y: %d \n", selectedPosition.x, selectedPosition.y);
					}
					result = placePlayerResult;
				}
			}
			else
			{
				printf("Debug Print 5: Exit 1\n");
				printInvalidInput();
				result = FALSE;
			}
		}
	}
	else
	{
		printInvalidInput();
		result = FALSE;
	}
	return result;
}
