/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 03:52:33 by sgah              #+#    #+#             */
/*   Updated: 2020/01/24 18:02:29 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_h

# include <unistd.h>
# include <fcntl.h>
# include "mlx.h"

typedef struct		s_cub
{
		void		*mlx_tmp;
	t_exture		*e;
	t_exture		*w;
	t_exture		*n;
	t_exture		*s;
	t_list			*map_tmp;
	int				**map;
	int				width;
	int				height;
	int				map_width;
	int				map_height;
	int				px;
	int				py;
	char			orientation;
	unsigned char	ceil[3];
	unsigned char	floor[3];
	int				map_started;
}					t_cub;

void				parsing(char *line, t_cub *info);
t_cub				parser(char *file);
void				clean_info(t_cub *info);
void				parserror(t_cub *info);


#endif
