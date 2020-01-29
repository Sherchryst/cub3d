/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:28:34 by sgah              #+#    #+#             */
/*   Updated: 2020/01/29 01:13:38 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_hud(t_god *game)
{
	t_rect			rect;
	unsigned char	color[4];

	set_color(color, 0, 0, 0);
	if (game->world->jump_time >= 0)
		rect.width = (24 - game->world->jump_time) / 24 * 190;
	else
		rect.width = 190;
	rect.height = 20;
	rect.x = (210 - 190) / 2;
	rect.y = 10;
	draw_rect(game->window, rect, color);
}

void	draw_pixel(t_window *window, unsigned int x, unsigned int y,
	unsigned char color[4])
{
	int index;
	int	i;

	if (x >= window->width || y >= window->height)
		return ;
	index = x * 4 + y * 4 * window->width;
	i = -1;
	while (++i < 4)
		window->data[index + i] = color[i];
}

static void	draw_ray(t_god *game, t_raycasting_data data)
{
	unsigned char		color[4];

	get_pixel_color(game->world->rays[data.i]->texture,
		game->world->rays[data.i]->wall_x *
		game->world->rays[data.i]->texture->width,
		(int)floor((float)(data.a) / (float)(data.d) *
			game->world->rays[data.i]->texture->height),
		color);
	draw_pixel(game->window, data.x, data.y, color);
}

void		draw_rays(t_god *game)
{
	t_raycasting_data	data;

	data.res = ceil(game->window->width / RAYS);
	data.i = -1;
	while (++data.i < RAYS)
	{
		data.d = (int)(game->window->height /
				game->world->rays[data.i]->distance);
		data.x = data.i * data.res;
		while (data.x < data.i * data.res + data.res)
		{
			data.y = (int)(game->window->height / 2 - data.d / 2)
				+ game->world->pz;
			data.a = 0;
			while (data.y < (int)(game->window->height / 2 - data.d / 2)
					+ game->world->pz + data.d)
			{
				draw_ray(game, data);
				data.y++;
				data.a++;
			}
			data.x++;
		}
	}
}
