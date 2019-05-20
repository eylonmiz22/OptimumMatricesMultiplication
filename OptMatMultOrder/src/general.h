#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

#ifndef GENERAL_H_
#define GENERAL_H_

typedef struct {
	int* m;
	int* s;
} MS;

void MATRIX_CHAIN_ORDER(int n , int* p , MS* ms);
void MATRIX_CHAIN_ORDER2(int n , int* p , MS* ms);
void optimumMatMultiplication(MS* ms, int i, int j, int n);
void printMatrix(int* matrix,int n);

#endif /* GENERAL_H_ */
