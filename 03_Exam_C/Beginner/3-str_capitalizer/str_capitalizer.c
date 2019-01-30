/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:14:55 by khou              #+#    #+#             */
/*   Updated: 2019/01/12 14:55:06 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


int		is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}



int main(int argc, char **argv)
{
	if (argc > 1)
	{
		int i = 1;
		while ( i < argc)
		{
			int word = 0;
			if (i > 1)
				write (1, "\n", 1);
			while (*argv[i])
			{
				while (*argv[i] && is_space(*argv[i]))
				{
					write (1, argv[i]++, 1);
				}
				if (*argv[i] && !is_space(*argv[i]))
				{
					if (*argv[i] > 96 && *argv[i] < 123)
						*argv[i] = *argv[i] - 32;
					write (1, argv[i]++, 1);
					word = 1;
				}
				while (*argv[i] && word == 1 && !is_space(*argv[i]))
				{
					if (*argv[i] > 64 && *argv[i] < 91)
						*argv[i] = *argv[i] + 32;
					write (1, argv[i]++, 1);
				}
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return(0);
}
