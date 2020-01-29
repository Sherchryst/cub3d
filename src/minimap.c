/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:05:12 by sgah              #+#    #+#             */
/*   Updated: 2020/01/29 03:17:54 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		color_case(int x, int y, t_god *game, unsigned char *color)
{
	if (game->world->px == x && game->world->py == y)
	{
		color[0] = 100;
		color[1] = 155;
		color[2] = 55;
		return ;
	}
	if (game->world->map[x][y] == 1 || game->world->map[x][y] == 2)
	{
		color[0] = 0;
		color[1] = 0;
		color[2] = 0;
		return ;
	}
	else
	{
		color[0] = 255;
		color[1] = 255;
		color[2] = 255;
	}
}

void			draw_minimap(t_god *game)
{
	t_rect		rect;
	int			i;
	int			j;
	unsigned char	color[4];

	i = 0;
	while (i < game->world->mx)
	{
		j = 0;
		while (j < game->world->my)
		{
			color_case(i, j, game, color);
			rect.x = game->window->width - (game->world->mx * 5) - 5 + (j * 5);
			rect.y = game->window->height - (game->world->my * 5) - 5 + (i * 5);
			rect.height = 4;
			rect.width = 4;
			draw_rect(game->window, rect, color);
			j++;
		}
		i++;
	}
}

