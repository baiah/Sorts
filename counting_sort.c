#include <stdio.h>
#include <stdlib.h>

static int encontra_maior(int *v, int n)
{
	int i, maior = v[0];
	for(i = 0; i < n; i++)
	{
		if(v[i] > maior)
		{
			maior = v[i];
		}
	}
	return maior;
}

void counting_sort(int *v, int n) 
{
	int k, *c, i, *aux;
	k = encontra_maior(v, n);

	c = (int *)malloc((k+1)* sizeof(int));
	aux = (int *)malloc((k+1)* sizeof(int));

	if (c == NULL || aux == NULL) {
   		printf ("quem disse que voce tem memoria pra isso!\n");
   		exit (EXIT_FAILURE);
	}

	for(i = 0; i <= k; i++)	c[i] = 0;

	for(i = 0; i <=n; i++) c[v[i]] = c[v[i]]+1;
	
	for(i = 1; i <=k; i++) c[i] = c[i]+ c[i-1];

	for(i = n; i>= 0; i--)
	{
		aux[c[v[i]]] = v[i];
		c[v[i]] = c[v[i]]-1;
	}

	for(i = 0; i <= n; i++)	v[i] = aux[i+1];
	
	free(c);
	free(aux);
}