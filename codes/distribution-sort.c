#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void distribution_sort(int *v, int n)
{
  int i;
  int s = v[0];
  int e = v[0];

  for (i = 1; (i < n); i++)
  {
    if (v[i] > e)
    {
      e = v[i];
    }
    if (v[i] < s)
    {
      s = v[i];
    }
  }

  int *c = (int *)calloc((e - s + 1), sizeof(int));
  int *w = (int *)malloc(n * sizeof(int));

  for (i = 0; i < n; i++)
  {
    c[v[i] - s]++;
  }

  for (i = 1; i < (e - s + 1); i++)
  {
    c[i] += c[i - 1];
  }

  for (i = n - 1; i >= 0; i--)
  {
    int d = v[i] - s;
    w[c[d] - 1] = v[i];
    c[d] -= 1;
  }

  for (int i = 0; i < n; i++)
  {
    v[i] = w[i];
  }

  free(c);
  free(w);
}

int main(int argc, char **argv)
{
  struct timespec a, b;
  unsigned int t, n;
  int i, *vetor;

  n = atoi(argv[1]);
  vetor = (int *)malloc(n * sizeof(int));
  srand(time(NULL));
    // CASO MÉDIO
    for (i = 0; i < n; i++)
    {
        vetor[i] = rand()%1000;
    }
  clock_gettime(CLOCK_MONOTONIC, &b);
  distribution_sort(vetor, n);
  clock_gettime(CLOCK_MONOTONIC, &a);

  t = (a.tv_sec * 1e9 + a.tv_nsec) - (b.tv_sec * 1e9 + b.tv_nsec);

  printf("%u\n", t);

  free(vetor);

  return 0;
}