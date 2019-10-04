#include <stdlib.h>
#include <stdio.h>

void swap(int *i, int *j)
{
  printf("i: %d, j: %d\n", *i, *j);
  int tmp = *i;
  *i = *j;
  *j = tmp;
}

void    add_to_tab(int *arr, int end, int **ret)
{
  static int i = 0;
  int j = 0;

  while (j < end)
    {
      ret[i][j] = arr[j];
      j++;
    }
  i++;
}

void    permutation(int *arr, int beg, int end, int **ret)
{
  if (beg == end)
    {
      add_to_tab(arr, end, ret);
    }
  else
    {
      for (int i = beg; i < end ; i++)
	{
	  swap(&arr[beg], &arr[i]);
	  permutation(arr, beg + 1, end, ret);
	  swap(&arr[beg], &arr[i]);
	}
    }
}

int main()
{
  int arr[3] = {0, 1, 2};
  int **ret = malloc(sizeof(int *) * 6);
  for (int i = 0; i < 6; i++)
    {
      ret[i]= malloc(sizeof(int) * 3);
    }

  permutation(arr, 0, 3, ret);

  int i = 0;
  while (i < 6)
    {
      int j = 0;
      while (j < 3)
	{
	  printf("%d ", ret[i][j]);
	  j++;
	}
      printf("\n");
      i++;
    }
  printf("\n");
}
