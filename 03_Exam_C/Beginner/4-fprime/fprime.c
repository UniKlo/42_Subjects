/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 22:10:54 by khou              #+#    #+#             */
/*   Updated: 2018/11/19 22:54:37 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		int nbr = atoi(argv[1]);
		if (nbr == 1)
			printf("1");
		else
		{
			int sign = 0;
			while (nbr > 1)
			{
				int fac = 2;
				if (sign == 1)
				{
					printf("*");
					sign = 0;
				}
				while (nbr > 1 && fac <= nbr && sign == 0)
				{
					if (nbr % fac == 0)
					{
						printf("%d", fac);
						nbr = nbr / fac;
						sign = 1;
					}
					fac++;
				}
			}
		}
	}
	printf("\n");
	return (0);
}
