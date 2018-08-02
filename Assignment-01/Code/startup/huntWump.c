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

   startMenu();
   
   /* return EXIT_SUCCESS; */
   return 0;
}

void showStudentInformation() {
   /* TODO not provided */
   printf(
        "----------------------------------\n"
        "Name: Elliot Schot\n"
        "Student ID: S3530160\n"
        "Email: S3530160@student.rmit.edu.au\n"
        "----------------------------------\n"
        "\n"
		);
}

#define INPUT_MAX_LENGTH 1
#define NEW_LINE_SPACE 1
#define NULL_SPACE 1
#define EXTRA_SPACES (NEW_LINE_SPACE + NULL_SPACE)

void startMenu() {
    int inputResult;
    int input[INPUT_MAX_LENGTH + EXTRA_SPACES];

    showStartMenu();
    inputResult = getInput("Please enter your choice:", input, sizeof(input));
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

    /*
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
		);
}

void exitProgram(){
    printf("Good bye! \n\n");
    exit(0);
}