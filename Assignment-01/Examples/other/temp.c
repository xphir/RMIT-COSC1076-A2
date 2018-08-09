


/* To fix type */
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

/* To fix type */
void game_CommandShoot(){

}

/* To fix type */
void game_AttemptMoveCommand(){

}

/* To fix type */
void game_Hunt(Board * board, Player * player){
	printf("GAME HUNT\n");
}


Boolean game_CommandLoad(char * loadSelection, Board * board)
{
	board_Load(&board, &BOARD_1);
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