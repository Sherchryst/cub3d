/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:57:42 by sgah              #+#    #+#             */
/*   Updated: 2019/10/15 14:36:07 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!(out = (char *)malloc(len_s1 + len_s2 + 1)))
		return (NULL);
	ft_memcpy(out, s1, len_s1 + 1);
	ft_memcpy(out + len_s1, s2, len_s2 + 1);
	return (out);
}
