#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	char name[10];
	int c;
	printf("Enter file name: ");
	scanf("%s",name);
	if ((fp = fopen(name,"r")) == NULL)
		fprintf(stderr,"File not found\n");
	else
	{
		while (1)
		{
			c = fgetc(fp);
			if (feof(fp))
				break;
			putc(c,stdout);
		}
	}
	return EXIT_SUCCESS;
}
