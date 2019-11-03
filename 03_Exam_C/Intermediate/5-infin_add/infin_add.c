#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int str_len(char *str)
{
  int l = 0;
  while (*str)
    {
      str++;
      l++;
    }
  return (l);

}

int	main(int argc, char **argv)
{
  //whether it is positive or negtive
  int tenth = 0; //adding on counter

  int l1 = str_len(argv[1]);
  int l2 = str_len(argv[2]);
  argc = 0;
  int l_ret = l1 > l2 ? l1 + 1 : l2 + 1;
  char *ret = malloc(sizeof(char) * l_ret);
  printf("l1: %d, l2: %d, l_ret: %d\n", l1, l2, l_ret);
  int add = 1; //whether it is adding
  if (argv[1][0] == '-' && argv[2][0] == '-')
    {
      add = -1;
      argv[1][0] = '0';
      argv[2][0] = '0';
    }
  else if (argv[1][0] == '-')
    {
      add = 0;
      argv[1][0] = '0';
    }
  else if (argv[2][0] == '-')
    {
      add = 0;
      argv[2][0] = '0';
    }
  int j = l_ret -1;
  if (!ret)
    return (0);
  int d1, d2 = 0;
  int sum = 0;

  while (l1 > 0 || l2 > 0)
    {
      if (l1 > 0)
	d1 = (int)argv[1][l1 - 1] - 48;
      else
	d1 = 0;
      if (l2 > 0)
	d2 = (int)argv[2][l2 - 1] - 48;
      else
	d2 = 0;

      if (add == 1 || add == -1) //this is adding
	{
	  sum = d1 + d2;
	  if (sum > 10)
	    {
	      ret[j] = (char)(sum % 10 + 48 + tenth);
	      tenth =1;
	    }
	  else
	    {
	      ret[j] = (char)(sum + 48 + tenth);
	      tenth =0;
	    }
	}
      else if (add == 0) //this is subtracting
	{
	  sum = d1 - d2;
	  //sprintf("sum: %d\n", sum);
	  if (sum < 0)
	    {
	      sum = 10 + d1 -d2;
              ret[j] = (char)(sum + 48 + tenth);
              tenth = -1;
            }
          else
            {
              ret[j] = (char)(sum + 48 + tenth);
              tenth = 0;
            }
	}
      printf("d1: %d, d2: %d, sum: %c, tenth: %d\n", d1, d2, ret[j], tenth);
      l1--;
      l2--;
      j--;
    }
  printf("ret fill up to j: %d\n", j);
  while (j > -1)
    {
      ret[j] = 0;
      j--;
    }
  j++;
  if (add == -1)
    write (1, "-", 1);
  printf("%c\n", ret[j]);
  while (ret[j] == 0)
    j++;
  while (j < l_ret)
    {
      write(1, &ret[j], 1);
      j++;
    }
  write(1, "\n", 1);

}
