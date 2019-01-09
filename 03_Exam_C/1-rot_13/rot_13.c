/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:44:14 by khou              #+#    #+#             */
/*   Updated: 2019/01/09 13:05:43 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		while (*argv[1])
		{
			if (*argv[1] >= 'a' && *argv[1] <= 'z')
			{
				if (*argv[1] + 13 <= 'z')
					*argv[1] = *argv[1] + 13;
				else
					*argv[1] = *argv[1] - 13;
			}
			if (*argv[1] >= 'A' && *argv[1] <= 'Z')
			{
				if (*argv[1] + 13 <= 'Z')
					*argv[1] = *argv[1] + 13;
                else
                    *argv[1] = *argv[1] - 13;
			}
			write(1, argv[1]++, 1);
		}
	}
			
	write (1, "\n", 1);
	return (0);
}
