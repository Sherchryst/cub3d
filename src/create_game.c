/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:21:37 by sgah              #+#    #+#             */
/*   Updated: 2020/01/28 03:19:41 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		draw_ceil_ground(t_god *game)
{
	t_rect rect;

	rect.x = 0;
	rect.y = 0;
	rect.height = game->window->height / 2 + game->world->pz;
	rect.width = game->window->width;
	draw_rect(game->window, rect, game->world->color_ceil);
	rect.y = rect.height;
	draw_rect(game->window, rect, game->world->color_ground);
}

void	clear_data(t_window *window)
{
	t_rect			rect;
	unsigned char	color[4];

	color[0] = 0;
	color[1] = 0;
	color[2] = 0;
	color[3] = 0;
	rect.x = 0;
	rect.y = 0;
	rect.width = window->width;
	rect.height = window->height;
	draw_rect(window, rect, color);
}

void	update(t_god *game)
{
	if (game->keys->k_right)
		rotate(game, 1);
	if (game->keys->k_left)
		rotate(game, -1);
	if (game->keys->k_up || game->keys->k_w)
		go(game, 0);
	if (game->keys->k_down || game->keys->k_s)
		go(game, 2);
	if (game->keys->k_a)
		go(game, 1);
	if (game->keys->k_d)
		go(game, 3);
	update_jump(game);
}

void	draw_game(t_god *game)
{
	update(game);
	mlx_clear_window(game->window->mlx_ptr, game->window->win_ptr);
	clear_data(game->window);
	raycast(game->world);
	draw_ceil_ground(game);
	draw_rays(game);
	draw_sprites(game);
	draw_hud(game);
	if (game->screenshot)
		stop_game(game);
	mlx_put_image_to_window(game->window->mlx_ptr, game->window->win_ptr,
			game->window->surface, 0, 0);
}
