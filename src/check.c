/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 22:48:24 by joivanau          #+#    #+#             */
/*   Updated: 2022/09/18 23:15:00 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	check_command(char *str)
{
	if (str)
	{
		if (ft_strlen(str) >= 2
			&& !ft_strncmp(str, "##", 2))
			return (1);
	}
	return (0);
}

int	check_comment(char *str)
{
	if (str)
	{
		if (ft_strlen(str)
			&& !check_command(str)
			&& !ft_strncmp(str, "#", 1))
			return (1);
	}
	return (0);
}

static int	check_room_name(char *str)
{
	if (str && ft_strlen(str))
	{
		if (str[0] == 'L' || str[0] == '#')
			return (0);
	}
	return (1);
}

int	check_room(char *str)
{
	int		result;
	char	**string;

	string = ft_strsplit(str, ' ');
	if (!string)
		terminate(ERR_SPLIT);
	if (ft_strsplit_len(string) == 3)
	{
		if (check_room_name(string[0])
			&& ft_strisnumeric(string[1])
			&& ft_strisnumeric(string[2]))
			result = 1;
	}
	ft_strsplit_free(&string);
	return (result);
}