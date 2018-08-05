/*
 * COSC1076 Assignment 1, Semester 2 2018
 * Student name  :
 * Student number:
 */
#include "huntWump.h"

int main()
{
   /**
    * Here's the main function. You can write the "main menu" loop/code
    * here or you can make separate functions - up to you.
    */

   /* TODO not provided */
    test();

   
   /* return EXIT_SUCCESS; */
   return 0;
}

int showStudentInformation() {
   return printf(
        "----------------------------------\n"
        "Name: %s\n"
        "Student ID: %s\n"
        "Email: %s\n"
        "----------------------------------\n"
        "\n", 
        "Elliot Schot", 
        "S3530160", 
        "S3530160@student.rmit.edu.au"
		);
}

#define INPUT_MAX_LENGTH 1
#define NEW_LINE_SPACE 1
#define NULL_SPACE 1
#define EXTRA_SPACES (NEW_LINE_SPACE + NULL_SPACE)

void startMenu() {
    /*
    char * result;
    char line[INPUT_MAX_LENGTH + EXTRA_SPACES];
    int inputResult;
    int input[INPUT_MAX_LENGTH + EXTRA_SPACES];

    showStartMenu();
    result = getInput("Please enter your choice:", input, sizeof(input));
    printf("\n%d\n", input);
   

    switch(input)
    {
        case 1: printf("You have entered choice 1\n");
                    break;
        case 2: printf("You have entered choice 2\n");
                    showStudentInformation();
                    break;
        case 3: printf("You have entered choice 3\n");
                    exitProgram();
                    break;
        default: printf("Invalid choice!\n");
                    return;
    };

    
    if(inputResult = 2) {

    } else {
       startMenu();
    }
    */
}

void showStartMenu(){
    printf(
        "Welcome to Hunt the Wumpus\n"
        "--------------------------\n"
        "1. Play game\n"
        "2. Show student information\n"
        "3. Quit\n"
        "\n"
        "Please enter your choice: "
		);
}

void exitProgram(){
    printf("Good bye! \n\n");
    exit(0);
}

void gameDisplayOptions(){
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
	"Press enter to continue... "
    );
}

void test()
{
    char *inputEndPtr;
    char input;
    int inputInt;
    int readResult;
    Boolean ongoing;

    enableWindowsCompatibility();
    ongoing = TRUE;
    while (ongoing)
    {
        showStartMenu();
        readResult = readInput(&input, 3, stdin);
        /*
        printf("Read Result: %d\n",readResult);
        printf("Input Char: %s\n", &input);
        */
        putchar(10);
        if ( readResult == ReadInputResultSuccess )
        {
            inputInt = strtol(&input, &inputEndPtr, 10);
            /*
            printf("Input Int: %d\n",inputInt);
            printf("inputEndPtr Int: %s\n",inputEndPtr);
            */
            
            if ( /* inputEndPtr == &input || *inputEndPtr  || */ inputInt <= 0 || inputInt > 3 )
            {
                printInvalidInput();
            }
            else if ( inputInt == 2 )
            {
                showStudentInformation();
            }
            else if ( inputInt == 3 )
            {
                ongoing = FALSE;
            }
            else
            {
                if ( inputInt != 1 )
                {
                    assert(0);
                }
                /* printf("Play The Game!"); */
                game_PlayGame();
            }
        }
        else
        {
            printInvalidInput();
        }
    }
    puts("Good bye! \n");
    exit(EXIT_SUCCESS);
}
