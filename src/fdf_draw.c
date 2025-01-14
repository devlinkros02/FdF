/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:54:53 by dkros             #+#    #+#             */
/*   Updated: 2024/05/16 15:58:32 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	prep_draw_line(t_data *data)
{
	int	dx;
	int	sx;
	int	sy;

	dx = abs(data->c.x2 - data->c.x1);
	data->c.dy = abs(data->c.y2 - data->c.y1);
	if (data->c.x1 < data->c.x2)
		sx = 1;
	else
		sx = -1;
	if (data->c.y1 < data->c.y2)
		sy = 1;
	else
		sy = -1;
	draw_line(data, dx, sx, sy);
	return ;
}

void	draw_line(t_data *data, int dx, int sx, int sy)
{
	int	e2;
	int	err;

	if (dx > data->c.dy)
		err = dx / 2;
	else
		err = -(data->c.dy) / 2;
	while (1)
	{
		my_pixel_put(data, (data->c.x1 + 100), (data->c.y1 + 75));
		if (data->c.x1 == data->c.x2 && data->c.y1 == data->c.y2)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= data->c.dy;
			data->c.x1 += sx;
		}
		if (e2 < data->c.dy)
		{
			err += dx;
			data->c.y1 += sy;
		}
	}
	return ;
}

void	my_pixel_put(t_data *data, int x, int y)
{
	if (x > 0 && x < 1000 && y > 0 && y < 750)
	{
		mlx_put_pixel(data->img, x, y, data->color);
	}
	return ;
}

void	draw_horizontal(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < data->height)
	{
		while (i < (data->width - 1))
		{
			data->c.x1 = data->map[j][i].x;
			data->c.y1 = data->map[j][i].y;
			data->c.x2 = data->map[j][i + 1].x;
			data->c.y2 = data->map[j][i + 1].y;
			prep_draw_line(data);
			i++;
		}
		i = 0;
		j++;
	}
	return ;
}

void	draw_vertical(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < (data->height - 1))
	{
		while (i < data->width)
		{
			data->c.x1 = data->map[j][i].x;
			data->c.y1 = data->map[j][i].y;
			data->c.x2 = data->map[j + 1][i].x;
			data->c.y2 = data->map[j + 1][i].y;
			prep_draw_line(data);
			i++;
		}
		i = 0;
		j++;
	}
	return ;
}
