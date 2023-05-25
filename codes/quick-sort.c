#include <time.h>
#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b)
{
    int m;
    m = *a;
    *a = *b;
    *b = m;
}

int partition(int *v,int s,int e)
{ 
    unsigned int i;
    unsigned int d = (s-1);
    for( i=s ; i < ( e - 1 ) ; i++ )
    {
        if (v[i] <= v[e])
        {
            d=d+1;
            swap(&v[d] , &v[i]);
        }
    }
    swap(&v[d+1],&v[e]);
    return (d+1);
}

void quick_sort(int *v,int s, int e)
{
    if (s < e)
    {
        int p = partition(v,s,e);
        quick_sort(v,s,p-1);
        quick_sort(v,p+1,e);
    }
}

int main(int argc, char **argv)
{
	struct timespec a, b;
	unsigned int t, n;
	int i, *vetor;

	n = atoi(argv[1]);
	vetor = (int *)malloc(n * sizeof(int));
	srand(time(NULL));

    // //CASO MÉDIO 
	// for (i = 0; i < n; i++)
    //{
	// 	vetor[i] = rand();
    //}
    
    // PIOR CASO
    for (i = 0; i < n; i++)
    {
        vetor[i] = n-i; 
    }
	clock_gettime(CLOCK_MONOTONIC, &b);
	quick_sort(vetor, 0, n - 1);
	clock_gettime(CLOCK_MONOTONIC, &a);
	t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);
	printf("%u\n", t);
	free(vetor);
	return 0;
}
