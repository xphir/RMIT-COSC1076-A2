#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100

int main(int argc, char **argv)
{
	FILE *fp1, *fp2;
	float numlist[10], num;
	float rlistb[10];
	float rlistt[10];
	int i;

	num = 0.0;
	for(i = 0; i < 10; i++, num = num + 1.0)
		numlist[i] = num;

	if ((fp1 = fopen("fb.txt","wb")) == NULL)
	{
		fprintf(stderr,"File not created\n");
		exit(EXIT_FAILURE);
	}
	if ((fp2 = fopen("ft.txt","w")) == NULL)
	{
		fprintf(stderr,"File not created\n");
		exit(EXIT_FAILURE);
	}

	for(i = 0; i < 10; i++)
	{
		fprintf(fp1,"%f\n",numlist[i]);
		fprintf(fp2,"%f\n",numlist[i]);
	}
	fclose(fp1);
	fclose(fp2);
	if ((fp1 = fopen("fb.txt","rb")) == NULL)
	{
		fprintf(stderr,"File not created\n");
		exit(EXIT_FAILURE);
	}
	if ((fp2 = fopen("ft.txt","r")) == NULL)
	{
		fprintf(stderr,"File not created\n");
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < 10; i++)
	{
		fscanf(fp1,"%f\n",&rlistb[i]);
		fscanf(fp2,"%f\n",&rlistt[i]);
	}
	fclose(fp1);
	fclose(fp2);
	for(i = 0; i < 10; i++)
	{
		printf("%f\n",rlistb[i]);
		printf("%f\n",rlistt[i]);
	}
	return EXIT_SUCCESS;
}
