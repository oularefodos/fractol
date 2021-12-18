/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foulare <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 20:59:41 by foulare           #+#    #+#             */
/*   Updated: 2021/12/18 01:28:15 by foulare          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"
#include "math.h"
#include "mlx.h"

int	ft_calcul_abs(float *z, float *c)
{
	float	temp;

	temp = (fabs(z[0]) * fabs(z[0])) - (fabs(z[1]) * fabs(z[1])) + c[0];
	z[1] = (2 * fabs(z[0]) * fabs(z[1])) + c[1];
	z[0] = temp;
	if (((z[0] * z[0]) + (z[1] * z[1])) > 4)
		return (1);
	return (0);
}

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

void	burning_ship(t_info *info)
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
				if (ft_calcul_abs(z, info->c))
					break ;
			if (zn.iter != info->max)
					info->buffer[zn.y * WIDTH + zn.x] = ft_color(zn.iter, info);
			else
				info->buffer[zn.y * WIDTH + zn.x] = 0x000000;
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->image, 0, 0);
}
