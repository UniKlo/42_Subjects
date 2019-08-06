#include <stdio.h>

int    volume_histogram(int *arr, int size)
{
  int	ret = 0;
  int i = 0;
  int j = size - 1;
  while(i < size)
    {
      if (arr[i])
	{
	  // int dis= 0;
	  int i1 = 0;
	  int tmp = 0;
	  while (arr[i + i1] <= arr[i])
	    i1++;
	  tmp = arr[i]*(i1) ;
	  printf("current area: %d, arr[%i]: %d, arr[%d]: %d\n",
		 tmp, i, arr[i], i+i1,  arr[i+i1]);
	  i = i1;
	  ret += tmp;

	}
      i++;
    }
  while (j)
    {
      j--;
    }
  return (ret);
}

int	main()
{
  int    histogram[] = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0};
  int    size = 16;

  printf("%d\n", volume_histogram(histogram, size));
}
