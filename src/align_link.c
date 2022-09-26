/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   align_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 23:18:46 by joivanau          #+#    #+#             */
/*   Updated: 2022/09/26 23:23:32 by joivanau         ###   ########.fr       */
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
