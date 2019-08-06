/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/04 23:52:26 by khou              #+#    #+#             */
/*   Updated: 2019/08/05 00:58:41 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

typedef struct s_node {
	int           data;
	struct s_node *next;
	struct s_node *other;
}	t_node;

t_node *new_node(int nbr)
{
	t_node *new_node = malloc(sizeof(t_node));

	new_node->data = nbr;
	new_node->next = NULL;
	new_node->other = NULL;
	return (new_node);
}

struct s_node *clone_list(struct s_node *node)
{
  t_node *beg;
  beg = node;
  t_node *start = 0 ;
  t_node *last = 0;
  while (node)
    {
      if (!start)
	{
	  start = last = new_node(node->data);
	}
      else
	{
	  last->next = new_node(node->data);
		  last = last->next;
	}
      node = node->next;
    }
  
  node = beg;
  t_node *tmp =  beg;
  t_node *tmp_new = start;

  last = start;
  while (node)
    {
      tmp = beg;
      tmp_new = start;
      if (node->other)
	{
	  while (tmp)
	    {
	      if (node->other == tmp)
		last->other = tmp_new;
	      tmp = tmp->next;
	      tmp_new = tmp_new->next;
	    }
	}
      node = node->next;
      last = last->next;
    }
  return (start);
}


#include <stdio.h>
void	print_list(t_node *org)
{
	if (!org)
		return ;
	printf("%d\n", org->data);
	print_list(org->next);
}

void    print_other(t_node *org)
{
    if (!org || !org->other)
        return ;
    printf("org: %d, other: %d\n", org->data, org->other->data);
    print_other(org->other);
}

int main()
{
    t_node *org = new_node(1);

	org->next = new_node(2);
	org->next->next = new_node(3);
	org->next->next->next = new_node(4);
	org->next->next->next->next = new_node(5);
	org->next->next->next->next->next = new_node(6);
	org->other = org->next->next; // 1 -> 3
	org->next->next->other = org->next; // 3 -> 2
	org->next->other = org->next->next->next->next->next;
	org->next->next->next->next->next->other = org->next->next->next->next;
	org->next->next->next->next->other = org->next->next->next; // 5 -> 4
	
	print_list(org);
	printf("print_other\n");
	print_other(org);
	printf("after\n");

	t_node *new = clone_list(org);
	print_list(new);
	printf("print_other\n");
        print_other(new);
}
