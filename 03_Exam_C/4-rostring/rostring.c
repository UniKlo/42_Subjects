/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 10:29:39 by exam              #+#    #+#             */
/*   Updated: 2018/12/04 12:10:24 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		main(int argc, char **argv)
{
	int		beg = 0;
	int i = 0;
	int word;

	if (argc >= 2)
	{
		while(argv[1][i] != '\0')
		{
			if (beg == 0)
			{
				while(argv[1][i] && is_space(argv[1][i]))
				{
					beg++;
					i++;
				}
				while(argv[1][i] && !is_space(argv[1][i]))
				{
					beg++;
					i++;
				}
			}
			if (beg != 0 && argv[1][i] && is_space(argv[1][i]))
                ;
			word = 0;
			while (argv[1][i] && !is_space(argv[1][i]))
			{
				write (1, &argv[1][i], 1);
				i++;
				word = 1;
			}
			if (word == 1)
				write (1, " ", 1);
			if (argv[1][i] != '\0')
				i++;
		}
		i = 0;
		while (i < beg)
		{
			if (is_space(argv[1][i]))
                ;
			else
				write (1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
