/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:52:43 by khou              #+#    #+#             */
/*   Updated: 2018/10/08 20:06:06 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	len(char *str)
{
	int l;

	l = 0;
	while(str[l])
		l++;
	return(l);
}

int main(int argc, char **argv)
{
	int l;

	if (argc == 2)
	{
		l = len(argv[1]);
		while (l)
			write(1, &argv[1][--l], 1);
	}
	write(1, "\n", 1);
	return(0);
}
		
