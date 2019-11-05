#include <stdlib.h>
#include <stdio.h>

void    add_to_tab(int *arr, int end, int **ret)
{
  printf("I m in adding\n");
  static int i = 0;
  int j = 0;
  while (j < end)
    {
      ret[i][j] = arr[j];
      j++;
    }
  i++;
}

void    permutation(int *org, int beg, int end, int **ret)
{
  int i = 0;
  while (i < end)
    {
      int j = 0;
      while (org[j] != i)
	j++;
      printf("%d\n", j);
      if (j != end)
	org[beg] = i;
      else
	return ;
      if (beg != end - 1)
	permutation(org, beg + 1, end, ret);
      else
	add_to_tab(org, end, ret);
      org[beg] = -1;
      i++;
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
  int fac = nbr_factorial(n);
  int **tab = malloc(sizeof(int *) * (fac + 1));
  int *org = malloc(sizeof(int) * n);  
  if (!n)
    return (NULL);

  printf("factorial: %d\n", fac);
  tab[fac] = NULL;
  
  int i = 0;
  while (i < n)
    {
      org[i] = -1;
      i++;
    }
  printf("i m here in range_comb\n");

  i = 0;
  while (i < fac)
    {
      tab[i] = malloc(sizeof(int) * n);
      i++;
    }
  permutation(org, 0, n, tab);
  return (tab);
}


int	main(int argc, char **argv)
{
  if (argc == 2)
    {
      int n = atoi(argv[1]);
      int **arr = range_comb(n);
      int nbr_combination = nbr_factorial(n);
      int i = 0;
      printf("I m in the main to show off!\n");
      while (i < nbr_combination)
	{
	  int j = 0;
	  while (j < n)
	    {
	      printf("%d ", arr[i][j]);
	      j++;
	    }
	  printf("\n");
	  i++;
	}
      printf("\n");
    }
}
