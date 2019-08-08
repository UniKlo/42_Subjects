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

int cmp_alp(char *s1, char *s2)
{
    int	i = 0;
    int	j = 0;
    while (s1[i] && s2[j])
    {
		if (s1[i] > s2[j])
			return (1);
        i++;
        j++;
    }
	return (1);
}

int	cmp(char *str1, char *str2)
{
//	printf("cmp %s to %s\n", str1, str2);
//	printf("cmp_len %d, ", cmp_len(str1, str2));
//	printf("cmp_alp %d\n", cmp_alp(str1, str2));
	if (cmp_len(str1, str2)) // is short
		return (1);
	else
		return (0);
	if (cmp_alp(str1, str2))
			return (1);
	return (0);
}

void insert(t_node *tree, char *str)
{
	t_node *new;
	printf("%s, %s, final: %d\n", tree->str, str,cmp(tree->str, str));	
	if (cmp(tree->str, str))// short, and early
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
		printf("I m in right\n");
		if (!tree->right)
		{
            new	= new_node(str);
            tree->right = new;
        }
		else
			insert(tree->right, str);
	}
}

void	print_tree(t_node *root)
{
	if (!root)
		return ;
	print_tree(root->left);
	printf("%s\n", root->str);
	print_tree(root->right);
}

int	main(int argc, char **argv)
{
	char **tab;
	t_node *root;
	if (argc == 2)
	{
		tab = str_split(argv[1]);
		printf("I m in main!\n");
		int i = 0;
//		if (tab[i])??
		root = new_node(tab[i]);
		i++;
		while (tab[i])
		{
			printf("%s\n", tab[i]);
			insert(root, tab[i]);
			i++;
		}
		printf("Here is the tree\n");
		print_tree(root);
	}
	printf("\n");
}
