/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 23:18:46 by joivanau          #+#    #+#             */
/*   Updated: 2022/10/17 11:33:19 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	swap_r(t_room **start, t_room **end)
{
	t_room	*tmp;

	tmp = *start;
	*start = *end;
	*end = tmp;
}

void	align_link(t_lemin *lem)
{
	t_link	*cur;

	cur = lem->links;
	while (cur)
	{
		if (cur->start->level > cur->end->level)
			swap_r(&cur->start, &cur->end);
		cur = cur->next;
	}
}

void	count_inout_link(t_lemin *lem)
{
	t_link	*cur;

	cur = lem->links;
	while (cur)
	{
		cur->start->output++;
		cur->end->input++;
		cur = cur->next;
	}
}

void	del_bad_links(t_lemin *lem)
{
	t_link	*cur;
	t_link	*del;
	int		bad;

	bad = 1;
	while (bad == 1)
	{
		bad = 0;
		cur = lem->links;
		while (cur)
		{
			del = cur;
			cur = cur->next;
			if ((del->start != lem->start
				&& del->start->input == 0
				&& del->start->output > 0)
				|| (del->end != lem->end
				&&	del->end->input > 0
				&&	del->end->output == 0))
			{
				remove_link(lem, del);
				bad = 1;
			}
		}
	}
}