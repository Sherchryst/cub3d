/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 03:29:22 by sgah              #+#    #+#             */
/*   Updated: 2020/01/28 03:39:36 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int ac, char **av)
{
	t_cub	*info;
	t_god	*create;

	info = parser(av[1]);
	create = creation(info);
	if (ac == 3 && !ft_strncmp(av[2], "-save", 5))
		create->screenshot = 1;
	clean_info(info);
	create->draw = &draw_game;
	mlx_loop(create->window->mlx_ptr);
	stop_game(create);
	return (0);
}
