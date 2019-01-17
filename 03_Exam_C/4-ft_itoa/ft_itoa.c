/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:55:34 by khou              #+#    #+#             */
/*   Updated: 2019/01/16 18:48:24 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int nbrlen(int nbr)
{
	int l = 0;
	while (nbr)
	{
		l++;
		nbr /= 10;
	}
	return (l);
}

char	*ft_itoa(int nbr)
{
	char *str = malloc(sizeof(char) * 12);
	int i = 0;

	if (nbr == 0)
		return("0");
	if (nbr == -2147483648)
		return("-2147483648");
	if (nbr < 0)
	{
		str[i++] = '-';
		nbr = -nbr;
	}
	int end = i + nbrlen(nbr);//no matter + -

	str[end--] = '\0';
	while ((end > -1) && nbr != 0)
	{
		str[end--] = (nbr % 10) + '0';
		nbr /= 10;
	}

	return (str);
}

/*
#include <stdio.h>
int	main()
{
	int nbr = 2147483647;

	printf("nbr: %s", ft_itoa(nbr));
	return(0);
}
*/	
	
