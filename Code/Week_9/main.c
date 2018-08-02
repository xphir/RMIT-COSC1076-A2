#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "person.h"

void readRestOfLine()
{
    int ch;

    /* Remove all characters from the buffer. */
    while(ch = getc(stdin), ch != '\n' && ch != EOF)
    { }

    /* Clear the error status of the input pointer. */
    clearerr(stdin);
}

bool getInput(char * str, int num)
{
    fgets(str, num, stdin);
    if(str[strlen(str) - 1] != '\n')
    {
        readRestOfLine();
        return false;
    }
    str[strlen(str) - 1] = '\0';

    return strlen(str) > 0;
}

int main()
{
    LinkedList * linkedList;

    linkedList = initialiseLinkedList();

    while(true)
    {
        Person person;
        char ageInput[100 + 1];
        char * endPtr;
        int age;

        printf("Enter first name: ");
        if(!getInput(person.fname, sizeof(person.fname)))
        {
            break;
        }

        printf("Enter last name: ");
        if(!getInput(person.lname, sizeof(person.lname)))
        {
            break;
        }

        printf("Enter age: ");
        if(!getInput(ageInput, sizeof(ageInput)))
        {
            break;
        }
        age = strtol(ageInput, &endPtr, 10);
        if(ageInput == endPtr || *endPtr != '\0' || age < 0)
        {
           printf("Invalid input. \n\n");
           continue;
        }
        person.age = age;

        addToLinkedList(linkedList, &person);

        printf("\n");
    }
    printf("\n");

    printf("--- Printing Linked List --- \n");
    printLinkedList(linkedList);

    linkedList = freeLinkedList(linkedList);

    return EXIT_SUCCESS;
}
