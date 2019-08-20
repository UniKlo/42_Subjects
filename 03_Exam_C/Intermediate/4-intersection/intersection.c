/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 23:14:34 by khou              #+#    #+#             */
/*   Updated: 2019/08/19 23:20:18 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_node {
  void *content;
  struct s_node *next;
}	t_node;

void *intersection(struct s_node *lst1, struct s_node *lst2)
{
  t_node *tmp = lst2;
  if (!lst1 || !lst2)
	  return (0);
  while(lst1)
    {
      lst2 = tmp;
      while (lst2)
	{
	  if (lst1 == lst2)
	    return (lst2);
	  lst2 = lst2->next;
	}
      lst1 = lst1->next;
    }
  return (0);
}

/*
#include <stdio.h>
#include <stdlib.h>

void	print_node(t_node *lst)
{
  if (!lst)
    return ;
  printf("%s\n", lst->content);
  print_node(lst->next);
}

t_node *new_node(void *content)
{
  t_node *new_node;
  new_node = malloc(sizeof(t_node));

  new_node->content = content;
  new_node->next = NULL;
  return (new_node);
}

int	main()
{
  t_node *lst1;
  t_node *lst2;

  lst1 = new_node("1");
  lst1->next = new_node("2");
  lst1->next->next = new_node("3");

  lst2 = new_node("one");
  lst2->next = new_node("two");
  //lst2->next->next = lst1->next->next;
  lst2->next->next = new_node("three");
  print_node(lst1);
  print_node(lst2);
  t_node *inter = intersection(lst1, lst2);
  printf("inter is %p\n", inter);

  t_node *lst3 = NULL;
  t_node *lst4 = NULL;
  t_node *inter1 = intersection(lst3, lst4);
  printf("inter is %p\n", inter1);

}

*/
