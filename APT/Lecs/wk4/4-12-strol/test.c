#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

	char line[12];
	char *token, *endPtr, *result;
	long num;

	printf("Enter birthdate in format dd/mm/yyyy\n");
	result = fgets(line,sizeof(line),stdin);
	if (result == NULL)
		printf("Failed to read a line\n");
	else {
		if (line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';
		token = strtok(line,"/");
		while (token != NULL){
			num = strtol(token,&endPtr,10);
			if (token == endPtr || *endPtr != '\0')
				printf(":%s: invalid number\n",token);
			else
				printf("Number is %ld\n",num);
			token = strtok(NULL,"/");
		}
	}
	
	return 0;
}
