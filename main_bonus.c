/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:48:42 by hbethann          #+#    #+#             */
/*   Updated: 2022/07/06 22:34:29 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_fdf	data;

	if (argc != 2)
	{
		ft_putstr_fd ("Usage : ./fdf path/to/map.fdf", 0);
		return (0);
	}
	data.shift_x = WIN_WIDTH / 3 - 125;
	data.shift_y = WIN_HEIGHT / 3 - 500;
	data.p = 1;
	data.anglex = 0.523599;
	data.angley = 0.523599;
	data.depth = 1;
	read_file(argv[1], &data);
	if (data.height < 100 && data.width < 100)
		data.zoom = 15;
	else
		data.zoom = 5;
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fdf");
	draw(&data);
	mlx_key_hook(data.win_ptr, press, &data);
	mlx_mouse_hook(data.win_ptr, mouseh, &data);
	mlx_loop(data.mlx_ptr);
}
