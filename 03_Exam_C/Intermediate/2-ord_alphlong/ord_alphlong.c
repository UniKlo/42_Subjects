/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 22:24:22 by khou              #+#    #+#             */
/*   Updated: 2019/08/08 00:56:24 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ord.h"

t_node *new_node(char *str)
{
	t_node  *node = malloc(sizeof(t_node));
	node->str = str;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int	cmp_len(char *s1, char *s2)
{
	int i = 0;
	int j = 0;
	while (s1[i] && s2[j])
	{
		i++;
		j++;
	}
	if (!s1[i] && !s2[j])
		return (-1);
	if (!s1[i])
		return (0);
	return (1);
}

int cmp_ascii(char a, char b)
{
  if (a < 97)
    a = a + 32;
  if (b < 97)
    b = b + 32;
  if (a > b)
    return (1);
  else 
    return (0);
}

int cmp_alp(char *s1, char *s2)
{
    int	i = 0;
    int	j = 0;
    while (s1[i] && s2[j])
    {
      if (cmp_ascii(s1[i],s2[j]))
	return (1);
      else
	return (0);
      i++;
      j++;
    }
    if (!s1[i] && !s2[j])
      return (-1);
    if (!s1[i])
      return (0);
    return (1);
}

int	cmp(char *str1, char *str2)
{
  int	is_short = cmp_len(str1, str2);
  int	go_before = cmp_alp(str1, str2);

	if (is_short == 1) // is short
		return (1);
	else if (!is_short)
		return (0);
	if (go_before)
	  return (1);
	return (0);
}

void insert(t_node *tree, char *str)
{
	t_node *new;
	if (cmp(tree->str, str))
	{
		if (!tree->left)
		{
			new = new_node(str);
			tree->left = new;
		}
		else
			insert(tree->left, str);
	}
	else
	{
		if (!tree->right)
		{
            new	= new_node(str);
            tree->right = new;
        }
		else
			insert(tree->right, str);
	}
}

int pre = 0;

int str_len(char * str)
{
  int l = 0;
  while (str[l])
    {
      l++;
    }
  return (l);
}
void	print_tree(t_node *root)
{
  int l = 0;
  if (!root)
    return ;
  print_tree(root->left);
  if (!pre)
    pre = l = str_len(root->str);
  else
    {
      l = str_len(root->str);
      if (l > pre)
	{
	  write(1, "\n", 1);
	  pre = l;
	}
      else 
	write(1, " ", 1);
    }
  while (l)
    {
    write(1, root->str++, 1);
    l--;
    }
  print_tree(root->right);
}

int	main(int argc, char **argv)
{
	char **tab;
	t_node *root;
	if (argc == 2)
	{
	  tab = str_split(argv[1]);
	  int i = 0;
	  if (tab)
	    {
	      root = new_node(tab[i]);
	      i++;
	      while (tab[i])
		{
		  insert(root, tab[i]);
		  i++;
		}
	      print_tree(root);
	    }
	}
	write(1, "\n", 1);
}
