/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:27:39 by dkros             #+#    #+#             */
/*   Updated: 2024/05/29 10:52:14 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_cleanup(t_data *data)
{
	int	i;

	i = 0;
	if (!data)
		return ;
	if (data->map)
	{
		while (i < data->height)
			free(data->map[i++]);
		free(data->map);
		data->map = NULL;
	}
	ft_cleanup_rest(data);
}

void	ft_cleanup_rest(t_data *data)
{
	if (data->file_content)
	{
		free(data->file_content);
		data->file_content = NULL;
	}
	if (data->img)
	{
		mlx_delete_image(data->mlx, data->img);
		data->img = NULL;
	}
	if (data->mlx)
	{
		mlx_terminate(data->mlx);
		data->mlx = NULL;
	}
}

mlx_image_t	*draw_frame(t_data *data)
{
	data->img = mlx_new_image(data->mlx, 1000, 750);
	if (!data->img)
		return (NULL);
	draw_horizontal(data);
	draw_vertical(data);
	mlx_image_to_window(data->mlx, data->img, 0, 0);
	return (data->img);
}

void	set_data_values(t_data *data)
{
	data->height = get_map_height(data->file_content);
	data->width = get_map_width(data->file_content);
	if ((800 / data->width) < (600 / data->height))
		data->scale = (800 / data->width);
	if ((800 / data->width) > (600 / data->height))
		data->scale = (600 / data->height);
	data->ang_x = 0;
	data->ang_y = 0;
	data->ang_z = 0;
	data->color = 0xAAAAAAFF;
	if (malloc_map(data) == 1)
	{
		free_func(&data->file_content);
		return ;
	}
	data->mlx = mlx_init(SCREEN_WIDTH, SCREEN_HEIGHT, "fdf", false);
	if (!data->mlx)
	{
		ft_cleanup(data);
		return ;
	}
	data->img = draw_frame(data);
	if (!data->img)
		ft_cleanup(data);
	return ;
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (argc != 2 || fd == -1 || !check_format(argv[1]))
	{
		ft_printf("Invalid filename or file not compatible\n");
		return (close(fd), 1);
	}
	data.file_content = (read_fdf(fd));
	if (!is_rect(data.file_content))
	{
		ft_printf("Map not rectangular");
		close(fd);
		return (free_func(&data.file_content), 1);
	}
	set_data_values(&data);
	if (data.mlx)
	{
		mlx_loop_hook(data.mlx, ft_on_key, &data);
		mlx_scroll_hook(data.mlx, &my_scrollhook, &data);
		mlx_loop(data.mlx);
	}
	ft_cleanup(&data);
	return (close(fd), 0);
}
