/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_last_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 19:45:39 by khou              #+#    #+#             */
/*   Updated: 2018/10/08 19:49:10 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
	if (argc > 1)
		while(*argv[argc-1])
			write(1, argv[argc-1]++,1);
	write(1, "\n",1);
	return(0);
}
				
