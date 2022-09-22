/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 00:59:27 by joivanau          #+#    #+#             */
/*   Updated: 2022/09/22 22:54:38 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_line	*create_line(char *content)
{
	t_line	*line;

	line = (t_line *) ft_memalloc(sizeof(t_line));
	if (!line)
		terminate(ERR_LINE);
	line->content = content;
	line->next = NULL;
	return (line);
}

static void	add_line(t_line **lines, t_line *line)
{
	t_line	*cur;

	if (lines && *lines)
	{
		cur = *lines;
		while (cur->next)
			cur = cur->next;
		cur->next = line;
	}
	else if (lines)
		*lines = line;
}

t_line	*read_line(t_line **lines)
{
	char	*content;
	t_line	*line;
	ssize_t	size;

	line = NULL;
	size = get_next_line(0, &content);
	if (size > 0)
		add_line(lines, (line = create_line(content)));
	if (size == -1)
		terminate(READ_ERROR);
	return (line);
}
