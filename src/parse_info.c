/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:20:55 by sgah              #+#    #+#             */
/*   Updated: 2020/01/28 02:50:33 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		parse_color(char *line, t_cub *info)
{
	char			type;
	unsigned char	res[3];

	while (ft_isspace(*line))
		line++;
	type = *line;
	line++;
	while (ft_isspace(*line))
		line++;
	res[0] = (unsigned char)ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line += (*line == ',');
	res[1] = (unsigned char)ft_atoi(line);
	while (ft_isdigit(*line))
		line++;
	line += (*line == ',');
	res[2] = (unsigned char)ft_atoi(line);
	if (type == 'C')
		set_color(info->ceil, res[0], res[1], res[2]);
	else if (type == 'F')
		set_color(info->floor, res[0], res[1], res[2]);
}

void		parse_resolution(char *line, t_cub *info)
{
	while (ft_isspace(*line))
		line++;
	line++;
	while (ft_isspace(*line))
		line++;
	info->width = min(ft_atoi(line), 2560);
	while (ft_isdigit(*line))
		line++;
	info->height = min(ft_atoi(line), 1440);
}

void		parse_texture(char *line, t_cub *info)
{
	char 	type[2];

	while (ft_isspace(*line))
		line++;
	type[0] = *line;
	line++;
	type[1] = *line;
	line++;
	while (ft_isspace(*line))
		line++;
	if (type[0] == 'N')
		info->n = load_texture(info->mlx_tmp, line);
	if (type[0] == 'E')
		info->e = load_texture(info->mlx_tmp, line);
	if (type[0] == 'W')
		info->w = load_texture(info->mlx_tmp, line);
	if (type[0] == 'S' && type[1] == 'O')
		info->s = load_texture(info->mlx_tmp, line);
	if (type[0] == 'S' && type[1] == ' ')
		info->sprite = load_texture(info->mlx_tmp, line);
}
