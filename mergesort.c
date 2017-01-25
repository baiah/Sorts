#include <stdio.h>
#include <stdlib.h>

static void merge(int *v, int inicio, int meio, int fim)
{
	int i = inicio, j = meio, k = 0, *aux;
	aux = (int *)malloc((fim-inicio)* sizeof(int));
	if (aux == NULL) {
   		printf ("quem disse que voce tem memoria pra isso!\n");
   		exit (EXIT_FAILURE);
	}

	while( i < meio && j < fim)
	{
		if( v[i] <= v[j])
		{
			aux[k++] = v[i++];
		}
		else
		{
			aux[k++] = v[j++];
		}
	}

	while(i < meio)
	{
		aux[k++] = v[i++];
	}

	while(j < fim)
	{
		aux[k++] = v[j++];
	}

	for(i = inicio; i < fim; ++i)
	{
		v[i] = aux[i-inicio];
	}
	free(aux);
}


void mergesort(int *v, int inicio, int fim)
{
	if(inicio < fim-1)
	{
		int meio = (inicio+fim)/2;
		if(inicio < meio)
		{
			mergesort(v, inicio, meio);
		}

		if(meio+1 < fim)
		{
			mergesort(v, meio, fim);
		}
		merge(v, inicio, meio, fim);
	}
}