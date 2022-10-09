/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_output.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 22:59:16 by joivanau          #+#    #+#             */
/*   Updated: 2022/10/04 23:29:55 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	path_len(t_lemin *lem, t_link *link, int len)
{
	if (link->end == lem->end)
		return (len + 1);
	if (link->start->input > 1)
		return (len + 1);
	return (path_len(lem, find_link(lem, link->end, NULL), len +1));
}

static void	delete_other_outputs(t_lemin *lem, t_link *link)
{
	t_link	*cur;
	t_link	*del;
	t_room	*room;

	room = link->start;
	cur = lem->links;
	while (cur)
	{
		del = cur;
		cur = cur->next;
		if (del->start == room && del != link)
			remove_link(lem, del);
	}
}

static void delete_output(t_lemin *lem, t_room *room)
{
	t_link	*cur;
	t_link	*min_path;
	int		cur_path_len;
	int		min_path_len;

	min_path_len = FT_INT_MAX;
	min_path = NULL;
	cur = lem->links;
	while (cur && room->output > 1)
	{
		if (cur->start == room)
		{
			cur_path_len = path_len(lem, cur, 0);
			if (min_path_len > cur_path_len)
			{
				min_path_len = cur_path_len;
				min_path = cur;
			}
		}
		cur = cur->next;
	}
	delete_other_outputs(lem, min_path);
	del_bad_links(lem);
}

void	delete_outputs(t_lemin *lem)
{
	int		level;
	t_room	*cur;

	level = lem->level;
	while (level > 0)
	{
		cur = lem->rooms;
		while (cur)
		{
			if (cur->level == level && cur->output > 1)
				delete_output(lem, cur);
			cur = cur->next;
		}
		level--;
	}
}