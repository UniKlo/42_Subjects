/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 20:38:19 by khou              #+#    #+#             */
/*   Updated: 2018/10/08 22:40:39 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int big(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
int sml(int a, int b)
{
    if (a < b)
		return (a);
    return (b);
}

int	euclid(int nbr1, int nbr2)
{
	int a = big(nbr1, nbr2);
	int b = sml(nbr1, nbr2);
	while(a > b)
		a = a - b;
	if(b % a == 0)
		return (a);
	else
		return(euclid(a, b));
}

int main(int argc, char **argv)
{
	if(argc == 3)
	{
		printf("%d", euclid(atoi(argv[1]), atoi(argv[2])));	
	}
	printf("\n");
	return (0);
}
