/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egor <egor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:36:10 by egor              #+#    #+#             */
/*   Updated: 2022/07/02 19:52:02 by egor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z, t_fdf	*data)
{
	float	a;

	a = *x;
	*x = ((*x - *y)) * cos(data->anglex);
	*y = (a + *y) * sin(data->angley) - z;
}

void	controler(t_fdf *data)
{
	int	z;
	int	z1;

	z = data->z_matrix[(int)data->y][(int)data->x] * data->depth;
	z1 = data->z_matrix[(int)data->y1][(int)data->x1] * data->depth;
	data->x *= data->zoom;
	data->x1 *= data->zoom;
	data->y *= data->zoom;
	data->y1 *= data->zoom;
	if (data->p == 1)
	{
		isometric(&data->x, &data->y, z, data);
		isometric(&data->x1, &data->y1, z1, data);
	}
	data->x += data->shift_x;
	data->x1 += data->shift_x;
	data->y += data->shift_y;
	data->y1 += data->shift_y;
}

void	bresenham(t_fdf *data)
{
	float	x_step;
	float	y_step;
	float	m_v;

	controler(data);
	x_step = data->x1 - data->x;
	y_step = data->y1 - data->y;
	m_v = max(abs((int)x_step), abs((int)y_step));
	x_step /= m_v;
	y_step /= m_v;
	while ((int)(data->x - data->x1) || (int)(data->y - data->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
			data->x, data->y, data->color);
		data->x += x_step;
		data->y += y_step;
	}
}

void	set_xy(t_fdf *data, int x, int y, int check)
{
	if (check == 0)
	{
		data->x = x;
		data->x1 = x + 1;
		data->y = y;
		data->y1 = y;
	}
	if (check == 1)
	{
		data->x = x;
		data->x1 = x;
		data->y = y;
		data->y1 = y +1;
	}
	bresenham(data);
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	menu(data);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->color = data->color_map[y][x];
			if (x < data->width - 1)
				set_xy(data, x, y, 0);
			if (y < data->height - 1)
				set_xy(data, x, y, 1);
			x++;
		}
		y++;
	}
}
