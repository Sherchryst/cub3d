/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:53:24 by sgah              #+#    #+#             */
/*   Updated: 2019/10/14 18:14:18 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(const char **s, char c)
{
	size_t	n;

	while (**s && **s == c)
		(*s)++;
	n = 0;
	while ((*s)[n] && (*s)[n] != c)
		n++;
	return (n);
}

static size_t	ft_wordcount(const char *s, char c)
{
	size_t w;
	size_t n;

	w = 0;
	while (*s)
	{
		if ((n = ft_wordlen(&s, c)))
			w++;
		s = s + n;
	}
	return (w);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	count;
	size_t	i;
	size_t	n;

	count = ft_wordcount(s, c);
	if (!(tab = (char **)malloc(sizeof(char*) * (count + 1))))
		return (NULL);
	i = 0;
	while (i < count)
	{
		n = ft_wordlen(&s, c);
		if (!(tab[i] = ft_substr(s, 0, n)))
		{
			while (i)
				free(tab[--i]);
			free(tab);
			return (NULL);
		}
		s = s + n;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
