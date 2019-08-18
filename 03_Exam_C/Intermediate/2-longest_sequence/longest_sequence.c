/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 23:38:09 by khou              #+#    #+#             */
/*   Updated: 2019/08/18 00:11:00 by khou             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>

typedef struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
}     t_node;

int max_nbr(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int max = 0;

int longest_sequence(struct s_node *node)
{
	if (!node)
		return (0);
	static int tmp = 1;
	if (node->left)
	{
		if (node->value + 1 == node->left->value)
		{
			tmp++;
			if (tmp > max)
				max = tmp;
		}
		else
			tmp = 1;
		longest_sequence(node->left);	
	}
	tmp = 1;
	if (node->right)
	{
		if (node->value + 1 == node->right->value)
		{
			tmp++;
			if (tmp > max)
                max = tmp;
        }
		else
            tmp	= 1;
        longest_sequence(node->right);
	}
	tmp = 1;
	return (MAX(tmp,max));
}

/*
int main()
{

	t_node tree[6];

	tree[0].value = 10;
	tree[0].left = &tree[1];
	tree[0].right = NULL;

	tree[1].value = 5;
    tree[1].left = &tree[2];
    tree[1].right = &tree[3];

	tree[2].value = 6;
    tree[2].left = &tree[4];
    tree[2].right = &tree[5];
	
	tree[3].value = 9;
    tree[3].left = NULL;
    tree[3].right = NULL;

	tree[4].value = 7;
    tree[4].left = NULL;
    tree[4].right = NULL;

	tree[5].value = 7;
    tree[5].left = NULL;
    tree[5].right = NULL;

	printf("max: %d\n", longest_sequence(tree));

	t_node tree[8];

    tree[0].value = 5;
    tree[0].left = &tree[1];
    tree[0].right = &tree[2];

    tree[1].value = 6;
    tree[1].left = NULL;
    tree[1].right = NULL;

    tree[2].value = 6;
    tree[2].left = &tree[3];
    tree[2].right = &tree[4];

    tree[3].value = 7;
    tree[3].left = &tree[5];
    tree[3].right = &tree[6];

    tree[4].value = 3;
    tree[4].left = NULL;
    tree[4].right = &tree[7];

    tree[5].value = 3;
    tree[5].left = NULL;
    tree[5].right = NULL;

	tree[6].value = 2;
    tree[6].left = NULL;
    tree[6].right = NULL;

	tree[7].value = 2;
    tree[7].left = NULL;
    tree[7].right = NULL;

	t_node tree2[1]; tree2[0].value = 1;
	tree2[0].left = tree2[0].right = 0;
	printf("max: %d\n", longest_sequence(tree2));

}
*/
