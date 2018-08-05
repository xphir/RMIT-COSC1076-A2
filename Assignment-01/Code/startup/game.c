/*
 * COSC1076 Assignment 1, Semester 2 2018
 * Student name  :
 * Student number:
 */
#include "game.h"

void game_PlayGame(){
	char input;
	Board board;
	Player player;

	srand(0);
	game_DisplayOptions();

	readInput(&input, 2, stdin);
	if (game_AttemptLoadCommand(&board))
	{
		
		if (game_AttemptInitCommand(&board, &player) )
		{
			/* game_Hunt(board, player); */
		}
		
		
	}
	printf("Set Cell Value %d\n",board[1][1]);
	board_Display(board);
}

/* DONE */
int game_DisplayOptions(){
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
	"Press enter to continue... "
    );
}

Boolean game_AttemptLoadCommand(Board * board){
	char input;
	char *promptMessage;

	promptMessage = "At this stage of the program, only two commands are acceptable: \nload <g> \nquit \n\n";
	while (TRUE)
	{
		while (TRUE)
		{
			getInput(promptMessage, &input, 52);
			putchar(10);
			if ( !strcmp(&input, "quit") )
				return FALSE;
			if ( !strncmp(&input, "load", 4) )
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

Boolean game_CommandLoad(char * loadSelection, Board * board)
{
	board_Load(board, &BOARD_1);
	return TRUE;

	/*
	char *endptr;
	char *selectionTok;
	int selectionInt;

	strtok(loadSelection, " ");
	selectionTok = strtok(0LL, &byte_402062);
	if (selectionTok)
	{
		selectionInt = strtol(selectionTok, &endptr, 10);
		if ( selectionTok == endptr || *endptr || selectionInt <= 0 || selectionInt > 2 )
		{
		return TRUE;
		}
		else
		{
		if ( selectionInt == 1 )
		{
			board_Load(a2, &BOARD_1);
		}
		else
		{
			if ( selectionInt != 2 )
			{
				assert(0);
			}
			board_Load(a2, &BOARD_2);
		}
		return TRUE;
		}
	}
	else
	{
		return FALSE;
	}
	*/
}

Boolean game_AttemptInitCommand(Board * board, Player * player)
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
		if ( !strcmp(&input, "quit") )
			return FALSE;
		if ( !strncmp(&input, "init", 4) )
			break;
		printInvalidInput();
		}
		selectionInt = game_CommandInit(&input, board, player);
	}
	while ( selectionInt != 1 );
	return TRUE;
}

Boolean game_CommandInit(char * input, Board * board, Player * player){
  	Boolean placePlayerResult;
	Boolean result;
	Position selectedPosition;

	selectedPosition.x = 1;
	selectedPosition.y = 1;

	placePlayerResult = board_PlacePlayer(board, selectedPosition);
	if ( placePlayerResult )
	{
		player_Initialise(player, selectedPosition);
	}
	else
	{
		printf("Unable to place player at that position. \n");
	}
	result = placePlayerResult;
	return result;
	/* TODO REST */
}
