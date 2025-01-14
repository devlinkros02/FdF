/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:10:19 by dkros             #+#    #+#             */
/*   Updated: 2024/05/29 10:20:11 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*read_fdf(int fd)
{
	char	*buffer;
	char	*remainder;
	int		bytesread;

	remainder = NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytesread = 1;
	while (bytesread > 0)
	{
		bytesread = read(fd, buffer, BUFFER_SIZE);
		if (bytesread > 0)
		{
			buffer[bytesread] = '\0';
			remainder = ft_strjoinn(remainder, buffer);
			if (!remainder)
				return (free_func(&buffer));
		}
	}
	free_func(&buffer);
	if (bytesread < 0)
		return (free_func(&remainder));
	return (remainder);
}

int	get_map_height(char *file_content)
{
	int	i;
	int	height;

	i = 0;
	height = 1;
	while (file_content[i] != '\0')
	{
		if (file_content[i] == '\n' && file_content[i + 1])
			height++;
		i++;
	}
	return (height);
}

int	get_map_width(char *file_content)
{
	int	i;
	int	width;

	i = 0;
	width = 1;
	while (file_content[i] != '\0' && file_content[i] != '\n')
	{
		if (file_content[i] == ' ' && (ft_isdigit(file_content[i + 1])
				|| file_content[i + 1] == '-'))
		{
			while (file_content[i] == ' ')
				i++;
			width++;
		}
		i++;
	}
	return (width);
}

int	malloc_map(t_data *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	data->map = malloc(data->height * sizeof(t_point *));
	if (!data->map)
		data->map = NULL;
	while (i < data->height)
	{
		data->map[i] = malloc(data->width * sizeof(t_point));
		if (!data->map[i])
		{
			while (j < i)
			{
				free(data->map[j++]);
			}
			free(data->map);
			return ((data->map = NULL), 1);
		}
		i++;
	}
	set_scale(data);
	set_coordinates(data);
	return (0);
}
