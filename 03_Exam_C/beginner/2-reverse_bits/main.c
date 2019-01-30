/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:13:33 by khou              #+#    #+#             */
/*   Updated: 2018/10/01 16:53:15 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	reverse_bits1(unsigned char octet);

unsigned char   reverse_bits2(unsigned char octet);

void	print_bits(unsigned char octet)
{
	unsigned char	cmp;

	cmp = 128;
	while (cmp)
	{
		if (octet & cmp)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		cmp >>= 1;
	}
}

int		main()
{
	write(1, "Org: ", 5);
	print_bits(4);
	write(1, "\n", 1);
	write(1, "New: ", 5);
	print_bits(reverse_bits1(4));
	write(1, "\n", 1);
	write(1, "New: ", 5);
        print_bits(reverse_bits2(4));
        write(1, "\n", 1);
	return (0);
}
