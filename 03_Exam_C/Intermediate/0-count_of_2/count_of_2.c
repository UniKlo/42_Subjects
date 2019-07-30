/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 19:33:26 by khou              #+#    #+#             */
/*   Updated: 2019/07/29 20:04:31 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int count = 0;

int		nbr_of_2(int n)
{
	if (n % 10 == 2)
		count++;
	if (n / 10)
		nbr_of_2(n/10);

	return (count);
}

int    count_of_2(int n)
{
	int i = 2;
	int total_count = 0;

	if (n <= 1)
		return (0);

	while (i <= n)
	{
		count = 0;
		total_count += nbr_of_2(i);
		count = 0;
		i++;
	}
	return (total_count);
};

/*
#include <stdio.h>
#include <stdlib.h>

int		main(int argc, char **argv)
{
	if (argc > 1)
	{
		printf("nbr of 2: %d", count_of_2(atoi(argv[1])));
	}
	printf("\n");
}
*/
