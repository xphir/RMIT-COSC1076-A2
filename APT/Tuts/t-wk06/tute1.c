#include <stdio.h>
#include <stdlib.h>
/* A very simple solution to week 6 tute question */

int main(int argc, char *argv[])
{
	int i,j, data[10],num,sum;
	FILE *fp;

	if (argc != 2)
		fprintf(stderr,"Incorrect number of arguments\n");
	else
	{
		if ((fp = fopen(argv[1],"r+")) == NULL)
		{
			fprintf(stderr,"Unable to open file %s for reading\n");
			return EXIT_SUCCESS;
		}
		
		for(i = 0;i < 10; i++)
		{
			if (fscanf(fp,"%d,",&num) == 0 || feof(fp))
				break;
			data[i] = num;
		}
		rewind(fp);
		j = i;
		sum = 0;
		for(i = 0;i < j; i++)
		{
			fprintf(fp,"%d,",data[i]);
			sum += data[i];
		}
		if (j > 0)
			fprintf(fp,"%d",sum);
		
		fclose(fp);
		
	}
	return EXIT_SUCCESS;
}
