/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 21:43:43 by joivanau          #+#    #+#             */
/*   Updated: 2022/09/18 23:17:09 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_type	get_type(char *str)
{
	if (!ft_strcmp(str, "##start"))
		return (START);
	else if (!ft_strcmp(str, "##end"))
		return (END);
	return (MID);
}

void	get_rooms(t_lemin *lem, t_line **cur, t_line **lines)
{
	t_type	type;
	t_room	*room;

	type = MID;
	if (!(*cur))
		(*cur) = read_line(lines);
	while (*cur && (check_command((*cur)->content)
			|| check_comment((*cur)->content)
			|| check_room((*cur)->content)))
	{
		if (check_command((*cur)->content))
			type = get_type((*cur)->content);
		(*cur) = NULL;
		(*cur) = read_line(lines);
	}
	(void)lem;
	(void)cur;
	(void)lines;
	(void)type;
	(void)room;
}
