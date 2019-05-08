/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:55:09 by khou              #+#    #+#             */
/*   Updated: 2019/03/04 22:09:56 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		two_digit(int a, int b)
{
	return (a * 10 + b);
}

void    equation(int n)
{
	int a, b, c;
	a = 0;
	b = 0;
	c = 0;
	if (n == 0)
	{
		printf("A = %d, B = %d, C = %d\n", a, b, c);
		return ;
	}
	while (a < 10)
	{
		b = 0;
		while (b < 10)
		{
			c = 0;
			while (c < 10)
			{
				if (two_digit(a, b) + two_digit(c, a) == n)
				{
					printf("A = %d, B = %d, C = %d\n", a, b, c);
				}
				c++;
			}
			b++;
		}
	a++;
	}
}

/*
int main()
{
	int a, b;

	a = 1;
	b = 111;
	
	printf("%d:\n", a);
	equation(a);
	printf("\n%d:\n", b);
	equation(b);
}
*/
