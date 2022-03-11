/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akilk <akilk@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:51:53 by akilk             #+#    #+#             */
/*   Updated: 2022/03/11 07:32:12 by akilk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_fdf *data)
{
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == 53)
		exit(0);
	if (key == 34)
		data->para = 0;
	if (key == 35)
		data->para = 1;
	if (data->zoom < 1)
		data->zoom = 1;
	if (key == 126)
		data->shift_y -= 10;
	if (key == 125)
		data->shift_y += 10;
	if (key == 123)
		data->shift_x -= 10;
	if (key == 124)
		data->shift_x += 10;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	return (0);
}

int	errors(int err)
{
	if (err == 1)
		ft_putstr("Usage: ./fdf filename\n");
	else if (err == 2)
		ft_putstr("Wrong filename\n");
	else if (err == 3)
		ft_putstr("Memory allocation failed\n");
	else if (err == 4)
		ft_putstr("Couldn't read file\n");
	return (-1);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_fdf	*data;

	if (argc != 2)
		return (errors(1));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (errors(2));
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
		return (errors(3));
	data->zoom = 30;
	data->shift_x = 300;
	data->shift_y = 200;
	data->para = 0;
	data->z_matrix = read_fdf(fd, data);
	if (!data->z_matrix)
		return (errors(4));
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "title");
	draw(data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
