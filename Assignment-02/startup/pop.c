/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S2 2018
******************************************************************************/

#include "pop.h"

Boolean pop_init(Pop_list **pop)
{
	Boolean result;
	Pop_list *new_pop;

	new_pop = malloc(sizeof(new_pop));
	if (new_pop)
	{
		new_pop->head = NULL;
		new_pop->count = 0;
		new_pop->create_rand_chrom = NULL;
		new_pop->crossover_genes = NULL;
		new_pop->evaluate_fn = NULL;
		new_pop->mutate_gene = NULL;
		*pop = new_pop;
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
