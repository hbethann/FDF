/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egor <egor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:30:47 by hbethann          #+#    #+#             */
/*   Updated: 2022/07/02 19:30:31 by egor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdio.h>
# include <math.h>
# define WIN_WIDTH 2560
# define WIN_HEIGHT 1600

typedef struct fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		color;
	int		p;
	int		**color_map;
	int		zoom;
	int		shift_x;
	int		shift_y;
	int		depth;
	float	x;
	float	x1;
	float	y;
	float	y1;
	float	anglex;
	float	angley;
	void	*xpm_img;
	void	*mlx_ptr;
	void	*win_ptr;	
}				t_fdf;

void	read_file(char *file_name, t_fdf *data);
int		get_width(char *file_name, int check);
void	fill_matrix(int *nums, int *color, char *line);
int		get_height(char *file_name);
void	menu(t_fdf *data);
float	max(float a, float b);
void	invalid_file(void);
int		ato_h(char *hex);
void	draw(t_fdf *data);
void	set_xy(t_fdf *data, int x, int y, int check);
void	bresenham(t_fdf *data);
void	controler(t_fdf *data);
void	isometric(float *x, float *y, int z, t_fdf	*data);
int		press(int key, t_fdf *data);
int		projection(int a);
void	depth(int key, t_fdf *data);
int		mouseh(int button, int x, int y, t_fdf *data);

#endif