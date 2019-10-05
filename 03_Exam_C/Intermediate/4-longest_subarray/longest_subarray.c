#include <stdlib.h>
#include <stdio.h>

char *ft_strdup(char *str, int i, int j)
{
  int ret_len = j - i + 1;
  char *ret = malloc(sizeof(char) * ret_len);

  ret[ret_len] = '\0';
  int n = 0;
  while (i <= j)
    {
      ret[n] = str[i];
      i++;
      n++;
    }
  return (ret);
}


char    *longest_subarray(char *str)
{
  char *ret = NULL;
  int nbr_odd = 0;
  int nbr_even = 0;
  int i = 0;
  while (str[i])
    {
      if(str[i] % 2 == 0)
	nbr_even++;
      else
	nbr_odd++;
      i++;
    }
  int max_len = nbr_odd < nbr_even ? nbr_odd * 2 : nbr_even * 2;
  int	str_len = nbr_odd + nbr_even;
  i = 0;
  while (max_len >= 2)
    {
      int beg = i;
      int end = str_len - 1;
      while (end - beg + 1 >= max_len)
	{
	  int tmp_odd = nbr_odd;
	  int tmp_even = nbr_even;
	  int tmp = beg;
	  int j = 0;
	  while (j < beg)
	    {
	      if (str[j] % 2 == 0)
		tmp_even--;
	      else
		tmp_odd--;
	      j++;
	    }
	  j = end;
	  while (j >= beg + max_len)
	    {
	      if (str[j] % 2 == 0)
		tmp_even--;
	      else
		tmp_odd--;
	      j--;
	    }
	  if (tmp_even == tmp_odd)
	    return (ret = ft_strdup(str, beg, beg + max_len - 1));
	  beg++;
	}
      max_len--;
    }
  return (ret);
}

int main()
{
  char *input = "1357913579024680213579";

  printf("%s\n", longest_subarray(input));

}
