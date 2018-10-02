/* Make a copy of a file */
#include <stdio.h>
#define MAXSTRING 100

int main(void)
{
 	char fname[MAXSTRING];
	int c;
	FILE *fp1, *fp2 ;

	fprintf(stderr, "\nInput the source filename:" );
	scanf("%s", fname);
	fp1 = fopen(fname, "rb");	/* read in binary mode */
	fprintf(stderr, "\nInput the destination filename:" );
	scanf("%s", fname);
	fp2 = fopen(fname, "wb");	/* write in binary mode */

	while (fread(&c, sizeof(c), 1, fp1) > 0) /* read until EOF */
	{
			fwrite(&c, sizeof(c), 1, fp2);	 /* write to the new file */		
	}

	fclose(fp1);
	fclose(fp2);
	return 0;
}

