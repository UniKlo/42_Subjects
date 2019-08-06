#include <stdlib.h>
#include <stdio.h>

char *ft_strdup(char *str, int i, int j)
{
  char *ret = malloc(sizeof(char) * (j - i + 1));

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
  printf("odd: %d, even: %d\n", nbr_odd, nbr_even);
  int max_len = nbr_odd < nbr_even ? nbr_odd * 2 : nbr_even * 2;
  int	str_len = nbr_odd + nbr_even;
  printf("max: %d\n", max_len);
  i = 0;
  while (str[i])
    {
      int j = str_len;
      int tmp = i;

      while (j)
	{
	  while (tmp <= j)
	    {
	      printf("%c", str[tmp]);
	      tmp++;
	    }
	  printf("\n");
	  //	  printf("j: %d\n", j);
	    j--;
	}
      i++;
    }
  return (ret);
}

int main()
{
  char *input = "134";

  printf("%s\n", longest_subarray(input));

}
