/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 12:57:22 by sgah              #+#    #+#             */
/*   Updated: 2019/10/15 13:37:26 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		size(long int n)
{
	long int	i;

	i = 1;
	if (n < 0)
	{
		n = n * -1;
		i++;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char		*fill_str(char *str, long int n, int len)
{
	int		start;

	str[len] = '\0';
	len--;
	if (n < 0)
	{
		n = n * -1;
		start = 1;
		str[0] = '-';
	}
	else
		start = 0;
	while (len >= start)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char			*str;
	int				len;
	long int		lln;

	lln = n;
	len = size(lln);
	if (!(str = ft_strnew(len)))
		return (NULL);
	str = fill_str(str, lln, len);
	return (str);
}
