/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 02:05:21 by sgah              #+#    #+#             */
/*   Updated: 2020/01/31 16:03:36 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_texture	*load_texture(void *mlx_ptr, char *filename)
{
	t_texture	*res;
	int			config[3];
	int			fd;

	if ((fd = open(filename, O_RDONLY)) < 0)
		parserror(NULL);
	close(fd);
	res = ft_calloc(sizeof(t_texture), 1);
	res->ptr = mlx_xpm_file_to_image(mlx_ptr, filename,
			&(res->width), &(res->height));
	if (!res->ptr)
		return (res);
	config[0] = 32;
	config[1] = res->width * 4;
	config[2] = 0;
	res->data = mlx_get_data_addr(res->ptr,
			&config[0], &config[1], &config[2]);
	return (res);
}

void		destroy_texture(void *mlx_ptr, t_texture *texture)
{
	mlx_destroy_image(mlx_ptr, texture->ptr);
	free(texture);
}

void		get_pixel_color(t_texture *texture, int x, int y,
		unsigned char *result)
{
	int index;
	int i;

	if (x >= texture->width || y >= texture->height)
		return ;
	if (x < 0 || y < 0)
		return ;
	index = (x + y * texture->width) * 4;
	i = -1;
	while (++i < 4)
		result[i] = texture->data[index + i];
}
