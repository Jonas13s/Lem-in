/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 21:43:43 by joivanau          #+#    #+#             */
/*   Updated: 2022/09/20 00:43:36 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	validate_r(t_lemin *lem, t_room *room)
{
	t_room	*cur;

	cur = lem->rooms;
	while (cur)
	{
		if (room != cur && !ft_strcmp(room->name, cur->name))
			terminate(ROOM_NAME_DUP);
		if (room != cur && room->x == cur->x && room->y == cur->y)
			terminate(ROOM_CORD_DUP);
		cur = cur->next;
	}
}

static t_type	get_type(char *str)
{
	if (!ft_strcmp(str, "##start"))
		return (START);
	else if (!ft_strcmp(str, "##end"))
		return (END);
	return (MID);
}

static t_room	*create_room(t_type type, char *str)
{
	char	**string;
	t_room	*room;

	string = ft_strsplit(str, ' ');
	if (!string)
		terminate(ERR_ROOM_CR);
	room = (t_room *)ft_memalloc(sizeof(t_room));
	if (!room)
		terminate(ERR_ROOM_CR);
	room->name = ft_strdup(string[0]);
	if (!room->name)
		terminate(ERR_ROOM_CR);
	room->x = ft_atoi(string[1]);
	room->y = ft_atoi(string[2]);
	room->type = type;
	room->level = -1;
	room->input = 0;
	room->output = 0;
	room->ant_number = -1;
	room->next = NULL;
	ft_strsplit_free(&string);
	return (room);
}

static void	add_room(t_lemin *lem, t_room *room)
{
	t_room	*cur;

	cur = lem->rooms;
	if (cur)
	{
		while (cur->next)
			cur = cur->next;
		cur->next = room;
	}
	else
	{
		lem->rooms = room;
	}
	if (room->type == START)
		lem->start = room;
	else if (room->type == END)
		lem->end = room;
	validate_r(lem, room);
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
		else if (check_room((*cur)->content))
		{
			room = create_room(type, (*cur)->content);
			add_room(lem, room);
			type = MID;
		}
		else
			type = MID;
		if ((type == END && lem->end) || (type == START && lem->start))
			terminate(ERR_ROOM);
		(*cur) = NULL;
		(*cur) = read_line(lines);
	}
}
