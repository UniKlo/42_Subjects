/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khou <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 23:20:31 by khou              #+#    #+#             */
/*   Updated: 2019/08/05 23:39:59 by khou             ###   ########.fr       */
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
	if (!queue || (!queue->first || !queue->last) )
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
		if (!queue)
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
#include <stdio.h>
int main(){
	struct s_queue *q = init();
	printf("isEmpty: %i\n", isEmpty(q));
	printf("Dequeueing: %s\n", dequeue(q));
	printf("Peeking: %s\n", peek(q));

	printf("Enqueueing one\n"); enqueue(q, "one");
	printf("Peeking: %s\n", peek(q));
	printf("isEmpty: %i\n", isEmpty(q));
	printf("Enqueueing two\n"); enqueue(q, "two");
	printf("Peeking: %s\n", peek(q));
	printf("isEmpty: %i\n", isEmpty(q));
	printf("Enqueueing three\n"); enqueue(q, "three");
	printf("Peeking: %s\n", peek(q));
	printf("isEmpty: %i\n", isEmpty(q));

	printf("Dequeueing: %s\n", dequeue(q));
	printf("isEmpty: %i\n", isEmpty(q));
	printf("Peeking: %s\n", peek(q));
	printf("Dequeueing: %s\n", dequeue(q));
	printf("isEmpty: %i\n", isEmpty(q));
	printf("Peeking: %s\n", peek(q));
	printf("Dequeueing: %s\n", dequeue(q));
	printf("isEmpty: %i\n", isEmpty(q));
	printf("Peeking: %s\n", peek(q));

}

*/
