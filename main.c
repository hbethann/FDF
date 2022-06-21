/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:48:42 by hbethann          #+#    #+#             */
/*   Updated: 2022/06/21 20:12:52 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, void *data)
{
	printf("%d", key);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;
	int		i;
	int		j;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	read_file(argv[1], data);
	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			printf("%3d", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
