/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 10:01:48 by exam              #+#    #+#             */
/*   Updated: 2019/07/23 10:28:25 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void reverse_tree(struct s_node *root)
{
    if (!root)
        return ;
	struct s_node *tmp;

	tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	reverse_tree(root->left);
	reverse_tree(root->right);
}
/*
#include <stdio.h>
void	print_tree(struct s_node *root)
{
	if (!root)
		return ;
	printf("%d\n", root->value);
	print_tree(root->left);
	print_tree(root->right);
}

int main()
{
	struct s_node root;
	struct s_node l;
	struct s_node r;
	struct s_node ll;
	struct s_node lr;
	struct s_node lll;
	struct s_node lrl;
	struct s_node lrr;
	struct s_node lrlr;

	root.value = 94;
	root.left = &l;
	root.right = &r;

	l.value = 34;
	l.left = &ll;
	l.right = &lr;

    r.value= 52;
    r.left = NULL;
    r.right= NULL;

    ll.value= 1;
    ll.left = &lll;
    ll.right= NULL;

    lr.value= 99;
    lr.left = &lrl;
    lr.right= &lrr;

    lll.value= 20;
    lll.left = NULL;
    lll.right= NULL;

    lrl.value= 83;
    lrl.left = NULL;
    lrl.right= &lrlr;

    lrr.value= 39;
    lrr.left = NULL;
    lrr.right= NULL;

    lrlr.value= 61;
    lrlr.left = NULL;
    lrlr.right= NULL;

	print_tree(&root);
	printf("After reverse\n");
	reverse_tree(&root);
	print_tree(&root);
}
*/
