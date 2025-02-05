/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 03:39:23 by sgah              #+#    #+#             */
/*   Updated: 2020/01/29 21:10:00 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# define MAX_OPEN 4096
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int				get_next_line(int fd, char **line);
void			my_ft_strjoin(char **s1, char *s2, int s2_size);
char			*first_line(const char *str);
void			cut(char **str);
unsigned int	count_bl(const char *str);

#endif
