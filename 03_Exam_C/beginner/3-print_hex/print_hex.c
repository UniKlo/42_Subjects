/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 23:03:24 by khou              #+#    #+#             */
/*   Updated: 2018/11/27 23:54:44 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		atoi(char *str)
{
	int i = 0;
	
	while(*str)
	{
		i = i * 10;
		i += *str - 48;
		str++;
	}
	return (i);
}

void	p_hex(int nbr)
{
	char tab[16] = "0123456789abcdef";
	
	if (nbr / 16)
		p_hex(nbr /16);
	write(1, &tab[nbr%16], 1);
}
		
int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		int a = atoi(argv[1]);
		p_hex(a);
	}
	write(1, "\n", 1);
	return (0);
}
