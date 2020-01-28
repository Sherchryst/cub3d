/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 01:06:59 by sgah              #+#    #+#             */
/*   Updated: 2020/01/28 01:46:26 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			loop_hook(void *param)
{
	if (((t_god *)param)->draw)
		((t_god *)param)->draw(param);
	return (1);
}

void		set_color(unsigned char color[4], unsigned char r,
					unsigned char j, unsigned char b)
{
	color[0] = r;
	color[1] = j;
	color[2] = b;
	color[3] = 0;
}

t_keys		*create_keys(void)
{
	t_keys	*keys;

	if (!(keys = ft_calloc(sizeof(t_keys), 1)))
		return (NULL);
	keys->k_up = 0;
	keys->k_down = 0;
	keys->k_left = 0;
	keys->k_right = 0;
	return (keys);
}

t_window	*create_window(t_cub *info, t_god *game)
{
	t_window	*window;
	int			config[3];

	if (!(window = ft_calloc(sizeof(t_window), 1)))
		return (NULL);
	config[0] = 32;
	config[1] = info->width * 4;
	config[2] = 0;
	window->width = info->width;
	window->height = info->height;
	window->title = "CUB3D";
	window->mlx_ptr = info->mlx_tmp;
	window->win_ptr = mlx_new_window(window->mlx_ptr, info->width,
			info->height, "cub3d");
	window->surface = mlx_new_image(window->mlx_ptr, info->width, info->height);
	window->data = mlx_get_data_addr(window->surface,
			&config[0], &config[1], &config[2]);
	mlx_hook(window->win_ptr, 2, 1L << 0, &key_pressed, game);
	mlx_hook(window->win_ptr, 3, 1L << 1, &key_released, game);
	mlx_hook(window->win_ptr, 17, 1L << 17, &program_exited, game);
	mlx_loop_hook(window->mlx_ptr, &loop_hook, game);
	return (window);
}
