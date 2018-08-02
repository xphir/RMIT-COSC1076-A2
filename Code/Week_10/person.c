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

bool removeFromLinkedList(LinkedList * linkedList, char * lastName)
{
    Node * previousNode, * currentNode;

    previousNode = NULL;
    currentNode = linkedList->head;
    while(currentNode != NULL)
    {
        if(strcmp(lastName, currentNode->person->lname) == 0)
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
        linkedList->head = currentNode->next;
    }
    else
    {
        previousNode->next = currentNode->next;
    }
    linkedList->size--;

    free(currentNode->person);
    free(currentNode);

    return true;
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

void ListPrint(LinkedList * linkedList)
{
    Node * node = linkedList->head;
    while(node != NULL)
    {
        NodePrint(node->person);

        node = node->next;
    }
}

void NodePrint(Person * person)
{
    printf("%s %s (%u) \n", person->fname, person->lname, person->age);
}

void ListPrintReversed(LinkedList * linkedList)
{
    NodePrintReversed(linkedList->head);
}

void NodePrintReversed(Node * node)
{
    if(node == NULL)
    {
        return;
    }

    NodePrintReversed(node->next);
    NodePrint(node->person);
}
