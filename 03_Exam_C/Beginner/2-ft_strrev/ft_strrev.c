/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:17:28 by khou              #+#    #+#             */
/*   Updated: 2018/11/19 21:40:47 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


int		len(char *str)
{
	int l = 0;
	while (*str++)
		l++;
	return (l);
}

char	*ft_strrev(char *str)
{
	if (!*str)
		return (str);
	int i = len(str);
	char tmp;
	int beg = -1;	
	while (--i > ++beg)
	{
		tmp = str[i];
		str[i] = str[beg];
		str[beg] = tmp;
		printf("index i: %d, beg: %d\n", i, beg);
	}
	
	return (str);
}

#include <stdio.h>

int		main()
{
	char *str;

	str = "abc";

	printf("org: %s\n", str);
	ft_strrev(str);
	printf("rev: %s\n", str);	
}
