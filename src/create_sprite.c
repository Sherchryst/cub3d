/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 01:32:47 by sgah              #+#    #+#             */
/*   Updated: 2020/01/30 18:57:14 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			get_nth_pixel_distance(t_god *game, int screen_x)
{
	int target;

	target = ((float)screen_x / (float)game->window->width) * RAYS;
	return (game->world->rays[target]->distance);
}

t_list		*create_sprites_array(t_cub *info)
{
	t_list		*res;
	t_sprite	*sprite;
	int			x;
	int			y;

	res = NULL;
	x = -1;
	while (++x < info->map_width)
	{
		y = -1;
		while (++y < info->map_height)
		{
			if (info->map[x][y] == 2 || info->map[x][y] == 3)
			{
				sprite = ft_calloc(sizeof(t_sprite), 1);
				sprite->x = x;
				sprite->y = y;
				sprite->sprite = sprites(x, y, info);
				ft_lstadd_back(&res, ft_lstnew(sprite));
				sprite = NULL;
			}
		}
	}
	return (res);
}

static void	draw_sprites_while1(t_god *game, t_sprite *sprite)
{
	sprite->dir_x = cos(deg_to_rad(game->world->angle));
	sprite->dir_y = sin(deg_to_rad(game->world->angle));
	sprite->sprite_x = sprite->x - game->world->px;
	sprite->sprite_y = sprite->y - game->world->py;
	sprite->inv_det = 1.0 / (
	game->world->plane_x * sprite->dir_y
		- sprite->dir_x * -game->world->plane_y);
	sprite->transform_x = sprite->inv_det * ((sprite->dir_y *
			sprite->sprite_x) - (sprite->dir_x * sprite->sprite_y));
	sprite->transform_y = sprite->inv_det *
		(game->world->plane_y * sprite->sprite_x +
		game->world->plane_x * sprite->sprite_y);
	sprite->sprite_screen_x = (int)((game->window->width / 2) *
			(1 + sprite->transform_x / sprite->transform_y));
	sprite->sprite_height = abs((int)(game->window->height /
		(sprite->transform_y)));
	sprite->draw_start_y = -sprite->sprite_height / 2 +
		game->window->height / 2 + game->world->pz;
	sprite->draw_end_y = sprite->sprite_height / 2 +
		game->window->height / 2 + game->world->pz;
	sprite->sprite_width = abs((int)(game->window->height /
		(sprite->transform_y)));
	sprite->draw_start_x = -sprite->sprite_width / 2 + sprite->sprite_screen_x;
	sprite->draw_end_x = sprite->sprite_width / 2 + sprite->sprite_screen_x;
}

static void	draw_sprites_while2(t_god *game, t_sprite *sprite, int x, int y)
{
	sprite->texture_x = ((float)(x - sprite->draw_start_x) /
			(float)(sprite->draw_end_x - sprite->draw_start_x)) *
		sprite->sprite->width;
	sprite->texture_y = (float)(y - sprite->draw_start_y) /
		(float)(sprite->draw_end_y - sprite->draw_start_y) *
		sprite->sprite->height;
	if (y < 0 || y >= (int)game->window->height
			|| x < 0 || x >= (int)game->window->width)
		return ;
	if (sprite->texture_x < 0 || sprite->texture_y < 0)
		return ;
	if (sprite->texture_x >= sprite->sprite->width ||
		sprite->texture_y >= sprite->sprite->height)
		return ;
	get_pixel_color(sprite->sprite, sprite->texture_x,
				sprite->texture_y, sprite->color);
	if (sprite->color[3] != 255)
		draw_pixel(game->window, x, y, sprite->color);
}

void		draw_sprites(t_god *game)
{
	t_list		*ptr;
	t_sprite	*sprite;
	int			x;
	int			y;

	ptr = game->world->sprites;
	while (ptr)
	{
		draw_sprites_while1(game, (sprite = ptr->content));
		x = sprite->draw_start_x - 1;
		sprite->draw_start_y = sprite->draw_start_y < 0
			? 0 : sprite->draw_start_y;
		while (++x < sprite->draw_end_x)
		{
			if (sprite->transform_y > 0 && x > 0 &&
				x < (int)game->window->width &&
				sprite->transform_y < get_nth_pixel_distance(game, x))
			{
				y = sprite->draw_start_y - 1;
				while (++y < sprite->draw_end_y)
					draw_sprites_while2(game, sprite, x, y);
			}
		}
		ptr = ptr->next;
	}
}
