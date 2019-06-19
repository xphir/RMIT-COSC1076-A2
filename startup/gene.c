/******************************************************************************
** Student name: 	Elliot Schot
** Student number: 	S3530160
** Course: 			Advanced Programming Techniques - S2 2018
******************************************************************************/

#include "gene.h"
/* Creates a pcbmill chromosome (an array of alleles) */
int *create_pcbmill_chrom(int numAlleles)
{
	int *resultChromosome;
	int allele1;
	int allele2;
	int i;
	int j;

	resultChromosome = malloc(numAlleles * sizeof(resultChromosome));
	if (resultChromosome != NULL)
	{
		/* This sets the chromosome to be 1,2,3,4.. and so on */
		for (i = 0; i < numAlleles; ++i)
		{
			resultChromosome[i] = i;
		}
		/* This randomly swaps around the chromosomes values*/
		for (j = 0; j < numAlleles; j = allele1 + 1)
		{
			allele1 = rand() % numAlleles;
			allele2 = rand() % numAlleles;
			gene_swap_alleles(resultChromosome, allele1, allele2);
		}
	}
	else
	{
		fwrite("Unable to allocate chromosome memory", 1, 36, stderr);
	}
	return resultChromosome;
}

/* Creates a minfn chromosome (an array of alleles) */
int *create_minfn_chrom(int numAlleles)
{
	int *resultChromosome;
	int i;

	resultChromosome = malloc(numAlleles * sizeof(resultChromosome));
	if (resultChromosome)
	{
		/* This sets the chromosomes values to randomly from 0 to MINFN_MAX */
		for (i = 0; i < numAlleles; ++i)
		{
			resultChromosome[i] = rand() % MINFN_MAX;
		}
	}
	else
	{
		fwrite("Unable to allocate chromosome memory", 1, 36, stderr);
	}
	return resultChromosome;
}

/* Swaps the values of two randomly selected alleles */
Gene *mutate_pcbmill(Gene *g)
{
	int randomInt1;
	int randomInt2;
	Gene *new_gene;

	new_gene = gene_copy(g);
	if (new_gene != NULL)
	{
		/* Set debug values */
		#ifdef DEBUG
			randomInt1 = 2;
			randomInt2 = 4;
		#else
			randomInt1 = rand() % new_gene->num_alleles;
			randomInt2 = rand() % new_gene->num_alleles;
		#endif

		/* Swap the two random alleles */
		gene_swap_alleles(new_gene->chromosome, randomInt1, randomInt2);

		#ifdef DEBUG
			fprintf(stdout, "index %d index %d\n", randomInt1, randomInt2);
		#endif
	}
	return new_gene;
}

/* Select a random allele and set a new random value 0 to MINFN_MAX*/
Gene *mutate_minfn(Gene *g)
{
	int randomInt;
	int randomIndex;
	Gene *new_gene;

	new_gene = gene_copy(g);
	if (new_gene != NULL)
	{
		/* Select a random allele */
		#ifdef DEBUG
			randomIndex = 2;
		#else
			randomIndex = rand() % new_gene->num_alleles;
		#endif
		/* Select random value 0 to MINFN_MAX*/
		randomInt = rand() % MINFN_MAX;
		
		new_gene->chromosome[randomIndex] = randomInt;

		#ifdef DEBUG
			fprintf(stdout, "index %d\n", randomIndex);
		#endif
	}
	return new_gene;
}

/* PCBMill crossover - see specs for more info */
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
			/* Select the first random value */
			randomInt1 = rand() % (new_gene->num_alleles - 1);
			/* Select a the 2nd random value */
			randomInt2 = randomInt1 + rand() % (new_gene->num_alleles + ~randomInt1) + 1;
		#endif	

		/* Set the new_gene to have its first values copyied over from g1*/
		for (i = 0; randomInt2 - randomInt1 >= i; i++)
		{
			new_gene->chromosome[i] = g1->chromosome[i + randomInt1];
		}

		/* Set the remaning values for new_gene from what is not in new_gene in the order from g2 */
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

/* MINFN crossover - see specs for more info */
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

		#ifdef DEBUG
			fprintf(stdout, "index %d\n", randomInt);
		#endif
	}
	return new_gene;
}

/* evaluate PCBMILL - see specs for more info */
double eval_pcbmill(InVTable *invt, Gene *gene)
{
	int *tableRow1;
	int *tableRow2;
	int numAlleles;
	double totalRawScore;
	int i;

	totalRawScore = 0.0;
	numAlleles = gene->num_alleles;
	/* calculate the distance between each allele */
	for (i = 0; numAlleles - 1 > i; ++i)
	{
		tableRow1 = invt->table[gene->chromosome[i]];
		tableRow2 = invt->table[gene->chromosome[i+1]];
		totalRawScore = pcbmill_distance(tableRow1, tableRow2) + totalRawScore;
	}
	/* return the combined total distance */
	return totalRawScore;
}

/* evaluate MINFN - see specs for more info */
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
		/* calculate the rawScore */
		for (j = 0; j < gene->num_alleles; j++)
		{
			rawScore += vector[j] * gene->chromosome[j];
		}
		/* minius the last vector value */
		rawScore -= vector[gene->num_alleles];
		/* make rawscore positive */
		totalRawScore += fabs(rawScore);
	}
	return totalRawScore;
}

/* Create a random gene */
Gene *gene_create_rand_gene(int numAlleles, CreateFn create_chrom)
{
	Gene *new_gene = malloc(sizeof(*new_gene));

	if (new_gene != NULL)
	{
		/* create the gene default values */
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

/* Self-explanatory */
void gene_calc_fitness(Gene *gene, EvalFn evaluate_fn, InVTable *invTab)
{
	gene->raw_score = evaluate_fn(invTab, gene);
	gene->fitness = gene_get_fitness(gene);
}

/* Self-explanatory */
void gene_normalise_fitness(Gene *gene, double total_fitness)
{
	gene->fitness /= total_fitness;
}

/* Self-explanatory */
void gene_free(Gene *gene)
{
	free(gene->chromosome);
	free(gene);
}

/* Self-explanatory */
double gene_get_fitness(Gene *gene)
{
	return 1 / (gene->raw_score + 1);
}

/* Print the genes values */
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

/* The PCBMILL calcuation function - see PCBMILL specs for more info */
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

/* Copy a gene to a new gene with a different memory address */
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
			/* Copy values from g */
			memcpy(new_gene->chromosome, g->chromosome, g->num_alleles * sizeof(int));
		}
	}
	else
	{
		fwrite("Unable to allocate memory in gene_copy\n", 1, 39, stderr);
	}

	return new_gene;
}

/* Swap the values in the chromosone  */
void gene_swap_alleles(int *chromosome, int allele1, int allele2)
{
	int av1;
	int av2;

	av1 = chromosome[allele1];
	av2 = chromosome[allele2];

	chromosome[allele1] = av2;
	chromosome[allele2] = av1;

	return;
}

/* Check if a gene contains a specific value less than index */
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