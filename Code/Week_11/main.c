#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "personlist.h"

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

void addPerson(struct list * list)
{
    struct person person, * newPerson;
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

    newPerson = make_person(person.fname, person.lname, person.age);
    list_add(list, newPerson);

    printf("\n");
}

void removePerson(struct list * list)
{
    struct person person;

    printf("Remove Person \n");

    printf("Enter last name: ");
    if(!getInput(person.lname, sizeof(person.lname)))
    {
        printf("\n");
        return;
    }

    if(list_remove(list, &person))
    {
        printf("Person with last name '%s' has been removed \n", person.lname);
    }
    else
    {
        printf("Person with last name '%s' was not found \n", person.lname);
    }
    printf("\n");
}

void printLinkedList(struct list * list)
{
    printf("--- Printing Linked List --- \n");
    print_list(list);
    printf("\n");
}

int main()
{
    struct list * list;

    list = list_init(person_cmp, person_equal, print_person, person_free);

    while(true)
    {
        char optionInput[100 + 1];
        char * endPtr;
        int option;
        bool success;

        printf("1. Add Person \n"
               "2. Remove Person \n"
               "3. Print Linked List \n"
               "4. Quit \n");
        printf("Enter option: ");

        success = getInput(optionInput, sizeof(optionInput));
        printf("\n");

        if(!success)
        {
            printf("Invalid input. \n\n");
            continue;
        }

        option = strtol(optionInput, &endPtr, 10);
        if(optionInput == endPtr || *endPtr != '\0' || option < 1 || option > 4)
        {
           printf("Invalid input. \n\n");
           continue;
        }

        if(option == 1)
        {
            addPerson(list);
        }
        else if(option == 2)
        {
            removePerson(list);
        }
        else if(option == 3)
        {
            printLinkedList(list);
        }
        else if(option == 4)
        {
            break;
        }
        else
        {
            assert(false);
        }
    }

    list_free(list);
    list = NULL;

    return EXIT_SUCCESS;
}
