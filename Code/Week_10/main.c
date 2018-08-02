#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
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
    if(fgets(str, num, stdin) == NULL)
    {
        return false;
    }

    if(str[strlen(str) - 1] != '\n')
    {
        readRestOfLine();
        return false;
    }
    str[strlen(str) - 1] = '\0';

    return strlen(str) > 0;
}

void addPerson(LinkedList * linkedList)
{
    Person person;
    char ageInput[100 + 1];
    char * endPtr;
    int age;

    printf("Add Person \n");

    printf("Enter first name: ");
    if(!getInput(person.fname, sizeof(person.fname)))
    {
        printf("\n");
        return;
    }

    printf("Enter last name: ");
    if(!getInput(person.lname, sizeof(person.lname)))
    {
        printf("\n");
        return;
    }

    printf("Enter age: ");
    if(!getInput(ageInput, sizeof(ageInput)))
    {
        printf("\n");
        return;
    }
    age = strtol(ageInput, &endPtr, 10);
    if(ageInput == endPtr || *endPtr != '\0' || age < 0)
    {
       printf("Invalid input. \n\n");
       return;
    }
    person.age = age;

    addToLinkedList(linkedList, &person);

    printf("\n");
}

void removePerson(LinkedList * linkedList)
{
    Person person;

    printf("Remove Person \n");

    printf("Enter last name: ");
    if(!getInput(person.lname, sizeof(person.lname)))
    {
        printf("\n");
        return;
    }

    if(removeFromLinkedList(linkedList, person.lname))
    {
        printf("Person with last name '%s' has been removed \n", person.lname);
    }
    else
    {
        printf("Person with last name '%s' was not found \n", person.lname);
    }
    printf("\n");
}

void printLinkedList(LinkedList * linkedList)
{
    printf("--- Printing Linked List --- \n");
    ListPrint(linkedList);
    printf("\n");
}

void printLinkedListReversed(LinkedList * linkedList)
{
    printf("--- Printing Linked List Reversed --- \n");
    ListPrintReversed(linkedList);
    printf("\n");
}

int main()
{
    LinkedList * linkedList;

    linkedList = initialiseLinkedList();

    while(true)
    {
        char optionInput[100 + 1];
        char * endPtr;
        int option;
        bool success;

        printf("1. Add Person \n"
               "2. Remove Person \n"
               "3. Print Linked List \n"
               "4. Print Linked List Reversed \n"
               "5. Quit \n");
        printf("Enter option: ");

        success = getInput(optionInput, sizeof(optionInput));
        printf("\n");

        if(!success)
        {
            printf("Invalid input. \n\n");
            continue;
        }

        option = strtol(optionInput, &endPtr, 10);
        if(optionInput == endPtr || *endPtr != '\0' || option < 1 || option > 5)
        {
           printf("Invalid input. \n\n");
           continue;
        }

        if(option == 1)
        {
            addPerson(linkedList);
        }
        else if(option == 2)
        {
            removePerson(linkedList);
        }
        else if(option == 3)
        {
            printLinkedList(linkedList);
        }
        else if(option == 4)
        {
            printLinkedListReversed(linkedList);
        }
        else if(option == 5)
        {
            break;
        }
        else
        {
            assert(false);
        }
    }

    linkedList = freeLinkedList(linkedList);

    return EXIT_SUCCESS;
}
