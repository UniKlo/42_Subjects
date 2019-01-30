/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:09:42 by khou              #+#    #+#             */
/*   Updated: 2018/10/01 14:09:30 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_bits1(unsigned char octet);
void    print_bits2(unsigned char octet);

int	main()
{
    write(1, "method 1: ", 10);
	print_bits1(42);
	write(1, "\n", 1);

    write(1, "method 2: ", 10);
    print_bits2(42);
    write(1, "\n", 1);
	return (0);
}
