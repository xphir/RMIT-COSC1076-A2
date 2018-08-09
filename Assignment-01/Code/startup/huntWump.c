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
    printf("DEBUG main(): 1.1 - Starting program\n");
    startMenu();

    /* return EXIT_SUCCESS; */
    printf("DEBUG startMenu(): 1.2 - Ending program?\n");
    return 0;
}

void showStudentInformation()
{
    printf(
        "----------------------------------\n"
        "Name: %s\n"
        "Student ID: %s\n"
        "Email: %s\n"
        "----------------------------------\n"
        "\n",
        "Elliot Schot",
        "S3530160",
        "S3530160@student.rmit.edu.au");
}

#define INPUT_MAX_LENGTH 1
#define NEW_LINE_SPACE 1
#define NULL_SPACE 1
#define EXTRA_SPACES (NEW_LINE_SPACE + NULL_SPACE)

void showStartMenu()
{
    printf(
        "Welcome to Hunt the Wumpus\n"
        "--------------------------\n"
        "1. Play game\n"
        "2. Show student information\n"
        "3. Quit\n"
        "\n"
        "Please enter your choice: ");
}

void exitProgram()
{
    printf("Good bye! \n\n");
    exit(0);
}

void startMenu()
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
        readResult = readInput(&input, 1 + EXTRA_SPACES, stdin);
        /*
        printf("Read Result: %d\n",readResult);
        printf("Input Char: %s\n", &input);
        */
        putchar(10);
        if (readResult == ReadInputResultSuccess)
        {
            printf("DEBUG startMenu(): 1.1 - Valid readResult\n");
            inputInt = strtol(&input, &inputEndPtr, 10);
            /*
            printf("Input Int: %d\n",inputInt);
            printf("inputEndPtr Int: %s\n",inputEndPtr);
            */

            if (/* inputEndPtr == &input || *inputEndPtr  || */ inputInt <= 0 || inputInt > 3)
            {
                printf("DEBUG startMenu(): 2.1 - Invalid inputInt\n");
                printInvalidInput();
            }
            else if (inputInt == 2)
            {
                printf("DEBUG startMenu(): 2.2 - Show student Info\n");
                showStudentInformation();
            }
            else if (inputInt == 3)
            {
                printf("DEBUG startMenu(): 2.3 - Starting Quit\n");
                ongoing = FALSE;
            }
            else
            {
                if (inputInt != 1)
                {
                    assert(0);
                }
                /* printf("Play The Game!"); */
                printf("DEBUG startMenu(): 2.3 - Play Game\n");
                game_PlayGame();
            }
        }
        else
        {
            printf("DEBUG startMenu(): 1.1 - Invalid readResult\n");
            printInvalidInput();
        }
    }
    puts("Good bye! \n");
    exit(EXIT_SUCCESS);
}

void Test(){

    /* Used for testing */

}