/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perimeter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 10:32:21 by exam              #+#    #+#             */
/*   Updated: 2019/07/23 11:01:52 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

#include <stdio.h>


void perimeter(struct s_node *root)
{
	static int i = 0;
	static int mark = 0;
	if (!root)
		return ;
	if (i == 1)
		printf(" ");
	i = 1;
	printf("%d", root->value);
	if (root->left)
	{
		mark = 1;
		perimeter(root->left);
	}
	perimeter(root->right);
	if (!root->left && !root->right)
	{
		perimeter(root->left);
		perimeter(root->right);
	}

}


void print_tree(struct s_node *root)
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
	struct s_node rr;
	struct s_node rl;
	struct s_node llr;
	struct s_node rrl;
	struct s_node rrr;

	root.value = 92;
	root.left = &l;
	root.right = &r;

	l.value = 85;
	l.left = &ll;
	l.right = NULL;

    r.value= 26;
    r.left = &rl;
    r.right= &rr;


    rl.value= 0;
    rl.left = NULL;
    rl.right= NULL;

    ll.value= 79;
    ll.left = NULL;
    ll.right= &llr;

    rr.value= 64;
    rr.left = &rrl;
    rr.right= &rrr;

    llr.value= 10;
    llr.left = NULL;
    llr.right= NULL;

    rrl.value= 40;
    rrl.left = NULL;
    rrl.right= NULL;

    rrr.value= 78;
    rrr.left = NULL;
    rrr.right= NULL;

	print_tree(&root);
	printf("print perimeter\n");
	perimeter(&root);
}
