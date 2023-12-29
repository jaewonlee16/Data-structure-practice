#ifndef FIBONNACI_H
#define FIBONNACI_H

#include <stdio.h>

typedef struct _Matrix2x2{
	unsigned long Data[2][2];
}Matrix2x2;

Matrix2x2 Matrix2x2_Multiply(Matrix2x2 A, Matrix2x2 B);

Matrix2x2 Matrix2x2_Power (Matrix2x2 A, int n);

unsigned long Fibonacci (int N);


#endif
