/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:17:55 by sgah              #+#    #+#             */
/*   Updated: 2019/10/15 14:42:16 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const *set, char const c)
{
	size_t i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

char		*ft_strtrim(char const *s, char const *set)
{
	int		len;

	while (*s && is_set(set, *s))
		(s)++;
	if (!(*s))
		return (ft_strnew(0));
	len = (int)(ft_strlen(s) - 1);
	while (is_set(set, s[len]) && len >= 0)
		len--;
	return (ft_substr(s, 0, (size_t)(len + 1)));
}
