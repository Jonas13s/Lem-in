/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 23:19:10 by joivanau          #+#    #+#             */
/*   Updated: 2022/09/22 22:17:39 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	get_links(lem, &cur, lines);
	return (lem);
}
