/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 00:20:36 by joivanau          #+#    #+#             */
/*   Updated: 2022/09/26 22:41:44 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_queue	*create_q(t_room	*room)
{
	t_queue	*q;

	q = (t_queue *)ft_memalloc(sizeof(t_queue));
	if (!q)
		terminate(ERR_BFS_ALLOC);
	q->room = room;
	q->next = NULL;
	return (q);
}

static void	add_q(t_queue **queue, t_queue *q)
{
	t_queue	*cur;

	if (queue && *queue)
	{
		cur = (*queue);
		while (cur->next)
			cur = cur->next;
		cur->next = q;
	}
	else if (queue)
		(*queue) = q;
}

t_queue	*q_head(t_queue **q)
{
	t_queue	*cur;

	cur = NULL;
	if (q && *q)
	{
		cur = (*q);
		(*q) = (*q)->next;
	}
	return (cur);
}

void	q_add_link(t_lemin *lem, t_queue **q, t_room *room)
{
	t_link	*cur;

	cur = lem->links;
	while (cur)
	{
		if (cur->start == room)
		{
			if (cur->end->level == -1)
			{
				cur->end->level = room->level + 1;
				add_q(q, create_q(cur->end));
			}
		}
		else if (cur->end == room)
		{
			if (cur->start->level == -1)
			{
				cur->start->level = room->level + 1;
				add_q(q, create_q(cur->start));
			}
		}
		cur = cur->next;
	}
}

void	bfs(t_lemin *lem)
{
	t_queue	*queue;
	t_queue	*cur;

	queue = NULL;
	lem->start->level = 0;
	add_q(&queue, create_q(lem->start));
	while (queue != NULL)
	{
		cur = q_head(&queue);
		if (cur->room != lem->end)
		{
			q_add_link(lem, &queue, cur->room);
			lem->level = cur->room->level;
		}
		else
			lem->end->level = 123123;
		free(cur);
	}
}
