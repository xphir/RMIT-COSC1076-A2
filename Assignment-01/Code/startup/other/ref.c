#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//example to pass a struct to void pointer and a void pointer to struct
//testing if allocation is done by callee and not caller

typedef struct mystructure{
    int a;
    char b;
    unsigned char c[10];
}mystruct;


void func(void *var){

    mystruct *s = var;
    s->a = 100;
    s->b = 'I';
    strncpy(s->c,"test",5);
    printf("In func\n");
    printf("s->a = %d\n",s->a);
    printf("s->b = %c\n",s->b);
    printf("s->c = %s\n",s->c);
}

void voidOut(void *var){

    mystruct *s = var;
    printf("In voidOut\n");
    printf("s->a = %d\n",s->a);
    printf("s->b = %c\n",s->b);
    printf("s->c = %s\n",s->c);

}


//here is void pointer is both and 'in' and 'out' parameter
void memfunc(void **var){

    mystruct *s = var;
    s = (mystruct *)malloc(sizeof(mystruct));
    s->a = 100;
    s->b = 'I';
    printf("In memfunc\n");
    strncpy(s->c,"test",5);
    printf("s->a = %d\n",s->a);
    printf("s->b = %c\n",s->b);
    printf("s->c = %s\n",s->c);
    //memcpy(var,s, sizeof(s));
}

//here is void pointer is an 'in' parameter
void memvoidOut(void **var){

    mystruct *s = var;
    printf("In memvoidOut\n");
    printf("s->a = %d\n",s->a);
    printf("s->b = %c\n",s->b);
    printf("s->c = %s\n",s->c);
}


int main(int argc, char *argv[]){
    mystruct val;
    func(&val);
    voidOut(&val);

    mystruct *ptr = NULL;
    memfunc(&ptr);
    memvoidOut(&ptr);

    return 0;
}