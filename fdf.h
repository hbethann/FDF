/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 18:30:47 by hbethann          #+#    #+#             */
/*   Updated: 2022/06/21 17:28:55 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdio.h>

typedef struct fdf
{
	int		width;
	int		height;
	int		**z_matrix;

	void	*mlx_ptr;
	void	*win_ptr;	
}				t_fdf;

void	read_file(char *file_name, t_fdf *data);
#endif