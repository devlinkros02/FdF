/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkros <dkros@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:06:35 by dkros             #+#    #+#             */
/*   Updated: 2024/05/20 11:14:51 by dkros            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	check_format(char *file)
{
	int		i;
	char	*content;

	i = 0;
	content = get_sample(file);
	if (!content)
		return (0);
	while (content[i] != '\0')
	{
		if (!(ft_isdigit(content[i])) && !(content[i] == ' ')
			&& !(content[i] == '\n') && !(content[i] == '-'))
			return (free_func(&content), 0);
		i++;
	}
	free_func(&content);
	return (1);
}

char	*get_sample(char *file)
{
	int		fd;
	int		bytesread;
	char	*content;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	content = malloc(1000 * sizeof(char));
	bytesread = read(fd, content, 999);
	if (bytesread < 0)
	{
		close(fd);
		return (free_func(&content));
	}
	content[bytesread] = '\0';
	close(fd);
	return (content);
}

int	is_rect(char *file_content)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	j = 1;
	width = 1;
	while (file_content[i] != '\0')
	{
		if (file_content[i] == '\n')
		{
			if (width - (get_map_width(file_content) * j++) != 0)
				return (0);
			width++;
		}
		if (file_content[i] == ' ' && (ft_isdigit(file_content[i + 1])
				|| file_content[i + 1] == '-'))
		{
			while (file_content[i] == ' ')
				i++;
			width++;
		}
		i++;
	}
	return (1);
}
