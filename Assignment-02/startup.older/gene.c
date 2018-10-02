/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S2 2018
******************************************************************************/

#include "gene.h"

/* Create a random chromosome of length num_alleles for a pcbmill gene */
int *create_pcbmill_chrom(int numAlleles)
{
	/* TODO */
	_DWORD *result;
	int v2;
	int v3;
	_DWORD *v4;
	signed int i;
	int j;

	v4 = malloc(sizeof(numAlleles);
	if (v4)
	{
		for (i = 0; i < numAlleles; ++i)
			v4[i] = i;
		for (j = 0; j < numAlleles; j = v2 + 1)
		{
			v2 = rand() % numAlleles;
			v3 = rand() % numAlleles;
			gene_swap_alleles((__int64)v4, v2, v3);
		}
		result = v4;
	}
	else
	{
		fwrite("Unable to allocate chromosome memory", 1uLL, 0x24uLL, stderr);
		result = FALSE;
	}
	return result;
}

int *create_minfn_chrom(int numAlleles)
{
	/* TO DO */
	return NULL;
}

Gene *mutate_pcbmill(Gene *g)
{
	/* TO DO */
	Gene *result; // rax@2
	int v2;		  // eax@3
	__int64 *v3;  // [sp+18h] [bp-8h]@1

	v3 = gene_copy(g);
	if (v3 == TRUE)
	{
		v2 = rand();
		gene_swap_alleles(*v3, v2 % *(_DWORD *)(g + 8), (v2 % *(_DWORD *)(g + 8) + 1) % *(_DWORD *)(g + 8));
		result = v3;
	}
	else
	{
		result = NULL;
	}
	return result;
}

Gene *mutate_minfn(Gene *g)
{
	/* TO DO */
	return NULL;
}

Gene *crossover_pcbmill(Gene *g1, Gene *g2)
{
	/* TO DO */
	return NULL;
}

Gene *crossover_minfn(Gene *g1, Gene *g2)
{
	/* TO DO */
	return NULL;
}

double eval_pcbmill(InVTable *invt, Gene *gene)
{
	/* TO DO */
	return 0.0;
}

double eval_minfn(InVTable *invt, Gene *gene)
{
	/* TO DO */
	return 0.0;
}

Gene *gene_create_rand_gene(int numAlleles, CreateFn create_chrom)
{
	/* TO DO */
}

void gene_calc_fitness(Gene *gene, EvalFn evaluate_fn, InVTable *invTab)
{
	/* TO DO */
}

void gene_normalise_fitness(Gene *gene, double total_fitness)
{
	/* TODO? */
	gene->fitness = gene->fitness / total_fitness;
}

void gene_free(Gene *gene)
{
	/* TODO? */
	free(gene);
}

double gene_get_fitness(Gene *gene)
{
	return gene->fitness;
}

int gene_get_chromosome(Gene *gene)
{
	return gene->chromosome;
}

void gene_print(Gene *gene)
{
	/* TO DO */
}

Gene *gene_copy(Gene *g)
{
	/* TO DO */
	return NULL;
}

void gene_swap_alleles(Gene *g, int a2, int a3)
{
	/* TO DO */
	return NULL;
}