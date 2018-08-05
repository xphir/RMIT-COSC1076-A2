/*
 * COSC1076 Assignment 1, Semester 2 2018
 * Student name  :
 * Student number:
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>


#ifndef BOARD_H
#define BOARD_H

#define BOARD_WIDTH 5
#define BOARD_HEIGHT 5

#define NUM_PITS 4
#define NUM_BATS 3
#define NUM_WUMPUS 1

typedef enum cell
{
	board_EMPTY,		
	board_TRAVERSED, /* an empty cell player has previously visited */
	board_BATS,		
	board_PIT,		
	board_WUMPUS,
	board_PLAYER
} Cell;

#define EMPTY_OUTPUT "  "
#define PLAYER_OUTPUT "##"
#define TRAVERSED_OUTPUT "**"

typedef Cell Board[BOARD_HEIGHT][BOARD_WIDTH];

Board BOARD_1, BOARD_2;


/**
 * Display the board according to the assignment specification. 
 * Here is an example output:

    0  1  2  3  4 
   ----------------
 0 |**|##|  |  |  |
   ---------------- 
 1 |  |  |  |  |  |
   ----------------  
 2 |  |  |  |  |  |
   ---------------- 
 3 |  |  |  |  |  |  
   ----------------
 4 |  |  |  |  |  |
   ---------------- 
 */

void board_Display(Board board);


#endif
