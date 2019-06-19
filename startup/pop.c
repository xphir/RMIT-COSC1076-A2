/******************************************************************************
** Student name: 	Elliot Schot
** Student number: 	S3530160
** Course: 			Advanced Programming Techniques - S2 2018
******************************************************************************/

#include "pop.h"

/* Initialise pop_list*/
Boolean pop_init(Pop_list **pop)
{
	Boolean result;
	Pop_list *new_pop;

	new_pop = malloc(sizeof(*new_pop));
	if (new_pop)
	{
		new_pop->head = NULL;
		new_pop->count = 0;
		new_pop->create_rand_chrom = NULL;
		new_pop->mutate_gene = NULL;
		new_pop->crossover_genes = NULL;
		new_pop->evaluate_fn = NULL;
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

/* Set pop_list pointers */
void pop_set_fns(Pop_list *p, CreateFn cf, MutateFn mf, CrossOverFn cof, EvalFn ef)
{
	p->create_rand_chrom = cf;
	p->mutate_gene = mf;
	p->crossover_genes = cof;
	p->evaluate_fn = ef;
}

/* Print the fittest pop */
void pop_print_fittest(Pop_list *pList)
{
	if (pList != NULL)
	{
		Pop_node *node = pList->head;
		/* Go throught each node */
		if (node != NULL)
		{
			fprintf(stdout, "Gen:%4d ", generation);
			gene_print(node->gene);
		}
		generation++;
	}
	else
	{
		fwrite("pop_print_fittest: pop is empty\n", 1, 32, stderr);
	}
}

/* Print the pop list */
void pop_print_all(Pop_list *pList)
{
	if (pList != NULL)
	{
		Pop_node *node = pList->head;
		/* Go throught each node */
		while (node != NULL)
		{
			fprintf(stdout, "Gen:%4d ", generation);
			gene_print(node->gene);
			node = node->next;
		}
		fprintf(stdout, "\n");
		generation++;
	}
	else
	{
		fwrite("pop_print_all: pop is empty\n", 1, 32, stderr);
	}
}

/* Add a new pop to pop_list */
Boolean pop_insert(Pop_list *pList, Gene *gene)
{
	Boolean result;
	Pop_node *node = malloc(sizeof(*node));
	if (node != NULL)
	{
		node->next = NULL;
		node->gene = gene;

		node->next = pList->head;
		pList->head = node;
		pList->count++;
		result = TRUE;
	}
	else
	{
		fwrite("failed to allocate memory in pop_insert\n", 1, 40, stderr);
		result = FALSE;
	}
	return result;
}

/* Free the malloc Pop_list */
void pop_free(Pop_list *pList)
{
	Pop_node *node = pList->head;
	while (node != NULL)
	{
		Pop_node *temp = node;
		node = node->next;
		pop_node_free(temp);
	}
	free(pList);
}

/* Free the malloc Pop_node */
void pop_node_free(Pop_node *node)
{
	gene_free(node->gene);
	free(node);
}

/* Evolution of the population */
Pop_list *pop_run(Pop_list *pList, int popSize, int numAlleles, int numGen, InVTable *invt)
{
    Pop_list *pListResult;
    Pop_list *pListNew;
    Pop_list *pListChild;
    int i;
    pListNew = pList;
    if (pop_create_rand_pop(pList, popSize, numAlleles) != FALSE)
    {
        for (i = 0; i < numGen; ++i)
        {
			/* evaluate + normalise pListNew */
            pop_evaluate(pListNew, invt);
			/* sort pListNew */
            pop_sort(pListNew->head);
            if (!pListNew)
            {
                fwrite("pop_sort failed\n", 1, 16, stderr);
                return NULL;
            }
			/* print pListNew */
            pop_print_fittest(pListNew);
			/* reproduct pListNew */
            pListChild = pop_reproduce(pListNew);
            if (!pListChild)
            {
                fwrite("pop_reproduce failed\n", 1, 21, stderr);
                return NULL;
            }
			/* free pListNew */
            pop_free(pListNew);
			/* set pListChild as pListNew for the next loop */
            pListNew = pListChild;
        }
        pListResult = pListNew;
    }
    else
    {
        fwrite("pop_create_rand_pop failed\n", 1, 27, stderr);
        pListResult = NULL;
    }
	/* pListResult is freed on return */
    return pListResult;
}

/* Create a random pop */
Boolean pop_create_rand_pop(Pop_list *pList, int popSize, int numAlleles)
{
	Gene *randomGene;
	int i;

	for (i = 0; i < popSize; ++i)
	{
		randomGene = gene_create_rand_gene(numAlleles, pList->create_rand_chrom);
		if (randomGene == NULL)
		{
			pop_free(pList);
			return FALSE;
		}
		pop_insert(pList, randomGene);
	}
	return TRUE;
}

/* Swaps two nodes around */
void swap_node(Pop_node *a, Pop_node *b)
{
	Gene *tempGene = a->gene;
	a->gene = b->gene;
	b->gene = tempGene;
}

/* Simple buble sort on the genes */
void pop_sort(Pop_node *start)
{
	Boolean swapped;
	Pop_node *ptr1;
	Pop_node *lptr = NULL;

	/* Checking for empty list */
	if (start == NULL)
	{
		return;
	}
	do
	{
		swapped = FALSE;
		ptr1 = start;
		while (ptr1->next != lptr)
		{
			if (ptr1->gene->fitness < ptr1->next->gene->fitness)
			{
				/* Swap the nodes for the sort */
				swap_node(ptr1, ptr1->next);
				swapped = TRUE;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapped);
}

/* evaluate the genes in the Pop_list */
void pop_evaluate(Pop_list *pList, InVTable *invt)
{
	Pop_node *node;
	double totalFitness;

	totalFitness = 0;
	node = pList->head;
	/* evaluate the genes */
	while (node != NULL)
	{
		gene_calc_fitness(node->gene, pList->evaluate_fn, invt);
		totalFitness += node->gene->fitness;
		node = node->next;
	}
	node = pList->head;

	/* normalise the genes */
	while (node != NULL)
	{
		gene_normalise_fitness(node->gene, totalFitness);
		node = node->next;
	}
}

/* Product a child Pop_list from an adult Pop_list */
Pop_list *pop_reproduce(Pop_list *pList)
{
	Pop_list *resultList;
	Gene *crossoverGene;
	Gene *mutateGene;
	Pop_list *pListChild;
	Gene *g1;
	Gene *g2;
	Gene *newGene;
	int i;

	if (pList != NULL)
	{
		/* Create the pListChild and set the correct pointer values */
		if (pop_init(&pListChild) == TRUE)
		{
			pop_set_fns(pListChild, pList->create_rand_chrom, pList->mutate_gene, pList->crossover_genes, pList->evaluate_fn);
			newGene = gene_copy(pList->head->gene);

			if (newGene != NULL)
			{
				if (pop_insert(pListChild, newGene) == TRUE)
				{
					/* Create the child genes */
					for (i = 1; pList->count > i; ++i)
					{
						/* Select 2 genes to reproduce - pop_proportionate_select makes it more likely to be higher fitness genes */
						g2 = pop_proportionate_select(pList);
						g1 = pop_proportionate_select(pList);
						if (g2 == NULL || g1 == NULL)
						{
							pop_free(pListChild);
							return NULL;
						}
						/* Reproduce the two select genes to make a child gene */
						crossoverGene = pList->crossover_genes(g2, g1);
						newGene = crossoverGene;
						if (crossoverGene == NULL)
						{
							pop_free(pListChild);
							return NULL;
						}
						/* Check if the child gene is going have a mutation */
						if (rand() % 100 < MUTATE_RATE)
						{
							mutateGene = pList->mutate_gene(newGene);
							if (mutateGene == NULL)
							{
								pop_free(pListChild);
								return NULL;
							}
							gene_free(newGene);
							newGene = mutateGene;
						}
						/* Add the new child gene to the child Pop_list */
						if (pop_insert(pListChild, newGene) == FALSE)
						{
							pop_free(pListChild);
							return NULL;
						}
					}
					resultList = pListChild;
				}
				else
				{
					pop_free(pListChild);
					resultList = NULL;
				}
			}
			else
			{
				pop_free(pListChild);
				resultList = NULL;
			}
		}
		else
		{
			resultList = NULL;
		}
	}
	else
	{
		resultList = NULL;
	}
	return resultList;
}

/* Select a population node for reproduction */
Gene *pop_proportionate_select(Pop_list *pList)
{
	double randomNum;
	double count;
	if (pList != NULL)
	{
		Pop_node *node = pList->head;
		/* Get a random double between 0 and 1 */
		randomNum = (double)(rand() % 1000) / 1000.0;
		count = 0.0;
		while (node != NULL)
		{
			/* add the normalised fitness to count */
			count += node->gene->fitness;
			/* if this gene's normalised fitness makes count > than randomNum then return said gene */
			if (count > randomNum)
			{
				return node->gene;
			}
			/* if not then go to the next node */
			node = node->next;
		}
	}
	else
	{
		return NULL;
	}
	return NULL;
}
