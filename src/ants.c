/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:25:08 by joivanau          #+#    #+#             */
/*   Updated: 2022/10/09 20:08:00 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	get_ants(t_lemin *lem, t_line **cur, t_line **lines)
{
	if (!(*cur))
		(*cur) = read_line(lines);
	if (*cur)
	{
		if (ft_strisnumeric((*cur)->content) == 1)
		{
			lem->start_ants = ft_atoi((*cur)->content);
			(*cur) = NULL;
			if (lem->start_ants <= 0)
				terminate(ENOUGH_ANTS);
		}
		else
			terminate(ANT_NOT_NUM);
	}
}
