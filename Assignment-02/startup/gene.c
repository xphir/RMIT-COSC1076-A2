/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S2 2018
******************************************************************************/

#include "gene.h"

int * create_pcbmill_chrom(int numAlleles){
	/* TO DO */
	return NULL;
}

int * create_minfn_chrom(int numAlleles){
	/* TO DO */
	return NULL;
}

Gene * mutate_pcbmill(Gene *g){
	/* TO DO */
	return NULL;
}

Gene * mutate_minfn(Gene *g){
	/* TO DO */
	return NULL;
}

Gene * crossover_pcbmill(Gene *g1, Gene *g2){
	/* TO DO */
	return NULL;
}

Gene * crossover_minfn(Gene *g1, Gene *g2){
	/* TO DO */
	return NULL;
}

double eval_pcbmill(InVTable *invt, Gene *gene){
	/* TO DO */
	return 0.0;
}

double eval_minfn(InVTable *invt, Gene *gene){
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