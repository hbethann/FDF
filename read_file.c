/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egor <egor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:45:39 by hbethann          #+#    #+#             */
/*   Updated: 2022/06/29 03:16:50 by egor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	fd = open(file_name, O_RDONLY);
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	return (height);
}

int	get_width(char *file_name)
{
	int	width;
	int	fd;

	fd = open(file_name, O_RDONLY);
	width = word_count(get_next_line(fd), ' ');
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**s_line;
	int		i;
	int		j;
	int		k;

	i = 0;
	s_line = ft_split(line, ' ');
	while (s_line[i])
	{
		z_line[i] = ft_atoi(s_line[i]);
		i++;
	}
	j = 0;
	while (s_line[j])
		free(s_line[j++]);
	free(s_line);
}

void	read_file(char *file_name, t_fdf *data)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(file_name, O_RDONLY);
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * data->width);
		line = get_next_line(fd);
		fill_matrix(data->z_matrix[i], line);
		free(line);
		i++;
	}
	data->z_matrix[i] = NULL;
}
