#include <stdio.h>

int sml_area(int a, int b)
{
  if (a < b)
    return (a);
  return (b);
}

int    volume_histogram(int *arr, int size)
{
  int	ret = 0;
  int n = 0;
  int r_wall = 0;
  int l_wall = 0;
  while (n < size)
    {
      if (arr[n])
	{
	  l_wall = n;
	  break;
	}
      n++;
    }

  n = size - 1;
  while (n > -1)
    {
      if (arr[n])
	{
          r_wall = n;
          break;
        }
      n--;
    }
  //  printf("l_wall: %d, r_wall:%d \n",l_wall, r_wall);
  n = 0;
  while (n < size)
    {
      int l_max = 1;
      int r_max = 1;
      int i = 0;
      int j = size - 1;
      while (i <= n)
	{
	  if (arr[i] > l_max)
	    l_max = arr[i];
	  i++;
	}
      while (j >= n)
	{
          if (arr[j] > r_max)
            r_max = arr[j];
          j--;
	}
      //      printf("arr[%d]: %d, left wall is %d, right wall is %d\n", n, arr[n], l_max, r_max);
      
      if (n >= l_wall && n <= r_wall)
	{
	  ret += sml_area(l_max, r_max) - arr[n];
	  // printf("sml: %d, current is %d, total is %d\n", sml_area(l_max, r_max), arr[n] * sml_area(l_max, r_max) - arr[n], ret);
	}
      n++;
    }

  return (ret);
}

int	main()
{
  int    histogram[] = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0};
  int    size = 16;

  printf("case size: %d, area is %d\n", size, volume_histogram(histogram, size));

  int    histogram1[] = {1, 0, 2, 0, 2};
  size = 5;

  printf("case size: %d, area is %d\n", size, volume_histogram(histogram1, size));
}
