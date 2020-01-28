/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 05:16:23 by sgah              #+#    #+#             */
/*   Updated: 2020/01/28 05:21:17 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_pixel(t_window *window, unsigned int x, unsigned int y)
{
	int	ptr;

	ptr = *(int*)(window->data
			+ (4 * (int)window->width * ((int)window->height - 1 - y))
			+ (4 * x));
	return ((ptr & 0xFF0000) | (ptr & 0x00FF00) | (ptr & 0x0000FF));
}

void	int_to_char(int n, unsigned char *src)
{
	src[0] = (unsigned char)(n);
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}

static void	bmp_header(t_god *game, int fd, int filesize)
{
	int						i;
	unsigned char			data[54];

	i = -1;
	while (++i < 54)
		data[i] = 0;
	data[0] = (unsigned char)('B');
	data[1] = (unsigned char)('M');
	int_to_char(filesize, data + 2);
	data[10] = (unsigned char)(54);
	data[14] = (unsigned char)(40);
	int_to_char(game->window->width, data + 18);
	int_to_char(game->window->height, data + 22);
	data[26] = (unsigned char)(1);
	data[28] = (unsigned char)(24);
	write(fd, data, 54);
}

static void	bmp_pixels(t_god *game, int fd, int pad)
{
	unsigned char	zero[3];
	unsigned int	i;
	unsigned int	j;
	int				color;

	i = -1;
	while (++i < 3)
		zero[i] = 0;
	i = 0;
	while (i < game->window->height)
	{
		j = 0;
		while (j < game->window->width)
		{
			color = get_pixel(game->window, j, i);
			write(fd, &color, 3);
			write(fd, &zero, pad);
			j++;
		}
		i++;
	}
}

int			screenshot(t_god *game)
{
	int			fd;
	int			filesize;
	int			pad;

	pad = (4 - (game->window->width * 3) % 4) % 4;
	filesize = 54 + (3 * (game->window->width + pad) * game->window->height);
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT |
					O_TRUNC | O_APPEND, 0666)) < 0)
		return (0);
	bmp_header(game, fd, filesize);
	bmp_pixels(game, fd, pad);
	close(fd);
	return (1);
}
