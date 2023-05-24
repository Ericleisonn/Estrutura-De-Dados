#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// int v[] = {10,9,8,7,6,5,4,3,2,1};
// int n = sizeof(v);


void swap(int *a, int *b)
{
    int m;
    m = *a;
    *a = *b;
    *b = m;
}

void insertion_sort(int *v, unsigned int n)
{
    unsigned int i,e;
    for (e=1; e<n; e++)
    {
        i= e;
        while (((i>0) &&(v[i-1])>(v[i])))
        {
            swap(&v[i-1],&v[i]);
            i=i-1;
        }
    }
}


int main(int argc, char **argv)
{
    struct timespec a, b;
    unsigned int t, n;
    int i, *v;

    n = atoi(argv[1]);
    v = (int *)malloc(n * sizeof(int));
    srand(time(NULL));

    // MELHOR CASO
    for (i = 0; i < n; i++)
       v[i] = i;

    // //CASO MÉDIO

    // for (i = 0; i < n; i++)
    //     v[i] = rand();

    // //PIOR CASO
    // for (i = 0; i < n; i++)
    //     v[i] = n-i;
        
    clock_gettime(CLOCK_MONOTONIC, &b);
    insertion_sort(v, n);
    clock_gettime(CLOCK_MONOTONIC, &a);

    t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

    printf("%u\n", t);

    free(v);

    return 0;
}
// int v[] = {10,9,8,7,6,5,4,3,2,1};
// int n = 10;
// int main()
// {
//     insertion_sort(v,n);
//     for (int i=1; i<n;i++)
//     {
//         printf("%d",i);
//     }
//     return 0;
// }