/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:32:41 by dkros             #+#    #+#             */
/*   Updated: 2024/05/29 10:02:59 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include "MLX42/MLX42.h"
# include <stdlib.h>
# include "Libft/libft.h"
# include <fcntl.h>
# include <stdarg.h>
# include <math.h>

# define SCREEN_WIDTH 1000
# define SCREEN_HEIGHT 750

typedef struct s_line_data_t
{
	int	x1;
	int	x2;
	int	y1;
	int	y2;
	int	dy;
}	t_line_data;

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
}	t_point;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*img;
	int32_t		x;
	int32_t		y;
	int32_t		height;
	int32_t		width;
	int32_t		scale;
	t_point		**map;
	int32_t		color;
	t_line_data	c;
	char		*file_content;
	double		ang_x;
	double		ang_y;
	double		ang_z;
}	t_data;

void		ft_cleanup(t_data *data);
char		*get_sample(char *file);
int			is_rect(char *file_content);
void		ft_cleanup_rest(t_data *data);
int			check_format(char *content);
void		ft_on_key(void *param);
void		prep_draw_line(t_data *data);
void		draw_line(t_data *data, int dx, int sx, int sy);
int			get_map_width(char *file_content);
int			get_map_height(char *file_content);
char		*read_fdf(int fd);
void		set_data_values(t_data *data);
void		draw_horizontal(t_data *data);
void		draw_vertical(t_data *data);
mlx_image_t	*draw_frame(t_data *data);
int			malloc_map(t_data *data);
t_point		**set_coordinates(t_data *data);
int			set_value_z(t_data *data, int i, int j, int k);
void		set_scale(t_data *data);
void		rotate_x_axis(t_point **map, double angle, int height, int width);
void		rotate_y_axis(t_point **map, double angle, int height, int width);
void		rotate_z_axis(t_point **map, double angle, int height, int width);
void		ft_key_pressed(t_data *data, enum keys keynum);
void		ft_sizeupdown(t_data *data, double factor);
void		my_pixel_put(t_data *data, int x, int y);
void		my_scrollhook(double xdelta, double ydelta, void *param);

#endif