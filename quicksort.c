#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *n1, int *n2)
{
	int aux;
	aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}

static int particao_deterministico(int *v, int inicio, int fim)
{
	int pivo = v[inicio], i = inicio+1, j = fim;

	while(i <= j)
	{
		while(i <= fim && v[i] <= pivo) { ++i; }
		while(v[j] > pivo) { --j; }

		if(i < j)
		{
			swap(v+i, v+j);
			++i;
			--j;
		}
	}

	v[inicio] = v[j];
	v[j] = pivo;
	return j;
}

static int particao_probabilistico(int *v, int inicio, int fim)
{
	int pivo, j = fim, i = inicio-1, x;
    x = inicio + rand() % (fim - inicio + 1);
    pivo = v[x];
    swap(v+x, v+fim);

    for(j = inicio; j < fim; j++)
    {
    	if(v[j] < pivo)
    	{
    		i++;
    		swap(v+i, v+j);
    	}
    }
    swap(v+i+1, v+fim);
    return i+1;
}

/*para trocar o metodo de escolha do pivo (deterministico = o primeiro do vetor; probabilistico = aleatorio) basta trocar
o metodo de particao*/

void quicksort(int *v, int inicio, int fim)
{
	if(inicio < fim)
	{
		int j = particao_probabilistico(v, inicio, fim);
		if(inicio < j-1) { quicksort(v, inicio, j-1); }
		if( j+1 < fim) { quicksort(v, j+1, fim);}
	}
}