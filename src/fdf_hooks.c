/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:59:28 by dkros             #+#    #+#             */
/*   Updated: 2024/05/16 15:58:50 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_on_key(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W)
		|| mlx_is_key_down(data->mlx, MLX_KEY_UP))
		ft_key_pressed(data, MLX_KEY_UP);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A)
		|| mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		ft_key_pressed(data, MLX_KEY_LEFT);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D)
		|| mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		ft_key_pressed(data, MLX_KEY_RIGHT);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S)
		|| mlx_is_key_down(data->mlx, MLX_KEY_DOWN))
		ft_key_pressed(data, MLX_KEY_DOWN);
	if (mlx_is_key_down(data->mlx, MLX_KEY_1))
		ft_key_pressed(data, MLX_KEY_1);
	if (mlx_is_key_down(data->mlx, MLX_KEY_2))
		ft_key_pressed(data, MLX_KEY_2);
	return ;
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (ydelta > 0)
		ft_sizeupdown(data, 1.005);
	else if (ydelta < 0)
		ft_sizeupdown(data, 0.995);
	if (xdelta > 100)
		xdelta--;
	return ;
}

void	ft_sizeupdown(t_data *data, double factor)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			data->map[j][i].x *= factor;
			data->map[j][i].y *= factor;
			data->map[j][i].z *= factor;
			i++;
		}
		j++;
	}
	mlx_delete_image(data->mlx, data->img);
	draw_frame(data);
	return ;
}

void	ft_key_pressed(t_data *data, enum keys keynum)
{
	if (keynum == MLX_KEY_W || keynum == MLX_KEY_UP)
		rotate_x_axis(data->map, 0.01, data->height, data->width);
	if (keynum == MLX_KEY_A || keynum == MLX_KEY_LEFT)
		rotate_y_axis(data->map, 0.01, data->height, data->width);
	if (keynum == MLX_KEY_D || keynum == MLX_KEY_RIGHT)
		rotate_y_axis(data->map, -0.01, data->height, data->width);
	if (keynum == MLX_KEY_S || keynum == MLX_KEY_DOWN)
		rotate_x_axis(data->map, -0.01, data->height, data->width);
	if (keynum == MLX_KEY_1)
		rotate_z_axis(data->map, 0.01, data->height, data->width);
	if (keynum == MLX_KEY_2)
		rotate_z_axis(data->map, -0.01, data->height, data->width);
	mlx_delete_image(data->mlx, data->img);
	draw_frame(data);
}
