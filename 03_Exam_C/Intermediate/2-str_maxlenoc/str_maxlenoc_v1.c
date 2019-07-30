/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 21:14:13 by khou              #+#    #+#             */
/*   Updated: 2019/07/29 21:16:25 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
      while (tab[n][i] && count < nbr)
	  {
		  beg = tmp;
		  while (tab[n][i] && tab[n][i] == str[beg] && beg <= end)
		  {
			  i++;
			  beg++;
		  }
		  if (beg == end + 1)
		  {
			  count++;
			  break;
		  }
		  else
			  i++;
	  }
      n++;
	}
  if (count == nbr)
  {
      beg = tmp;
      while (beg <= end)
	  {
		  write(1, &str[beg], 1);
		  beg++;
	  }
      write(1, "\n", 1);
      return (1);
  }
  return (0);
}


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
			if (min_len > len)
			{
				min_len = len;
				min_str = argv[i];
			}
			i++;			
		}
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
				  int found =  str_array_cmp(beg, end, min_str, argv, argc - 1);
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
