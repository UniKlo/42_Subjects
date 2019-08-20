/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volume_histogram.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 22:48:35 by khou              #+#    #+#             */
/*   Updated: 2019/08/19 23:04:32 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
  if (!arr)
	  return (0);
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

  if (r_wall == l_wall)
	  return (0);
  
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
      
      if (n >= l_wall && n <= r_wall)
	  {
		  ret += sml_area(l_max, r_max) - arr[n];
	  }
      n++;
  }
  
  return (ret);
}

#include <stdio.h>

int	main()
{
  int    histogram[] = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0};
  int    size = 16;

  printf("case size: %d, area is %d\n", size, volume_histogram(histogram, size));

  int    histogram1[] = {1, 0, 2, 0, 2};
  size = 5;

  printf("case size: %d, area is %d\n", size, volume_histogram(histogram1, size));

  int    histogram2[] = {0, 1, 0};
  size = 3;

  printf("case size: %d, area is %d\n", size, volume_histogram(histogram2, size));

  int    histogram3[] = {0};
  size = 1;

  printf("case size: %d, area is %d\n", size, volume_histogram(histogram3, size));
  
}

