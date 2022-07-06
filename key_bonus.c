/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egor <egor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 02:13:14 by egor              #+#    #+#             */
/*   Updated: 2022/07/05 17:40:12 by egor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	projection(int a)
{
	if (a == 1)
		return (0);
	return (1);
}

void	depth(int key, t_fdf *data)
{
	if (key == 0)
		data->depth += 1;
	if (key == 1)
		data->depth -= 1;
}

int	press(int key, t_fdf *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (key == 53)
		exit(0);
	if (key == 12)
		data->zoom += 1;
	if (key == 13)
		data->zoom -= 1;
	if (key == 124)
		data->shift_x += 20;
	if (key == 123)
		data->shift_x -= 20;
	if (key == 125)
		data->shift_y += 20;
	if (key == 126)
		data->shift_y -= 20;
	if (key == 7)
		data->anglex += 0.1;
	if (key == 6)
		data->angley += 0.1;
	depth(key, data);
	if (key == 35)
		data->p = projection(data->p);
	draw(data);
	return (0);
}	

int	mouseh(int button, int x, int y, t_fdf *data)
{
	data->color = 0;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	if (button == 4)
		data->zoom += 1;
	if (button == 5)
		data->zoom -= 1;
	if (button == 1)
	{
		data->shift_x = x;
		data->shift_y = y;
	}
	draw(data);
	return (0);
}
