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
			gene_swap_alleles(alleles, alleleA, alleleB);
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
	/* TO DO */
	Gene *new_gene;
	Gene *result_gene;
	int randomInt;

	new_gene = gene_copy(g);
	if (new_gene != NULL)
	{
		randomInt = rand();
		/* TO DO */
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
	/* TO DO */
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
	/* TO DO */
}

void gene_swap_alleles(__int64 g, int alleleA, int alleleB)
{
	unsigned int v3; // ST1C_4@1
	__int64 result;  // rax@1

	v3 = *(_DWORD *)(4LL * alleleA + g);
	*(_DWORD *)(g + 4LL * alleleA) = *(_DWORD *)(4LL * alleleB + g);
	result = v3;
	*(_DWORD *)(g + 4LL * alleleB) = v3;
	return result;
}

Gene *gene_copy(Gene *g)
{

	Gene *result_gene;
	Gene *new_gene;
	void *v2;

	new_gene = malloc(sizeof(new_gene));
	if (new_gene)
	{
		v2 = malloc(sizeof(v2));
		if (v2)
		{
			new_gene->chromosome = v2;
			new_gene->num_alleles = numAlleles;
			new_gene->raw_score = 0;
			new_gene->fitness = 0;
			*(_QWORD *)new_gene = v2;
			new_gene[2] = *(_DWORD *)(g + 8);
			*((_QWORD *)new_gene + 3) = *(_QWORD *)(g + 24);
			*((_QWORD *)new_gene + 2) = *(_QWORD *)(g + 16);
			memcpy(*(void **)new_gene, *(const void **)g, 4LL * *(_DWORD *)(g + 8));
			result_gene = new_gene;
		}
		else
		{
			fwrite("Unable to allocate memory in gene_copy\n", 1, 39, stderr);
			free(new_gene);
			result_gene = NULL;
		}
	}
	else
	{
		fwrite("Unable to allocate memory in gene_copy\n", 1, 39, stderr);
		result_gene = NULL;
	}
	return result_gene;
}