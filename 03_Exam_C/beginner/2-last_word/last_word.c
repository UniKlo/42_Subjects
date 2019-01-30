/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:11:15 by khou              #+#    #+#             */
/*   Updated: 2018/10/08 12:33:42 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		len(char *str)
{
	int l;
	for (l = 0; *str++; l++);
	return (l);
}

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
		int i = len(argv[1]) - 1;
		while(is_space(argv[1][i]))
			i--;
		int b = i;
		while(argv[1][b] && !is_space(argv[1][b]))
			b--;
		while (i - b)
			write(1, &argv[1][++b], 1);			
	}
	write(1, "\n", 1);
	return (0);
}
