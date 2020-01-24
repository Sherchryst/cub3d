/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 16:46:09 by sgah              #+#    #+#             */
/*   Updated: 2020/01/24 18:02:29 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

t_cub		parser(char *file)
{
	t_cub	*info;
	int		fd;
	int		ret;
	char	*line;

	info = malloc(sizeof(t_cub));
	if ((fd = open(file, O_RDONLY)) < 0)
		parserror(info);
	info->mlx_tmp = mlx_init();
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		parsing(line, info);
		free(line);
	}
	parsing(line, info);
	free(line);
}
