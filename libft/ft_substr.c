/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:12:45 by sgah              #+#    #+#             */
/*   Updated: 2019/10/15 14:53:39 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub;

	if (start > ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	if (!(sub = (char *)ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	ft_strncpy(sub, s + start, len);
	return (sub);
}
