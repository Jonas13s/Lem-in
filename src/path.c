/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:13:07 by joivanau          #+#    #+#             */
/*   Updated: 2022/10/17 11:12:30 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_path	*new_path(void)
{
	t_path	*new;

	new = (t_path *)ft_memalloc(sizeof(t_path));
	if (!new)
		terminate(ERR_NEW_PATH);
	new->head = NULL;
	new->length = 0;
	new->next = NULL;
	return (new);
}

static void add_path(t_lemin *lem, t_path *path)
{
	t_path	*cur;
	t_path	*prev;

	prev = NULL;
	cur = lem->paths;
	if (cur)
	{
		while (cur && path->length > cur->length)
		{
			prev = cur;
			cur = cur->next;
		}
		if (!prev)
			lem->paths = path;
		else
			prev->next = path;
		path->next = cur;
	}
	else
		lem->paths = path;
}

static void	add_path_link(t_path *path, t_link *link)
{
	t_link	*cur;
	t_link	*prev;

	prev = NULL;
	cur = path->head;
	if (cur)
	{
		while (cur)
		{
			prev = cur;
			cur = cur->next;
		}
		link->prev = prev;
		prev->next = link;
	}
	else
		path->head = link;
	path->length++;
}

void	form_path(t_lemin *lem)
{
	t_path	*path;
	t_link	*link;

	while (lem->links)
	{
		path = new_path();
		link = find_link(lem, lem->start, NULL);
		add_path_link(path, del_link(lem, link));
		while (link->end != lem->end)
		{
			link = find_link(lem, link->end, NULL);
			add_path_link(path, del_link(lem, link));
		}
		add_path(lem, path);
	}
}