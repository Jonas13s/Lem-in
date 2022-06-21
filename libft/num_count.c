/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 01:14:16 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/16 01:21:54 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_count(long long int i)
{
	int		count;
	char	*s;

	count = 0;
	if (i < 0)
	{
		i *= -1;
		count++;
	}
	s = hex_conv(i, DIGITS);
	count += ft_strlen(s);
	ft_strdel(&s);
	return (count);
}
