/* 
* complex.c 
*/ 
#include <stdio.h> 
#include "complex.h" 
void InitComplex(Complex * cp) 
{ 
  cp->real = 0; 
  cp->img = 0; 
} 

void SetComplex(Complex * cp, int real, int img) 
{ 
  cp->real = real; 
  cp->img = img; 
} 

void AddToComplex(Complex * dst, Complex * src) 
{ 
  dst->real += src->real; 
  dst->img += dst->real; 
} 

void DisplayComplex(Complex * cp) 
{ 
  printf("%d+%d%c", cp->real, cp->img, 'i'); 
} 
