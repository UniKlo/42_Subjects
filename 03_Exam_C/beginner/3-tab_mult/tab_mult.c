/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 09:59:25 by khou              #+#    #+#             */
/*   Updated: 2018/11/28 10:29:54 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		atoi(char *nbr)
{
	int i = 0;
	while (*nbr)
	{
		i *= 10;
		i += *nbr - 48;
		nbr++;
	}
	return (i);
}

void	putnbr(int nbr)
{
	if (nbr / 10)
		putnbr(nbr / 10);
	char c;
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		int a = atoi(argv[1]);
		char c = '1';
		int i = 1;
		while (c <= '9')
		{
			int ret = 0;
			int j = 0;
			write(1, &c, 1);
			write(1, " x ", 3);
			while (argv[1][j])
				write(1, &argv[1][j++], 1);
			write(1, " = ", 3);
			ret = i * a;
			putnbr(ret);
			c++;
			i++;
			write(1, "\n", 1);
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}
