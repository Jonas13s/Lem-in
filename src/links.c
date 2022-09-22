/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:25:40 by joivanau          #+#    #+#             */
/*   Updated: 2022/09/22 23:04:19 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	validate_l(t_lemin *lem, t_link *link)
{
	t_link	*cur;

	cur = lem->links;
	while (cur)
	{
		if (link != cur
			&& ((!ft_strcmp(link->start->name, cur->start->name)
					&& !ft_strcmp(link->end->name, cur->end->name))
				|| (!ft_strcmp(link->start->name, cur->end->name)
					&& !ft_strcmp(link->end->name, cur->start->name))))
			terminate(ERR_LINK_DUP);
		cur = cur->next;
	}
}

static void	add_link(t_lemin *lem, t_link *link)
{
	t_link	*cur;

	cur = lem->links;
	if (cur)
	{
		while (cur->next)
			cur = cur->next;
		cur->next = link;
	}
	else
	{
		lem->links = link;
	}
}

static t_link	*init_link(t_room *start, t_room *end)
{
	t_link	*link;

	link = (t_link *)ft_memalloc(sizeof(t_link));
	if (!link)
		terminate(ERR_LINK_I);
	link->start = start;
	link->end = end;
	link->next = NULL;
	link->prev = NULL;
	return (link);
}

static	t_link	*create_link(t_lemin *lem, char *str)
{
	char	*start;
	char	*end;
	char	*dash;
	t_room	*start_room;
	t_room	*end_room;

	dash = str;
	dash = ft_strchr(dash + 1, '-');
	if (dash == NULL)
		return (NULL);
	start = ft_strsub(str, 0, dash - str);
	if (!start)
		terminate(ERR_LINK_I);
	end = ft_strsub(dash + 1, 0, ft_strlen(dash));
	if (!end)
		terminate(ERR_LINK_I);
	start_room = find_room(lem, start);
	end_room = find_room(lem, end);
	free(start);
	free(end);
	if (start_room && end_room)
		return (init_link(start_room, end_room));
	return (NULL);
}

void	get_links(t_lemin *lem, t_line **cur, t_line **lines)
{
	t_link	*link;

	if (!(*cur))
		(*cur) = read_line(lines);
	while ((*cur))
	{
		if (!check_command((*cur)->content)
			&& !check_comment((*cur)->content))
		{
			if (!ft_strlen((*cur)->content))
				break ;
			link = create_link(lem, (*cur)->content);
			if (!link)
				terminate(ERR_LINK);
			add_link(lem, link);
			validate_l(lem, link);
		}
		(*cur) = NULL;
		(*cur) = read_line(lines);
	}
}
