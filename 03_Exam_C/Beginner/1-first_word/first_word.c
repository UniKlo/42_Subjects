/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:07:45 by khou              #+#    #+#             */
/*   Updated: 2018/10/05 14:21:27 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}


int main(int argc, char **argv)
{
	if (argc == 2)
	{
		while (*argv[1])
		{
			while (is_space(*argv[1]))
				argv[1]++;
			while (*argv[1] && !is_space(*argv[1]))
				write(1, argv[1]++, 1);
			if (is_space(*argv[1]) || !*argv[1])
				break;
		}
	}
	write(1,"\n",1);
	return (0);
}
