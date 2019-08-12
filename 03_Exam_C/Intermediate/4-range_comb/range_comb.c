#include <stdlib.h>
#include <stdio.h>

void swap(int *i, int *l)
{
  int *tmp = 0;
  tmp = i;
  i = l;
  l = tmp;
}

void	permutation(int *arr, int l, int r, int n)
{
  if (l == r)
    ;
  for (int i = l; i <= r; i++)
    {
      swap(&arr[l], &arr[i]);
      int j = 0;
      while (j < n)
	printf("%d", arr[j++]);
    }
  //  permutation(arr, l, r);
  //  swap (i, l);
}

int    **range_comb(int n)
{
  int i = 0;
  int j = n;
  int **tab = NULL;
  int factorial = 1;
  
  while ( j )
    {
      factorial *= j;
      j--;
    }
  printf("factorial: %d\n", factorial);
  tab = malloc(sizeof(int *) * (factorial + 1));
  tab[factorial] = NULL;
  
  i = 0;
  while (tab[i])
    {
      tab[i] = malloc(sizeof(int) * n);
      tab[i] = NULL;
      i++;
    }
  /*
  i = 0;
  while(i < n)
    {
      printf("arr: %d\n", tab[i]);
      i++;
      }*/
  //  permutation(arr, i , j, tab);
  //  permutation(arr, i , j, n);
  return (tab);
}

int	main(int argc, char **argv)
{
  if (argc == 2)
    {
      int n = atoi(argv[1]);
      int	**arr = range_comb(n);
      int i = 0;
      while (i < 50)
	{
	  int j = 0;
	  while (j < n)
	    {
	      printf("%d ", arr[i][j]);
	      j++;
	    }
	}
      printf("\n");
      i++;
    }

}
