/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 23:12:43 by khou              #+#    #+#             */
/*   Updated: 2019/08/07 23:14:14 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ord.h"

int is_space(char c)
{
    if (c == ' ' || c == '\t')
        return (1);
    return (0);
}

char **str_split(char *str)
{
    char **tab = NULL;
    int i = 0;
    int word_count = 0;
    while (str[i])
    {
        while (is_space(str[i]) && str[i])
            i++;
        int found = 0;
        while (!is_space(str[i]) && str[i])
        {
            found = 1;
            i++;
        }
        word_count += found;
    }
	
	tab = malloc(sizeof(char **) * word_count + 1);
	tab[word_count] = NULL;
    i =	0;
    int	j = 0;
    while (str[i])
    {
        while (is_space(str[i]) && str[i])
            i++;
        int beg = i;
        int l = 0;
        while (!is_space(str[i]) && str[i])
        {
            l++;
            i++;
        }
        if (l)
        {
            tab[j] = malloc(sizeof(char*) * l);
            int k = 0;
            tab[j][l-1] = '\0';
            while (k < l)
            {
                tab[j][k] = str[beg];
                beg++;
                k++;
            }
            j++;
        }
    }
    return (tab);
}
