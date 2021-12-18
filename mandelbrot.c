/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:44:50 by foulare           #+#    #+#             */
/*   Updated: 2021/12/18 01:27:48 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
#include "mlx.h"

static void	ft_init(int x, int y, float *z, t_info *info)
{
	t_complex	pmax;
	t_complex	pmin;

	pmin = info->pmin;
	pmax = info->pmax;
	info->c[0] = ((float)x * (pmax.x - pmin.x)) / WIDTH + pmin.x;
	info->c[1] = ((float)y * (pmax.y - pmin.y)) / HEIGHT + pmin.y;
	z[0] = 0;
	z[1] = 0;
}

void	mandelbrot(t_info *info)
{
	t_init	zn;
	float	z[2];

	zn.y = -1;
	while (++zn.y < HEIGHT)
	{
		zn.x = -1;
		while (++zn.x < WIDTH)
		{
			ft_init(zn.x, zn.y, z, info);
			zn.iter = -1;
			while (++zn.iter < info->max)
				if (ft_calcul(z, info->c))
					break ;
			if (zn.iter != info->max)
					info->buffer[zn.y * WIDTH + zn.x] = ft_color(zn.iter, info);
			else
				info->buffer[zn.y * WIDTH + zn.x] = 0x000000;
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->image, 0, 0);
}
