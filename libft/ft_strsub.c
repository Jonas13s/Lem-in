/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joivanau <joivanau@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 16:32:44 by joivanau          #+#    #+#             */
/*   Updated: 2022/09/14 00:44:46 by joivanau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	x;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (NULL);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	x = 0;
	i = start;
	while (x < len && s[i] != '\0')
	{
		str[x] = s[i];
		x++;
		i++;
	}
	str[x] = '\0';
	return (str);
}
