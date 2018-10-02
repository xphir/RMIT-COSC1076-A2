#ifndef _CONTAINER_H_
#define _CONTAINER_H_

struct container;

struct container *container_new();

int container_insert(struct container*, int);

void container_print(struct container*);

void container_free(struct container*);

size_t container_size(struct container*);

#endif /* _CONTAINER_H_ */
