/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 09:02:56 by exam              #+#    #+#             */
/*   Updated: 2019/03/05 09:54:46 by exam             ###   ########.fr       */
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
}

/*
#include <stdio.h>

int		main()
{
	int	n = 22;
	printf("%d\n", count_of_2(n));


	int nbr = 42200002;
	printf("%d has %d\n", nbr, nbr_of_2(nbr));
	count = 0;
	int nbr1 = 6662202;
    printf("%d has %d\n", nbr, nbr_of_2(nbr1));

	return (0);
}
*/
