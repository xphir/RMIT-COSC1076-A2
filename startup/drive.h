/******************************************************************************
** Student name: 	Elliot Schot
** Student number: 	S3530160
** Course: 			Advanced Programming Techniques - S2 2018
******************************************************************************/

#ifndef DRIVE_H
#define DRIVE_H

#include "utility.h"

/* The seed value for srand */
#define SRAND_SEED 1

/* Possible valid values of argv[geneType] (see the enum below)*/
#define CMD_ARG_MINFN "minfn"
#define CMD_ARG_PCBMILL "pcbmill"

/* The maximum number of command line arguments expected */
#define CMD_ARG_MAX 7
/* The minimum number of command line arguments expected */
#define CMD_ARG_MIN 6

#define DECIMAL 10

/* The number of alleles for use in the two test functions 
 * test_pcbmill() and test_minfn() */
#define TEST_ALLELE_LEN 6

/* Avoid having 'magic numbers' when using argv ... */
enum argtype
{
    geneType = 1,
    alleleSize = 2,
    popSize = 3,
    numGen = 4,
    inputFile = 5,
    outputFile = 6
};

/* Functions for testing creation of random genes, crossover and mutation.
 * These functions are only called if a DEBUG macro has been defined during 
 * compilation */
void test_pcbmill(void);
void test_minfn(void);

#endif
