/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egor <egor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:30:47 by hbethann          #+#    #+#             */
/*   Updated: 2022/06/30 13:30:41 by egor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdio.h>
# include <math.h>
# define WIN_WIDTH 2800
# define WIN_HEIGHT 1800

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
int		get_width(char *file_name);
void	fill_matrix(int *z_line, char *line);
int		get_height(char *file_name);
void	menu(t_fdf *data);
float	max(float a, float b);
void	invalid_file(void);
int		ato_h(char *hex);

#endif