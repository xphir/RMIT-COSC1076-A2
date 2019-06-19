/******************************************************************************
** Student name: 	Elliot Schot
** Student number: 	S3530160
** Course: 			Advanced Programming Techniques - S2 2018
******************************************************************************/

#ifndef POP_H
#define POP_H

#include "gene.h"
#include "invector.h"

#define MUTATE_RATE 5

typedef struct pop_node {
	Gene *gene;
	struct pop_node *next;
} Pop_node;

typedef struct pop_list {
	/* the head of the population list */
	Pop_node *head;
	/* the size of the population */
	int count;
	/* pointers to functions to perform
 	 * gene chromosome creation, mutation,
 	 * crossover and evaluation */
	CreateFn create_rand_chrom;
	MutateFn mutate_gene;
	CrossOverFn crossover_genes;
	EvalFn evaluate_fn;
} Pop_list;

int generation;

/* Create and initialise the population list to a safe state.
 * Returns TRUE on success */
Boolean pop_init(Pop_list **);

/* Set the function pointers of a population list */
void pop_set_fns(Pop_list *p,CreateFn cf,MutateFn mf,CrossOverFn cof,EvalFn ef);

/* This function causes details of the fittest gene of the generation to 
 * be printed out.
 * The function also prints out the number of the current generation.
 * This function must not be able to access any generation value outside
 * of the function. */
void pop_print_fittest(Pop_list *pList);
void pop_print_all(Pop_list *pList);


/* TO DO - other functions as appropriate */
void pop_free(Pop_list *pList);
void pop_node_free(Pop_node * node);

void swap_node(Pop_node *a, Pop_node *b);
void pop_sort(Pop_node * start);

Pop_list *pop_run(Pop_list *pList, int popSize, int numAlleles, int numGen, InVTable *invt);
Boolean pop_create_rand_pop(Pop_list *pList, int popSize, int numAlleles);
void pop_evaluate(Pop_list *pList, InVTable *invt);
Pop_list * pop_reproduce(Pop_list * pList);
Gene *pop_proportionate_select(Pop_list *pList);

#endif
