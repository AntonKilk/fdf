/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:52:56 by akilk             #+#    #+#             */
/*   Updated: 2022/03/11 06:54:07 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <mlx.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_fdf
{
	int		width;
	int		height;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	int		para;
	int		**z_matrix;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_fdf;

typedef struct s_draw
{
	int	step_fst;
	int	step_snd;
	int	fst;
	int	fst_end;
	int	snd;
	int	snd_end;
}			t_draw;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}		t_point;

typedef struct s_screen_point
{
	int	x;
	int	y;
}	t_screen_point;

int		main(int argc, char **argv);
int		**read_fdf(int fd, t_fdf *data);
void	bresenham(t_screen_point *sp1, t_screen_point *sp2, t_fdf *data);
void	draw(t_fdf *data);

#endif
