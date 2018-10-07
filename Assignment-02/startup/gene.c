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
	int allele1;
	int allele2;
	int i;
	int j;

	alleles = malloc(numAlleles * sizeof(alleles));
	if (alleles != NULL)
	{
		for (i = 0; i < numAlleles; ++i)
		{
			alleles[i] = i;
		}
		for (j = 0; j < numAlleles; j = allele1 + 1)
		{
			allele1 = rand() % numAlleles;
			allele2 = rand() % numAlleles;
			gene_swap_alleles(alleles, allele1, allele2);
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

	alleles = malloc(numAlleles * sizeof(alleles));
	if (alleles)
	{
		for (i = 0; i < numAlleles; ++i)
		{
			alleles[i] = rand() % MINFN_MAX;
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
	int randomInt1;
	int randomInt2;
	int value1;
	int value2;
	Gene *new_gene;

	new_gene = gene_copy(g);
	if (new_gene != NULL)
	{
#ifdef DEBUG
		randomInt1 = 2;
		randomInt2 = 4;
#else
		randomInt1 = rand() % new_gene->num_alleles;
		randomInt2 = rand() % new_gene->num_alleles;
#endif

		value1 = new_gene->chromosome[randomInt1];
		value2 = new_gene->chromosome[randomInt2];

		new_gene->chromosome[randomInt1] = value2;
		new_gene->chromosome[randomInt2] = value1;
#ifdef DEBUG
		fprintf(stdout, "index %d index %d\n", randomInt1, randomInt2);
#endif
	}

	return new_gene;
}

Gene *mutate_minfn(Gene *g)
{
	int randomInt;
	int randomIndex;
	Gene *new_gene;

	new_gene = gene_copy(g);
	if (new_gene != NULL)
	{
#ifdef DEBUG
		randomIndex = 2;
#else
		randomIndex = rand() % new_gene->num_alleles;
#endif

		randomInt = rand() % MINFN_MAX;
		new_gene->chromosome[randomIndex] = randomInt;

#ifdef DEBUG
		fprintf(stdout, "index %d\n", randomIndex);
#endif
	}
	return new_gene;
}

Gene *crossover_pcbmill(Gene *g1, Gene *g2)
{
	Gene *new_gene;
	int randomInt1;
	int randomInt2;
	int j;
	int i;

	new_gene = gene_copy(g1);
	if (new_gene != NULL)
	{
#ifdef DEBUG
		randomInt1 = 2;
		randomInt2 = 4;
#else
		randomInt1 = rand() % (new_gene->num_alleles - 1);
		randomInt2 = randomInt1 + rand() % (new_gene->num_alleles + ~randomInt1) + 1;
#endif
		for (i = 0; randomInt2 - randomInt1 >= i; i++)
		{
			new_gene->chromosome[i] = g1->chromosome[i + randomInt1];
		}
		for (j = 0; g2->num_alleles > j; j++)
		{
			if (gene_chrom_contains(new_gene, randomInt2 - randomInt1, g2->chromosome[j]) == FALSE)
			{
				new_gene->chromosome[i++] = g2->chromosome[j];
			}
		}
#ifdef DEBUG
		fprintf(stdout, "index %d index %d\n", randomInt1, randomInt2);
#endif
	}
	return new_gene;
}

Gene *crossover_minfn(Gene *g1, Gene *g2)
{
	Gene *new_gene;
	int randomInt;
	int i;
	new_gene = gene_copy(g1);
	if (new_gene != NULL)
	{
/* Select a random index */
#ifdef DEBUG
		randomInt = 2;
#else
		randomInt = rand() % new_gene->num_alleles;
#endif
		/* Copy every chromosome less than and including randomInt from g1 */
		for (i = 0; i <= randomInt; i++)
		{
			new_gene->chromosome[i] = g1->chromosome[i];
		}
		/* Copy every chromosome greater than randomInt from g2 */
		for (i = (randomInt + 1); i < new_gene->num_alleles; i++)
		{
			new_gene->chromosome[i] = g2->chromosome[i];
		}
		/* Fill raw and fitness at 0  */
		new_gene->raw_score = 0;
		new_gene->fitness = 0;
/* Set the result_gene  */
#ifdef DEBUG
		fprintf(stdout, "index %d\n", randomInt);
#endif
	}

	return new_gene;
}

double eval_pcbmill(InVTable *invt, Gene *gene)
{
	int *tableRow1;
	int *tableRow2;
	int numAlleles;
	double resultEval;
	int i;

	resultEval = 0.0;
	numAlleles = gene_get_num_alleles(gene);
	for (i = 0; numAlleles - 1 > i; ++i)
	{
		tableRow1 = invector_get_table_row(invt, gene->chromosome[i]);
		tableRow2 = invector_get_table_row(invt, gene->chromosome[i + 1]);
		resultEval = pcbmill_distance(tableRow1, tableRow2) + resultEval;
	}
	return resultEval;
}

double eval_minfn(InVTable *invt, Gene *gene)
{
	double totalRawScore;
	int i;
	totalRawScore = 0;
	for (i = 0; i < invt->tot; i++)
	{
		int *vector = invt->table[i];
		int j;
		double rawScore;

		rawScore = 0;
		for (j = 0; j < gene->num_alleles; j++)
		{
			rawScore += vector[j] * gene->chromosome[j];
		}
		rawScore -= vector[gene->num_alleles];
		totalRawScore += fabs(rawScore);
	}
	return totalRawScore;
}

Gene *gene_create_rand_gene(int numAlleles, CreateFn create_chrom)
{
	Gene *new_gene = malloc(sizeof(*new_gene));

	if (new_gene != NULL)
	{
		new_gene->chromosome = create_chrom(numAlleles);
		new_gene->num_alleles = numAlleles;
		new_gene->raw_score = 0;
		new_gene->fitness = 0;
	}
	else
	{
		fwrite("Unable to allocate memory in gene_create_rand_gene\n", 1, 51, stderr);
	}
	return new_gene;
}

void gene_calc_fitness(Gene *gene, EvalFn evaluate_fn, InVTable *invTab)
{
	gene->raw_score = evaluate_fn(invTab, gene);
	gene->fitness = gene_get_fitness(gene);
}

void gene_normalise_fitness(Gene *gene, double total_fitness)
{
	gene->fitness /= total_fitness;
}

void gene_free(Gene *gene)
{
	free(gene->chromosome);
	free(gene);
}

double gene_get_fitness(Gene *gene)
{
	return 1 / (gene->raw_score + 1);
}

void gene_print(Gene *gene)
{
	int i;

	fwrite("chrom:", 1, 6, stdout);
	for (i = 0; gene->num_alleles > i; ++i)
	{
		fprintf(stdout, "%2d", gene->chromosome[i]);
		if (gene->num_alleles - 1 != i)
		{
			fputc(',', stdout);
		}
	}
	fprintf(stdout, " fit:%6.3f raw:%7.3f\n", gene->fitness, gene->raw_score);
	return;
}

double pcbmill_distance(int *tableRow1, int *tableRow2)
{
	int calcY;
	int calcX;
	double result;
	calcY = tableRow2[0] - tableRow1[0];
	calcX = tableRow2[1] - tableRow1[1];
	result = sqrt(((calcY * calcY) + (calcX * calcX)));
	return result;
}

Gene *gene_copy(Gene *g)
{
	int *chromosome;
	Gene *new_gene = malloc(sizeof(*g));

	if (new_gene != NULL)
	{
		chromosome = malloc(g->num_alleles * sizeof(int));
		if (chromosome != NULL)
		{
			new_gene->chromosome = chromosome;
			new_gene->num_alleles = g->num_alleles;
			new_gene->fitness = new_gene->raw_score = 0;
			/* Copy Values */
			memcpy(new_gene->chromosome, g->chromosome, g->num_alleles * sizeof(int));
		}
	}
	else
	{
		fwrite("Unable to allocate memory in gene_copy\n", 1, 39, stderr);
	}

	return new_gene;
}

int *gene_get_chrom(Gene *g)
{
	return g->chromosome;
}

int gene_get_num_alleles(Gene *g)
{
	return g->num_alleles;
}

void gene_swap_alleles(int *alleles, int allele1, int allele2)
{
	int alleleValue1;
	int alleleValue2;

	alleleValue1 = alleles[allele1];
	alleleValue2 = alleles[allele2];

	alleles[allele1] = alleleValue2;
	alleles[allele2] = alleleValue1;

	return;
}

Boolean gene_chrom_contains(Gene *g, int index, int value)
{
	int i;
	for (i = 0; i <= index; ++i)
	{
		if (g->chromosome[i] == value)
		{
			return TRUE;
		}
	}
	return FALSE;
}