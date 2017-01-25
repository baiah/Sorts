#include <stdio.h>
#include <stdlib.h>

void swap(int *n1, int *n2)
{
	int aux;
	aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}

void selection_sort(int *v, int n)
{
	int i, min, j;
	for(i = 0; i <= n-2; i++)
	{
		min = i;
		for(j = i + 1; j <= n - 1; j++)
		{
			if(*(v+j) < *(v+min)) {
				min = j;
			}
		}
		swap(v+min, v+i);
	}
}