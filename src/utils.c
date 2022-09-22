/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:17:01 by joivanau          #+#    #+#             */
/*   Updated: 2022/09/22 23:02:53 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
