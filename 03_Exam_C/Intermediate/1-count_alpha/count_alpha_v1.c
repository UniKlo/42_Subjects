/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 22:11:43 by khou              #+#    #+#             */
/*   Updated: 2019/03/04 23:23:23 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}


char	pos_alpha(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}


int		main(int argc, char **argv)
{
	char str[126];
	char alpha[26];
	int i = 0;
	int mark = 0 ;
	char c;

	if (argc == 2)
	{
		while (i < 126)
			str[i++] = 0;
		i = 0;
		while (i < 36)
            alpha[i++] = 0;
		i = 0;
		while (*argv[1])
		{
			if (is_alpha(*argv[1]))
			{
				c = pos_alpha(*argv[1]);
				if (str[(int)c] == 0)
					alpha[i++] = c;
				str[(int)c] += 1;
			}
			argv[1]++;
		}
		i = 0;
		while (i < 26)
		{
			while (!alpha[i] && i < 26)
                i++;
            if (i < 26 && mark)
                printf(", ");
			if (alpha[i])
			{
				printf("%d%c",  str[(int)alpha[i]], alpha[i]);
				mark = 1;
			}
			i++;
		}
	}
	printf("\n");
}
