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

unsigned char	reverse_bits(unsigned char octet)
{
   unsigned char	new;
/*
   new = ((octet & 0xF) << 12) ^ 0xF000;
    new += ((octet & 0xF0) << 4) ^ 0xF00;
   new += ((octet & 0xF00) >> 4) ^ 0xF0;
   new += ((octet & 0xF000) >> 12) ^ 0xF;
*/
   new = 0;
   int	len = 7;
   while (len > -1)
   {
	   new += octet << len;
	   
	   print_bits(new);
	   write(1, "\n", 1);
	   len -= 1;
   }
   


	return (new);
}
