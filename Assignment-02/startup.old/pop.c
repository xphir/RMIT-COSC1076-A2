/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S2 2018
******************************************************************************/

#include "pop.h"

Boolean pop_init(Pop_list **pop)
{
    Boolean result;
    Pop_list *localPop = malloc(sizeof(localPop));
    if (localPop == TRUE)
    {
        /* TODO */
        localPop->head = 0;
        localPop->count = 0;
        localPop->create_rand_chrom = 0;
        localPop->mutate_gene = 0;
        localPop->crossover_genes = 0;
        localPop->evaluate_fn = 0;
        /* TODO */
        pop = localPop;
        result = TRUE;
    }
    else
    {
        fwrite("pop_init: memory allocation failed", 1uLL, 0x22uLL, stderr);
        result = FALSE;
    }
    return result;
}

void pop_set_fns(Pop_list *p, CreateFn cf, MutateFn mf, CrossOverFn cof, EvalFn ef)
{
    p->create_rand_chrom = cf;
    p->mutate_gene = mf;
    p->crossover_genes = cof;
    p->evaluate_fn = ef;
    return;
}

void pop_print_fittest(Pop_list *p)
{
    /* TO DO */
}

/* TO DO - other functions as appropriate */

