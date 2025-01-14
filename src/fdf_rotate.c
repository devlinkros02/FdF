/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 20:36:45 by dkros             #+#    #+#             */
/*   Updated: 2024/05/16 15:56:41 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	rotate_x_axis(t_point **map, double angle, int height, int width)
{
	int		i;
	int		j;
	double	prev_y;

	i = 0;
	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			prev_y = map[j][i].y;
			map[j][i].y = prev_y * cos(angle) - map[j][i].z * sin(angle);
			map[j][i].z = prev_y * sin(angle) + map[j][i].z * cos(angle);
			i++;
		}
		j++;
	}
	return ;
}

void	rotate_y_axis(t_point **map, double angle, int height, int width)
{
	int		i;
	int		j;
	double	prev_x;

	i = 0;
	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			prev_x = map[j][i].x;
			map[j][i].x = prev_x * cos(angle) + map[j][i].z * sin(angle);
			map[j][i].z = -prev_x * sin(angle) + map[j][i].z * cos(angle);
			i++;
		}
		j++;
	}
	return ;
}

void	rotate_z_axis(t_point **map, double angle, int height, int width)
{
	int		i;
	int		j;
	double	prev_x;

	i = 0;
	j = 0;
	while (j < height)
	{
		i = 0;
		while (i < width)
		{
			prev_x = map[j][i].x;
			map[j][i].x = prev_x * cos(angle) - map[j][i].y * sin(angle);
			map[j][i].y = prev_x * sin(angle) + map[j][i].y * cos(angle);
			i++;
		}
		j++;
	}
	return ;
}
