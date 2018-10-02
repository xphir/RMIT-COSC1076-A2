/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S2 2018
******************************************************************************/

#include "drive.h"
#include "invector.h"
#include "pop.h"
#include "gene.h"

void test_pcbmill(void)
{
	/* TO DO */

	printf("PCBMILL gene:\n");
	/* TO DO - create a random pcbmill gene by calling create_rand_gene
	   The length of the gene's chromosome should be TEST_ALLELE_LEN */

	/* TO DO - print the gene using gene_print */
	printf("\nMutate: ");
	/* TO DO - create a mutant copy of the gene using mutate_pcbmill */
	/* TO DO - print the mutant gene using gene_print */
	printf("\n");
	/* TO DO - free the original gene and the mutant */
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

void test_minfn(void)
{
	/* TO DO */

	printf("MINFN gene:\n");
	/* TO DO - create a random minfn gene by calling create_rand_gene
	   The length of the gene's chromosome should be TEST_ALLELE_LEN */

	/* TO DO - print the gene */
	printf("\nMutate: ");
	/* TO DO - create a mutant copy of the gene using mutate_minfn */
	/* TO DO - print the mutant gene */
	printf("\n");
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

int main(int argc, char *argv[])
{
	double v3;
	int result;
	int inputVectorWidth;
	int inputVectorNumber;
	int numGen;
	int popSize;
	int alleleSize;
	int counter;
	InVTable inputVectorTable;
	Pop_list *populationList;
	char *endptr;
	FILE *stream;

	/* The only point at which srand should be called */
	srand(SRAND_SEED);

	/* Argument examples */
	/* ./ga [1]geneType  [2]alleleSize [3]popSize [4]numGen [5]inputFile [6-Optional]outputFile  */

	/* Check if there is the correct number of arguments */
	if (argc <= 5 || argc > 7)
	{
		fwrite("main: incorrect number of arguments\n", 1uLL, 0x24uLL, stderr);
		return EXIT_FAILURE;
	}

	/* Initialise populationList */
	if (pop_init(&populationList) == FALSE)
	{
		return EXIT_FAILURE;
	}

	/* Initialise inputVectorTable */
	invector_init(&inputVectorTable);

	/* Get 5th argument */
	/* Load inputFile (input vector) */
	if (!invector_load(&inputVectorTable, argv[5]))
	{
		pop_free(populationList);
		return EXIT_FAILURE;
	}

	/* Get 2nd argument */
	alleleSize = strtol(argv[2], &endptr, 10);

	/* Invalid integer argument */
	if (argv[2] == endptr || *endptr || (signed int)alleleSize <= 0)
	{
		fwrite("invalid integer argument\n", 1uLL, 0x19uLL, stderr);
		pop_free(populationList);
		return EXIT_FAILURE;
	}

	/* Check to see minfn or pcbmill is selected */
	if (!strncmp(argv[1], "minfn", 6))
	{
		/* minfn was selected */

		inputVectorWidth = invector_get_width(&inputVectorTable);

		/* Check minfn width*/
		if (inputVectorWidth - 1 != alleleSize)
		{
			fwrite("allelesize mismatch with vector size\n", 1uLL, 0x25uLL, stderr);
			pop_free(populationList);
			return EXIT_FAILURE;
		}
		/* Check minfn width*/
		if ((unsigned int)invector_get_num_invector(&inputVectorTable) != 1)
		{
			fwrite("too many input vectors for minfn data file\n", 1uLL, 0x2BuLL, stderr);
			pop_free(populationList);
			return EXIT_FAILURE;
		}
		pop_set_fns(
			populationList,
			create_minfn_chrom,
			mutate_minfn,
			crossover_minfn,
			eval_minfn);
	}
	else
	{
		/* 2nd argument is neither minfn or pcbmill */
		if (strncmp(argv[1], "pcbmill", 8))
		{
			fwrite("incorrect 2nd argument\n", 1uLL, 0x17uLL, stderr);
			return EXIT_FAILURE;
		}

		/* pcbmill was selected */
		/* gets the number of input vectors */
		inputVectorNumber = invector_get_num_invector(&inputVectorTable);

		/* allelesize mismatch with num vectors */
		if (inputVectorNumber != alleleSize)
		{
			fwrite("allelesize mismatch with num vectors\n", 1uLL, 0x25uLL, stderr);
			pop_free(populationList);
			return EXIT_FAILURE;
		}

		/* Set the function pointers of a population list */
		pop_set_fns(
			populationList,
			create_pcbmill_chrom,
			mutate_pcbmill,
			crossover_pcbmill,
			eval_pcbmill);
	}

	/* Get 3rd argument */
	popSize = strtol(argv[3], &endptr, 10);

	if (argv[3] == endptr || *endptr || popSize <= 1)
	{
		/* 3rd argument is not a correct integer */
		fwrite("invalid integer argument\n", 1uLL, 0x19uLL, stderr);
		pop_free(populationList);
		return EXIT_FAILURE;
	}
	else
	{
		/* Get 4th argument */
		numGen = strtol(argv[4], &endptr, 10);

		if (argv[4] == endptr || *endptr || numGen < 0)
		{
			fwrite("invalid integer argument\n", 1uLL, 0x19uLL, stderr);
			pop_free(populationList);
			return EXIT_FAILURE;
		}
		else if (argc != 7 || (stream = freopen(argv[6], "w", stdout)) != FALSE)
		{
			/* Get 6th argument */
			populationList = pop_run(populationList, popSize, alleleSize, numGen, &inputVectorTable, v3);
			if (populationList)
			{
				pop_free(populationList);
				if (stream)
					fclose(stream);
				return EXIT_SUCCESS;
			}
			else
			{
				pop_free(0LL);
				return EXIT_FAILURE;
			}
		}
		else
		{
			fwrite("Unable to open output file \n", 1uLL, 0x1CuLL, stderr);
			pop_free(populationList);
			return EXIT_FAILURE;
		}
	}
	return result;
}