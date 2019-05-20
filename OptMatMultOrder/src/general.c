#include "general.h"

//Eylon Mizrahi, Daniel Ivkovich

// matrixVector = {p0,..pn}
// Ai = p(i-1) x p(i)

int *p;
int main(int argc, char **argv)
{
	printf("Please enter Pi's:\n");
	MS ms = { 0, 0 };
	MATRIX_CHAIN_ORDER2(6, p, &ms);
	printMatrix(ms.m, 6);
	printMatrix(ms.s, 6);
	printf("\n");
	optimumMatMultiplication(&ms, 1, 5, 6);
	return 1;
}

void MATRIX_CHAIN_ORDER2(int n , int* p , MS* ms)
{
	int i, L, k, j, q;
	p = (int*) malloc(n  * sizeof(int));

	for (i = 0; i < n; i++)
	{
		scanf("%d",&p[i]);
	}

	ms->m = (int*) malloc(n * n * sizeof(int));
	ms->s = (int*) malloc(n * n * sizeof(int));

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			*(ms->m + i * n + j) = 0;
			*(ms->s + i * n + j) = 0;

		}
	}

	for (L = 2; L < n; L++) // index zigzug
	{

		for (i = 1; i < n - L + 1; i++) // good
		{
				j = L + i - 1;
				*(ms->m + i*n+j) = 99999;

				for (k = i; k <= j-1; k++)
				{
					q = *(ms->m + i * n + k) + *(ms->m + (k + 1) * n + j)
												+ p[i-1] * p[k] * p[j];
					if (q < *(ms->m + i * n + j))
					{
						*(ms->m + i * n + j) = q;
						*(ms->s + i * n + j) = k;
					}
				}
		}
	}
}

void optimumMatMultiplication(MS* ms, int i, int j, int n)
{
	int k = ms->s[i * n + j];

	// Left
	if(k == i)
	{
		printf("%c%d", 'M', i);
	}
	else
	{
		printf("%c", '(');
		optimumMatMultiplication(ms, i, k, n);
		printf("%c", ')');
	}

	// Right
	if(k + 1 == j)
	{
		printf("%c%d", 'M', j);
	}
	else
	{
		printf("%c", '(');
		optimumMatMultiplication(ms, k + 1, j, n);
		printf("%c", ')');
	}
}


void printMatrix(int* matrix, int n)
{
	printf("\n");
	int i, j;
	for (i = 1; i < n; i++) {
		for (j = 1; j < n; j++) {
			if(*(matrix + i * n + j) <= 99999)
			printf("%d \t\t", *(matrix + i * n + j));
			else printf("%d \t", *(matrix + i * n + j));
		}
		printf("\n");

	}
}

