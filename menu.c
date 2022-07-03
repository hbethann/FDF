/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egor <egor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:22:10 by egor              #+#    #+#             */
/*   Updated: 2022/07/02 13:30:48 by egor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ato_h(char *hex)
{
	int	length;
	int	base;
	int	demical;

	length = ft_strlen(hex) - 1;
	base = 1;
	demical = 0;
	while (length >= 0)
	{
		if (hex[length] >= '0' && hex[length] <= '9')
			demical += (hex[length] - 48) * base;
		if (hex[length] >= 'A' && hex[length] <= 'F')
			demical += (hex[length] - 55) * base;
		if (hex[length] >= 'a' && hex[length] <= 'f')
			demical += (hex[length] - 87) * base;
		base *= 16;
		length--;
	}
	return (demical);
}

void	invalid_file(void)
{
	ft_putstr_fd("invalid file\n", 1);
	exit(1);
}

float	max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	menu(t_fdf *data)
{
	int	wigth;
	int	heigth;

	data->xpm_img = mlx_xpm_file_to_image(data->mlx_ptr,
			"pic.xpm", &wigth, &heigth);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->xpm_img, 0, 0);
}
