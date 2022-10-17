/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:17:01 by joivanau          #+#    #+#             */
/*   Updated: 2022/10/17 10:50:24 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	*find_link(t_lemin *lem, t_room *start, t_room *end)
{
	t_link	*cur;

	cur = lem->links;
	while (cur)
	{
		if (start && cur->start == start)
			return (cur);
		if (end && cur->end == end)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

t_room	*find_room(t_lemin *lem, char *str)
{
	t_room	*cur;

	cur = lem->rooms;
	while (cur)
	{
		if (!ft_strcmp(cur->name, str))
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

void	terminate(char	*str)
{
	if (errno == 0)
		ft_putendl_fd(str, 2);
	else
		perror(str);
	exit(1);
}
