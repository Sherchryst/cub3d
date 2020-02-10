/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 03:29:22 by sgah              #+#    #+#             */
/*   Updated: 2020/02/10 21:06:11 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			main(int ac, char **av)
{
	t_cub		*info;
	t_god		*create;

	if (ac > 3 || ac < 2 || !ft_endfile(av[1]))
		parserror(NULL);
	info = parser(av[1]);
	create = creation(info);
	clean_info(info);
	if (ac == 3)
	{
		if (!ft_strncmp(av[2], "-save", 5))
			create->screenshot = 1;
		else
			parserror(NULL);
	}
	create->draw = &draw_game;
	mlx_loop(create->window->mlx_ptr);
	stop_game(create);
	return (0);
}
