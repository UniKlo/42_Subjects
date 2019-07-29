/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 19:01:18 by khou              #+#    #+#             */
/*   Updated: 2019/07/28 19:04:41 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		nbr_of_2(int n)
{
	static int count = 0;
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
		total_count += nbr_of_2(i);
		i++;
	}
	return (total_count);
}
