/* 
* complex.h 
*/ 
typedef struct complex 
{ 
	int real; 
	int img;
} Complex; 

void InitComplex(Complex *); 
void SetComplex(Complex *, int, int); 
void AddToComplex(Complex *, Complex *); 
void DisplayComplex(Complex *); 
