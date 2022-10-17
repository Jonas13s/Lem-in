/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 01:23:45 by joivanau          #+#    #+#             */
/*   Updated: 2022/10/17 11:39:40 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int has_output(t_lemin *lem, t_link *link)
{
	if (link->start == lem->start)
		return (0);
	if (link->start->output > 1)
		return (1);
	return (has_output(lem, find_link(lem, NULL, link->start)));
}

static void	delete_other_inputs(t_lemin *lem, t_link *link)
{
	t_room	*end;
	t_link	*cur;
	t_link	*del;

	end = link->end;
	cur = lem->links;
	while (cur)
	{
		del = cur;
		cur = cur->next;
		if (del->end == end && del != link)
			remove_link(lem, del);
	}
}

static void delete_input(t_lemin *lem, t_room *room)
{
	t_link	*cur;
	t_link	*del;

	cur = lem->links;
	while (cur && room->input > 1)
	{
		del = cur;
		cur = cur->next;
		if (del->end == room)
		{
			if (!has_output(lem, del))
				delete_other_inputs(lem, del);
			else
				remove_link(lem, del);
			del_bad_links(lem);
		}
	}
}

void	delete_inputs(t_lemin *lem)
{
	int		level;
	t_room	*cur;

	level = 1;
	while (level <= lem->level)
	{
		cur = lem->rooms;
		while (cur)
		{
			if (cur->level == level && cur->input > 1)
				delete_input(lem, cur);
			cur = cur->next;
		}
		level++;
	}
}