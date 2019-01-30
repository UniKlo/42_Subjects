/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:33:08 by khou              #+#    #+#             */
/*   Updated: 2018/10/08 12:06:51 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		len(char *str)
{
	int l;
	for (l = 0; *str; l++)
		str++;
	return (l);
}
	

int		main(int argc, char **argv)
{
	if (argc == 4)
	{
		while (*argv[1] && len(argv[2]) == 1 && len(argv[3]) == 1)
		{
			if (*argv[1] == *argv[2])
				*argv[1] = *argv[3];
			write(1, argv[1], 1);
			argv[1]++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
