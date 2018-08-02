#include "list.h"

#define NAMELEN 20

struct person 
{
    char fname[NAMELEN + 1];
    char lname[NAMELEN + 1];
    unsigned age;
};

struct person * make_person(char * fname, char * lname, unsigned age);

int person_cmp(void * data, void * otherData);
bool person_equal(void * data, void * otherData);
void print_person(void * data);
void person_free(void * data);
