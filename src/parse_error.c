/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 17:13:51 by sgah              #+#    #+#             */
/*   Updated: 2020/02/10 19:34:08 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		destroy(void *content)
{
	free(content);
}

void			clean_info(t_cub *info)
{
	if (info && info->map_tmp)
		ft_lstclear(&info->map_tmp, &destroy);
	free(info);
}

void			parserror(t_cub *info)
{
	if (info)
		clean_info(info);
	write(1, "Error\n", 6);
	exit(0);
}

int				ft_endfile(char *file)
{
	static char	*type = ".cub";
	int			i;

	i = ft_strlen(file) - 4;
	return (ft_strncmp(type, file + i, 4) == 0);
}
