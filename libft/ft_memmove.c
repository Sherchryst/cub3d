/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 20:09:16 by sgah              #+#    #+#             */
/*   Updated: 2019/10/14 15:22:19 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmp_d;
	char	*tmp_s;
	int		i;

	i = -1;
	tmp_d = (char *)dst;
	tmp_s = (char *)src;
	if (tmp_d < tmp_s)
		while ((int)(--len) >= 0)
			*tmp_d++ = *tmp_s++;
	else
		while ((int)(--len) >= 0)
			*(tmp_d + len) = *(tmp_s + len);
	return (dst);
}
