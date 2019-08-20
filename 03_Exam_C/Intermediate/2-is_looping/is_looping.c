/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 22:26:25 by khou              #+#    #+#             */
/*   Updated: 2019/08/19 22:29:26 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_node {
	int value;
	struct s_node *next;
} t_node;

int	is_looping(struct s_node *node)
{
	t_node *cmp = node;
	int mark = 0;
	if (!node)
		return (0);
	while (cmp && node)
	{
		if (node == cmp)
		{
			if (mark == 0)
				mark = 1;
			else
				return (1);
		}
		node = node->next;
		if (cmp->next->next)
			cmp = cmp->next->next;
		else
			return (0);
	}
	return(0);
}
