/****************************************************************************
* Steven Burrows
* sdb@cs.rmit.edu.au
* 
* intlist-dynarray.h
* Example of an interface for a dynamically allocated integer array.
****************************************************************************/

/*
 * IntList
 * -- simple unordered array implementation that uses dynamic memory
 *
 * type:  
 * IntList
 *
 * constants: 
 *     SUCCESS
 *     FAILURE
 *
 * interface routines:
 *
 * int MakeList(IntList* pil, int size)  
 *    attempts to initialise an IntList variable (passed by address)
 *    if insufficient memory is available for the size list requested
 *    then MakeList() retuns FAILURE, otherwise it returns SUCCESS
 *    MakeList() must be applied to an IntList before any other 
 *    function.
 *
 * void FreeList(IntList* pil)
 *    attempts to reset an IntList variable (passed by address) to 
 *    the "empty" state, depending on the implementation this may 
 *    involve deallocation of memory. IntList must be initialised
 *    with MakeList() again before use. Typically FreeList() is
 *    the last function to be applied to an IntList
 *
 * int AddList(IntList* pil,int data);
 *    attempts to add a new int (data) to an IntList variable
 *    (passed by address). If the addition was successful AddList()
 *    will return SUCCESS, otherwise FAILURE 
 *
 * void DisplayList(IntList* pil);
 *    displays all integers currently stored in the IntList
 *    values displayed one per line on standard output   
 *
 * unsigned SizeList(IntList* pil);
 *    returns the current size of the IntList 
 *    ie. how many data items are currently stored within the list
 *
 */

#define INTLISTSIZE 100

#define SUCCESS 1
#define FAILURE 0

typedef struct
{
   int *array;
   unsigned size;
} IntList;

int MakeList(IntList*,int);

void FreeList(IntList*);

int AddList(IntList*,int);

void DisplayList(IntList*);

unsigned SizeList(IntList*);

/*
 *
 */
