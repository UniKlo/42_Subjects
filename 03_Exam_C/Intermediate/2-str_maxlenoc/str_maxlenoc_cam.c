/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 21:04:15 by khou              #+#    #+#             */
/*   Updated: 2019/07/22 00:13:46 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//get the shortest string
//get the pattern of the string

#include <unistd.h>

int str_len(char *str)
{
	int l = 0;
	while (*str)
	{
		l++;
		str++;
	}
	return (l);
}

int	str_array_cmp(int beg, int end, char *str, char **tab, int nbr)
{
  int n = 1;
  int tmp = beg;
  int count = 0;
  
  while (tab[n] && count < nbr)
    {
      int i = 0;
      beg = tmp;
      //      printf(" cmp to: %s\n",tab[n]);
      
      while (tab[n][i] && count < nbr)
	{
	  beg = tmp;
	  while (tab[n][i] && tab[n][i] == str[beg] && beg <= end)
	    {
	      //	      printf("comparing tab[%d][%d]: %c, str[%d]: %c\n",n, i,tab[n][i], beg, str[beg]);
	      i++;
	      beg++;
	    }
	  //	  printf("tab[%d][%d]: %c, beg: %d, tmp: %d\n",n, i, tab[n][i], beg, tmp);
	  if (beg == end + 1)
	    {
	      //	      printf("match!!!\n");
	      count++;
	      break;
	    }
	  else
	    i++;
	  }
      n++;
      }
  //  printf("count: %d, nbr: %d\n", count, nbr);
  if (count == nbr)
    {
      beg = tmp;
      //      printf("print out the word:");
      while (beg <= end)
	{
	  write(1, &str[beg], 1);
	  //	  printf("%c", str[beg]);
	  beg++;
	}
      write(1, "\n", 1);
      return (1);
    }
  return (0);
}

#include <stdio.h>

int		main(int argc, char **argv)
{
	
	if (argc > 1)
	{
		int i = 1;
		int	len = 0;
		int min_len = str_len(argv[i]);
		char *min_str = argv[1];
		while (i < argc)
		{
			len = str_len(argv[i]);
//			printf("len of str: %d %s\n", len, argv[i]);
			if (min_len > len)
			{
				min_len = len;
				min_str = argv[i];
			}
//			printf("min_len: %d, %s\n", min_len, min_ID);
			i++;			
		}
		//		printf("min_len: %d, %s\n", min_len, min_str);
		int count = min_len;
		while (count)
		{
			int beg = 0;
			int end = min_len - 1;
			while (beg < min_len)
			{
				end = beg + count - 1;
				if (end < min_len)
				{
				  //				  printf("main: beg: %d, end: %d\n", beg, end);
				  int found =  str_array_cmp(beg, end, min_str, argv, argc - 1);
				  //printf("found: %d\n", found);
				  if (found == 1)
				    return (0);
				}
				beg++;
			}
			count--;
		}
		write(1, "\n", 1);

	}
	else
	  write(1, "\n", 1);
}
