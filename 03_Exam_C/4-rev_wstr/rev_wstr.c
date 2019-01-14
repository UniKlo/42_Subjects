/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 14:24:04 by khou              #+#    #+#             */
/*   Updated: 2019/01/14 15:10:30 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		len(char *str)
{
	int l = 0;
	while (*str)
	{
		l++;
		str++;
	}
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
		int max_i = len(argv[1]) - 1;
		while (max_i > -1)
		{
			if (is_space(argv[1][max_i]))
			{
				write(1, " ", 1);
				max_i--;
			}
			int	word_beg = 0;
			int word_end = max_i;
			while(!is_space(argv[1][max_i]) && argv[1][max_i])
				max_i--;
			word_beg = max_i + 1;
			while((word_end - word_beg) > -1)
				write(1, &argv[1][word_beg++], 1);
		}
	}
	write (1, "\n", 1);
	return (0);
}
