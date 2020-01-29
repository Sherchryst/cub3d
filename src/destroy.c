/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 02:10:41 by sgah              #+#    #+#             */
/*   Updated: 2020/01/29 05:24:20 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_2d_array(int **array, int x)
{
	while (x--)
		free(array[x]);
	free(array);
}

void		destroy_sprite(void *content)
{
	free(content);
}


void		free_ray_array(t_ray **rays)
{
	int i;

	i = RAYS;
	while (i--)
		free(rays[i]);
	free(rays);
}
