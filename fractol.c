/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 22:03:31 by foulare           #+#    #+#             */
/*   Updated: 2021/12/18 01:44:18 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx.h"
#include "fractol.h"
#include <stdio.h>
#include <stdlib.h>

int	mouse_move(int x, int y, t_info *info)
{
	t_complex	pmin;
	t_complex	pmax;

	pmin = info->pmin;
	pmax = info->pmax;
	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		info->c[0] = (float)x * (pmax.x - pmin.x) / WIDTH + pmin.x;
		info->c[1] = (float)y * (pmax.y - pmin.y) / HEIGHT + pmin.y;
		julia(info);
	}
	return (0);
}

int	mouse_hook(int button, int mousex, int mousey, void *params)
{
	t_info	*info;

	info = (t_info *)params;
	if (button == 5)
	{
		info->max += 50;
		ft_zoom_mouse(info, mousex, mousey, 1);
	}
	if (button == 4)
	{
		if (info->max > 50)
			info->max -= 50;
		ft_zoom_mouse(info, mousex, mousey, 0);
	}
	if (info->status == 2)
		julia(info);
	if (info-> status == 1)
		mandelbrot(info);
	return (0);
}

int	ft_close(void *params)
{
	t_info	*info;

	info = (t_info *)params;
	mlx_destroy_image(info->mlx, info->image);
	mlx_destroy_image(info->mlx, info->win);
	exit(EXIT_SUCCESS);
	return (0);
}

void	var_init(t_info *info)
{
	info->x = 0;
	info->y = 0;
	info->posx = 0;
	info->posy = 0;
	info->pmin.x = -2;
	info->pmax.x = 2;
	info->pmin.y = -2;
	info->pmax.y = 2;
	info->max = 50;
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, WIDTH, HEIGHT, "fractol");
	info->image = mlx_new_image(info->mlx, WIDTH, HEIGHT);
	info->buffer = (unsigned int *)mlx_get_data_addr(info->image, \
			&info->pix, &info->lin, &info->d);
}

int	main(int ac, char **str)
{
	t_info	info;

	if (ac != 2)
		ft_error();
	var_init(&info);
	if (ft_strcmp(str[1], "mandelbrot") == 0)
	{
		info.status = 1;
		mandelbrot(&info);
	}
	else if (ft_strcmp(str[1], "julia") == 0)
	{
		info.status = 2;
		info.c[0] = 0.5;
		info.c[1] = 0.3;
		julia(&info);
		mlx_hook(info.win, 6, 0, mouse_move, &info);
	}
	else
		ft_error();
	mlx_hook(info.win, 17, 0, ft_close, &info);
	mlx_hook(info.win, 4, 0, mouse_hook, &info);
	mlx_hook(info.win, 2, 0, key_hook, &info);
	mlx_loop(info.mlx);
	return (0);
}
