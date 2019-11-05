#include <stdio.h>
#include <unistd.h>
int str_len(char *str)
{
  int i = 0;
  while (str[i])
    i++;
  return (i);
}
int get_digit(char *str, int i)
{
  int digit = 1;
  if(str[i])
    digit = (int)str[i] - 48;
  else
    digit = 1;
  return (digit);
}

int main(int argc, char **argv)
{
  argc = 0;
  if (argv[1][0] == '0' || argv[2][0] == '0')
    {
      write(1, "0\n", 2);
      return (0);
    }
  int sign = 0; //whether have -
  if (argv[1][0] == '-' && argv[2][0] != '-')
    {
      sign = 1;
      argv[1]++;
    }
  else if (argv[1][0] != '-' && argv[2][0] == '-')
    {
      sign = 1;
      argv[2]++;
    }
  else if (argv[1][0] == '-' && argv[2][0] == '-')
    {
      argv[1]++;
      argv[2]++;
    }
  if (sign)
    write(1, "-", 1);
  int l1 = str_len(argv[1]);
  int l2 = str_len(argv[2]);
  int l_ret = l1 + l2 -1;
  char ret[l_ret];
  int i = l_ret -1;
  int d1 = 0, d2 = 0, nbr_pw = 1, product = 0;
  int tmp1 = l1, tmp2 = l2, power = 0, tenth = 0;
  int pre_nbr_pw = 0;
  while (tmp1 > 0)
    {
      tmp2 = l2;
      while (tmp2 > 0)
	{
	  nbr_pw = 1;
	  d1 = get_digit(argv[1], tmp1 - 1);
	  d2 = get_digit(argv[2], tmp2 - 1);
	  power = (l1 - tmp1) + (l2 - tmp2);
	  printf("10th: %d\n", power);
	  i = l_ret - power -1;
	  while (power > 0)
	    {
	      nbr_pw *= 10;
	      power--;
	    }
	  if (pre_nbr_pw == nbr_pw)
	    product += d1 * d2;
	  else
	    product = d1 * d2;
	  pre_nbr_pw = nbr_pw;
	  printf("d1: %d, d2: %d, product: %d\n", d1, d2, product);
	  ret[i] = (char)(product% 10 + tenth + 48);

	  tenth = product /10;

	  //printf("ret[%d] %c\n", i, ret[i]);
	  tmp2--;
	}
      tmp1--;
    }
  if(sign)
    write(1, "-", 1);
  i = 0;
  while (i < l_ret)
    {
      write(1, &ret[i], 1);
      i++;
    }
  write(1, "\n", 1);
}
