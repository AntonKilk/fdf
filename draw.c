/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 13:36:39 by akilk             #+#    #+#             */
/*   Updated: 2022/03/11 07:05:03 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

/*
** Apply zoom.
** Apply parallel or isometric formulas - change between 'i' and 'p'.
** Apply shift - move with arrows.
*/

static void	isometric(t_point *p, t_screen_point *sp, t_fdf *data)
{
	float	x;
	float	y;
	float	z;

	x = p->x;
	y = p->y;
	z = p->z;
	if (data->para == 1)
	{
		sp->x = data->zoom * x + data->shift_x;
		sp->y = data->zoom * y + data->shift_y;
	}
	else
	{
		sp->x = data->zoom * (x - y) * cos(0.6) + data->shift_x;
		sp->y = data->zoom * (x + y) * sin(0.4) - z + data->shift_y;
	}
}

/*
** Apply color to non-empty z cells
** Apply Isometry.
** Call Bresenham.
*/

static void	apply_coord(t_point *p1, t_point *p2, t_fdf *data)
{
	t_screen_point	sp1;
	t_screen_point	sp2;

	if (p1->z || p2->z)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
	isometric(p1, &sp1, data);
	isometric(p2, &sp2, data);
	bresenham(&sp1, &sp2, data);
}

static void	fill_point_data(t_point *p, int x, int y, int z)
{
	p->x = x;
	p->y = y;
	p->z = z;
}

/*
** Draw the 2D matrix using height and width from input file.
*/

void	draw(t_fdf *data)
{
	t_point	p1;
	t_point	p2;
	int		i;
	int		j;

	j = -1;
	while (++j < data->height)
	{
		i = -1;
		while (++i < data->width)
		{
			fill_point_data(&p1, i, j, data->z_matrix[j][i]);
			if (i < data->width - 1)
			{
				fill_point_data(&p2, i + 1, j, data->z_matrix[j][i + 1]);
				apply_coord(&p1, &p2, data);
			}
			if (j < data->height - 1)
			{
				fill_point_data(&p2, i, j + 1, data->z_matrix[j + 1][i]);
				apply_coord(&p1, &p2, data);
			}
		}
	}
}
