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

void pop_set_fns(Pop_list *p, CreateFn cf, MutateFn mf, CrossOverFn cof, EvalFn ef)
{
	p->create_rand_chrom = cf;
	p->mutate_gene = mf;
	p->crossover_genes = cof;
	p->evaluate_fn = ef;
}

/* TO DO - other functions as appropriate */
void pop_print_fittest(Pop_list *pList)
{
	if (pList != NULL)
	{
		double totalFitness = 0;
		Pop_node *node = pList->head;
		while (node != NULL)
		{
			fprintf(stdout, "Gen:%4d ", generation);
			gene_print(node->gene);
			totalFitness += node->gene->fitness;
			node = node->next;
		}
		fprintf(stdout, "\n");
		generation++;
	}
	else
	{
		fwrite("pop_print_fittest: pop is empty\n", 1, 32, stderr);
	}
}

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

void pop_node_free(Pop_node *node)
{
	gene_free(node->gene);
	free(node);
}

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

			pop_evaluate(pListNew, invt);
			pop_sort(pListNew->head);
			if (!pListNew)
			{
				puts("pop_sort failed");
				return NULL;
			}
			pop_print_fittest(pListNew);
			pListChild = pop_reproduce(pListNew);
			if (!pListChild)
			{
				puts("pop_reproduce failed");
				return NULL;
			}
			pop_free(pListNew);
			pListNew = pListChild;
		}
		pListResult = pListNew;
	}
	else
	{
		puts("pop_create_rand_pop failed");
		pListResult = NULL;
	}
	return pListResult;
}

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

void swap_node(Pop_node *a, Pop_node *b)
{
	Gene *tempGene = a->gene;
	a->gene = b->gene;
	b->gene = tempGene;
}

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
				swap_node(ptr1, ptr1->next);
				swapped = TRUE;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapped);
}

void pop_evaluate(Pop_list *pList, InVTable *invt)
{
	Pop_node *node;
	double totalFitness;

	totalFitness = 0;
	node = pList->head;
	while (node != NULL)
	{
		gene_calc_fitness(node->gene, pList->evaluate_fn, invt);
		totalFitness += node->gene->fitness;
		node = node->next;
	}
	node = pList->head;
	while (node != NULL)
	{
		gene_normalise_fitness(node->gene, totalFitness);
		node = node->next;
	}
}

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

	if (pList)
	{
		if (pop_init(&pListChild))
		{
			pop_set_fns(pListChild, pList->create_rand_chrom, pList->mutate_gene, pList->crossover_genes, pList->evaluate_fn);
			newGene = gene_copy(pList->head->gene);

			if (newGene)
			{
				if (pop_insert(pListChild, newGene))
				{
					for (i = 1; pList->count > i; ++i)
					{
						g2 = pop_proportionate_select(pList);
						g1 = pop_proportionate_select(pList);
						if (g2 == NULL)
						{
						}
						if (g1 == NULL)
						{
						}
						if (g2 == NULL || g1 == NULL)
						{
							pop_free(pListChild);
							return NULL;
						}
						crossoverGene = pList->crossover_genes(g2, g1);
						newGene = crossoverGene;
						if (!crossoverGene)
						{
							pop_free(pListChild);
							return NULL;
						}
						if (rand() % 100 < MUTATE_RATE)
						{
							mutateGene = pList->mutate_gene(newGene);
							if (!mutateGene)
							{
								pop_free(pListChild);
								return NULL;
							}
							gene_free(newGene);
							newGene = mutateGene;
						}
						if (!pop_insert(pListChild, newGene))
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

Gene *pop_proportionate_select(Pop_list *pList)
{
	double randomNum;
	double count;
	if (pList != NULL)
	{
		Pop_node *node = pList->head;
		randomNum = (double)(rand() % 1000) / 1000.0;
		count = 0.0;
		while (node != NULL)
		{
			count += node->gene->fitness;
			if (count > randomNum)
			{
				return node->gene;
			}
			node = node->next;
		}
	}
	else
	{
		return NULL;
	}
	return NULL;
}
