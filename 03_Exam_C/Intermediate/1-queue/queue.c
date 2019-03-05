/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 09:56:24 by exam              #+#    #+#             */
/*   Updated: 2019/03/05 11:26:27 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void *content;
	struct s_node *next;
};

struct s_queue {
	struct s_node *first;
	struct s_node *last;
};

int isEmpty(struct s_queue *queue)
{
	if (!queue || !queue->first || !queue->last )
		return (1);
	return (0);
}

struct s_queue *init(void)
{
	struct s_queue *que = malloc(sizeof(struct s_queue));

	if (!que)
		return (NULL);
	que->first = NULL;
	que->last = NULL;
	return (que);
}

void enqueue(struct s_queue *queue, void *content)
{
	struct s_node	*new_node = malloc(sizeof(struct s_node));
	if (!new_node)
		return ;
	new_node->content = content;
	new_node->next = NULL;
	if (isEmpty(queue))
	{
		queue = init();
		queue->first = new_node;
		queue->last = new_node;
	}
	else
	{
	queue->last->next = new_node;
	queue->last = new_node;
	}
}

void *dequeue(struct s_queue *queue)
{
	if (isEmpty(queue))
		return (NULL);
	struct s_node *tmp = queue->first;
	void	*content = queue->first->content;
	queue->first = queue->first->next;
	free(tmp);
	return (content);
}

void *peek(struct s_queue *queue)
{
    if (isEmpty(queue))
        return (NULL);
	return (queue->first->content);
}


/*
int		main()
{
	t_node list[3];
	list[0].content = 1;
	list[0].next = &list[1];

	list[1].content = 32;
	list[1].next = &list[2];

    list[2].content = 52;
    list[2].next = NULL;

	t_queue *que = init();

	enqueue(que, 13);

}
*/
