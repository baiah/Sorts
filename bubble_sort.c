#include <stdio.h>
#include <stdlib.h>

void swap(int *n1, int *n2)
{
	int aux;
	aux = *n1;
	*n1 = *n2;
	*n2 = aux;
}

/*bolha com flag*/
void bolha(int *v, int n)
{
    int i=0, j, flag;
    do 
    {
        flag = 0;
        for (j = 0; j < n-1-i; j++)
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