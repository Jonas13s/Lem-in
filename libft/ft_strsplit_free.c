/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 23:11:36 by joivanau          #+#    #+#             */
/*   Updated: 2022/09/18 23:13:58 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strsplit_free(char ***string)
{
	char	**cur;

	while (string && *string)
	{
		cur = (*string);
		while ((*cur))
			free((*(cur++)));
		free(*string);
		(*string) = NULL;
	}
}