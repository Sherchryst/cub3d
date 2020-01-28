/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:44:31 by sgah              #+#    #+#             */
/*   Updated: 2020/01/28 03:22:23 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_jump(t_god *game)
{
	if (game->world->jump_time >= 0)
	{
		game->world->jump_time++;
		game->world->pz = (-1 * ((game->world->jump_time / 4 - 3) *
					(game->world->jump_time / 4 - 3)) + 9) * JUMP_HEIGHT;
	}
	if (game->world->jump_time >= 24)
	{
		game->world->jump_time = -1;
		game->world->pz = 0;
	}
}

void	jump(t_god *game)
{
	if (game->world->jump_time == -1)
		game->world->jump_time = 0;
}

static void	go_helper(t_god *game, int direction)
{
	if (direction == 0)
	{
		game->world->px += cos(deg_to_rad(game->world->angle)) * PLAYER_SPEED;
		game->world->py += sin(deg_to_rad(game->world->angle)) * PLAYER_SPEED;
	}
	if (direction == 1)
	{
		game->world->px += cos(deg_to_rad(game->world->angle - 90))
			* PLAYER_SPEED;
		game->world->py += sin(deg_to_rad(game->world->angle - 90))
			* PLAYER_SPEED;
	}
	if (direction == 2)
	{
		game->world->px -= cos(deg_to_rad(game->world->angle)) * PLAYER_SPEED;
		game->world->py -= sin(deg_to_rad(game->world->angle)) * PLAYER_SPEED;
	}
	if (direction == 3)
	{
		game->world->px += cos(deg_to_rad(game->world->angle + 90)) *
			PLAYER_SPEED;
		game->world->py += sin(deg_to_rad(game->world->angle + 90)) *
			PLAYER_SPEED;
	}
}

void		go(t_god *game, int direction)
{
	float	pos_x;
	float	pos_y;

	pos_x = game->world->px;
	pos_y = game->world->py;
	go_helper(game, direction);
	if (game->world->map[(int)floor(game->world->px)]
			[(int)floor(game->world->py)] == 1)
	{
		game->world->px = pos_x;
		game->world->py = pos_y;
	}
}

void	draw_rect(t_window *window, t_rect rect, unsigned char color[4])
{
	int i;
	int j;

	i = -1;
	while (++i < rect.width)
	{
		j = -1;
		while (++j < rect.height)
			draw_pixel(window, rect.x + i, rect.y + j, color);
	}
}
