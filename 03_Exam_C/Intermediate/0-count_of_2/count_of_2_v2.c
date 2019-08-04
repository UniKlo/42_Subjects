
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2_v2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 00:03:51 by khou              #+#    #+#             */
/*   Updated: 2019/08/04 00:05:14 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int count_of_2(int n) {
	int count = 0;
	int i = 0;
	while (i <= n)
	{
		int tmp = i;
		while (tmp > 0)
		{
			if (tmp % 10 == 2)
				count++;
			tmp /= 10;
		}
		i++;
	}
	return (count);
}


//test 
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av){
	printf("%i\n", count_of_2(atoi(av[1])));	
}
