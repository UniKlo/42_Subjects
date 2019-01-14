/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 16:13:16 by khou              #+#    #+#             */
/*   Updated: 2019/01/12 16:18:30 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char    *ft_itoa_base(int value, int base)
{
	int		nbr;
	int		len;
	char	*new;
	char	*nbr_base = "0123456789ABCDEF";

	len = 0;
	if (value == 0)
		return ("0");
	if (value == 2147483647)
	return ("+2147483647");
	if (value == -2147483647)
    return ("-2147483647");
	nbr = value;
	while (nbr)
	{
		nbr /= base;
		len++;
	}
    nbr = value;
    if (value < 0)
    {
        if (base == 10)
            len++;
		value = -value;
    }


	if (!(new = (char *)malloc(sizeof(char) * len)))
		  return (NULL);
	while (value)
	{
		new[--len] = nbr_base[value % base];
		value /= base;
	}
	if (nbr < 0 && base == 10)
		new[0] = '-';
	
	
	return(new);
}
