/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 12:18:39 by khou              #+#    #+#             */
/*   Updated: 2018/10/01 20:39:39 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void    print_bits(unsigned char octet);

unsigned char	reverse_bits1(unsigned char octet)
{
  octet = (octet & 0xF0) >> 4 | (octet & 0x0F) << 4;
  octet = (octet & 0xCC) >> 2 | (octet & 0x33) << 2;
  octet = (octet & 0xAA) >> 1 | (octet & 0x55) << 1;
   
   return (octet);
}

unsigned char   reverse_bits2(unsigned char octet)
{
  unsigned char    new;
  unsigned char    cmp;
  int		i;
  i = 0;
  
  new = 0;
  cmp = 1;
  //   int  len = 7;
  while (cmp <= 128)//have to mask it somewhere in order to get the value
    {
      new = (new << (7 - i++)) | (octet & (cmp << 1);
      //      print_bits(octet & cmp);
      // write(1, "\n", 1);
      cmp = cmp * 2;
    }
  return (new);
}
