/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 20:53:01 by khou              #+#    #+#             */
/*   Updated: 2018/10/20 02:19:06 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
//#include <stdio.h>

void	print_hex(int tlb)
{
	char *hex = "0123456789abcdef";
	write(1, hex + ((tlb / 16) % 16), 1);
    write(1, hex + (tlb % 16), 1);
}

void	print_memory(const void *addr, size_t size2)
{
	unsigned char *tlb = (unsigned char*)addr;//to get a byte
	int j = 0;
	int size = size2;
	
	while (size)
	{	
		int i = 0;
		int count = 0;
        while (i < 16 && i++ < size)
        {
			print_hex(tlb[j++]);
			count++;
			if (count == 2)
			{
				write(1, " ", 1);
				count = 0;
			}
        }
		int a = i;
		while (a < 16)
		{
			write(1, "          ", 10);
			a += 4;
		}
		j -= i;
		i = 0;
		while (i++ < 16 && size-- > 1)
		{
			if (tlb[j] > 32 && tlb[j] < 127)
				write(1, &tlb[j], 1);
			else
				write(1, ".", 1);
		 	j++;
		}
		write(1, "\n", 1);
	}
}


#include <stdio.h>

int	main(void)
{
	int	tab[10] = {256, 23, 150, 255, 12, 16,  21, 42};

	print_memory(tab, sizeof(tab));
	return (0);
}
