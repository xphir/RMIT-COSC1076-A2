/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S2 2018
******************************************************************************/

#include "pop.h"

Boolean pop_init(Pop_list **popList)
{
	Pop_list *initPopList;
	Boolean result;

	initPopList = malloc(sizeof(*initPopList));

	if (initPopList != NULL)
	{
		initPopList->head = NULL;
		initPopList->count = 0;
		initPopList->create_rand_chrom = NULL;
		initPopList->mutate_gene = NULL;
		initPopList->crossover_genes = NULL;
		initPopList->evaluate_fn = NULL;
		*popList = initPopList;
		result = TRUE;
	}
	else
	{
		fwrite("pop_init: memory allocation failed", 1, 34, stderr);
		result = FALSE;
	}
	return result;
}

void pop_set_fns(Pop_list *p, CreateFn cf, MutateFn mf, CrossOverFn cof, EvalFn ef)
{
	/* TO DO */
}

void pop_print_fittest(Pop_list *p)
{
	/* TO DO */
}

/* TO DO - other functions as appropriate */
