/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:27:43 by khou              #+#    #+#             */
/*   Updated: 2018/10/12 21:49:37 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int is_power_of_2(unsigned int n)
{
	int i = 0;
	unsigned int cmp = n;
	if (!n)
		return (0);

	while (n / 2 != 1)
	{
		n /= 2;
		i++;
	}
	if (n % 2 == 0)
	{
		while (i--)
			n *= 2;
		if(cmp == n)
			return (1);
		else
			return (0);
	}
	else
		return (0);
}

int is_power_of_22(unsigned n)
{
	if (n == 0)
		return (0);
	return (( n & (n-1)) == 0);//power of 2 is always one bit turns on
}

#include <stdio.h>

int main()
{
	printf("64 is_power_of_2 T/F: %d\n", is_power_of_2(64));
	printf("17 is_power_of_2 T/F: %d\n", is_power_of_2(17));
	printf("96 is_power_of_2 T/F: %d\n", is_power_of_2(96));
	printf("0  is_power_of_2 T/F: %d\n", is_power_of_2(0));

	printf("64 is_power_of_2 T/F: %d\n", is_power_of_22(64));
    printf("17 is_power_of_2 T/F: %d\n", is_power_of_22(17));
    printf("96 is_power_of_2 T/F: %d\n", is_power_of_22(96));
    printf("0  is_power_of_2 T/F: %d\n", is_power_of_22(0));

	
	return (0);
}
