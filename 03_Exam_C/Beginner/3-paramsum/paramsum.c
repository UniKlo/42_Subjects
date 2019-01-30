/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:07:22 by khou              #+#    #+#             */
/*   Updated: 2019/01/09 15:20:46 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	putnbr(int nbr)
{
	char c;
	
	if (nbr/10)
		putnbr(nbr/10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

int		 main(int argc, char **argv)
{
	argv[0] = "bicha";
	putnbr(argc - 1);
	write (1, "\n", 1);
	return (0);
}
