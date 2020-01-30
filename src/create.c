/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:48:19 by sgah              #+#    #+#             */
/*   Updated: 2020/01/30 08:27:13 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_world(t_world *world, t_cub *info)
{
	world->map = info->map;
	world->mx = info->map_width;
	world->my = info->map_height;
	world->px = info->px;
	world->py = info->py;
	world->pz = 0;
	world->plane_x = (info->orientation == 'E'
		|| info->orientation == 'W' ? 0.0 : 0.40);
	world->plane_y = (info->orientation == 'E'
			|| info->orientation == 'W' ? 0.40 : 0.0);
	if (info->orientation == 'E' || info->orientation == 'S')
	{
		world->plane_x *= -1;
		world->plane_y *= -1;
	}
	world->jump_time = -1;
	world->e = info->e;
	world->s = info->s;
	world->o = info->w;
	world->n = info->n;
	world->sprite = info->sprite;
	world->sprite2 = info->sprite2;
	world->sprites = create_sprites_array(info);
}

t_world		*create_world(t_cub *info)
{
	t_world	*world;

	if (!(world = ft_calloc(sizeof(t_world), 1)))
		return (NULL);
	world->angle = 0;
	if (info->orientation == 'N')
		world->angle = -90;
	if (info->orientation == 'W')
		world->angle = 180;
	if (info->orientation == 'S')
		world->angle = 90;
	if (!(world->rays = create_ray_array(world->angle)))
		return (NULL);
	init_world(world, info);
	set_color(world->color_ceil, info->ceil[0], info->ceil[1], info->ceil[2]);
	set_color(world->color_ground, info->floor[0],
		info->floor[1], info->floor[2]);
	return (world);
}

t_god		*creation(t_cub *info)
{
	t_god *create;

	if (!(create = ft_calloc(sizeof(t_god), 1)))
		return (NULL);
	create->world = create_world(info);
	create->keys = create_keys();
	create->draw = NULL;
	create->window = create_window(info, create);
	FMOD_System_Create(&(create->system));
	FMOD_System_Init(create->system, 2, FMOD_INIT_NORMAL, NULL);
	FMOD_System_CreateSound(create->system, "res/jump.wav", FMOD_CREATESAMPLE, 0, &(create->j));
	if (info->px == -42)
		parserror(NULL);
	return (create);
}
