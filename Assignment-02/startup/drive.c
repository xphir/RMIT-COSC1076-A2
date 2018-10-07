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

	printf("Mutate: ");
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

	printf("Crossover: ");
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
	printf("\n");
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
	gene_print(pcbGene);
	printf("Mutate: ");
	/* TO DO - create a mutant copy of the gene using mutate_minfn */
	mutate_pointer = &mutate_minfn;
	mutantGene = mutate_pointer(pcbGene);
	/* TO DO - print the mutant gene */
	gene_print(mutantGene);

	/* TO DO - free the original gene and the mutant */
	gene_free(pcbGene);
	gene_free(mutantGene);

	printf("MINFN genes:\n");
	/* TO DO - create 2 random minfn 'parent' genes using calls
	   to create_rand_gene
	   The length of the gene's chromosome should be TEST_ALLELE_LEN */
	parentGeneA = gene_create_rand_gene(TEST_ALLELE_LEN, chrom_pointer);
	parentGeneB = gene_create_rand_gene(TEST_ALLELE_LEN, chrom_pointer);

	/* TO DO - print each gene */
	gene_print(parentGeneA);
	gene_print(parentGeneB);

	printf("Crossover: ");
	/* TO DO produce a new gene by calling crossover_minfn
	   with the parent genes */
	crossover_pointer = &crossover_minfn;
	childGene = crossover_pointer(parentGeneA, parentGeneB);

	/* TO DO - print the new gene */
	gene_print(childGene);
	/* TO DO - free both parents and the child gene */
	gene_free(parentGeneA);
	gene_free(parentGeneB);
	gene_free(childGene);
	printf("\n");
}
#endif

int main(int argc, char *argv[])
{
	int inputVectorWidth;
	int inputVectorNumber;
	int localNumGen;
	int localPopSize;
	int localAlleleSize;
	InVTable *inputVectorTable;
	Pop_list *pList;
	char *endptr;
	FILE *stream;

	/* Argument examples: ./ga [1]geneType  [2]localAlleleSize [3]localPopSize [4]localNumGen [5]inputFile [6-Optional]outputFile  */

	/* The only point at which srand should be called */
	srand(SRAND_SEED);

/* Called on -DDEBUG make */
	#ifdef DEBUG
		test_minfn();
		test_pcbmill();
		return EXIT_SUCCESS;
	#endif
	/*
	argc = 6;
	argv[geneType] = CMD_ARG_PCBMILL;
	argv[alleleSize] = "12";
	argv[popSize] = "10";
	argv[numGen] = "20";
	argv[inputFile] = "pcbin.dat";
	argv[outputFile] = "output.txt";*/
	

	fprintf(stdout, "argc: %d | argv[geneType]: %s | argv[alleleSize]: %s | argv[popSize]: %s | argv[numGen]: %s | argv[inputFile]: %s | argv[outputFile]: %s\n", argc, argv[geneType], argv[alleleSize], argv[popSize], argv[numGen], argv[inputFile], argv[outputFile]);
	
	/* Check if there is the correct number of arguments */
	if (argc < CMD_ARG_MIN || argc > CMD_ARG_MAX)
	{
		fwrite("main: incorrect number of arguments\n", 1, 36, stderr);
		return EXIT_FAILURE;
	}

	/* Initialise pList */
	if (pop_init(&pList) == FALSE)
	{
		return EXIT_FAILURE;
	}

	/* Initialise inputVectorTable */
	invector_init(&inputVectorTable);

	/* Get 5th argument */
	/* Load inputFile (input vector) */
	if (!invector_load(&inputVectorTable, argv[inputFile]))
	{
		pop_free(pList);
		return EXIT_FAILURE;
	}

	/* Get 2nd argument */
	localAlleleSize = strtol(argv[alleleSize], &endptr, 10);

	/* Invalid integer argument */
	if (argv[alleleSize] == endptr || *endptr || localAlleleSize <= 0)
	{
		fwrite("invalid integer argument\n", 1, 25, stderr);
		pop_free(pList);
		return EXIT_FAILURE;
	}

	/* Check to see minfn or pcbmill is selected */
	if (!strncmp(argv[geneType], CMD_ARG_MINFN, 6))
	{
		/* minfn was selected */
		inputVectorWidth = invector_get_width(&inputVectorTable);

		/* Check minfn width*/
		if (inputVectorWidth - 1 != localAlleleSize)
		{
			fwrite("alleleSize mismatch with vector size\n", 1, 37, stderr);
			pop_free(pList);
			return EXIT_FAILURE;
		}
		/* Check minfn width*/
		if (invector_get_num_invector(&inputVectorTable) != 1)
		{
			fwrite("too many input vectors for minfn data file\n", 1, 43, stderr);
			pop_free(pList);
			return EXIT_FAILURE;
		}
		/* Set the function pointers of minfn */
		pop_set_fns(
			pList,
			create_minfn_chrom,
			mutate_minfn,
			crossover_minfn,
			eval_minfn);
	}
	else if (!strncmp(argv[geneType], CMD_ARG_PCBMILL, 8))
	{
		/* pcbmill was selected */
		inputVectorNumber = invector_get_num_invector(&inputVectorTable);

		/* Check pcbmill width*/
		if (inputVectorNumber != localAlleleSize)
		{
			fwrite("alleleSize mismatch with num vectors\n", 1, 37, stderr);
			pop_free(pList);
			return EXIT_FAILURE;
		}

		/* Set the function pointers of pcbmill */
		pop_set_fns(
			pList,
			create_pcbmill_chrom,
			mutate_pcbmill,
			crossover_pcbmill,
			eval_pcbmill);
	}
	else
	{
		fwrite("incorrect 2nd argument\n", 1, 23, stderr);
		return EXIT_FAILURE;
	}

	/* Get 3rd argument popSize */
	localPopSize = strtol(argv[popSize], &endptr, 10);

	if (argv[popSize] == endptr || *endptr || localPopSize <= 1)
	{
		/* 3rd argument is not a correct integer */
		fwrite("invalid integer argument\n", 1, 25, stderr);
		pop_free(pList);
		return EXIT_FAILURE;
	}

	/* Get 4th argument numGen */
	localNumGen = strtol(argv[numGen], &endptr, 10);

	if (argv[numGen] == endptr || *endptr || localNumGen < 0)
	{
		fwrite("invalid integer argument\n", 1, 25, stderr);
		pop_free(pList);
		return EXIT_FAILURE;
	}
	else if (argc != CMD_ARG_MAX || (stream = freopen(argv[outputFile], "w", stdout)) != NULL)
	{
		/* Get 6th argument */
		pList = pop_run(pList, localPopSize, localAlleleSize, localNumGen, &inputVectorTable);
		if (pList)
		{
			pop_free(pList);
			if (stream != NULL)
			{
				fclose(stream);
			}
			return EXIT_SUCCESS;
		}
		else
		{
			/* pop_free(NULL); */
			return EXIT_FAILURE;
		}
	}
	else
	{
		fwrite("Unable to open output file \n", 1, 28, stderr);
		pop_free(pList);
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}