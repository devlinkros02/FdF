/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 00:49:01 by dkros             #+#    #+#             */
/*   Updated: 2024/05/20 10:54:32 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point	**set_coordinates(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			k = set_value_z(data, i, j, k);
			i++;
		}
		j++;
	}
	return (data->map);
}

int	set_value_z(t_data *data, int i, int j, int k)
{
	int	current_number;
	int	sign;

	sign = 1;
	current_number = 0;
	while (data->file_content[k] == ' ' || data->file_content[k] == '\n')
		k++;
	while (data->file_content[k] != '\0')
	{
		if (data->file_content[k] == '-')
			sign = -1;
		else if (data->file_content[k] >= '0' && data->file_content[k] <= '9')
			current_number = (current_number * 10)
				+ (data->file_content[k] - '0');
		else if (data->file_content[k] == ' ' || data->file_content[k] == '\n'
			|| data->file_content[k + 1] == '\0')
		{
			data->map[j][i].z = current_number * sign * data->scale;
			return (k + 1);
		}
		k++;
	}
	return (k);
}

void	set_scale(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			data->map[j][i].x = (double)(i * data->scale);
			data->map[j][i].y = (double)(j * data->scale);
			i++;
		}
		j++;
	}
	return ;
}
