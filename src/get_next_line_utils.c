/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 02:12:35 by sgah              #+#    #+#             */
/*   Updated: 2020/01/29 19:17:36 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			my_ft_strjoin(char **s1, char *s2, int s2_size)
{
	char	*res;
	int		i;
	int		j;
	int		s;

	i = -1;
	j = -1;
	s = ft_strlen(*s1);
	if (!(*s1) || !s2)
		return ;
	s2[s2_size] = '\0';
	res = ft_calloc(sizeof(char), s + s2_size + 1);
	if (!res)
		return ;
	while (++i < s)
		res[i] = (*s1)[i];
	while (++j < s2_size)
		res[i + j] = s2[j];
	res[i + j] = '\0';
	free(*s1);
	*s1 = res;
}

char			*first_line(char const *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!(res = ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	while (i--)
		res[i] = str[i];
	return (res);
}

void			cut(char **str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
		i++;
	if (!(res = ft_calloc(ft_strlen(*str) - i + 1, sizeof(char))))
		return ;
	while ((*str)[i])
		res[j++] = (*str)[i++];
	free(*str);
	*str = res;
}
