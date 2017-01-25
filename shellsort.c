#include <stdio.h>
#include <stdlib.h>

void swap(int *n1, int *n2)
{
	int aux;
	aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}

/*linha shell adaptive: para usar o modo normal use 1 no valor de h*/
void selection_shelladaptive(int *v, int n, int h)
{
	int i, min, j;
	for(i = 0; i < n-1; i++)
	{
		min = i;
		for(j = i+h; j <n; j++)
		{
			if(*(v+j) < *(v+min))
			{
				min = j;
			}
		}
		swap(v+min, v+i);
	}
}

void insertion_shelladaptive(int *v, int n, int h)
{
	int i, j, gatilho;
	for(i = h; i < n; i++)
	{
		gatilho = *(v+i);
		j = i-h;
		while(j>= 0 && *(v+j) > gatilho)
		{
			*(v+j+h) = *(v+j);
			j = j-h;
		}
		*(v+j+h) = gatilho;
	}

}

void bubble_shelladaptive(int *v, int n, int h)
{
	int i=0, j, flag;
    do 
    {
        flag = 0;
        for (j = h; j < n-1-i; j++)
        {
            if(*(v+j) > *(v+j+1))
            {
                swap((v+j), (v+j+1));
                flag = 1;
            }
        }
        i++;
    }while(flag == 1);
}

void shellsort(int *v, int n)
{
	int h = 1;

	while(h < n)
	{
		h = 3*h+1;
	}
		do{
			int i;
			h = (h/3);
			for(i = h; i <n; i++)
			{
				insertion_shelladaptive(v, n, h);
			}
		}while(h > 1);
}