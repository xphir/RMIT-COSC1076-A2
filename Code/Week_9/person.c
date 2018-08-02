#include "person.h"

LinkedList * initialiseLinkedList()
{
    LinkedList * linkedList = malloc(sizeof(*linkedList));
    if(linkedList != NULL)
    {
        linkedList->head = NULL;
        linkedList->size = 0;
    }

    return linkedList;
}

bool addToLinkedList(LinkedList * linkedList, Person * person)
{
    Node * previousNode, * currentNode;

    Node * newNode = malloc(sizeof(*newNode));
    if(newNode == NULL)
    {
        return false;
    }
    newNode->person = malloc(sizeof(*newNode->person));
    if(newNode->person == NULL)
    {
        free(newNode);
        return false;
    }

    *newNode->person = *person;
    /* OR */
    /* memcpy(newNode->person, person, sizeof(*person)); */
    newNode->next = NULL;

    previousNode = NULL;
    currentNode = linkedList->head;
    while(currentNode != NULL)
    {
        if(strcmp(person->lname, currentNode->person->lname) < 0)
        {
            break;
        }

        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    if(linkedList->head == NULL)
    {
        /* Empty list. */
        linkedList->head = newNode;
    }
    else if(previousNode == NULL)
    {
        /* Inserting at the head. */
        newNode->next = linkedList->head;
        linkedList->head = newNode;
    }
    else
    {
        previousNode->next = newNode;
        newNode->next = currentNode;
    }
    linkedList->size++;

    return true;
}

void printLinkedList(LinkedList * linkedList)
{
    Node * node = linkedList->head;
    while(node != NULL)
    {
        printf("%s %s (%u) \n",
            node->person->fname, node->person->lname, node->person->age);

        node = node->next;
    }
    printf("\n");
}

LinkedList * freeLinkedList(LinkedList * linkedList)
{
    Node * node = linkedList->head;
    while(node != NULL)
    {
        Node * temp = node;
        node = node->next;

        free(temp->person);
        free(temp);
    }
    free(linkedList);

    return NULL;
}
