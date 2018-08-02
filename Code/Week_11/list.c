#include "list.h"

/**************************************************************************
 * initialise the list to a safe state where all values start from known
 * values. 
 *************************************************************************/
struct list * list_init(int (*cmp)(void * data, void * otherData),
                        bool (*equal)(void * data, void * otherData),
                        void (*print)(void * data),
                        void (*datafree)(void * data))
{
    struct list * list = malloc(sizeof(*list));

    if(list != NULL)
    {
        /* set the content of the list to have all 0 values. */
        memset(list, 0, sizeof(*list));

        list->cmp = cmp;
        list->equal = equal;
        list->print = print;
        list->datafree = datafree;
    }

    return list;
}

/**************************************************************************
 * list_add() - implements the algorithm to insert into a list in sorted 
 * order. If you think back to the sorting algorithms covered earlier in 
 * this course this is an insertion sort.
 *************************************************************************/
bool list_add(struct list * list, void * data)
{
    /* make sure to initialise your prev pointer to NULL */
    struct list_node * current, * prev = NULL;
    struct list_node * new;

    /* ensure our incoming pointers are valid */
    assert(list);
    assert(data);

    /* allocate space for the node */
    new = malloc(sizeof(struct list_node));

    /* initialise the next and data pointers to the appropriate values */
    /* setting next to NULL handles when we add to the end of the list */
    new->next = NULL;
    new->data = data;

    /* if we are at the begging of the list just assign the new node 
     * to the head of the list */
    if(list->head == NULL)
    {
        list->head = new;

        /* increment the count of items in the list */ 
        ++list->count;

        /* job done */
        return true;
    }

    /* grab the beginning of the list and find the insertion point 
     * for our data. Remember that cmp functions work essentially
     * like subtraction - is current data less than data in our 
     * sort order?
     **/ 
    current = list->head;
    while(current != NULL && list->cmp(current->data, data) < 0)
    {
        /* grab the current pointer and assign it to previous so we can 
         * insert data between two nodes
         */
        prev = current;
        current = current->next;
    }

    /* insertion at the beginning of the list */
    if(prev == NULL)
    {
        new->next = list->head;
        list->head = new;
    }
    /* insertion at the end - redundant if statement because of the 
     * else statement further on
     **/
    else if(!current)
    {
        new->next = NULL;
        prev->next = new;
    }
    else
    {
        prev->next = new;
        new->next = current;
    }
    /* increment the count of items in the list */
    ++list->count;

    /* job done */
    return true;
}

bool list_remove(struct list * list, void * data)
{
    struct list_node * previousNode, * currentNode;

    previousNode = NULL;
    currentNode = list->head;
    while(currentNode != NULL)
    {
        if(list->equal(data, currentNode->data) == 0)
        {
            break;
        }

        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    if(currentNode == NULL)
    {
        return false;
    }

    if(previousNode == NULL)
    {
        /* Remove at the head. */
        list->head = currentNode->next;
    }
    else
    {
        previousNode->next = currentNode->next;
    }
    list->count--;

    list->datafree(currentNode->data);
    free(currentNode);

    return true;
}

/**************************************************************************
 * prints the contents of the data elements of each link in the list
 **************************************************************************/
void print_list(struct list * list)
{
    struct list_node * current;

    assert(list);

    /* grab the beginning of the list */
    current = list->head;

    /* while there are still more elements in the list */
    while(current)
    {
        /* grab the data*/
        struct person * data = current->data;

        /* print the data */
        list->print(data);

        /* move onto the next node in the list */
        current = current->next;
    }
}

/**************************************************************************
 * free all the items in the list
 *************************************************************************/
void list_free(struct list * list)
{
    /* grab the beginning of the list */
    struct list_node * current = list->head;

    /* iterate over all the list elements */
    while(current != NULL)
    {
        struct list_node * next;

        /* grab the current element so we can free it */
        next = current;

        /* move on to the next element */
        current = current->next;

        /* free the data */
        list->datafree(next->data);

        /* free the list node */
        free(next);
    }
}
