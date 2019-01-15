/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:58:16 by khou              #+#    #+#             */
/*   Updated: 2019/01/14 16:52:37 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* an int is 4 bytes, an unsigned char is 1 byte
there are 10 int in the array, and if the array is represented in unsigned char,
the size of array is 40 (10 * 4).
And each int represents in a group of 4 unsigned char. 
for print_memory:
each unsigned char is converted into two-digit hex.
 */

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
	unsigned char *tlb = (unsigned char*)addr;
	int i = 0;
	int size = size2;

//	printf("sizeof: %zu\n", size2);
	while (size > 0)
	{	
		int col = 0;
		int count = 0;
        while (col < 16 && col < size)
        {
//			printf("tlb[%d]: %d\n", i, tlb[i] );
			print_hex(tlb[i++]);
			count++;
			if (count == 2)
			{
				write(1, " ", 1);
				count = 0;
			}
			col++;
        }
		int a = col;
//		printf("col: %d, i: %d, size: %d\n", col, i, size);
		while (a < 16)
		{
			write(1, "          ", 10);
			a += 4;
		}
		i -= col;// i = 32
		col = 0;
		while (col < 16 && size > 0  )
		{
//			printf("tlb[%d]: %d\n", i, tlb[i]);
			if (tlb[i] > 32 && tlb[i] < 127)
				write(1, &tlb[i], 1);
			else
				write(1, ".", 1);
		 	i++;
			col++;
			size--;
		}
		write(1, "\n", 1);
	}
}

int		main()
{
	int	table[10] = {0, 23, 150, 255,  12, 16,  42, 103};
//	int table[2] = {-1 , 9};

	print_memory(table, sizeof(table));
	return (0);
}
