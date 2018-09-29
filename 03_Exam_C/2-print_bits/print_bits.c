#include <unistd.h>

void	print_bits(unsigned char octet)
{
  int	cmp;
  
  cmp = 128;
  while(cmp > 0)
    {
      if (octet & cmp)
	write(1, "1", 1);
      else
	write(1, "0", 1);
      cmp /= 2;
    }
}
