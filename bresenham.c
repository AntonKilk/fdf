/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 06:33:59 by akilk             #+#    #+#             */
/*   Updated: 2022/03/10 11:12:52 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* x = fst. x_step is bigger. */
void	bresenham_x(t_draw *d, t_fdf *data)
{
	int	dir;
	int	p;
	int	i;

	dir = 1;
	if (d->snd > d->snd_end)
		dir = -1;
	p = 2 * d->step_snd - d->step_fst;
	i = 0;
	while (i < d->step_fst)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
			d->fst, d->snd, data->color);
		p += 2 * d->step_snd;
		if (p >= 0)
		{
			d->snd += dir;
			p -= 2 * d->step_fst;
		}
		d->fst += 1;
		i++;
	}
}

/* y = fst. y_step is bigger. */
void	bresenham_y(t_draw *d, t_fdf *data)
{
	int	dir;
	int	p;
	int	i;

	dir = 1;
	if (d->snd > d->snd_end)
		dir = -1;
	p = 2 * d->step_snd - d->step_fst;
	i = 0;
	while (i < d->step_fst)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr,
			d->snd, d->fst, data->color);
		p += 2 * d->step_snd;
		if (p >= 0)
		{
			d->snd += dir;
			p -= 2 * d->step_fst;
		}
		d->fst += 1;
		i++;
	}
}

void	fill_draw_data_x(t_draw *d, t_screen_point *sp1, t_screen_point *sp2)
{
	if (sp1->x > sp2->x)
	{
		d->fst = sp2->x;
		d->fst_end = sp1->x;
		d->snd = sp2->y;
		d->snd_end = sp1->y;
	}
	else
	{
		d->fst = sp1->x;
		d->fst_end = sp2->x;
		d->snd = sp1->y;
		d->snd_end = sp2->y;
	}
	d->step_snd = ft_abs(sp2->y - sp1->y);
}

void	fill_draw_data_y(t_draw *d, t_screen_point *sp1, t_screen_point *sp2)
{
	if (sp1->y > sp2->y)
	{
		d->fst = sp2->y;
		d->fst_end = sp1->y;
		d->snd = sp2->x;
		d->snd_end = sp1->x;
	}
	else
	{
		d->fst = sp1->y;
		d->fst_end = sp2->y;
		d->snd = sp1->x;
		d->snd_end = sp2->x;
	}
	d->step_snd = ft_abs(sp2->x - sp1->x);
}

void	bresenham(t_screen_point *sp1, t_screen_point *sp2, t_fdf *data)
{
	t_draw	d;

	d.step_fst = ft_max(ft_abs(sp2->x - sp1->x), ft_abs(sp2->y - sp1->y));
	if (d.step_fst == ft_abs(sp2->x - sp1->x))
	{
		fill_draw_data_x(&d, sp1, sp2);
		bresenham_x(&d, data);
	}
	else
	{
		fill_draw_data_y(&d, sp1, sp2);
		bresenham_y(&d, data);
	}
}
