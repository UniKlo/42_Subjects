/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 15:17:18 by khou              #+#    #+#             */
/*   Updated: 2019/05/02 16:00:33 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*object:
1. test main
2. pass nbr form command
3. 10 * A + B + 10 * C + A = n, 11 * A + 10 * C + B = n
4. 3 layer while loop
*/
#include <stdio.h>

void    equation(int n)
{
	int a;
	int b;
	int c;
	a = 0;
	while (a < 10)
	{
		b = 0;
		while (b < 10)
		{
			c = 0;
			while (c < 10)
			{
				if (11 * a + 10 * c + b == n)
					printf("A = %d, B = %d, C = %d\n", a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
	
}



/*
#include <stdlib.h>

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		equation(atoi(argv[1]));
	}
	
}
*/
