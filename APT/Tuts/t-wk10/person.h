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
bool removeFromLinkedList(LinkedList * linkedList, char * lastName);
void freeLinkedList(LinkedList * linkedList);

void ListPrint(LinkedList * linkedList);
void NodePrint(Person * person);
void ListPrintReversed(LinkedList * linkedList);
void NodePrintReversed(Node * node);

#endif
