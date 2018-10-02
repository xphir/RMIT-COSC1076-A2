#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 30
#define NAME "Kelvin Ngyuen"

typedef struct person
{
	char *name;
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
   if ((n = malloc(strlen(NAME) + 1)) == NULL)
   {
      printf("Unable to allocate memory for name of Person.\n");
      /* Danger! Why SHOULDN'T we return NULL just yet?
       * We have forgotten to do something... do you see what?
       */
      return NULL;
   }
   p->name = n;
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
   free(tp->name);
   free(tp);

   return EXIT_SUCCESS;
}

