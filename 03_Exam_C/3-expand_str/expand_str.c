/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:46:01 by khou              #+#    #+#             */
/*   Updated: 2019/01/13 17:48:32 by khou             ###   ########.fr       */
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
                write(1, "   ", 3);
			i = 1;
			while (*(argv[1]) && !is_space(*argv[1]))
				write(1, argv[1]++, 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
