/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 01:13:48 by joivanau          #+#    #+#             */
/*   Updated: 2022/03/16 01:21:44 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*hex_conv(unsigned long long i, char *base)
{
	char				*string;
	unsigned long long	number;
	size_t				size;
	int					base_len;

	base_len = ft_strlen(base);
	number = i;
	size = 0;
	while (i)
	{
		i /= base_len;
		if (i)
			size++;
	}
	string = ft_strnew(size + 1);
	if (!string)
		return (0);
	while (number > 0)
	{
		string[size--] = base[number % base_len];
		number /= base_len;
	}
	if (size == 0 && string[1] == '\0')
		string[0] = '0';
	return (string);
}
