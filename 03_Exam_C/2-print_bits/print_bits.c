#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
  int	cmp;
  int	len;
  
  cmp = 1;
  len = 7;
  while(len > -1)
    {
      if (octet & cmp << len)
	write(1, "1", 1);
      else
	write(1, "0", 1);
      len -= 1;
      printf("len: %d\n", len);
    }
}


void    print_bits1(unsigned char octet)
{
  int   cmp;

  cmp = 128;
  while(cmp)
    {
      if (octet & cmp)
        write(1, "1", 1);
      else
        write(1, "0", 1);
      cmp /= 2;;
      printf("cmp: %d\n", cmp);
    }
}
