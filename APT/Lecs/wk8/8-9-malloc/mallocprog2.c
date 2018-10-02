#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 30
#define NAME "Kelvin Ngyuen"

typedef struct person
{
	char name[MAX_LEN];
	char address[MAX_LEN];
	int age;
} Person;


Person * makePerson()
{
   Person *p;
   char *n;

   if ((p = malloc(sizeof(Person))) == NULL)
   {
      printf("Unable to allocate memory for Person.\n");
      return NULL;
   }
   strcpy(p->name,NAME);
   strcpy(p->address,"24 Frost St Mitcham 3132");
   p->age = 20;

   return p;
}

int main(void)
{
   Person *tp;

   tp = makePerson();
   if (tp == NULL)
	  return EXIT_FAILURE;
  
   printf("%s\n%s\nage: %d\n",
	  tp->name,tp->address,tp->age);
   free(tp);

   return EXIT_SUCCESS;
}

