#ifndef INTLIST_H
#define INTLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bool.h"

#define INTLIST_SIZE 10

typedef struct
{
    int list[INTLIST_SIZE];
    unsigned size;
} IntList;

IntList createIntList();
/* --- OR --- */
void initialiseIntList(IntList * intList);

bool insertIntList(IntList * intList, int value);
bool removeIntList(IntList * intList, int value);
void displayIntList(IntList * intList);
void displayCsvIntList(IntList * intList);

#endif
