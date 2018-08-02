#ifndef PERSON_H
#define PERSON_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bool.h"

#define NAMELEN 40
typedef struct
{
    char fname[NAMELEN + 1];
    char lname[NAMELEN + 1];
    unsigned int age;
} Person;

typedef struct node
{
    Person * person;
    struct node * next;
} Node;

typedef struct
{
    Node * head;
    unsigned int size;
} LinkedList;

LinkedList * initialiseLinkedList();
bool addToLinkedList(LinkedList * linkedList, Person * person);
void printLinkedList(LinkedList * linkedList);
LinkedList * freeLinkedList(LinkedList * linkedList);

#endif
