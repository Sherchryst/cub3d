/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 01:22:21 by sgah              #+#    #+#             */
/*   Updated: 2020/01/30 08:26:39 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		rotate(t_god *game, int direction)
{
	float temp;

	temp = game->world->plane_x;
	game->world->plane_x = game->world->plane_x * cos(-deg_to_rad(direction *
				ROTATE_SPEED)) - game->world->plane_y *
		sin(-deg_to_rad(direction * ROTATE_SPEED));
	game->world->plane_y = temp * sin(-deg_to_rad(direction * ROTATE_SPEED)) +
		game->world->plane_y * cos(-deg_to_rad(direction * ROTATE_SPEED));
	rotate_ray_array(game->world->rays, direction * ROTATE_SPEED);
	game->world->angle += direction * ROTATE_SPEED;
	game->world->angle = mod(game->world->angle, 360);
}

void		stop_game(t_god *game)
{
	if (game->screenshot)
		screenshot(game);
	FMOD_Sound_Release(game->j);
	FMOD_System_Close(game->system);
	FMOD_System_Release(game->system);
	destroy_texture(game->window->mlx_ptr, game->world->n);
	destroy_texture(game->window->mlx_ptr, game->world->s);
	destroy_texture(game->window->mlx_ptr, game->world->e);
	destroy_texture(game->window->mlx_ptr, game->world->o);
	destroy_texture(game->window->mlx_ptr, game->world->sprite);
	mlx_destroy_window(game->window->mlx_ptr, game->window->win_ptr);
	mlx_destroy_image(game->window->mlx_ptr, game->window->surface);
	free_2d_array(game->world->map, game->world->mx);
	free_ray_array(game->world->rays);
	ft_lstclear(&(game->world->sprites), &destroy_sprite);
	free(game->world);
	free(game->window);
	free(game->keys);
	free(game);
	exit(EXIT_SUCCESS);
}

int			program_exited(void *game)
{
	stop_game((t_god *)game);
	exit(0);
}

int			key_released(int key, void *game)
{
	if (key == 126)
		((t_god*)game)->keys->k_up = 0;
	if (key == 125)
		((t_god*)game)->keys->k_down = 0;
	if (key == 123)
		((t_god*)game)->keys->k_left = 0;
	if (key == 124)
		((t_god*)game)->keys->k_right = 0;
	if (key == 0)
		((t_god*)game)->keys->k_a = 0;
	if (key == 2)
		((t_god*)game)->keys->k_d = 0;
	if (key == 13)
		((t_god*)game)->keys->k_w = 0;
	if (key == 1)
		((t_god*)game)->keys->k_s = 0;
	return (0);
}

int			key_pressed(int key, void *game)
{
	if (key == 12 || key == 53)
		stop_game(game);
	if (key == 126)
		((t_god*)game)->keys->k_up = 1;
	if (key == 125)
		((t_god*)game)->keys->k_down = 1;
	if (key == 123)
		((t_god*)game)->keys->k_left = 1;
	if (key == 124)
		((t_god*)game)->keys->k_right = 1;
	if (key == 0)
		((t_god*)game)->keys->k_a = 1;
	if (key == 2)
		((t_god*)game)->keys->k_d = 1;
	if (key == 13)
		((t_god*)game)->keys->k_w = 1;
	if (key == 1)
		((t_god*)game)->keys->k_s = 1;
	if (key == 49)
		jump(game);
	return (0);
}
