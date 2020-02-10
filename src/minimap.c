/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 01:05:12 by sgah              #+#    #+#             */
/*   Updated: 2020/02/10 22:12:15 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		color_case(int x, int y, t_god *game, unsigned char color[4])
{
	int i;

	i = -1;
	if (game->world->map[x][y] == 1 || game->world->map[x][y] == 2)
		set_color(color, 0, 0, 0);
	else if (game->world->map[x][y] == 3)
		set_color(color, 200, 100, 200);
	else
		set_color(color, 255, 255, 255);
	while ((i += 30) < 200)
	{
		if (game->world->rays[i]->map_x == x &&
				game->world->rays[i]->map_y == y)
			set_color(color, 100, 100, 100);
	}
}

void			draw_minimap(t_god *game)
{
	t_rect			rect;
	int				i;
	int				j;
	unsigned char	color[4];

	j = 0;
	while (j < game->world->my)
	{
		i = 0;
		while (i < game->world->mx)
		{
			color_case(i, j, game, color);
			rect.x = game->window->width - (game->world->mx * 5) - 5 + (i * 5);
			rect.y = game->window->height - (game->world->my * 5) - 5 + (j * 5);
			rect.height = 4;
			rect.width = 4;
			draw_rect(game->window, rect, color);
			i++;
		}
		j++;
	}
}
