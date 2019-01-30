/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:27:59 by khou              #+#    #+#             */
/*   Updated: 2019/01/07 20:49:12 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	valid_char(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{

	int time_base = 0;
	int nbr = 0;
	int sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		++str;
	}

	while (*str && valid_char(*str))
	{
		if (time_base == 1)
		{
			nbr *= str_base;
			time_base = 0;
		}
		if (*str >= '0' && *str <= '9')
            nbr += *str - '0';
		if (*str >= 'a' && *str <= 'f')
            nbr += *str - 'a' + 10;
		if (*str >= 'A' && *str <= 'F')
            nbr += *str - 'A' + 10;
		str++;
		time_base = 1;
	}
	if (sign)
		nbr = sign * nbr;
	return (nbr);	
}


#include <stdio.h>

int		main()
{
	char str[] = "0";
	int str_base = 2;
	int ret = ft_atoi_base(str, str_base);
	printf("%d\n", ret);

	char str1[] = "-314-Ab";
    int str_base1 = 8;
    ret = ft_atoi_base(str1, str_base1);
	printf("%d\n", ret);

	char str2[] = "aB";
    int str_base2 = 16;
    ret = ft_atoi_base(str2, str_base2);
	printf("%d\n", ret);
	return (0);
}
