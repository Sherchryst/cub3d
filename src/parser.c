/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:46:09 by sgah              #+#    #+#             */
/*   Updated: 2020/01/28 17:01:36 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_parsing(t_cub *info)
{
	if (info->width <= 0 || info->height <= 0)
		return (0);
	if (!info->n->ptr || !info->s->ptr || !info->w->ptr || !info->e->ptr ||
		!info->sprite->ptr)
		return (0);
	if (!check_map(info))
		return (0);
	return (1);
}

void		parsing_map(char *line, t_cub *info)
{
	ft_lstadd_back(&(info->map_tmp), ft_lstnew(ft_strdup(line)));
}

void		parsing_info(char *line, t_cub *info)
{
	char	type;
	int		i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	type = line[i];
	if (type == 'R')
		parse_resolution(line, info);
	if (type == 'N' || type == 'S' || type == 'W' || type == 'E')
		parse_texture(line, info);
	if (type == 'C' || type == 'F')
		parse_color(line, info);
}

void		parsing(char *line, t_cub *info)
{
	if (*line == '\0')
		return ;
	if (!ft_isdigit(*line) && info->map_started)
		parserror(info);
	if (ft_isdigit(*line))
	{
		info->map_started = 1;
		parsing_map(line, info);
	}
	else
		parsing_info(line, info);
}

t_cub		*parser(char *file)
{
	t_cub	*info;
	int		fd;
	int		ret;
	char	*line;

	if (!(info = malloc(sizeof(t_cub))))
		parserror(NULL);
	if ((fd = open(file, O_RDONLY)) < 0)
		parserror(info);
	info->mlx_tmp = mlx_init();
	info->map_started = 0;
	info->map_tmp = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		parsing(line, info);
		free(line);
	}
	parsing(line, info);
	free(line);
	if (!check_parsing(info))
		parserror(info);
	create_map(info);
	return (info);
}
