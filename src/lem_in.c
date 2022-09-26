/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 23:19:10 by joivanau          #+#    #+#             */
/*   Updated: 2022/09/26 23:23:20 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_links(t_lemin *lem);
t_lemin	*reading(t_line **lines);

t_lemin	*int_lem(void)
{
	t_lemin	*cur;

	cur = (t_lemin *) malloc(sizeof(t_lemin));
	if (!cur)
		terminate(ERR_LEM);
	cur->start_ants = 0;
	cur->end_ants = 0;
	cur->ants = 0;
	cur->level = -1;
	cur->rooms = NULL;
	cur->end = NULL;
	cur->start = NULL;
	cur->links = NULL;
	return (cur);
}

int	main(int args, char **argv)
{
	t_lemin	*lem;
	t_line	*lines;

	lines = NULL;
	lem = reading(&lines);
	bad_links(lem);
	align_link(lem);
	print_links(lem);
	(void)argv;
	(void)args;
	(void)lem;
	return (0);
}

t_lemin	*reading(t_line **lines)
{
	t_lemin	*lem;
	t_line	*cur;

	cur = NULL;
	lem = int_lem();
	get_ants(lem, &cur, lines);
	get_rooms(lem, &cur, lines);
	if (!lem->start || !lem->end)
		terminate(ERR_START_END);
	get_links(lem, &cur, lines);
	if (!lem->links)
		terminate(ERR_NO_LINK);
	bfs(lem);
	return (lem);
}

void	print_names(t_lemin *lem)
{
	t_room	*cur;

	cur = lem->rooms;
	while (cur)
	{
		ft_printf("%s", cur->name);
		cur = cur->next;
	}
}

void	print_links(t_lemin *lem)
{
	t_link	*cur;

	cur = lem->links;
	while (cur)
	{
		ft_printf("start: %s level: %d | end: %s level: %d\n", cur->start->name, cur->start->level, cur->end->name, cur->end->level);
		cur = cur->next;
	}
}
