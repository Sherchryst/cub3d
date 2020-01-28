/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgah <sgah@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 01:55:51 by sgah              #+#    #+#             */
/*   Updated: 2020/01/28 02:51:49 by sgah             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	deg_to_rad(float a)
{
	return (a / 360 * (2 * M_PI));
}

float	dist(float a, float b, float x, float y)
{
	return (sqrt(pow(a - x, 2) + pow(b - y, 2)));
}

int		max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

float	mod(float a, float b)
{
	a -= b * fabs((float)((int)(a / b)));
	if (a >= 0)
		return (a);
	return (a + b);
}
