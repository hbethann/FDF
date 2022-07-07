/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:45:39 by hbethann          #+#    #+#             */
/*   Updated: 2022/07/07 05:54:07 by hbethann         ###   ########.fr       */
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
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	return (height);
}

int	get_width(char *file_name, int check)
{
	int		width;
	int		fd;
	char	*line;

	if (check == 1)
	{
		fd = open(file_name, O_RDONLY);
		line = get_next_line(fd);
		width = word_count(line, ' ');
		free (line);
	}
	else
		width = word_count(file_name, ' ');
	return (width);
}

void	fill_matrix(int *nums, int *color, char *line)
{
	char	**s_line;
	int		i;
	int		j;
	int		k;

	i = 0;
	s_line = ft_split(line, ' ');
	while (s_line[i])
	{
		nums[i] = ft_atoi(s_line[i]);
		k = 0;
		while (s_line[i][k] != ',' && s_line[i][k])
			k++;
		if (s_line[i][k++] == ',')
			color[i] = ato_h(&s_line[i][k]);
		else
			color[i] = ft_atoi("0");
		i++;
	}
	j = 0;
	while (s_line[j])
		free(s_line[j++]);
	free(s_line);
}

int	check_dir(char *filename)
{
	int		nb;
	int		fd;
	char	*buf;

	fd = open(filename, O_RDONLY);
	buf = malloc(sizeof(char) * 2);
	nb = read(fd, buf, 2);
	if (nb <= 0)
		return (1);
	free(buf);
	return (0);
}

void	read_file(char *file_name, t_fdf *data)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(file_name, O_RDONLY);
	if (fd < 0 || check_dir(file_name))
		invalid_file();
	data->height = get_height(file_name);
	data->width = get_width(file_name, 1);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	data->color_map = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * data->width);
		data->color_map[i] = (int *)malloc(sizeof(int) * data->width);
		line = get_next_line(fd);
		if (data->width != get_width(line, 0))
			invalid_file();
		fill_matrix(data->z_matrix[i], data->color_map[i], line);
		free(line);
		i++;
	}
	data->z_matrix[i] = NULL;
}
