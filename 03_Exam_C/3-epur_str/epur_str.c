/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:37:55 by khou              #+#    #+#             */
/*   Updated: 2018/10/08 13:05:30 by khou             ###   ########.fr       */
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
	if (argc == 2)
	{
		int i = 0;
		while (*argv[1])
		{
			while (is_space(*argv[1]))
				argv[1]++;
			if (i == 1 && *argv[1])
                write(1, " ", 1);
			i = 1;
			while (*(argv[1]) && !is_space(*argv[1]))
				write(1, argv[1]++, 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
