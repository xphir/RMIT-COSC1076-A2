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