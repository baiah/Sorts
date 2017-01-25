#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int *v, int n)
{
	int i, pivo, j;
	for(i = 1; i <= n-1; i++)
		{
			pivo = *(v+i);
			j = i - 1;
			while(j >= 0 && *(v+j) > pivo)
			{
				*(v+j+1) = *(v+j);
				j--;
			}
			*(v+j+1) = pivo;
		}
}