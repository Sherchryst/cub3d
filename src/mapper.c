/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 02:14:20 by sgah              #+#    #+#             */
/*   Updated: 2020/01/30 04:05:08 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_line(char *line)
{
	int i;

	i = 0;
	if (line[i++] != '1')
		return (0);
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int			check_map(t_cub *info)
{
	unsigned int	target;
	t_list			*lst;

	lst = info->map_tmp;
	target = ft_strlen(lst->content);
	if (!check_line(lst->content))
		return (0);
	lst = lst->next;
	while (lst)
	{
		if (ft_strlen(lst->content) != target)
			return (0);
		if (((char*)lst->content)[0] != '1' ||
				((char*)lst->content)[target - 1] != '1')
			return (0);
		if (!lst->next && !check_line(lst->content))
			return (0);
		lst = lst->next;
	}
	info->map_width = (target + 1) / 2;
	info->map_height = ft_lstsize(info->map_tmp);
	return (1);
}

static void	starter(char *line, t_cub *info, int x, int y)
{
	if (*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
	{
		info->px = x;
		info->py = y;
		info->orientation = *line;
	}
	else
		info->map[x][y] = ft_atoi(line);
}

void		create_map(t_cub *info)
{
	int		x;
	int		y;
	t_list	*lst;
	char	*line;

	lst = info->map_tmp;
	info->px = -42;
	info->map = ft_calloc(sizeof(int*), info->map_width);
	x = -1;
	while (++x < info->map_width)
		info->map[x] = ft_calloc(sizeof(int), info->map_height);
	y = 0;
	while (y < info->map_height)
	{
		line = lst->content;
		x = 0;
		while (x < info->map_width)
		{
			starter(line, info, x, y);
			line += 2;
			x++;
		}
		lst = lst->next;
		y++;
	}
}
