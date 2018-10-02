/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S2 2018
******************************************************************************/

#include "drive.h"
#include "invector.h"
#include "pop.h"
#include "gene.h"

void test_pcbmill(void){
	/* TO DO */

	printf("PCBMILL gene:\n");
	/* TO DO - create a random pcbmill gene by calling create_rand_gene
	   The length of the gene's chromosome should be TEST_ALLELE_LEN */
	
	Gene * pcbGene;
	CreateFn chrom_pointer = &create_pcbmill_chrom;
	pcbGene = gene_create_rand_gene(TEST_ALLELE_LEN, chrom_pointer);
	
	/* TO DO - print the gene using gene_print */
	gene_print(pcbGene);
	

	printf("\nMutate: ");
	/* TO DO - create a mutant copy of the gene using mutate_pcbmill */
	
	/* TO DO - print the mutant gene using gene_print */

	printf("\n");
	/* TO DO - free the original gene and the mutant */
	free(pcbGene)
	printf("PCBMILL genes:\n");
	/* TO DO - create 2 random pcbmill 'parent' genes using calls
	   to create_rand_gene
	   The length of the gene's chromosome should be TEST_ALLELE_LEN */
	/* TO DO - print each gene */
	printf("\nCrossover: ");
	/* TO DO produce a new gene by calling crossover_pcbmill
	   with the parent genes */
	/* TO DO - print the new gene */
	printf("\n");
	/* TO DO - free both parents and the child gene */
}

void test_minfn(void){
	/* TO DO */

	printf("MINFN gene:\n");
	/* TO DO - create a random minfn gene by calling create_rand_gene
	   The length of the gene's chromosome should be TEST_ALLELE_LEN */
	Gene * pcbGene;
	CreateFn chrom_pointer = &create_minfn_chrom;
	pcbGene = gene_create_rand_gene(TEST_ALLELE_LEN, chrom_pointer);

	/* TO DO - print the gene */
	gene_print(pcbGene);

	printf("\nMutate: ");
	/* TO DO - create a mutant copy of the gene using mutate_minfn */
	/* TO DO - print the mutant gene */
	printf("\n");

	free(pcbGene)
	/* TO DO - free the original gene and the mutant */
	printf("MINFN genes:\n");
	/* TO DO - create 2 random minfn 'parent' genes using calls
	   to create_rand_gene
	   The length of the gene's chromosome should be TEST_ALLELE_LEN */
	/* TO DO - print each gene */
	printf("\nCrossover: ");
	/* TO DO produce a new gene by calling crossover_minfn
	   with the parent genes */
	/* TO DO - print the new gene */
	printf("\n");
	/* TO DO - free both parents and the child gene */
}

int main(int argc, char *argv[]){

	/* TO DO */

	/* The only point at which srand should be called */
	srand(SRAND_SEED);

	void test_minfn(void);
	void test_pcbmill(void);

	return EXIT_SUCCESS;
}

