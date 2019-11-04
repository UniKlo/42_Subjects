#include <stdio.h>A
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
  int digit = 0;
  if(str[i])
    digit = (int)str[i] - 48;
  else
    digit = 0;
  return (digit);
}
int main(int argc, char **argv)
{
  argc = 0;
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
  if (sign)
    write(1, "-", 1);
  int l1 = str_len(argv[1]);
  int l2 = str_len(argv[2]);
  int l_ret = l1 + l2;
  char ret[l_ret];
  int i = l_ret -1;
  int d1, d2, tenth, product = 0;
  
  while (i)
    {
      d1 = get_digit(argv[1], l1 - 1);
      d2 = get_digit(argv[2], l2 - 1);
      product = d1 * d2;
      ret[i] = (char)(product % 10 + tenth + 48);
      if (product > 10)
	tenth = product / 10;
      else
	tenth = 0;
      printf("d1: %d, d2: %d, product: %d, char: %c\n", d1, d2, product, ret[i]);
      l1--;
      l2--;
      i--;
    }
}
