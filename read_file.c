/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:45:39 by hbethann          #+#    #+#             */
/*   Updated: 2022/06/21 20:27:17 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *file_name)
{
	int	fd;
	int	height;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	while (get_next_line(fd))
		height++;
	close(fd);
	return (height);
}

int	get_width(char *file_name)
{
	int	width;
	int	fd;

	fd = open(file_name, O_RDONLY, 0);
	width = word_count(get_next_line(fd), ' ');
	close (fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		i++;
		printf("%d", z_line[i]);
	}
	free(nums);
}

void	read_file(char *file_name, t_fdf *data)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(file_name, O_RDONLY, 0);
	line = get_next_line(fd);
	data->height = get_height(file_name);
	data->width = get_width(file_name);
	data->z_matrix = (int **)malloc(sizeof(int *) * (data->height + 1));
	i = 0;
	while (i <= data->height)
		data->z_matrix[i++] = (int *)malloc(sizeof(int) * (data->width + 1));
	i = 0;
	while (i < data->height)
	{
		fill_matrix(data->z_matrix[i], line);
		line = get_next_line(fd);
		free(line);
		i++;
	}
	data->z_matrix[i] = NULL;
	close (fd);
}
