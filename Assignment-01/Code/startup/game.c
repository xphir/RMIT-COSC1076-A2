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

	/* COMPLETE Sets no random variation */
	srand(0);
	/* COMPLETE Shows game options */
	game_DisplayOptions();
	/* COMPLETE Takes an enter input - ie no vales */
	readInput(&input, 2, stdin);
	/* COMPLETE tries to load the game then calls subcalls > game_CommandLoad()*/
	if (game_AttemptLoadCommand(board))
	{
		/* COMPLETE tries to initialise the player then calls > game_CommandInit */
		if (game_AttemptInitCommand(board, &player))
		{
			/* COMPLETE starts the game (eg movement, shooting, quit */
			game_Hunt(board, &player);
		}
	}
}

/* DONE */
void game_DisplayOptions()
{
	printf(
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

Boolean game_AttemptLoadCommand(Board board)
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

Boolean game_CommandLoad(char *loadSelection, Board board)
{
	Boolean moveResult;
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
			moveResult = FALSE;
		}
		else
		{
			if (selectedBoard == 1)
			{
				board_Load(board, BOARD_1);
			}
			else
			{
				if (selectedBoard != 2)
					assert(0);
				board_Load(board, BOARD_2);
			}
			moveResult = TRUE;
		}
	}
	else
	{
		moveResult = FALSE;
	}

	return moveResult;
}

Boolean game_AttemptInitCommand(Board board, Player * player)
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

Boolean game_CommandInit(char *input, Board board, Player * player)
{
	Boolean placePlayermoveResult;
	Boolean moveResult;
	Position selectedPosition;
	char *endptr;
	char *nptr;

	strtok(input, " ");

	nptr = strtok(NULL, ",");

	if (nptr)
	{
		selectedPosition.x = strtol(nptr, &endptr, 10);
		if (nptr == endptr || *endptr || selectedPosition.x < 0 || selectedPosition.x > BOARD_WIDTH)
		{
			printInvalidInput();
			moveResult = FALSE;
		}
		else
		{
			nptr = strtok(NULL, ",");
			if (nptr)
			{
				selectedPosition.y = strtol(nptr, &endptr, 10);
				if (nptr == endptr || *endptr || selectedPosition.y < 0 || selectedPosition.y > BOARD_HEIGHT)
				{
					printInvalidInput();
					moveResult = FALSE;
				}
				else
				{
					placePlayermoveResult = board_PlacePlayer(board, selectedPosition);
					if (placePlayermoveResult)
					{
						player_Initialise(player, selectedPosition);
					}
					else
					{
					}
					moveResult = placePlayermoveResult;
				}
			}
			else
			{
				printInvalidInput();
				moveResult = FALSE;
			}
		}
	}
	else
	{
		printInvalidInput();
		moveResult = FALSE;
	}
	return moveResult;
}

void game_Hunt(Board board, Player * player)
{
	char input;
	char *promptMessage;
	unsigned int direction;
	int ongoing;

	ongoing = TRUE;
	while (ongoing)
	{
		promptMessage = "At this stage of the program, only three commands are acceptable: \n"
						" <direction> \n"
						" shoot <direction> \n"
						" quit \n"
						"Where <direction> is one of: north,n,south,s,east,e,west,w\n"
						"\n"
						"Please enter your choice: ";

		board_Display(board);
		board_DisplayWarnings(board, player->position);
		putchar(10);
		getInput(promptMessage, &input, 52);
		
		if (!strcmp(&input, "north") || !strcmp(&input, "n"))
		{
			direction = player_NORTH;
			ongoing = game_AttemptMoveCommand(board, player, direction);
		}
		else if (!strcmp(&input, "south") || !strcmp(&input, "s"))
		{
			direction = player_SOUTH;
			ongoing = game_AttemptMoveCommand(board, player, direction);
		}
		else if (!strcmp(&input, "east") || !strcmp(&input, "e"))
		{
			direction = player_EAST;
			ongoing = game_AttemptMoveCommand(board, player, direction);
		}
		else if (!strcmp(&input, "west") || !strcmp(&input, "w"))
		{
			direction = player_WEST;
			ongoing = game_AttemptMoveCommand(board, player, direction);
		}
		else if (!strncmp(&input, "shoot", 5))
		{
			ongoing = game_CommandShoot(&input, board, player) == 0;
		}
		else
		{
			if (!strcmp(&input, "quit"))
			{
				ongoing = FALSE;
				return;
			}
			printInvalidInput();
		}
	}
}

PlayerMove game_AttemptMoveCommand(Board board, Player * player, Direction direction)
{
	Position nextPosition;
	Position nextPositionCopy;
	Position batDragPosition;
	PlayerMove moveType;
	Direction directionCopy;
	PlayerMove moveResult;
	char *message;

	directionCopy = direction;
	do
	{
		nextPosition = player_GetNextPosition(player->position, directionCopy);
		nextPositionCopy = nextPosition;
		moveType = board_MovePlayer(board, player->position, nextPosition);
		moveResult = moveType;
		if (moveType == board_PLAYER_KILLED)
		{
			message = "Player killed!";
		}
		else if (moveType == board_PLAYER_MOVED)
		{
			message = "Player moved.";
			player->position = nextPositionCopy;
		}
		else if (moveType == board_BAT_CELL)
		{
			message = "Bat cell!";
			do
			{
				batDragPosition.x = rand() % 5;
				batDragPosition.y = rand() % 5;
			} while (!board_PlacePlayer(board, batDragPosition));
			player->position = batDragPosition;
			moveResult = board_PLAYER_MOVED;
		}
		else if (moveType == board_OUTSIDE_BOUNDS)
		{
			message = "Unable to move - outside bounds.";
		}
		else
		{
			assert(0);
		}
	} while (moveResult && moveResult != board_PLAYER_KILLED && moveResult != board_OUTSIDE_BOUNDS);
	printf("%s \n\n", message);
	return moveResult != board_PLAYER_KILLED;
}

Boolean game_CommandShoot(char *inputTODO, Board board, Player * player)
{
	Boolean result;
	Position arrowTarget;
	ArrowHit arrowResult;
	char *inputTok;
	Direction arrowDirection;

	result = FALSE;
	strtok(inputTODO, " ");
	inputTok = strtok(NULL, " ");
	if (!inputTok)
	{
		printInvalidInput();
		return FALSE;
	}
	if (!strcmp(inputTok, "north") || !strcmp(inputTok, "n"))
	{
		arrowDirection = player_NORTH;
	}
	else if (!strcmp(inputTok, "south") || !strcmp(inputTok, "s"))
	{
		arrowDirection = player_SOUTH;
	}
	else if (!strcmp(inputTok, "east") || !strcmp(inputTok, "e"))
	{
		arrowDirection = player_EAST;
	}
	else if (!strcmp(inputTok, "west") || !strcmp(inputTok, "w"))
	{
		arrowDirection = player_WEST;
	}
	else
	{
		printInvalidInput();
		return FALSE;
	}
	if (player->numArrows)
	{
		arrowTarget = player_GetNextPosition(player->position, arrowDirection);
		arrowResult = board_FireArrow(board, arrowTarget);
		if (arrowResult == board_WUMPUS_KILLED)
		{
			--player->numArrows;
			puts("You killed the Wumpus!\n");
			result = TRUE;
		}
		else if (arrowResult == board_ARROW_MISSED)
		{
			--player->numArrows;
			printf("Missed. You now have %d arrows\n\n", player->numArrows);
		}
		else if (arrowResult == board_ARROW_OUTSIDE_BOUNDS)
		{
			puts("Unable to fire arrow in that direction. \n");
		}
		else
		{
			assert(0);
		}
	}
	else
	{
		puts("You don't have any arrows to fire.\n");
		result = FALSE;
	}
	return result;
}