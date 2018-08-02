#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bool.h"

struct list_node
{
    void * data;
    struct list_node * next;
};

struct list
{
    struct list_node * head;
    unsigned count;
    int (*cmp)(void * data, void * otherData);
    bool (*equal)(void * data, void * otherData);
    void (*print)(void * data);
    void (*datafree)(void * data);
};

struct list * list_init(int (*cmp)(void * data, void * otherData),
                        bool (*equal)(void * data, void * otherData),
                        void (*print)(void * data),
                        void (*datafree)(void * data));

bool list_add(struct list * list, void * data);
bool list_remove(struct list * list, void * data);
void print_list(struct list * list);
void list_free(struct list * list);
