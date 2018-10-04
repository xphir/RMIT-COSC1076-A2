/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S2 2018
******************************************************************************/

#include "drive.h"
#include "invector.h"
#include "pop.h"
#include "gene.h"

#ifdef DEBUG
void test_pcbmill(void)
{
	Gene *pcbGene;
	Gene *mutantGene;

	Gene *parentGeneA;
	Gene *parentGeneB;
	Gene *childGene;

	CreateFn chrom_pointer;
	MutateFn mutate_pointer;
	CrossOverFn crossover_pointer;
	/* TO DO */

	printf("PCBMILL gene:\n");
	/* TO DO - create a random pcbmill gene by calling create_rand_gene
	   The length of the gene's chromosome should be TEST_ALLELE_LEN */
	chrom_pointer = &create_pcbmill_chrom;
	pcbGene = gene_create_rand_gene(TEST_ALLELE_LEN, chrom_pointer);

	/* TO DO - print the gene using gene_print */
	gene_print(pcbGene);

	printf("Mutate:\n");
	/* TO DO - create a mutant copy of the gene using mutate_pcbmill */
	mutate_pointer = &mutate_pcbmill;
	mutantGene = mutate_pointer(pcbGene);

	/* TO DO - print the mutant gene using gene_print */
	gene_print(mutantGene);

	/* TO DO - free the original gene and the mutant */
	gene_free(pcbGene);
	gene_free(mutantGene);

	printf("PCBMILL genes:\n");
	/* TO DO - create 2 random pcbmill 'parent' genes using calls
	   to create_rand_gene
	   The length of the gene's chromosome should be TEST_ALLELE_LEN */
	parentGeneA = gene_create_rand_gene(TEST_ALLELE_LEN, chrom_pointer);
	parentGeneB = gene_create_rand_gene(TEST_ALLELE_LEN, chrom_pointer);

	/* TO DO - print each gene */
	gene_print(parentGeneA);
	gene_print(parentGeneB);

	printf("Crossover:\n");
	/* TO DO produce a new gene by calling crossover_pcbmill
	   with the parent genes */
	crossover_pointer = &crossover_pcbmill;
	childGene = crossover_pointer(parentGeneA, parentGeneB);

	/* TO DO - print the new gene */

	gene_print(childGene);
	
	/* TO DO - free both parents and the child gene */
	gene_free(parentGeneA);
	gene_free(parentGeneB);
	gene_free(childGene);
}
#endif

#ifdef DEBUG
void test_minfn(void)
{
	Gene *pcbGene;
	Gene *mutantGene;

	Gene *parentGeneA;
	Gene *parentGeneB;
	Gene *childGene;

	CreateFn chrom_pointer;
	MutateFn mutate_pointer;
	CrossOverFn crossover_pointer;

	/* TO DO */

	printf("MINFN gene:\n");
	/* TO DO - create a random minfn gene by calling create_rand_gene
	   The length of the gene's chromosome should be TEST_ALLELE_LEN */

	chrom_pointer = &create_minfn_chrom;
	pcbGene = gene_create_rand_gene(TEST_ALLELE_LEN, chrom_pointer);

	/* TO DO - print the gene */
	printf("DEBUG: gene_print(pcbGene);\n");
	gene_print(pcbGene);
	printf("Mutate:\n");
	/* TO DO - create a mutant copy of the gene using mutate_minfn */
	mutate_pointer = &mutate_minfn;
	mutantGene = mutate_pointer(pcbGene);
	/* TO DO - print the mutant gene */
	printf("DEBUG: gene_print(mutantGene);\n");
	gene_print(mutantGene);
	printf("DEBUG: gene_print(pcbGene);\n");
	gene_print(pcbGene);

	/* TO DO - free the original gene and the mutant */
	printf("DEBUG: gene_free(pcbGene);\n");
	gene_free(pcbGene);
	printf("DEBUG: gene_free(mutantGene);\n");
	gene_free(mutantGene);

	printf("MINFN genes:\n");
	/* TO DO - create 2 random minfn 'parent' genes using calls
	   to create_rand_gene
	   The length of the gene's chromosome should be TEST_ALLELE_LEN */
	parentGeneA = gene_create_rand_gene(TEST_ALLELE_LEN, chrom_pointer);
	parentGeneB = gene_create_rand_gene(TEST_ALLELE_LEN, chrom_pointer);

	/* TO DO - print each gene */
	printf("DEBUG: gene_print(parentGeneA);\n");
	gene_print(parentGeneA);
	printf("DEBUG: gene_print(parentGeneB);\n");
	gene_print(parentGeneB);

	printf("Crossover:\n");
	/* TO DO produce a new gene by calling crossover_minfn
	   with the parent genes */
	crossover_pointer = &crossover_minfn;
	childGene = crossover_pointer(parentGeneA, parentGeneB);

	/* TO DO - print the new gene */
	printf("DEBUG: gene_print(childGene);\n");
	gene_print(childGene);
	/* TO DO - free both parents and the child gene */
	/* gene_free(parentGeneA);
	gene_free(parentGeneB);
	gene_free(childGene); */
}
#endif

int main(int argc, char *argv[])
{

	/* TO DO */

	/* The only point at which srand should be called */
	srand(SRAND_SEED);

	/* Called on -DDEBUG make */
	#ifdef DEBUG
		test_minfn();
		test_pcbmill();
	#endif

	
			

	return EXIT_SUCCESS;
}