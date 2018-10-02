#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100

int main(int argc, char **argv)
{
	FILE *fp;
	char line[MAXLINE];
	int line_no = 1;

	if (argc != 2)
	{
		fprintf(stderr,"Invalid usage: %s \n",argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1],"r")) == NULL)
	{
		fprintf(stderr,"File not found\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		fgets(line,MAXLINE,fp);
		if (feof(fp))
			break;
		printf("%d ",line_no++);
		fputs(line,stdout);
	}
	return EXIT_SUCCESS;
}
