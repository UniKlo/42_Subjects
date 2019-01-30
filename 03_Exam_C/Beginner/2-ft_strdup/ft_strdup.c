/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 18:10:10 by khou              #+#    #+#             */
/*   Updated: 2019/01/18 18:15:11 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int ft_strlen(char *str) {int len = 0; while (*str++) ++len; return (len); }

char    *ft_strdup(char *src)
{	
	char *beg;

    if (!src)
        return (NULL);
	int l = ft_strlen(src);
	char *cpy;
	if (!(cpy = malloc(sizeof(char) * l)))
		return (NULL);
	beg = cpy;
	while (l-- > -1)
		*cpy++ = *src++; //can derefernce an empty str
	*cpy = '\0';
	return (beg);
}
