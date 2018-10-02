#include <stdio.h> 
#include <stdlib.h> 
#include "complex.h" 
#define CSIZE 4 
int main(void) 
{ 
  Complex c1, c2, Carr[CSIZE]; 
  int i; 

  InitComplex(&c1); 
  DisplayComplex(&c1); 
  printf("\n"); 
  SetComplex(&c2, 1, 2); 
  DisplayComplex(&c2); 
  printf("\n"); 
  AddToComplex(&c1, &c2); 
  DisplayComplex(&c1); 
  printf("\n"); 

  for(i=0; i < CSIZE; i++) 
  { 
    SetComplex(&Carr[i], i+1, i+2); 
    AddToComplex(&Carr[i], &c1); 
  } 

  for(i=0; i < CSIZE; i++) 
  { 
    DisplayComplex(&Carr[i]); 
    printf("\n"); 
  } 

  return EXIT_SUCCESS; 
  } 
