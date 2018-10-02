/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 12:38:52 by khou              #+#    #+#             */
/*   Updated: 2018/10/01 15:13:30 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits1(unsigned char octet)
{
	int		cmp;
	int		len;
  
	cmp = 1;
	len = 7;
	while(len > -1)
    {
		if (octet & cmp << len)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		len -= 1;
    }
}


void    print_bits2(unsigned char octet)
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
    }
}
