#include <stdio.h>
#include <stdlib.h>

typedef s_node {

  int value;
  int *edge;
  int weight;
  int bool;
} t_node;

int is_stop(char c)
{
  if (c == '-' || c == '\0' || c == '\n' || c == '\t')
    return (1);
  else
    return (0);
}

int nbr_len(int nbr)
{
  int l = 0;
  while (nbr)
    {
      nbr = nbr/10;
      l++;
    }
  return (l);
}

int get_nbr(char *str)
{
  int nbr = 0;
  int tenth = 0;
  while(*str)
    {
      if (is_stop(*str))
	break;
      nbr += *str - 30 + tenth * 10;
      str++;
    }
  return (nbr);
}

int main(int argc, char **argv)
{
  if (argc != 2)
    {
      write(1, "ending\n", 7);
      return (0);
    }
  while (*argv[1])
    {
      int nbrA = 0;
      int nbrB = 0;
      new_node(nbrA);
      new_node(nbrB);
    }
}
