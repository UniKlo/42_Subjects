#include <unistd.h>

unsigned char	swap_bits(unsigned char octet)
{
  octet = (octet & 0xF0) >> 4 | (octet & 0x0F) << 4;   
  return (octet);
}
