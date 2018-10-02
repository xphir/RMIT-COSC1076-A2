/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S2 2018
******************************************************************************/

#include "gene.h"

int *create_pcbmill_chrom(int numAlleles)
{
	int *result;
	int *alleles;
	int alleleA;
	int alleleB;

	int i;
	int j;

	alleles = malloc(sizeof(numAlleles));
	if (alleles != NULL)
	{
		for (i = 0; i < numAlleles; ++i)
		{
			alleles[i] = i;
		}
		for (j = 0; j < numAlleles; j = alleleA + 1)
		{
			alleleA = rand() % numAlleles;
			alleleB = rand() % numAlleles;
			/* TO DO */
			/* gene_swap_alleles(alleles, alleleA, alleleB); */
		}
		result = alleles;
	}
	else
	{
		fwrite("Unable to allocate chromosome memory", 1, 36, stderr);
		result = NULL;
	}
	return result;
}

int *create_minfn_chrom(int numAlleles)
{
	int *result;
	int *alleles;
	int i;

	alleles = malloc(sizeof(numAlleles));
	if (alleles)
	{
		for (i = 0; i < numAlleles; ++i)
		{
			alleles[i] = rand() % 30;
		}
		result = alleles;
	}
	else
	{
		fwrite("Unable to allocate chromosome memory", 1, 36, stderr);
		result = NULL;
	}
	return result;
}

Gene *mutate_pcbmill(Gene *g)
{
	Gene *new_gene;
	Gene *result_gene;
	int randomInt;

	new_gene = gene_copy(g);
	if (new_gene != NULL)
	{
		randomInt = rand();
		/* TO DO */
		/* gene_swap_alleles(g, v2 % *(_DWORD *)(a1 + 8), (v2 % *(_DWORD *)(a1 + 8) + 1) % *(_DWORD *)(a1 + 8)) */
		result_gene = new_gene;
	}
	else
	{
		result_gene = NULL;
	}
	return result_gene;
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
	int chromosome;
	Gene *result_gene;
	Gene *new_gene = malloc(sizeof(*new_gene));

	chromosome = create_chrom(numAlleles);

	if (new_gene != NULL)
	{
		new_gene->chromosome = chromosome;
		new_gene->num_alleles = numAlleles;
		new_gene->raw_score = 0;
		new_gene->fitness = 0;
		result_gene = new_gene;
	}
	else
	{
		fwrite("Unable to allocate memory in gene_create_rand_gene\n", 1, 51, stderr);
		result_gene = NULL;
	}
	return result_gene;
}

void gene_calc_fitness(Gene *gene, EvalFn evaluate_fn, InVTable *invTab)
{
	/* TO DO */
}

void gene_normalise_fitness(Gene *gene, double total_fitness)
{
	/* TO DO */
}

void gene_free(Gene *gene)
{
	/* TO DO */
}

double gene_get_fitness(Gene *gene)
{
	/* TO DO */
	return 0.0;
}

void gene_print(Gene *gene)
{
	int i;

	fwrite("chrom:", 1, 6, stdout);
	for (i = 0; gene->num_alleles > i; ++i)
	{
		fprintf(stdout, "%2d", gene->chromosome[i]);
		if (gene->num_alleles - 1 != i) {
			fputc(44, stdout);
		}
			
	}
	return fprintf(stdout, " fit:%6.3f raw:%7.3f", gene->fitness, gene->raw_score);
}