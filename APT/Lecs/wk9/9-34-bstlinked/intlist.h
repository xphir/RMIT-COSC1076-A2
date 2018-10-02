/****************************************************************************
* intlist-BST-list.h
* Example of an interface for binary search tree
****************************************************************************/

#define INTLISTSIZE 100

#define SUCCESS 1
#define FAILURE 0

typedef struct intlistnode * IntBSTNodePtr;

typedef struct intlistnode
{  int num;
   IntBSTNodePtr left;
   IntBSTNodePtr right;
} IntBSTNode;

typedef struct
{  IntBSTNodePtr root;
   unsigned size;
} IntList;

int MakeList(IntList*,int);

void postorderFree(IntBSTNodePtr pNode);

void FreeList(IntList*);

int AddList(IntList*,int);

void inoderDisplayList(IntBSTNodePtr pNode);

void DisplayList(IntList*);

unsigned SizeList(IntList*);

