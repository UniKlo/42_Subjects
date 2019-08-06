
typedef struct s_node {
  void *content;
  struct s_node *next;
}	t_node;

void *intersection(struct s_node *lst1, struct s_node *lst2)
{
  t_node *tmp = lst2;
  while(lst1)
    {
      lst2 = tmp;
      while (lst2)
	{
	  if (lst1 == lst2)
	    return (lst2->content);
	  lst2 = lst2->next;
	}
      lst1 = lst1->next;
    }
  return ("\0");
}


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
  //  lst2->next->next = lst1->next->next;
  lst2->next->next = new_node("three");
  print_node(lst1);
  print_node(lst2);
  printf("T/F: %s\n", intersection(lst1, lst2));
}

