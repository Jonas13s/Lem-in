/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_links.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:34:27 by joivanau          #+#    #+#             */
/*   Updated: 2022/09/26 22:41:36 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	remove_link(t_lemin *lem, t_link *link)
{
	t_link	*cur;
	t_link	*prev;

	prev = NULL;
	cur = lem->links;
	while (cur && cur != link)
	{
		prev = cur;
		cur = cur->next;
	}
	if (!prev && cur)
		lem->links = cur->next;
	else if (cur)
		prev->next = cur->next;
	if (link->end->input > 0)
		link->end->input--;
	if (link->start->output > 0)
		link->start->output--;
	free(link);
}

void	bad_links(t_lemin *lem)
{
	t_link	*cur;
	t_link	*del;

	cur = lem->links;
	while (cur)
	{
		del = cur;
		cur = cur->next;
		if (del->start->level == -1
			|| del->end->level == del->start->level
			|| del->end->level == -1)
			remove_link(lem, del);
	}
}
