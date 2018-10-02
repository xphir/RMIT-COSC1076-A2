/****************************************************************************
* intlist-BST-list.h
* Example of an interface for binary search tree
****************************************************************************/

#define INTLISTSIZE 100
#define EMPTY -1

#define SUCCESS 1
#define FAILURE 0

typedef struct
{  int numArray[INTLISTSIZE];
   unsigned size;
} IntList;

int MakeList(IntList*,int);

int getLeftIndex(int);

int getRightIndex(int);

void FreeList(IntList*);

int AddList(IntList*,int);

void inorderDisplay(IntList*, int);
void preorderDisplay(IntList*, int);
void postorderDisplay(IntList*, int);

void DisplayList(IntList*);

unsigned SizeList(IntList*);

