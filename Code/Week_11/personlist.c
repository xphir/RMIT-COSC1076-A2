#include "personlist.h"

/**************************************************************************
 * function that creates a new person based on the data passed in - think
 * of this like a constructor in object oriented languages.
 *************************************************************************/
struct person * make_person(char * fname, char * lname, unsigned age)
{
    struct person * new;

    /* fname and age must be valid pointers */
    assert(fname);
    assert(lname);

    /* make space for the person */
    new = malloc(sizeof(*new));

    if(new != NULL)
    {
        /* copy in the data */
        strcpy(new->fname, fname);
        strcpy(new->lname, lname);
        new->age = age;
    }

    return new;
}

/**************************************************************************
 * a comparison function that compares to person structs. 
 * as these are now used in a generic list, they need to be void pointers
 * as that is what was specified for the function pointer in the list type.
 * a comparison function returns a negative number if the first number
 * is lower in the sort order, a positive number if the first number is 
 * greater in the sort order and 0 if they are equal.
 *************************************************************************/
int person_cmp(void * data, void * otherData)
{
    int cmp;

    /* compare for last name to begin with and if they are different 
     * return the result
     */
    struct person * pfirst = data, * psecond = otherData;
    cmp = strcmp(pfirst->lname, psecond->lname);
    if(cmp != 0)
        return cmp;

    /* otherwise compare on their first name. But what if their first and 
     * last names are the same? */
    cmp = strcmp(pfirst->fname, psecond->fname);
    if(cmp != 0)
        return cmp;

    /* we could also compare their ages */
    return pfirst->age - psecond->age;
}

bool person_equal(void * data, void * otherData)
{
    struct person * person = data, * otherPerson = otherData;

    return strcmp(person->lname, otherPerson->lname);
}

void print_person(void * data)
{
    struct person * person = data;

    printf("%s\t%s\t%u\n", person->fname, person->lname, person->age);
}

void person_free(void * data)
{
    free(data);
}
