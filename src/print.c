/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:35:07 by joivanau          #+#    #+#             */
/*   Updated: 2022/10/09 20:35:53 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	print_map(t_line *lines)
{
	t_line	*cur;

	cur = lines;
	while (cur)
	{
		ft_putendl(cur->content);
		cur = cur->next;
	}
}