/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 12:38:52 by khou              #+#    #+#             */
/*   Updated: 2018/10/01 12:56:34 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
  unsigned char	cmp;

  cmp = 128;// cmp = 1 << 7;
  while(cmp)
    {
      if (octet & cmp)
        write(1, "1", 1);
      else
        write(1, "0", 1);
      cmp /= 2;
      printf("cmp: %d\n", cmp);
    }
}

void    print_bits2(unsigned char octet)
{
	if (octet > 0)
		print_bits2(octet / 2);
	printf("%d", octet % 2);
}

void    print_bits3(unsigned char octet)
{
    if (octet > 1)
        print_bits3(octet >> 1);
    printf("%d", octet & 1);
}
