/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:54:16 by khou              #+#    #+#             */
/*   Updated: 2019/01/14 17:56:31 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

int		atoi(char *str)
{
	int nbr;

	nbr = 0;
	while (*str)
	{
		nbr = nbr * 10 + *str++ - '0';
	}
	return (nbr);
}

void	putnbr(int nbr)
{
	char c;

	c = '\0';
	if (nbr / 10 > 0)
		putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write (1, &c, 1);
}


int		main(int argc, char **argv)
{
	int i;
	int sum;
	int nbr;
	int	d;
	int mark;

	sum = 0;
	i = 2;

	if (argc == 2)
	{
		nbr = atoi(argv[1]);
		while (i <= nbr)
		{
			d = 2;
			mark = 0;
			while (d < i)
			{
				if (i % d++ == 0)
					mark = 1;
			}
			if (mark == 0)
				sum = sum + i;
			i++;
		}
		putnbr(sum);
		write(1, "\n", 1);
	}
	else
		write(1, "0\n", 2);

}
