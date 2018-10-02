#include <stdio.h>
#include <string.h>

int main(void){
	char line[23] = "03/04/2000,Suzan Smith";
	char *token;

	token = strtok(line,"/, ");
	while (token != NULL){
		printf(":%s:\n",token);
		token = strtok(NULL,"/, ");
	}

	return 0;
}
