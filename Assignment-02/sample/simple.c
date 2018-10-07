void pop_print_fittest(Pop_list *pList)
{
    Gene *result;
    double randomNum;
    double count;
	if (pList != NULL)
	{
		Pop_node *node = pList->head;
        randomNum = (double)(rand() % 1000) / 1000.0;
        count = 0.0;
		while (node != NULL)
		{
			result = node->gene;
			count += node->gene->fitness;
			node = node->next;
		}
		fprintf(stdout, "\n");
		generation++;
	}
	else
	{
		fwrite("pop_print_fittest: pop is empty\n", 1, 32, stderr);
	}
}