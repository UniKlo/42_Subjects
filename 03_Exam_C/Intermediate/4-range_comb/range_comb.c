#include <stdlib.h>
#include <stdio.h>

void swap(int *i, int *l)
{
  int *tmp = 0;
  tmp = i;
  i = l;
  l = tmp;
}

void	add_to_tab(int *arr, int end, int **ret)
{
  static int i = 1;
  int j = 0;

  while (j < end)
    {
      ret[i][j] = arr[j];
      j++;
    }
  i++;
}

void	permutation(int *arr, int beg, int end, int **ret)
{
  if (beg == end)
    {
      add_to_tab(arr, end, ret);
    }
  for (int i = 0; i < end ; i++)
    {
      swap(&arr[beg], &arr[i]);
      permutation(arr, beg + 1, end, ret);
      swap(&arr[beg], &arr[i]);
    }
}

int	nbr_factorial(int n)
{
  int factorial = 1;
  while (n)
  {
    factorial *= n;
    n--;
  }
  return (factorial);
}

int    **range_comb(int n)
{
  int **tab = NULL;
  int fac = nbr_factorial(n);
  
  if (!n)
    return (NULL);

  printf("factorial: %d\n", fac);
  tab = malloc(sizeof(int *) * (fac + 1));
  tab[fac] = NULL;
  
  int i = 0;
  while (i < n)
    {
      tab[i] = malloc(sizeof(int) * n);
      i++;
    }
  printf("i m here in range_comb\n");
  printf("%p\n", tab[0]);
  i = 0;
  while (i < n)
    {
      tab[0][i] = i;
      printf("%d ", tab[0][i]);
      i++;
    }
  //  permutation(tab[0], 0, n, tab);
  return (tab);
}

int	main(int argc, char **argv)
{
  if (argc == 2)
    {
      int n = atoi(argv[1]);
      int **arr = range_comb(n);
      int i = 0;
      arr = NULL;
      while (i < 50)
	{
	  int j = 0;
	  while (j < n)
	    {
	      //	      printf("%d ", arr[i][j]);
	      j++;
	    }
	  i++;
	}
      printf("\n");
    }

}
