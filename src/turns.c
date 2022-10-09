/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turns.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 23:35:28 by joivanau          #+#    #+#             */
/*   Updated: 2022/10/09 20:10:12 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	difference(t_lemin *lem, t_path *path)
{
	int		value;
	t_path	*cur;

	value = 0;
	cur = lem->paths;
	while (cur != path)
	{
		value += path->length - cur->length;
		cur = cur->next;
	}
	return (value);
}

t_location	*new_location(int ants, t_room *room)
{
	t_location	*new;

	new = (t_location *)ft_memalloc(sizeof(t_location));
	if (!new)
		terminate(ERR_NEW_LOC);
	new->ant_number = ants;
	new->room = room;
	new->next = NULL;
	return (new);
}

void	make_location(t_lemin *lem, t_location *loc)
{
	t_location	*prev;
	t_location	*cur;

	prev = NULL;
	cur = lem->locations;
	if	(cur)
	{
		while (cur && loc->ant_number > cur->ant_number)
		{
			prev = cur;
			cur = cur->next;
		}
		if (!prev)
			lem->locations = loc;
		else
			prev->next = loc;
		loc->next = cur;
	}
	else
		lem->locations = loc;
}

static void move_ant_along(t_lemin *lem, t_path *path)
{
	t_link	*cur;

	cur = path->head;
	while (cur->next)
		cur = cur->next;
	while (cur)
	{
		if (cur->start->ant_number != -1 && cur->end == lem->end)
		{
			make_location(lem, new_location(cur->start->ant_number, cur->end));
			cur->start->ant_number = -1;
			lem->end_ants++;
		}
		else if (cur->start->ant_number != -1)
		{
			make_location(lem, new_location(cur->start->ant_number, cur->end));
			cur->end->ant_number = cur->start->ant_number;
			cur->start->ant_number = -1;
		}
		cur = cur->prev;
	}
}

static void move_ants_along(t_lemin *lem)
{
	t_path	*cur;

	cur = lem->paths;
	while (cur)
	{
		move_ant_along(lem, cur);
		cur = cur->next;
	}
}

void	move_starting_ant(t_lemin *lem, t_path *path)
{
	if (path->head->end == lem->end)
	{
		lem->start_ants--;
		lem->end_ants++;
		make_location(lem, new_location(++(lem->ants), path->head->end));
	}
	else
	{
		lem->start_ants--;
		path->head->end->ant_number = ++(lem->ants);
		make_location(lem, new_location(path->head->end->ant_number, path->head->end));
	}
}

void	move_starting_ants(t_lemin *lem)
{
	t_path	*cur;

	cur = lem->paths;
	while (cur && lem->start_ants)
	{
		if (lem->start_ants > difference(lem, cur))
			move_starting_ant(lem, cur);
		cur = cur->next;
	}
}

void	print_location(t_lemin *lem)
{
	t_location	*cur;

	cur = lem->locations;
	while (cur)
	{
		if (cur != lem->locations)
			ft_putchar(' ');
		ft_putchar('L');
		ft_putnbr(cur->ant_number);
		ft_putchar('-');
		ft_putstr(cur->room->name);
		cur = cur->next;
	}
	ft_printf("\n");
}

void	do_turns(t_lemin *lem)
{
	(void)move_ants_along(lem);
	while (lem->start_ants || lem->ants != lem->end_ants)
	{
		move_ants_along(lem);
		move_starting_ants(lem);
		print_location(lem);
		lem->locations = NULL;
	}
}